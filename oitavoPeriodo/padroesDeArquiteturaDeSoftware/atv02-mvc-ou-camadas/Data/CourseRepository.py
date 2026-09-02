from Data.Database import get_connection
from Domain.Entities.Course import Course


class CourseRepository:
    """Implementação SQLite de CourseRepositoryInterface."""

    def add(self, course: Course) -> Course:
        with get_connection() as connection:
            cursor = connection.execute(
                """
                INSERT INTO courses (name, code, workload, description)
                VALUES (?, ?, ?, ?)
                """,
                (
                    course.name,
                    course.code,
                    course.workload,
                    course.description,
                ),
            )
            course.id = cursor.lastrowid
        return course

    def list_all(self) -> list[Course]:
        with get_connection() as connection:
            rows = connection.execute(
                "SELECT * FROM courses ORDER BY id"
            ).fetchall()
        return [self._to_entity(row) for row in rows]

    def get_by_id(self, course_id: int) -> Course | None:
        with get_connection() as connection:
            row = connection.execute(
                "SELECT * FROM courses WHERE id = ?", (course_id,)
            ).fetchone()
        return self._to_entity(row) if row else None

    @staticmethod
    def _to_entity(row) -> Course:
        return Course(
            id=row["id"],
            name=row["name"],
            code=row["code"],
            workload=row["workload"],
            description=row["description"],
        )
