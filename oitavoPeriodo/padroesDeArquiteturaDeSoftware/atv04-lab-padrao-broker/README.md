## Aluno: João Victor Lemes Faria - 202302614

### Primeira saída do Programa

```txt
[Cliente] Consultando produto 2
[Broker] Encaminhado solicitção para: produto
[Cliente] Resposta: Mouse - R$ 80,00
[Cliente] Consultando consumidor 1
[Broker] Encaminhado solicitção para: consumidor
[Cliente] Resposta: João
```

### Respostas:

1, 2 - O cliente não conhece diretamente nenhuma das classes que implementam 
3 - O único que conhece os serviços é a classe main que precisa saber de tais para injetá-los no Broker.
4 - Quem decide quem deve receber a solicitação é o próprio chamador ao definir qual serviço quer utilizar na chamada através do broker.
5 - O uso de interface reduz drasticamente o acoplamento. Facilitando também a extensão, já que qualquer serviço que implemente a interface pode ser facilmente adicionado ao broker.

### Segunda saída do programa:

```txt
[Cliente] Consultando produto 2
[Broker] Encaminhado solicitção para: produto
[Cliente] Resposta: Mouse - R$ 80,00
[Cliente] Consultando consumidor 1
[Broker] Encaminhado solicitção para: consumidor
[Cliente] Resposta: João
[Cliente] Consultando pedido 2
[Broker] Encaminhado solicitção para: pedido
[Cliente] Resposta: 1x Teclado, 1x Mouse
```

### Saída do experimento final:

```txt
Serviço não encontrado: pagamento
[Cliente] Consultando produto 2
[Broker] Encaminhado solicitção para: produto
[Cliente] Resposta: Mouse - R$ 80,00
[Cliente] Consultando consumidor 1
[Broker] Encaminhado solicitção para: consumidor
[Cliente] Resposta: João
[Cliente] Consultando pedido 2
[Broker] Encaminhado solicitção para: pedido
[Cliente] Resposta: 1x Teclado, 1x Mouse
```

### Perguntas finais:

1 - O padrão broker busca solucionar o problema de acoplamento entre os chamadores e as implementações dos serviços. Permitindo que mais serviços e mais chamadores sejam adicionados ou removidos sem grandes alterações arquiteturais. Nesse padrão o cliente tem papel de indicar para o broker qual serviço quer chamar e qual dado servirá de input, o Broker tem papel de abstrair a implementação do serviço chamado desde que ele implemente a devida interface.

2 - Dois benefífios do padrão broker são:
- Maior facilidade em adicionar serviços para serem chamados no broker sem ter que adicionar a dependência em todos os chamadores.
- Menor acoplamento entre as classes do sistema.

Dois trade-offs do padrão broker são:
- Aumento do rico de quebra caso remova um serviço já que a dependência não é explícita devido a existência do broker.
- Uma camada de broker, que necessita de manutenção é adicionada a arquitetura do sistema.

Consideraria adequado utilizar esse padrão em uma situação em que um menor acoplamento ou uma maior flexibilidade em qual serviço irá processar a requisição seja necessária.

E não utilizaria em sistemas altamente críticos e com baixa flexibilidade, como sistemas de saúde ou sistemas embarcados.
