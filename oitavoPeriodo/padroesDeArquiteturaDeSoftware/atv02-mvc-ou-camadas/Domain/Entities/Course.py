from dataclasses import dataclass

@dataclass
class Course:
    name: str
    code: str
    workload: int
    description: str
    id: int | None = None
