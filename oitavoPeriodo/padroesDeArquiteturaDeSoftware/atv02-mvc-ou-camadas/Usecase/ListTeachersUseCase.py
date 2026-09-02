from Domain.Entities.Teacher import Teacher
from Domain.Interfaces.TeacherRepositoryInterface import TeacherRepositoryInterface


class ListTeachersUseCase:
    def __init__(self, repository: TeacherRepositoryInterface):
        self.repository = repository

    def execute(self) -> list[Teacher]:
        return self.repository.list_all()

    def execute_by_id(self, teacher_id: int) -> Teacher | None:
        return self.repository.get_by_id(teacher_id)
