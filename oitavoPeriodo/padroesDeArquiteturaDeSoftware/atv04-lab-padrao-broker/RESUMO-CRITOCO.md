## Resumo crítico do seminário 31/08
Aluno: João Victor L. Faria - 202302614

### Apresentação 1: Padrões Arquiteturais e Componentes

O grupo apresentou um estudo de caso fictício para apresentar o uso de dois padrões arquiteturais, pipes and filters e broker, ambos utilizados no contexto de uma arquitetura tecnológica de uma varejista com presença online.

O sistema pipes and filters é focado no processamento massivo dos dados

O sistema broker é focado na platafora web 

O subsistema pipes and filter possui diversos filtros, entre eles: Receptor, Validador, Limpador, entre outros. Estes devem operar de maneira independente e com tolerância a falhas. Com componentes reutilizáveis.

O pipes and filters é adequado nesse cenário, uma vez que em um cenário de uma aplicação para lidar com dados em grande quantidade se beneficia muito dos atributos de qualidade do padrão pipes and filters.

o subsistema web possui um design utilizando padrões request and reply, HTTP e broker load balancer.

O fato da utilização do broker beneficia uma maior escalabilidade ao permitir a redistribuição das requisições em diversos servidores que irão se dividir para responderem a momentos de pico de requisições.

### Apresentação 2: Padrões de Arquitetura de Software: Pipes and Filters e Cliente-Servidor

O grupo propôs uma arquitetura de pipes and filters bem completa, utilizando componentes além da arquitetura tradicional, utilizando componentes complementares como pump, quarentine e sink para uma primeira aplicação de processamento de pipeline de dados.

Já o segundo problema atacado, utiliza uma arquitetura cliente servidor em camadas.
