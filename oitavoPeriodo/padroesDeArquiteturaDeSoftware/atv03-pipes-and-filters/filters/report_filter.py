from pipeline.filter import Filter

SEPARATOR = "=" * 40


class ReportFilter(Filter):
    def process(self, data):
        lines = [
            SEPARATOR,
            "RELATÓRIO DE VENDAS",
            SEPARATOR,
            "Vendas válidas: " + str(data.valid_sales),
            "Produtos vendidos: " + str(data.total_quantity),
            "Valor total: " + self.format_money(data.total_value),
            SEPARATOR,
        ]
        return "\n".join(lines)

    def format_money(self, value):
        text = f"{value:,.2f}"
        text = text.replace(",", "#").replace(".", ",").replace("#", ".")
        return "R$ " + text
