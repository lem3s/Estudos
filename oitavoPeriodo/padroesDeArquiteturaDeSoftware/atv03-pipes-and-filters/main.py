import os
import sys

from filters import CleanFilter, ReadFilter, ReportFilter, SumFilter, TransformFilter
from pipeline import Pipeline

BASE_DIR = os.path.dirname(os.path.abspath(__file__))
DEFAULT_CSV = os.path.join(BASE_DIR, "assets", "vendas_exemplo_10_linhas.csv")


def show_discarded(clean_filter):
    print("Registros descartados: " + str(len(clean_filter.discarded)))
    for item in clean_filter.discarded:
        print(
            "  linha "
            + str(item.raw.line_number)
            + " (id_venda="
            + item.raw.sale_id
            + "): "
            + item.reason
        )


def main():
    csv_path = DEFAULT_CSV
    verbose = False

    for argument in sys.argv[1:]:
        if argument == "-v" or argument == "--verbose":
            verbose = True
        else:
            csv_path = argument

    clean_filter = CleanFilter()
    sales_pipeline = Pipeline(
        [
            ReadFilter(),
            clean_filter,
            TransformFilter(),
            SumFilter(),
            ReportFilter(),
        ]
    )

    try:
        report = sales_pipeline.process(csv_path)
    except (FileNotFoundError, ValueError, UnicodeDecodeError) as error:
        print("Erro ao processar " + str(csv_path) + ": " + str(error))
        return 1

    print(report)
    if verbose:
        print()
        print("Pipeline: " + " -> ".join(sales_pipeline.steps()))
        show_discarded(clean_filter)
    return 0


if __name__ == "__main__":
    sys.exit(main())
