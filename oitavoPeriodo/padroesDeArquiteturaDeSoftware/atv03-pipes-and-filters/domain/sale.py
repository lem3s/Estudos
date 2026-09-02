from dataclasses import dataclass


@dataclass
class RawSale:
    line_number: int
    sale_id: str
    product: str
    quantity: str
    unit_price: str


@dataclass
class Sale:
    line_number: int
    sale_id: str
    product: str
    quantity: int
    unit_price: float


@dataclass
class DiscardedSale:
    raw: RawSale
    reason: str


@dataclass
class PricedSale:
    sale_id: str
    product: str
    quantity: int
    unit_price: float
    total_value: float


@dataclass
class SalesSummary:
    valid_sales: int
    total_quantity: int
    total_value: float
