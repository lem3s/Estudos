package controller;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Optional;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.ButtonType;
import javafx.scene.control.Label;
import javafx.scene.control.TableView;

import model.Repositorio;

/**
 * Controlador genérico para operações CRUD. Concentra toda a lógica de tela
 * comum às entidades: máquina de estados (navegação/inserção/edição),
 * sincronização da TableView, confirmação de exclusão e tratamento de erros.
 *
 * Cada entidade só precisa de uma subclasse que implemente os métodos
 * abstratos abaixo — nenhuma regra de CRUD é reescrita.
 *
 * @param <E>  entidade de domínio (ex.: model.Filme)
 * @param <V>  ViewModel exibido na TableView (ex.: view.Filme)
 * @param <ID> tipo da chave primária (ex.: Integer)
 */
public abstract class AbstractCrudController<E, V, ID> {

    protected enum Modo {
        NAVEGACAO,
        INSERCAO,
        EDICAO
    }

    protected static final SimpleDateFormat DATE_FORMAT = new SimpleDateFormat("dd/MM/yyyy");

    protected Modo modo = Modo.NAVEGACAO;

    // ---------------------------------------------------------------
    // Contrato que cada entidade implementa
    // ---------------------------------------------------------------

    /** Repositório específico da entidade. */
    protected abstract Repositorio<E, ID> getRepositorio();

    /** Tabela da tela. */
    protected abstract TableView<V> getTabela();

    /** Converte a entidade de domínio no ViewModel exibido na tabela. */
    protected abstract V modelToView(E entidade);

    /** Cria uma entidade a partir dos campos preenchidos na tela, validando-os. */
    protected abstract E viewToModel() throws Exception;

    /** Copia os dados do ViewModel selecionado para os campos da tela. */
    protected abstract void preencherCampos(V item);

    /** Limpa todos os campos da tela. */
    protected abstract void limparCampos();

    /** Habilita ou desabilita os campos editáveis. */
    protected abstract void desabilitarCampos(boolean desabilitado);

    /** Habilita ou desabilita os cinco botões da tela. */
    protected abstract void desabilitarBotoes(boolean adicionar, boolean atualizar,
                                              boolean deletar, boolean cancelar, boolean salvar);

    /** Extrai a chave primária do ViewModel. */
    protected abstract ID getIdFromViewModel(V viewModel);

    /** Atribui a chave primária à entidade. */
    protected abstract void setIdOnEntity(E entidade, ID id);

    // ---------------------------------------------------------------
    // Ganchos opcionais
    // ---------------------------------------------------------------

    /** Label de status da tela; retorne null se a tela não tiver um. */
    protected Label getStatusLabel() {
        return null;
    }

    /** Foco no primeiro campo editável ao entrar em inserção/edição. */
    protected void focarPrimeiroCampo() {
        // sem foco por padrão
    }

    /** Descrição do item usada na confirmação de exclusão. */
    protected String descricaoDoItem(V item) {
        return "o registro de id " + getIdFromViewModel(item);
    }

    // ---------------------------------------------------------------
    // Comportamento herdado por todas as telas
    // ---------------------------------------------------------------

    /** Carrega a tabela e liga a seleção ao preenchimento do formulário. */
    public void initialize() {
        getTabela().setItems(loadAll());
        getTabela().getSelectionModel().selectedItemProperty().addListener(
                (obs, selecaoAntiga, selecaoNova) -> {
                    if (selecaoNova == null) {
                        return;
                    }
                    preencherCampos(selecaoNova);
                    desabilitarBotoes(false, false, false, true, true);
                });
        entrarModoNavegacao();
    }

    /** Relê todos os registros do banco e volta ao modo navegação. */
    public void recarregar() {
        getTabela().setItems(loadAll());
        entrarModoNavegacao();
    }

    protected ObservableList<V> loadAll() {
        ObservableList<V> lista = FXCollections.observableArrayList();
        try {
            for (E entidade : getRepositorio().loadAll()) {
                lista.add(modelToView(entidade));
            }
        } catch (Exception e) {
            new Alert(AlertType.ERROR, "Erro ao carregar dados: " + e.getMessage()).show();
        }
        return lista;
    }

    public void onAdicionar() {
        modo = Modo.INSERCAO;
        getTabela().getSelectionModel().clearSelection();
        limparCampos();
        desabilitarCampos(false);
        desabilitarBotoes(true, true, true, false, false);
        focarPrimeiroCampo();
        setStatus("Preencha os dados e clique em Salvar para inserir.");
    }

