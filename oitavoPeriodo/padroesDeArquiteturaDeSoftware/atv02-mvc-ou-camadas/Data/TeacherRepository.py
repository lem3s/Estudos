from datetime import date

from Data.Database import get_connection
from Domain.Entities.Teacher import Teacher


class TeacherRepository:
    """Implementação SQLite de TeacherRepositoryInterface."""

    def add(self, teacher: Teacher) -> Teacher:
        with get_connection() as connection:
            cursor = connection.execute(
                """
                INSERT INTO teachers (name, birth_date, cpf, subject, registration)
                VALUES (?, ?, ?, ?, ?)
                """,
                (
                    teacher.name,
                    teacher.birth_date.isoformat(),
                    teacher.cpf,
                    teacher.subject,
                    teacher.registration,
                ),
            )
            teacher.id = cursor.lastrowid
        return teacher

    def list_all(self) -> list[Teacher]:
        with get_connection() as connection:
            rows = connection.execute(
                "SELECT * FROM teachers ORDER BY id"
            ).fetchall()
        return [self._to_entity(row) for row in rows]

    def get_by_id(self, teacher_id: int) -> Teacher | None:
        with get_connection() as connection:
            row = connection.execute(
                "SELECT * FROM teachers WHERE id = ?", (teacher_id,)
            ).fetchone()
        return self._to_entity(row) if row else None

    @staticmethod
    def _to_entity(row) -> Teacher:
        return Teacher(
            id=row["id"],
            name=row["name"],
            birth_date=date.fromisoformat(row["birth_date"]),
            cpf=row["cpf"],
            subject=row["subject"],
            registration=row["registration"],
        )
