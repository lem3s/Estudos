package controller;

import java.net.URL;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;
import java.util.Optional;
import java.util.ResourceBundle;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonType;
import javafx.scene.control.Label;
import javafx.scene.control.MenuItem;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;

import view.AppView;

public class AppController implements Initializable {

    @FXML private TableView<view.Course> tabela;
    @FXML private TableColumn<view.Course, Integer> idCol;
    @FXML private TableColumn<view.Course, String> nameCol;
    @FXML private TableColumn<view.Course, String> professorNameCol;
    @FXML private TableColumn<view.Course, Integer> hourLoadCol;
    @FXML private TableColumn<view.Course, String> beginDateCol;
    @FXML private TableColumn<view.Course, String> endDateCol;

    @FXML private TextField idField;
    @FXML private TextField nameField;
    @FXML private TextField professorNameField;
    @FXML private TextField hourLoadField;
    @FXML private TextField beginDateField;
    @FXML private TextField endDateField;

    @FXML private Button adicionarButton;
    @FXML private Button atualizarButton;
    @FXML private Button deletarButton;
    @FXML private Button cancelarButton;
    @FXML private Button salvarButton;

    @FXML private MenuItem recarregarMenuItem;
    @FXML private MenuItem sairMenuItem;

    @FXML private Label statusLabel;

    private static final SimpleDateFormat DATE_FORMAT = new SimpleDateFormat("dd/MM/yyyy");

    private enum Modo { 
        NAVEGACAO, 
        INSERCAO, 
        EDICAO 
    }

    private Modo modo = Modo.NAVEGACAO;

    private final AppView appView;

    private static final model.Database database = new model.Database("school.db");
    private static final model.CourseRepository courseRepo = new model.CourseRepository(database);

    public AppController() {
        this.appView = new AppView();
    }

    public static void main(String[] args) throws Exception {
        AppController appController = new AppController();
        appController.appView.run(args);
    }

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        idCol.setCellValueFactory(new PropertyValueFactory<>("id"));
        nameCol.setCellValueFactory(new PropertyValueFactory<>("name"));
        professorNameCol.setCellValueFactory(new PropertyValueFactory<>("professorName"));
        hourLoadCol.setCellValueFactory(new PropertyValueFactory<>("hourLoad"));
        beginDateCol.setCellValueFactory(new PropertyValueFactory<>("beginDate"));
        endDateCol.setCellValueFactory(new PropertyValueFactory<>("endDate"));

        tabela.setItems(loadAllCourses());

        tabela.getSelectionModel().selectedItemProperty().addListener(
                (observableValue, oldSelection, newSelection) -> handleCourseSelected(newSelection));

