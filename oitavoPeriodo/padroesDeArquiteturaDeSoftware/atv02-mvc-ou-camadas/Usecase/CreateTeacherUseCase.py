from Domain.Entities.Teacher import Teacher
from Domain.Interfaces.TeacherRepositoryInterface import TeacherRepositoryInterface


class CreateTeacherUseCase:
    def __init__(self, repository: TeacherRepositoryInterface):
        self.repository = repository

    def execute(self, teacher: Teacher) -> Teacher:
        return self.repository.add(teacher)
