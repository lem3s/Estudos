from Domain.Entities.Student import Student
from Domain.Interfaces.StudentRepositoryInterface import StudentRepositoryInterface


class ListStudentsUseCase:
    def __init__(self, repository: StudentRepositoryInterface):
        self.repository = repository

    def execute(self) -> list[Student]:
        return self.repository.list_all()

    def execute_by_id(self, student_id: int) -> Student | None:
        return self.repository.get_by_id(student_id)
