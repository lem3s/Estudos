<h1 align="center">Diário de Bordo 2</h1>
<h2 align="center">Aluno: João Victor Lemes - 202302614<br>Linguagem: Go</h2>

<h2 align=center>Subprogramas</h2>

Subprogramas em Go permitem a execução e reutilização de blocos de código e 
podem ser classificados em dois tipos: funções e métodos.

### Funções

São declaradas usando a palavra-chave ```func``` seguida do nome da função,
a lista de parâmetros entre parênteses, o tipo do retorno e por fim o corpo da
função.

Portanto exemplos de funções em Go seriam:

```go
func fatorial(n int) int {
    if n == 0 {
        return 1
    }
    return n * fatorial(n-1)
}
```

```go
func adicionar(a int, b int) int {
    return a + b
}
```

> Funções também podem não ter valores de retorno, nesse caso basta fazer:
```go
func imprimeQuadrado() {
    fmt.Println("*******")
    fmt.Println("*     *")
    fmt.Println("*     *")
    fmt.Println("*******")
}
```

> Uma particularidade dessa lilnguagem é permitir funções com multiplos retornos
```go
func dividir(a int, b int) (int, int) {
    quociente := a / b
    resto := a % b
    return quociente, resto
}
```

> Ademais, Go também permite a declaração de funções com um número variável de parâmetros
```go
func somar(valores ...int) int {
    total := 0
    for _, valor := range valores {
       total += valor
    }
return total
}
```

### Métodos

Em Go métodos são funções que se assemelham a aos métodos existentes em liguagens
orientadas a objeto, pois permitem atrelar funções a certos tipos de dados (structs)

Para declarar um método é necessário usar a palavra `func` seguida do tipo de dado
com um nome para referecialo dentro so bloco de código, um nome para o método e o tipo
de retorno da função.

```go
type Retangulo struct {
    largura, altura float64
}

func (r Retangulo) Area() float64 {
    return r.largura * r.altura
}
```

### Outros tipos de subprogramas

Em Go podemos ter também funções anônimas

```go
nomeCompleto := func(nome, sobrenome string) string{ 
    return "Olá" + nome + " " + sobrenome
}
```

<h2 align=center>Tratamento de Exceções</h2>

### O tipo `error`

Em Go não existe o tradicional tratamento de erros com "try-catch". Em vez disso
Go utiliza uma abordagem utilizando um tipo de dado `error`.

Dessa maneira utilizando a prorpiedade da linguagem de permitir multiplos retornos, as funções
podem retornar um valor do tipo `error` para realizar o tratamento do erro.

```go
func dividir(a, b int) (int, error) {
    if b == 0 {
        return 0, errors.New("divisão por zero")
    }
    return a / b, nil
}
```

A desvantagem de se tratar erros dessa maneira é que os erros devem ser tratados explicitamente
e os casos devem ser previamente pensados, não podendo simplesmente definir o que o programa
irá fazer caso encontre um erro qualquer em um bloco de código como outras linguagens normalmente fazem.

### Funções auxiliares de tramento de erro

A linguagem go possui funções que auxiliam no tratamento de casos de erro, são elas:

- Defer

A instrução `defer` adia a execução de uma função até que a função que a contém termine.

```go
```

- Panic

`panic` é usado para abortar a execução do programa de maneira abrupta.

```go
```

- Recover

`recover` é usado para recuperar a execução normal de um panic.

```go
```