        entrarModoNavegacao();
    }

    @FXML
    public void onAdicionarButtonAction() {
        modo = Modo.INSERCAO;
        tabela.getSelectionModel().clearSelection();
        limparCampos();
        desabilitarCampos(false);
        desabilitarBotoes(true, true, true, false, false);
        nameField.requestFocus();
        setStatus("Preencha os dados e clique em Salvar para inserir.");
    }

    @FXML
    public void onAtualizarButtonAction() {
        if (tabela.getSelectionModel().getSelectedItem() == null) {
            return;
        }
        modo = Modo.EDICAO;
        desabilitarCampos(false);
        desabilitarBotoes(true, true, true, false, false);
        nameField.requestFocus();
        setStatus("Altere os dados e clique em Salvar para atualizar o id "
                + idField.getText() + ".");
    }

    @FXML
    public void onSalvarButtonAction() {
        try {
            if (modo == Modo.INSERCAO) {
                model.Course course = new model.Course();
                preencherModeloComFormulario(course);

                model.Course salvo = courseRepo.create(course);

                view.Course courseView = modelToView(salvo);
                tabela.getItems().add(courseView);
                tabela.getSelectionModel().select(courseView);
                setStatus("Disciplina inserida com id " + salvo.getId() + ".");

            } else if (modo == Modo.EDICAO) {
                view.Course selecionado = tabela.getSelectionModel().getSelectedItem();
                if (selecionado == null) {
                    throw new IllegalStateException("Nenhuma linha selecionada");
                }

                model.Course course = courseRepo.loadFromId(selecionado.getId());
                if (course == null) {
                    throw new IllegalStateException(
                            "Registro id " + selecionado.getId() + " não existe mais no banco");
                }
                preencherModeloComFormulario(course);

                courseRepo.update(course);

                int indice = tabela.getItems().indexOf(selecionado);
                view.Course atualizado = modelToView(course);
                tabela.getItems().set(indice, atualizado);
                tabela.getSelectionModel().select(atualizado);
                setStatus("Disciplina de id " + course.getId() + " atualizada.");
            }

            modo = Modo.NAVEGACAO;
            desabilitarCampos(true);
            desabilitarBotoes(false, false, false, true, true);

        } catch (Exception e) {
            new Alert(AlertType.ERROR, "Erro ao salvar: " + e.getMessage()).show();
        }
    }

    @FXML
    public void onDeletarButtonAction() {
        view.Course selecionado = tabela.getSelectionModel().getSelectedItem();
        if (selecionado == null) {
            return;
        }
        Alert confirmacao = new Alert(AlertType.CONFIRMATION,
                "Confirma a exclusão da disciplina \"" + selecionado.getName()
                        + "\" (id " + selecionado.getId() + ")?",
                ButtonType.OK, ButtonType.CANCEL);
        confirmacao.setHeaderText("Excluir registro");
        Optional<ButtonType> resposta = confirmacao.showAndWait();

        if (resposta.isPresent() && resposta.get() == ButtonType.OK) {
            try {
                model.Course course = courseRepo.loadFromId(selecionado.getId());
                if (course == null) {
                    throw new IllegalStateException(
                            "Registro id " + selecionado.getId() + " não existe mais no banco");
                }
                courseRepo.delete(course);
                tabela.getItems().remove(selecionado);
                setStatus("Disciplina de id " + selecionado.getId() + " removida.");
                entrarModoNavegacao();
            } catch (Exception e) {
                new Alert(AlertType.ERROR, "Erro ao deletar: " + e.getMessage()).show();
            }
        }
    }

    @FXML
    public void onCancelarButtonAction() {
        entrarModoNavegacao();
        setStatus("Operação cancelada.");
    }

    @FXML
    public void onRecarregarMenuItemAction() {
        tabela.setItems(loadAllCourses());
        entrarModoNavegacao();
        setStatus("Dados recarregados do banco de dados.");
    }

    @FXML
    public void onSairMenuItemAction() {
        database.close();
        System.exit(0);
    }

    private void handleCourseSelected(view.Course newSelection) {
        if (newSelection == null) {
            return;
        }
        idField.setText(Integer.toString(newSelection.getId()));
        nameField.setText(newSelection.getName());
        professorNameField.setText(newSelection.getProfessorName());
        hourLoadField.setText(Integer.toString(newSelection.getHourLoad()));
        beginDateField.setText(newSelection.getBeginDate());
        endDateField.setText(newSelection.getEndDate());
        desabilitarBotoes(false, false, false, true, true);
    }

    private view.Course modelToView(model.Course course) {
        return new view.Course(
                course.getId(),
                course.getName(),
                course.getProfessorName(),
                course.getHourLoad(),
                formatarData(course.getBeginDate()),
                formatarData(course.getEndDate()));
    }

    private void preencherModeloComFormulario(model.Course course) throws ParseException {
        String nome = nameField.getText() == null ? "" : nameField.getText().trim();
        if (nome.isEmpty()) {
            throw new IllegalArgumentException("O nome da disciplina é obrigatório");
        }
        int cargaHoraria;
        try {
            cargaHoraria = Integer.parseInt(hourLoadField.getText().trim());
        } catch (NumberFormatException e) {
            throw new IllegalArgumentException("A carga horária deve ser um número inteiro");
        }
        course.setName(nome);
        course.setProfessorName(professorNameField.getText().trim());
        course.setHourLoad(cargaHoraria);
        course.setBeginDate(converterData(beginDateField.getText()));
        course.setEndDate(converterData(endDateField.getText()));
    }

    private String formatarData(Date data) {
        return data == null ? "" : DATE_FORMAT.format(data);
    }

    private Date converterData(String texto) throws ParseException {
        if (texto == null || texto.trim().isEmpty()) {
            return null;
        }
        DATE_FORMAT.setLenient(false);
        return DATE_FORMAT.parse(texto.trim());
    }

    private ObservableList<view.Course> loadAllCourses() {
        ObservableList<view.Course> lista = FXCollections.observableArrayList();
        try {
            List<model.Course> listaDoBanco = courseRepo.loadAll();
            for (model.Course course : listaDoBanco) {
                lista.add(modelToView(course));
            }
        } catch (Exception e) {
            new Alert(AlertType.ERROR, "Erro ao carregar dados: " + e.getMessage()).show();
        }
        return lista;
    }

    private void entrarModoNavegacao() {
        modo = Modo.NAVEGACAO;
        desabilitarCampos(true);
        desabilitarBotoes(false, true, true, true, true);
        limparCampos();
        tabela.getSelectionModel().clearSelection();
    }

    private void desabilitarBotoes(boolean adicionar, boolean atualizar, boolean deletar,
                                   boolean cancelar, boolean salvar) {
        adicionarButton.setDisable(adicionar);
        atualizarButton.setDisable(atualizar);
        deletarButton.setDisable(deletar);
        cancelarButton.setDisable(cancelar);
        salvarButton.setDisable(salvar);
    }

    private void desabilitarCampos(boolean desabilitado) {
        nameField.setDisable(desabilitado);
        professorNameField.setDisable(desabilitado);
        hourLoadField.setDisable(desabilitado);
        beginDateField.setDisable(desabilitado);
        endDateField.setDisable(desabilitado);
    }

    private void limparCampos() {
        idField.setText("");
        nameField.setText("");
        professorNameField.setText("");
        hourLoadField.setText("");
        beginDateField.setText("");
        endDateField.setText("");
    }

    private void setStatus(String mensagem) {
        if (statusLabel != null) {
            statusLabel.setText(mensagem);
        }
    }
}