    public void onAtualizar() {
        V selecionado = getTabela().getSelectionModel().getSelectedItem();
        if (selecionado == null) {
            new Alert(AlertType.WARNING, "Nenhum item selecionado para atualizar.").show();
            return;
        }
        modo = Modo.EDICAO;
        desabilitarCampos(false);
        desabilitarBotoes(true, true, true, false, false);
        focarPrimeiroCampo();
        setStatus("Altere os dados e clique em Salvar para atualizar o id "
                + getIdFromViewModel(selecionado) + ".");
    }

    public void onSalvar() {
        try {
            if (modo == Modo.INSERCAO) {
                E entidade = viewToModel();
                E salvo = getRepositorio().create(entidade);

                V novoItem = modelToView(salvo);
                getTabela().getItems().add(novoItem);
                getTabela().getSelectionModel().select(novoItem);
                setStatus("Registro inserido com id " + getIdFromViewModel(novoItem) + ".");

            } else if (modo == Modo.EDICAO) {
                V selecionado = getTabela().getSelectionModel().getSelectedItem();
                if (selecionado == null) {
                    throw new IllegalStateException("Nenhuma linha selecionada");
                }

                ID id = getIdFromViewModel(selecionado);
                if (getRepositorio().loadFromId(id) == null) {
                    throw new IllegalStateException(
                            "Registro id " + id + " não existe mais no banco");
                }

                E entidade = viewToModel();
                setIdOnEntity(entidade, id);
                getRepositorio().update(entidade);

                V atualizado = modelToView(entidade);
                int indice = getTabela().getItems().indexOf(selecionado);
                getTabela().getItems().set(indice, atualizado);
                getTabela().getSelectionModel().select(atualizado);
                setStatus("Registro de id " + id + " atualizado.");

            } else {
                return;
            }

            modo = Modo.NAVEGACAO;
            desabilitarCampos(true);
            desabilitarBotoes(false, false, false, true, true);

        } catch (Exception e) {
            new Alert(AlertType.ERROR, "Erro ao salvar: " + e.getMessage()).show();
        }
    }

    public void onDeletar() {
        V selecionado = getTabela().getSelectionModel().getSelectedItem();
        if (selecionado == null) {
            new Alert(AlertType.WARNING, "Nenhum item selecionado para deletar.").show();
            return;
        }

        Alert confirmacao = new Alert(AlertType.CONFIRMATION,
                "Confirma a exclusão de " + descricaoDoItem(selecionado) + "?",
                ButtonType.OK, ButtonType.CANCEL);
        confirmacao.setHeaderText("Excluir registro");
        Optional<ButtonType> resposta = confirmacao.showAndWait();

        if (resposta.isEmpty() || resposta.get() != ButtonType.OK) {
            return;
        }

        try {
            ID id = getIdFromViewModel(selecionado);
            E entidade = getRepositorio().loadFromId(id);
            if (entidade == null) {
                throw new IllegalStateException("Registro id " + id + " não existe mais no banco");
            }

            getRepositorio().delete(entidade);
            getTabela().getItems().remove(selecionado);
            entrarModoNavegacao();
            setStatus("Registro de id " + id + " removido.");

        } catch (Exception e) {
            new Alert(AlertType.ERROR, "Erro ao deletar: " + e.getMessage()).show();
        }
    }

    public void onCancelar() {
        entrarModoNavegacao();
        setStatus("Operação cancelada.");
    }

    protected void entrarModoNavegacao() {
        modo = Modo.NAVEGACAO;
        desabilitarCampos(true);
        desabilitarBotoes(false, true, true, true, true);
        limparCampos();
        getTabela().getSelectionModel().clearSelection();
    }

    protected void setStatus(String mensagem) {
        Label statusLabel = getStatusLabel();
        if (statusLabel != null) {
            statusLabel.setText(mensagem);
        }
    }

    // ---------------------------------------------------------------
    // Utilitários de data compartilhados pelas telas
    // ---------------------------------------------------------------

    protected String formatarData(Date data) {
        return data == null ? "" : DATE_FORMAT.format(data);
    }

    protected Date converterData(String texto) throws ParseException {
        if (texto == null || texto.trim().isEmpty()) {
            return null;
        }
        DATE_FORMAT.setLenient(false);
        return DATE_FORMAT.parse(texto.trim());
    }

    protected int converterInteiro(String texto, String nomeDoCampo) {
        try {
            return Integer.parseInt(texto == null ? "" : texto.trim());
        } catch (NumberFormatException e) {
            throw new IllegalArgumentException(nomeDoCampo + " deve ser um número inteiro");
        }
    }

    protected String obrigatorio(String texto, String nomeDoCampo) {
        String valor = texto == null ? "" : texto.trim();
        if (valor.isEmpty()) {
            throw new IllegalArgumentException(nomeDoCampo + " é obrigatório");
        }
        return valor;
    }
}
