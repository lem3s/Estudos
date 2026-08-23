from dataclasses import dataclass
from datetime import date

@dataclass
class Student:
    name: str
    birth_date: date
    mother_name: str
    cpf: str
    registration: str
    id: int | None = None
