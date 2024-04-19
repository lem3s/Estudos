<h1 align="center">Diário de Bordo 1</h1>
<h2 align="center">Aluno: João Victor Lemes - 202302614<br>Linguagem: Go</h2>

<h2 align=center>Introdução</h2>

### Critérios de avaliação de uma linguagem

Uma linguagem pode ser avaliada de acordo com diversos critérios, entre eles 
alguns dos mais importantes são: a legibilidade, redigibilidade e confiabilidade

- Legibilidade é a capacidade que uma linguagem possui em ser simples, coesa, consistente,
uniforme, flexível, autodescritiva e consequentemente facilmente entendida.

- Redigibilidade está muita atrelada a legibilidade de uma linguagem, para ela ser ter boa
redigibilidade ela precisa ser simples, com bom nível de abstração, expressiva e com
maneiras eficientes de representar uma lógica.

- Confiabilidade envolve a proficiência de um linguagem em proporcionar uma experiência
segura tanto processo de desenvolvimento quanto em produção, possibilitado verificar e
tratar erros.

Ademais existem diversos outros critérios para avaliar uma linguagem que podem ser importantes
dependendo do contexto como o seu custo computacional, sua velocidade e o quão geral ela é.

> A linguagem Go possui em geral uma boa legibilidade, redigibilidade e confiabilidade.
Já que não é muito próxima da linguagem de máquina, possui um bom nível de abstração e 
um bom tratamento de erros e excessões
```go
package main

import "fmt"

func main() {
    fmt.Println("Olá, diário de bordo.")
}
```

### Categorias de linguagem

Cada linguagem pode ser classificada em imperativa, funcional, lógica.

- Imperativa: As linguagem mais habituais que funcionam através de variáveis,
atribuição e iteração. Tal classificação inclui outros tipos populares de linguagens
como as orientadas a objeto, visuais e de script.

- Funcional: Funciona através da execução de funções, praticamente sem utilização de variáveis
de atribuição, e depende bastante em funções recursivas.

- Lógica: Funciona atrvés da avaliação do valor verdade de determinadas expressões. Um
exemplo de linguagem dessa categoria é Prolog.

- Marcação: Linguagens de que eram originalmente de marcação e foram extendidas para dar
suporte a programação.

> A linguagem Go é uma linguagem imperativa
```go

```

### Métodos de implementação

- Compilação: A linguagem é "traduzida" para linguagem de máquina antes de ser executada.

- Interpretação: A linguagem é traduzida para linguagem de máquina ao mesmo tempo que que
vai sendo executada. Por isso é mais lenta que linguagens interpretadas.

- Híbrida: A linguagem é compilada para uma linguagem intermediária que depois é interpretada
por um outro programa. Tal modelo permite que o programa seja mais portavel para diferentes
sistemas, já que pode-se compartilhar o programa intermediário que poderá ser executado em qualquer
máquina que possua um "interpretador" desse código intermediário.

> A linguagem Go é uma linguagem compilada
```

```

<h2 align=center>Variáveis</h2>

Variáveis são abstrações da memória do computador para aumentar a redigibilidade.
Possuem diversas características como nome, endereço, valor, tipo, tempo de vida e escopo.

### Nomes

São usados para referenciar as variáveis. E cada linguagem possui suas restrições e boas práticas quanto ao nome das variáveis.

Pode ser ou não case-sensitive e ter ou não regras específicas de declaração
como uso de símbolos de identificação ($, @).

Existem também certas palavras que cada linguagen define como reservadas
que compõem a estrutura sintática da linguagem e não podem ser usadas para
nomear variáveis.

```go

```

### Variáveis

- Endereço: é o endereço físico da memória a qual a variável referencia. Uma
variável pode referenciar endereços diferentes em momentos diferentes, mas também
variáveis diferentes podem referenciar o mesmo endereço.

- Valor: É o conteúdo que está armazenado naquele endereço de memória.

- Tipo: As variáveis geralmente precisam ter seu tipo definido, o tipo irá
determinar a faixa de valores que aquela variável é capaz de armazenar
e quais operações são possíveis de serem feitas.

```go

```

### Amarração

É a relação existente entre a operação que será executada na linguagem e 
um símbolo ou palavra. Está relacionada a declaração de variáveis.

- Estática: O tipo da variável precisa ser declarado antes do programa ser
executado. Pode ser de maneira explícita ou implícita.

- Dinâmica: O tipo da variável é flexível, pode ser alterado em tempo de
execução e não precisa ser declarado.

- Inferência de tipo: O tipo da variável não precisa ser definido previamente
e é inferido pelo interpretador em tempo de execução.

```go

```

### Amarrações de armazenagem

- Estático: A memória é alocada durante a compilação do programa.

- Heap: A memória é alocada dinamicamente durante a execução do programa.

- Pilha

### Escopo

- Estático

  - Subprogramas

  - Blocos

  - Globais

- Dinâmico

>
### Ambiente de refenciação

### Constantes
