<h1 align="center">Trabalho Final</h1>
<h2 align="center">Aluno: João Victor Lemes - 202302614<br>Linguagem: Go</h2>

Como trabalho final para a disciplina de LPP decidi por fazer um gerenciador de
senhas que funciona através de linha de comando por ser uma solução capaz de
demonstrar a simplicidade e ao mesmo tempo eficiência e robustez que a linguagem
Go pode proporcionar.

### Funcionalidades

O sistema possui três funcionalidades básicas: `gerar`, `salvar` e `obter`
senhas

Para utilizar o programa basta ter o compilador da liguagem Go e assim as
funcionalidades podem ser acessadas através de argumentos da linha de comando
assim basta utilizar comandos como:

```
go run main.go -acao=gerar -servico=nome_do_servico -tamanho=20
```

> Essa ação irá gerar uma nova senha aleatória forte de tamanho 20, e salvá-la
> associada ao nome do serviço especifico para que será usada para que assim
> possa ser consultada posteriormente

```
go run main.go -acao=salvar -servico=nome_do_servico -senha=suaSenhaForte
```

> Essa ação irá salvar uma senha que foi definida manualmente pelo usuário

```
go run main.go -acao=obter -servico=nome_do_servico
```

> Essa ação irá exibir a senha salva para aquele serviço

As senhas serão salvas de maneira criptografada em um arquivo chamado
"senhas.txt"
