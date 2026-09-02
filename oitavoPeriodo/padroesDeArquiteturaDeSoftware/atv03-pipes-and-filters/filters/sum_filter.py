from domain.sale import SalesSummary
from pipeline.filter import Filter


class SumFilter(Filter):
    def process(self, data):
        valid_sales = 0
        total_quantity = 0
        total_value = 0.0

        for priced in data:
            valid_sales = valid_sales + 1
            total_quantity = total_quantity + priced.quantity
            total_value = total_value + priced.total_value

        return SalesSummary(
            valid_sales=valid_sales,
            total_quantity=total_quantity,
            total_value=round(total_value, 2),
        )
