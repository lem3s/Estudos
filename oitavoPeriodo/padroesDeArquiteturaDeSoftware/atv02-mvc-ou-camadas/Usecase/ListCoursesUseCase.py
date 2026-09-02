from Domain.Entities.Course import Course
from Domain.Interfaces.CourseRepositoryInterface import CourseRepositoryInterface


class ListCoursesUseCase:
    def __init__(self, repository: CourseRepositoryInterface):
        self.repository = repository

    def execute(self) -> list[Course]:
        return self.repository.list_all()

    def execute_by_id(self, course_id: int) -> Course | None:
        return self.repository.get_by_id(course_id)
