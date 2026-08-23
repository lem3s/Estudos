from datetime import date

from Data.Database import get_connection
from Domain.Entities.Student import Student


class StudentRepository:
    """Implementação SQLite de StudentRepositoryInterface."""

    def add(self, student: Student) -> Student:
        with get_connection() as connection:
            cursor = connection.execute(
                """
                INSERT INTO students (name, birth_date, mother_name, cpf, registration)
                VALUES (?, ?, ?, ?, ?)
                """,
                (
                    student.name,
                    student.birth_date.isoformat(),
                    student.mother_name,
                    student.cpf,
                    student.registration,
                ),
            )
            student.id = cursor.lastrowid
        return student

    def list_all(self) -> list[Student]:
        with get_connection() as connection:
            rows = connection.execute(
                "SELECT * FROM students ORDER BY id"
            ).fetchall()
        return [self._to_entity(row) for row in rows]

    def get_by_id(self, student_id: int) -> Student | None:
        with get_connection() as connection:
            row = connection.execute(
                "SELECT * FROM students WHERE id = ?", (student_id,)
            ).fetchone()
        return self._to_entity(row) if row else None

    @staticmethod
    def _to_entity(row) -> Student:
        return Student(
            id=row["id"],
            name=row["name"],
            birth_date=date.fromisoformat(row["birth_date"]),
            mother_name=row["mother_name"],
            cpf=row["cpf"],
            registration=row["registration"],
        )
