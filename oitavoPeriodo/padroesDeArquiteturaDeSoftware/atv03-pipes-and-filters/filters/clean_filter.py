from domain.sale import DiscardedSale, Sale
from pipeline.filter import Filter


class CleanFilter(Filter):
    def __init__(self):
        self.discarded = []

    def process(self, data):
        self.discarded = []
        valid_sales = []

        for raw in data:
            reason = self.find_problem(raw)
            if reason is not None:
                self.discarded.append(DiscardedSale(raw=raw, reason=reason))
            else:
                valid_sales.append(
                    Sale(
                        line_number=raw.line_number,
                        sale_id=raw.sale_id,
                        product=raw.product,
                        quantity=int(raw.quantity),
                        unit_price=float(raw.unit_price),
                    )
                )

        return valid_sales

    def find_problem(self, raw):
        if raw.sale_id == "":
            return "id_venda ausente"

        if raw.product == "":
            return "produto ausente"

        if raw.quantity == "":
            return "quantidade ausente"

        try:
            quantity = int(raw.quantity)
        except ValueError:
            return "quantidade não numérica (" + raw.quantity + ")"

        if quantity <= 0:
            return "quantidade menor ou igual a zero (" + raw.quantity + ")"

        if raw.unit_price == "":
            return "preco_unitario ausente"

        try:
            unit_price = float(raw.unit_price)
        except ValueError:
            return "preco_unitario não numérico (" + raw.unit_price + ")"

        if unit_price < 0:
            return "preco_unitario negativo (" + raw.unit_price + ")"

        return None
