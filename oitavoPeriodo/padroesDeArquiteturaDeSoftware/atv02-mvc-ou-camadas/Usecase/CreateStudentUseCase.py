from Domain.Entities.Student import Student
from Domain.Interfaces.StudentRepositoryInterface import StudentRepositoryInterface


class CreateStudentUseCase:
    def __init__(self, repository: StudentRepositoryInterface):
        self.repository = repository

    def execute(self, student: Student) -> Student:
        return self.repository.add(student)
