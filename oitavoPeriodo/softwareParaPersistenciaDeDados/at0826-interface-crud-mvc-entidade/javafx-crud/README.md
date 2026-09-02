# AT0826 — Interface CRUD (MVC) para uma entidade Java

**Aluno:** João Victor Lemes Faria — 202302614
**Disciplina:** Software para Persistência de Dados
**Baseado em:** [Tutorial JavaFX CRUD — Marcelo Akira](https://github.com/marceloakira/tutorials/tree/main/javafx-crud)

Aplicação desktop em **JavaFX** que realiza as quatro operações CRUD
(*Create*, *Retrieve*, *Update*, *Delete*) sobre a entidade **`Course`**
(disciplina), persistida em **SQLite** através do ORM **ORMLite**.

---

## 1. Requisitos

| Ferramenta | Versão usada | Observação |
|---|---|---|
| JDK | 21 ou superior | testado com Temurin 25 |
| Maven | 3.6+ | resolve JavaFX, ORMLite e o driver SQLite |
| Scene Builder | 21+ | opcional, apenas para editar `app.fxml` |

Não é necessário instalar o JavaFX separadamente: o `javafx-maven-plugin`
baixa os artefatos nativos correspondentes ao sistema operacional.

## 2. Como executar

O projeto inclui o **Maven Wrapper**, portanto não é preciso ter o Maven
instalado — o próprio script baixa a versão correta na primeira execução:

```bash
cd javafx-crud
./mvnw clean javafx:run       # Linux / macOS
mvnw.cmd clean javafx:run     # Windows
```

Se você já tiver o Maven no `PATH`, `mvn clean javafx:run` funciona igualmente.

O plugin compila o projeto, monta o *module-path* do JavaFX e executa a classe
`controller.AppController`, que é o ponto de entrada da aplicação.

### Banco de dados

O arquivo **`school.db`** (SQLite) já acompanha o projeto com alguns registros
de exemplo. Ele é aberto a partir do diretório de trabalho da aplicação
(a raiz de `javafx-crud/`). Se o arquivo for apagado, ele é recriado
automaticamente e a tabela `course` é gerada pelo ORMLite a partir das
anotações da entidade (`TableUtils.createTableIfNotExists`).

Para inspecionar o banco pela linha de comando:

```bash
sqlite3 school.db "select * from course;"
```

## 3. Arquitetura — MVC em três pacotes

```
javafx-crud/
├── pom.xml                     dependências e plugin de execução
├── school.db                   base SQLite
└── src/main/
    ├── java/
    │   ├── model/              CAMADA DE MODELO (domínio + persistência)
    │   │   ├── Course.java             entidade anotada com ORMLite
    │   │   ├── Database.java           gerencia a conexão JDBC/SQLite
    │   │   └── CourseRepository.java   DAO com create/update/delete/load
    │   ├── view/               CAMADA DE VISÃO
    │   │   ├── AppView.java            Application do JavaFX, carrega o FXML
    │   │   └── Course.java             view model com Simple*Property
    │   └── controller/         CAMADA DE CONTROLE
    │       └── AppController.java      eventos da UI -> chamadas CRUD
    └── resources/view/
        └── app.fxml            layout declarativo (Scene Builder)
```

### Por que existem duas classes `Course`?

* **`model.Course`** é a entidade persistida. Seus atributos são tipos Java
  comuns (`int`, `String`, `Date`) anotados com `@DatabaseField`. Ela não
  depende de nada do JavaFX — poderia ser reaproveitada em uma aplicação web
  ou de linha de comando.
* **`view.Course`** é o *view model* consumido pelo `TableView`. Seus atributos
  são `SimpleIntegerProperty` / `SimpleStringProperty`, ou seja, objetos
  **observáveis**: quando o valor muda, a célula correspondente se redesenha
  sozinha (padrão *Observer*), sem chamada manual de *refresh*.

A conversão entre as duas é feita pelo método `modelToView()` do controlador —
é exatamente esse ponto que mantém as camadas desacopladas.

### Fluxo de uma operação

```
usuário clica em Salvar
  → FXML dispara onSalvarButtonAction()          [controller]
  → controlador lê os TextField e valida         [controller]
  → preenche um model.Course                     [controller → model]
  → courseRepo.create(course)                    [model: INSERT via ORMLite]
  → modelToView(salvo) entra na ObservableList   [controller → view]
  → TableView se atualiza automaticamente        [view]
```

## 4. Operações implementadas

| Operação | Botão / menu | Método do controlador | Método do repositório | SQL gerado |
|---|---|---|---|---|
| **C**reate | Adicionar → Salvar | `onAdicionarButtonAction` + `onSalvarButtonAction` | `create()` | `INSERT INTO course ...` |
| **R**etrieve | carga inicial e *Arquivo → Recarregar* | `initialize` / `onRecarregarMenuItemAction` | `loadAll()` | `SELECT * FROM course` |
| **U**pdate | Atualizar → Salvar | `onAtualizarButtonAction` + `onSalvarButtonAction` | `loadFromId()` + `update()` | `UPDATE course SET ... WHERE id = ?` |
| **D**elete | Deletar (com confirmação) | `onDeletarButtonAction` | `loadFromId()` + `delete()` | `DELETE FROM course WHERE id = ?` |

O tutorial original deixa `update()` e `delete()` como `// TODO`; **ambos foram
implementados nesta atividade**, junto com a máquina de estados do formulário
que decide se o botão *Salvar* executa um *insert* ou um *update*.

### Máquina de estados da interface

| Modo | Campos | Adicionar | Atualizar | Deletar | Cancelar | Salvar |
|---|---|---|---|---|---|---|
| Navegação (nada selecionado) | desabilitados | ✔ | ✖ | ✖ | ✖ | ✖ |
| Linha selecionada | desabilitados | ✔ | ✔ | ✔ | ✖ | ✖ |
| Inserção | habilitados | ✖ | ✖ | ✖ | ✔ | ✔ |
| Edição | habilitados | ✖ | ✖ | ✖ | ✔ | ✔ |

Esse controle de habilitação evita estados inválidos — por exemplo, tentar
deletar sem ter selecionado um registro.

## 5. Validações

* Nome da disciplina é obrigatório.
* Carga horária precisa ser um inteiro válido (`NumberFormatException` tratada).
* Datas são digitadas em `dd/MM/aaaa` e convertidas com `SimpleDateFormat` em
  modo estrito (`setLenient(false)`), de modo que `31/02/2026` é rejeitada.
* O campo `Id` é somente leitura: o valor é gerado pelo banco
  (`@DatabaseField(generatedId = true)`).
* Erros são exibidos ao usuário em um `Alert` do tipo `ERROR`, e não apenas
  impressos no console.

## 6. Diferenças em relação ao tutorial

1. **Entidade própria:** `Course` (disciplina), reaproveitada da atividade
   AT0708, no lugar de `Estudante`.
2. **Update e Delete implementados** (no tutorial são `// TODO`).
3. **Projeto Maven** em vez de BlueJ, com o `javafx-maven-plugin` para execução.
4. **FXML carregado do classpath** (`getResource("/view/app.fxml")`) em vez de
   um caminho relativo do disco — funciona igualmente pela IDE, pelo Maven ou
   dentro de um JAR.
5. **Tratamento de exceções propagado:** o repositório lança `SQLException` em
   vez de apenas imprimir no console, permitindo que o controlador avise o
   usuário.
6. **Datas** (`java.util.Date` mapeadas como `DataType.DATE`) com conversão e
   validação entre modelo e visão.

## 7. Editando a interface no Scene Builder

```bash
open src/main/resources/view/app.fxml   # macOS, com o Scene Builder instalado
```

Os `fx:id` dos componentes precisam continuar iguais aos nomes dos atributos
`@FXML` de `AppController`, e os `onAction` precisam apontar para métodos
existentes no controlador — é essa correspondência por nome que o `FXMLLoader`
resolve por reflexão em tempo de execução.
