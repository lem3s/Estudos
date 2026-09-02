from dataclasses import dataclass
from datetime import date

@dataclass
class Teacher:
    name: str
    birth_date: date
    cpf: str
    subject: str
    registration: str
    id: int | None = None
