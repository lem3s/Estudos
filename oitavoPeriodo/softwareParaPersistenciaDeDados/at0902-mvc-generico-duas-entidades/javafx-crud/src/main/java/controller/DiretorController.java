package controller;

import java.net.URL;
import java.util.ResourceBundle;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;

import model.Repositorio;
import model.Repositorios;

/**
 * Tela de cadastro de diretores. Toda a lógica de CRUD vem de
 * AbstractCrudController: aqui só ficam os campos da tela e as conversões
 * específicas da entidade.
 */
public class DiretorController
        extends AbstractCrudController<model.Diretor, view.Diretor, Integer>
        implements Initializable {

    @FXML private TableView<view.Diretor> tabela;
    @FXML private TableColumn<view.Diretor, Integer> idCol;
    @FXML private TableColumn<view.Diretor, String> nomeCol;
    @FXML private TableColumn<view.Diretor, String> nacionalidadeCol;
    @FXML private TableColumn<view.Diretor, String> dataNascimentoCol;

    @FXML private TextField idField;
    @FXML private TextField nomeField;
    @FXML private TextField nacionalidadeField;
    @FXML private TextField dataNascimentoField;

    @FXML private Button adicionarButton;
    @FXML private Button atualizarButton;
    @FXML private Button deletarButton;
    @FXML private Button cancelarButton;
    @FXML private Button salvarButton;

    @FXML private Label statusLabel;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        idCol.setCellValueFactory(new PropertyValueFactory<>("id"));
        nomeCol.setCellValueFactory(new PropertyValueFactory<>("nome"));
        nacionalidadeCol.setCellValueFactory(new PropertyValueFactory<>("nacionalidade"));
        dataNascimentoCol.setCellValueFactory(new PropertyValueFactory<>("dataNascimento"));
        super.initialize();
    }

    @Override
    protected Repositorio<model.Diretor, Integer> getRepositorio() {
        return Repositorios.DIRETOR;
    }

    @Override
    protected TableView<view.Diretor> getTabela() {
        return tabela;
    }

    @Override
    protected view.Diretor modelToView(model.Diretor diretor) {
        return new view.Diretor(
                diretor.getId(),
                diretor.getNome(),
                diretor.getNacionalidade(),
                formatarData(diretor.getDataNascimento()));
    }

    @Override
    protected model.Diretor viewToModel() throws Exception {
        model.Diretor diretor = new model.Diretor();
        diretor.setNome(obrigatorio(nomeField.getText(), "O nome do diretor"));
        diretor.setNacionalidade(nacionalidadeField.getText() == null
                ? "" : nacionalidadeField.getText().trim());
        diretor.setDataNascimento(converterData(dataNascimentoField.getText()));
        return diretor;
    }

    @Override
    protected void preencherCampos(view.Diretor item) {
        idField.setText(Integer.toString(item.getId()));
        nomeField.setText(item.getNome());
        nacionalidadeField.setText(item.getNacionalidade());
        dataNascimentoField.setText(item.getDataNascimento());
    }

    @Override
    protected void limparCampos() {
        idField.clear();
        nomeField.clear();
        nacionalidadeField.clear();
        dataNascimentoField.clear();
    }

    @Override
    protected void desabilitarCampos(boolean desabilitado) {
        nomeField.setDisable(desabilitado);
        nacionalidadeField.setDisable(desabilitado);
        dataNascimentoField.setDisable(desabilitado);
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
    protected Integer getIdFromViewModel(view.Diretor viewModel) {
        return viewModel.getId();
    }

    @Override
    protected void setIdOnEntity(model.Diretor entidade, Integer id) {
        entidade.setId(id);
    }

    @Override
    protected Label getStatusLabel() {
        return statusLabel;
    }

    @Override
    protected void focarPrimeiroCampo() {
        nomeField.requestFocus();
    }

    @Override
    protected String descricaoDoItem(view.Diretor item) {
        return "o diretor \"" + item.getNome() + "\" (id " + item.getId() + ")";
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
