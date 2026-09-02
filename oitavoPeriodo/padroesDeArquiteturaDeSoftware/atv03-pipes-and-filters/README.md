# Atividade 03 — Pipes and Filters

Aluno: João Victor Lemes Faria — 202302614
Disciplina: Padrões de Arquitetura de Software

Processamento de um arquivo CSV de vendas organizado com o padrão arquitetural
Pipes and Filters, gerando um relatório consolidado.

## Como executar

```bash
python3 main.py                                   # usa assets/vendas_exemplo_10_linhas.csv
python3 main.py caminho/do/arquivo.csv            # usa outro arquivo
python3 main.py caminho/do/arquivo.csv --verbose  # mostra os registros descartados
```

Testes:

```bash
python3 -m unittest discover -s tests -v
```

Não há dependências externas: apenas a biblioteca padrão do Python.

## O pipeline

```
[Arquivo CSV]
     |
     v
[ReadFilter]       caminho do arquivo  ->  list[RawSale]
     |
     v
[CleanFilter]      list[RawSale]       ->  list[Sale]
     |
     v
[TransformFilter]  list[Sale]          ->  list[PricedSale]
     |
     v
[SumFilter]        list[PricedSale]    ->  SalesSummary
     |
     v
[ReportFilter]     SalesSummary        ->  str
     |
     v
[Relatório]
```

| Filtro | Responsabilidade |
| --- | --- |
| `ReadFilter` | Lê o CSV e transforma cada linha em um `RawSale` (todos os campos como texto). Não valida nada. |
| `CleanFilter` | Converte os campos numéricos e separa os registros válidos dos inválidos. |
| `TransformFilter` | Calcula `valor_total = quantidade x preco_unitario` para cada venda. |
| `SumFilter` | Acumula vendas válidas, quantidade total de produtos e valor total. |
| `ReportFilter` | Formata o resumo como o texto final do relatório. |

## Estrutura de pastas

```
pipeline/
  filter.py        classe base Filter (contrato: um process(entrada) -> saída)
  pipeline.py      classe Pipeline, que encadeia os filtros
domain/
  sale.py          estruturas que trafegam pelos pipes
filters/
  read_filter.py, clean_filter.py, transform_filter.py,
  sum_filter.py, report_filter.py
tests/
  test_filters.py  testes de cada filtro isoladamente + teste do pipeline completo
assets/
  vendas_exemplo_10_linhas.csv
main.py            monta o pipeline e o executa
```

## Como o padrão foi aplicado

- **Responsabilidade específica**: cada filtro faz uma única coisa (ler, validar,
  calcular, somar, formatar).
- **Independência**: nenhum filtro importa outro filtro. Todos dependem apenas
  da classe base `Filter` e das estruturas de `domain/`.
- **Uma entrada e uma saída**: todo filtro implementa somente `process(data)`,
  recebendo um dado e devolvendo outro, sem efeitos colaterais externos. O
  `ReportFilter`, por exemplo, devolve o texto em vez de imprimi-lo — quem
  imprime é o `main.py`.
- **Sem conhecimento interno dos demais**: a ordem das etapas existe apenas no
  `main.py`, ao construir o `Pipeline`. Trocar, remover ou acrescentar um filtro
  é uma alteração local a esse arquivo.
- **Testável isoladamente**: cada filtro é testado entregando a ele uma entrada
  construída à mão, sem precisar dos outros filtros nem de um arquivo CSV
  (exceto, naturalmente, o `ReadFilter`).

A classe `Pipeline` também herda de `Filter`, então um pipeline inteiro pode ser
usado como uma etapa de outro pipeline.

## Tratamento dos registros inválidos

Um registro é considerado inválido pelo `CleanFilter` quando:

| Situação | Motivo registrado |
| --- | --- |
| `id_venda` vazio | `id_venda ausente` |
| `produto` vazio | `produto ausente` |
| `quantidade` vazia | `quantidade ausente` |
| `quantidade` não é um inteiro | `quantidade não numérica (...)` |
| `quantidade` menor ou igual a zero | `quantidade menor ou igual a zero (...)` |
| `preco_unitario` vazio | `preco_unitario ausente` |
| `preco_unitario` não é um número | `preco_unitario não numérico (...)` |
| `preco_unitario` negativo | `preco_unitario negativo (...)` |

Registros inválidos **são descartados**: não seguem para o `TransformFilter` e
não entram em nenhum total. Em vez de serem silenciosamente perdidos, ficam
guardados na lista `CleanFilter.discarded`, cada um com a linha de origem e o
motivo da rejeição. O `main.py` exibe essa lista quando executado com
`--verbose`.

## Resultado com o arquivo de 10 registros

Dos 10 registros, 2 são inválidos: a linha 10 (`009`) tem quantidade `-1` e a
linha 11 (`010`) está sem preço unitário.

```
========================================
RELATÓRIO DE VENDAS
========================================
Vendas válidas: 8
Produtos vendidos: 20
Valor total: R$ 14.630,00
========================================
```

Com `--verbose`:

```
Pipeline: ReadFilter -> CleanFilter -> TransformFilter -> SumFilter -> ReportFilter
Registros descartados: 2
  linha 10 (id_venda=009): quantidade menor ou igual a zero (-1)
  linha 11 (id_venda=010): preco_unitario ausente
```

## Arquivo de 1000 registros

Basta colocar o arquivo em `assets/` e informar o caminho:

```bash
python3 main.py assets/vendas_exemplo_1000_linhas.csv --verbose
```

Nenhuma alteração de código é necessária: o caminho do CSV é a entrada do
pipeline, e os filtros não fazem suposição sobre a quantidade de registros.
