# Atividade 06 - Resumo crítico do seminário "trade-offs entre Blackboard, MVC e Multitiers" - 14/09
Aluno: João Victor Lemes Faria - 202302614

## Apresentação 01: Caio e Jaime

O grupo apresentou um exemplo para utilizar como estudo de caso para comparar os trade-offs entre as três opções arquiteturais propostas.

Considerando o contexo de uma aplicação para gestão do tráfego de uma metrópole, foram definidos os requisitos arquiteturalmente significativos para uma aplicação capaz de atender com qualidade essa demanda.

A primeira arquitetura roposta foi a de blackboard e trouxe um estado compartilhado entre o agente coordenador e os agentes especialistas que compõem o blackboard, para observarem o estado do tráfego nas vias e outros fatos observáveis, para realizarem análises e atuarem para melhor coordenar o trânsito. Essa arquitetura favorece a extensibilidade e rastreabilidade, porém desfavorece a manutenebilidade e escalabilidade.

Já no MVC, popuseram um painel de operador que interagiria com os dados das vias através de regras de negócio. Essa arquitetura favoreceu a extensibilidade e manutenebilidaed, porém desfavoreceu a rastreabilidade e escalabilidade.

Na aplicação multitiers, apresentou uma aplicação similar a camadas, porém com um maior desacoplamento para permitir escalabilidade e interoperabilidade independente entre as camadas. Favoreceu a extensibilidade e manutenibilidade e desfavoreceu a rastreabilidade.

## Apresentação 02: Thiago e Moisés

O segundo grupo apresentou um estudo de caso de uma instanciação para uma aplicação de análise inteligente de imagens.

A primeira arquitetura proposta, trouxe o Blackboard como uma alternativa flexível, porém com baixa escalabilidade.

Em uma arquitetura proposta de MVC, a manutenebilidade foi colocada como trade off relevante, uma vez que a adição de uma nova entidade de domínio, levaria a criação de classes de Modelo, Controle e View equivalentes.

Por fim, na aplicação Multitier, a separação de responsabilidades e escalabilidade foram postos como pontos positivos ao facilitar a escalabilidade da aplicação, entretanto a latência entre as aplicações deve ser levada em conta na decisão por essa arquitetura.

Na conclusão, propuseram como arquitetura uma abordagem mista, utilizando os três padrões arquiteturais em conjunto, cada um atuando em uma parte do sistema em que seus atributos de qualidade seriam mais vantajosos.
