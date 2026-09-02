from domain.sale import PricedSale
from pipeline.filter import Filter


class TransformFilter(Filter):
    def process(self, data):
        priced_sales = []

        for sale in data:
            total_value = sale.quantity * sale.unit_price
            priced_sales.append(
                PricedSale(
                    sale_id=sale.sale_id,
                    product=sale.product,
                    quantity=sale.quantity,
                    unit_price=sale.unit_price,
                    total_value=round(total_value, 2),
                )
            )

        return priced_sales
