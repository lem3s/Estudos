# Atividade 0902 - Utilização de classes genéricas
Aluno: João Victor L. Faria - 202302614

Considerando o contexto da atividade, foi feita uma aplicação MVC utilizando JavaFX, para o domínio de informações relacionadas a cinema, em que algumas classes chave foram criadas utilizando propriedades genéricas, a fim de melhorar o reuso do código/componentes. São elas:

A classe de repositório reutilizada entre as entidades de domínio a serem persistidas.
```java
public class Repositorio<T, ID> {

    private Database database;
    private Dao<T, ID> dao;
    private final Class<T> entityClass;
    private List<T> loadedEntities;
    private T loadedEntity;

    public Repositorio(Database database, Class<T> entityClass) {
        this.entityClass = entityClass;
        this.loadedEntities = new ArrayList<T>();
        setDatabase(database);
    }

    public void setDatabase(Database database) {
        this.database = database;
        try {
            this.dao = DaoManager.createDao(database.getConnection(), entityClass);
            TableUtils.createTableIfNotExists(database.getConnection(), entityClass);
        } catch (SQLException e) {
            System.out.println(e);
        }
    }

    public T create(T entity) throws SQLException {
        int nrows = dao.create(entity);
        if (nrows == 0) {
            throw new SQLException("Erro: objeto não foi salvo");
        }
        this.loadedEntity = entity;
        this.loadedEntities.add(entity);
        return entity;
    }

    public T update(T entity) throws SQLException {
        int nrows = dao.update(entity);
        if (nrows == 0) {
            throw new SQLException("Erro: objeto não foi atualizado");
        }
        this.loadedEntity = entity;
        return entity;
    }

    public void delete(T entity) throws SQLException {
        int nrows = dao.delete(entity);
        if (nrows == 0) {
            throw new SQLException("Erro: objeto não foi removido");
        }
        this.loadedEntities.remove(entity);
    }

    public T loadFromId(ID id) throws SQLException {
        this.loadedEntity = dao.queryForId(id);
        if (this.loadedEntity != null) {
            this.loadedEntities.add(this.loadedEntity);
        }
        return this.loadedEntity;
    }

    public List<T> loadAll() throws SQLException {
        this.loadedEntities = dao.queryForAll();
        if (!this.loadedEntities.isEmpty()) {
            this.loadedEntity = this.loadedEntities.get(0);
        }
        return this.loadedEntities;
    }

    public Database getDatabase() {
        return database;
    }

    public T getLoadedEntity() {
        return loadedEntity;
    }

    public List<T> getLoadedEntities() {
        return loadedEntities;
    }
}
```

A classe de Controller a ser reutilizada entre os controllers de cada tela/entidade que será exibida em tela para interações com o usuário.
```java
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
```

As entidades de domínio são:

```java
public class Diretor {

    @DatabaseField(generatedId = true)
    private int id;

    @DatabaseField(dataType = DataType.STRING)
    private String nome;

    @DatabaseField(dataType = DataType.STRING)
    private String nacionalidade;

    @DatabaseField(dataType = DataType.DATE)
    private Date dataNascimento;

    public Diretor() {
        super();
    }

    public Diretor(String nome, String nacionalidade, Date dataNascimento) {
        this.nome = nome;
        this.nacionalidade = nacionalidade;
        this.dataNascimento = dataNascimento;
    }

    // Getters e setters omitodos

    /** Rótulo exibido no ComboBox de diretores da tela de filmes. */
    @Override
    public String toString() {
        return nome == null ? "" : nome;
    }
}
```

```java
@DatabaseTable(tableName = "filme")
public class Filme {

    @DatabaseField(generatedId = true)
    private int id;

    @DatabaseField(dataType = DataType.STRING)
    private String titulo;

    @DatabaseField(dataType = DataType.STRING)
    private String genero;

    @DatabaseField(dataType = DataType.INTEGER)
    private int duracaoMinutos;

    @DatabaseField(dataType = DataType.DATE)
    private Date dataLancamento;

    // foreignAutoRefresh faz o ORMLite carregar o diretor junto com o filme,
    // permitindo filme.getDiretor().getNome() logo após um loadAll()
    @DatabaseField(foreign = true, foreignAutoRefresh = true)
    private Diretor diretor;

    public Filme() {
        super();
    }

    public Filme(String titulo, String genero, int duracaoMinutos, Date dataLancamento, Diretor diretor) {
        this.titulo = titulo;
        this.genero = genero;
        this.duracaoMinutos = duracaoMinutos;
        this.dataLancamento = dataLancamento;
        this.diretor = diretor;
    }

    // Getters e setters omitodos

    @Override
    public String toString() {
        return "Filme [id=" + id + ", titulo=" + titulo + ", genero=" + genero
                + ", duracaoMinutos=" + duracaoMinutos + ", dataLancamento=" + dataLancamento
                + ", diretor=" + diretor + "]";
    }
}
```

> Vale evidenciar o uso de Foreign Key entre as entidades, conceito primordial em banco de dados.

Por fim, seguem evidências das execuções cruciais da aplicação com CRUD simples.

### Create

![](/PreCreate.png)
![](/PosCreate.png)

> Resalto novamente aqui o seletor dinâmico de diretor ao cadastrar filme, com base nos diretores persistidos no banco de dados.
![](/PreCreateFilme.png)
![](/PosCreateFilme.png)

### Read

![](/Read.png)

### Update

![](/PreAtualizacao.png)
![](/PosAtualizacao.png)

### Delete

![](/PreDelete.png)
![](/PosDelete.png)
