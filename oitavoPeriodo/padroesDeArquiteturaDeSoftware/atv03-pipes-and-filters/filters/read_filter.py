import csv
import os

from domain.sale import RawSale
from pipeline.filter import Filter

COLUMNS = ["id_venda", "produto", "quantidade", "preco_unitario"]


class ReadFilter(Filter):
    def process(self, data):
        file_path = str(data)
        if not os.path.isfile(file_path):
            raise FileNotFoundError("Arquivo CSV não encontrado: " + file_path)

        raw_sales = []
        with open(file_path, newline="", encoding="utf-8") as file:
            reader = csv.DictReader(file)
            self.check_columns(reader.fieldnames)

            line_number = 2
            for row in reader:
                raw_sales.append(
                    RawSale(
                        line_number=line_number,
                        sale_id=self.get_field(row, "id_venda"),
                        product=self.get_field(row, "produto"),
                        quantity=self.get_field(row, "quantidade"),
                        unit_price=self.get_field(row, "preco_unitario"),
                    )
                )
                line_number = line_number + 1

        return raw_sales

    def check_columns(self, fieldnames):
        if fieldnames is None:
            fieldnames = []

        header = []
        for name in fieldnames:
            if name is not None:
                header.append(name.strip())

        missing = []
        for column in COLUMNS:
            if column not in header:
                missing.append(column)

        if len(missing) > 0:
            raise ValueError(
                "Cabeçalho do CSV não possui a(s) coluna(s): " + ", ".join(missing)
            )

    def get_field(self, row, column):
        value = row.get(column)
        if value is None:
            return ""
        return value.strip()
