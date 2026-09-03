package controller;

import java.net.URL;
import java.util.ResourceBundle;

import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.ListCell;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;

import model.Repositorio;
import model.Repositorios;

/**
 * Tela de cadastro de filmes. Além das conversões da entidade, trata a chave
 * estrangeira para Diretor através de um ComboBox.
 */
public class FilmeController
        extends AbstractCrudController<model.Filme, view.Filme, Integer>
        implements Initializable {

    @FXML private TableView<view.Filme> tabela;
    @FXML private TableColumn<view.Filme, Integer> idCol;
    @FXML private TableColumn<view.Filme, String> tituloCol;
    @FXML private TableColumn<view.Filme, String> generoCol;
    @FXML private TableColumn<view.Filme, Integer> duracaoMinutosCol;
    @FXML private TableColumn<view.Filme, String> dataLancamentoCol;
    @FXML private TableColumn<view.Filme, String> diretorCol;

    @FXML private TextField idField;
    @FXML private TextField tituloField;
    @FXML private TextField generoField;
    @FXML private TextField duracaoMinutosField;
    @FXML private TextField dataLancamentoField;
    @FXML private ComboBox<model.Diretor> diretorComboBox;

    @FXML private Button adicionarButton;
    @FXML private Button atualizarButton;
    @FXML private Button deletarButton;
    @FXML private Button cancelarButton;
    @FXML private Button salvarButton;

    @FXML private Label statusLabel;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        idCol.setCellValueFactory(new PropertyValueFactory<>("id"));
        tituloCol.setCellValueFactory(new PropertyValueFactory<>("titulo"));
        generoCol.setCellValueFactory(new PropertyValueFactory<>("genero"));
        duracaoMinutosCol.setCellValueFactory(new PropertyValueFactory<>("duracaoMinutos"));
        dataLancamentoCol.setCellValueFactory(new PropertyValueFactory<>("dataLancamento"));
        diretorCol.setCellValueFactory(new PropertyValueFactory<>("diretorNome"));

        diretorComboBox.setCellFactory(combo -> new DiretorListCell());
        diretorComboBox.setButtonCell(new DiretorListCell());
        recarregarDiretores();

        super.initialize();
    }

    /**
     * Relê a lista de diretores do banco, preservando a seleção atual.
     * Chamado pelo AppController quando a aba de filmes é exibida, para que
     * diretores cadastrados na outra aba apareçam sem reiniciar a aplicação.
     */
    public void recarregarDiretores() {
        model.Diretor selecionado = diretorComboBox.getValue();
        try {
            diretorComboBox.setItems(
                    FXCollections.observableArrayList(Repositorios.DIRETOR.loadAll()));
        } catch (Exception e) {
            new Alert(AlertType.ERROR, "Erro ao carregar diretores: " + e.getMessage()).show();
            return;
        }
        if (selecionado != null) {
            selecionarDiretorPorId(selecionado.getId());
        }
    }

    @Override
    protected Repositorio<model.Filme, Integer> getRepositorio() {
        return Repositorios.FILME;
    }

    @Override
    protected TableView<view.Filme> getTabela() {
        return tabela;
    }

    @Override
    protected view.Filme modelToView(model.Filme filme) {
        model.Diretor diretor = filme.getDiretor();
        return new view.Filme(
                filme.getId(),
                filme.getTitulo(),
                filme.getGenero(),
                filme.getDuracaoMinutos(),
                formatarData(filme.getDataLancamento()),
                diretor == null ? 0 : diretor.getId(),
                diretor == null ? "" : diretor.getNome());
    }

    @Override
    protected model.Filme viewToModel() throws Exception {
        model.Diretor diretor = diretorComboBox.getValue();
        if (diretor == null) {
            throw new IllegalArgumentException("Selecione o diretor do filme");
        }

        model.Filme filme = new model.Filme();
        filme.setTitulo(obrigatorio(tituloField.getText(), "O título do filme"));
        filme.setGenero(generoField.getText() == null ? "" : generoField.getText().trim());
        filme.setDuracaoMinutos(
                converterInteiro(duracaoMinutosField.getText(), "A duração em minutos"));
        filme.setDataLancamento(converterData(dataLancamentoField.getText()));
        filme.setDiretor(diretor);
        return filme;
    }

    @Override
    protected void preencherCampos(view.Filme item) {
        idField.setText(Integer.toString(item.getId()));
        tituloField.setText(item.getTitulo());
        generoField.setText(item.getGenero());
        duracaoMinutosField.setText(Integer.toString(item.getDuracaoMinutos()));
        dataLancamentoField.setText(item.getDataLancamento());
        selecionarDiretorPorId(item.getDiretorId());
    }

    @Override
    protected void limparCampos() {
        idField.clear();
        tituloField.clear();
        generoField.clear();
        duracaoMinutosField.clear();
        dataLancamentoField.clear();
        diretorComboBox.setValue(null);
    }

    @Override
    protected void desabilitarCampos(boolean desabilitado) {
        tituloField.setDisable(desabilitado);
        generoField.setDisable(desabilitado);
        duracaoMinutosField.setDisable(desabilitado);
        dataLancamentoField.setDisable(desabilitado);
        diretorComboBox.setDisable(desabilitado);
    }

    @Override
    protected void desabilitarBotoes(boolean adicionar, boolean atualizar,
                                     boolean deletar, boolean cancelar, boolean salvar) {
        adicionarButton.setDisable(adicionar);
        atualizarButton.setDisable(atualizar);
        deletarButton.setDisable(deletar);
        cancelarButton.setDisable(cancelar);
        salvarButton.setDisable(salvar);
    }

    @Override
    protected Integer getIdFromViewModel(view.Filme viewModel) {
        return viewModel.getId();
    }

    @Override
    protected void setIdOnEntity(model.Filme entidade, Integer id) {
        entidade.setId(id);
    }

    @Override
    protected Label getStatusLabel() {
        return statusLabel;
    }

    @Override
    protected void focarPrimeiroCampo() {
        tituloField.requestFocus();
    }

    @Override
    protected String descricaoDoItem(view.Filme item) {
        return "o filme \"" + item.getTitulo() + "\" (id " + item.getId() + ")";
    }

    /** Seleciona no ComboBox o diretor com o id informado. */
    private void selecionarDiretorPorId(int diretorId) {
        for (model.Diretor diretor : diretorComboBox.getItems()) {
            if (diretor.getId() == diretorId) {
                diretorComboBox.setValue(diretor);
                return;
            }
        }
        diretorComboBox.setValue(null);
    }

    /** Exibe o nome do diretor tanto na lista quanto no botão do ComboBox. */
    private static class DiretorListCell extends ListCell<model.Diretor> {
        @Override
        protected void updateItem(model.Diretor diretor, boolean vazio) {
            super.updateItem(diretor, vazio);
            setText(vazio || diretor == null ? "" : diretor.getNome());
        }
    }

    // Ações do FXML: delegam para a superclasse genérica

    @FXML
    @Override
    public void onAdicionar() {
        super.onAdicionar();
    }

    @FXML
    @Override
    public void onAtualizar() {
        super.onAtualizar();
    }

    @FXML
    @Override
    public void onSalvar() {
        super.onSalvar();
    }

    @FXML
    @Override
    public void onDeletar() {
        super.onDeletar();
    }

    @FXML
    @Override
    public void onCancelar() {
        super.onCancelar();
    }
}
