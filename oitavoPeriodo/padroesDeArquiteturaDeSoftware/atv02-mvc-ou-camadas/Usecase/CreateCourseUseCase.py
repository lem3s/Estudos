from Domain.Entities.Course import Course
from Domain.Interfaces.CourseRepositoryInterface import CourseRepositoryInterface


class CreateCourseUseCase:
    def __init__(self, repository: CourseRepositoryInterface):
        self.repository = repository

    def execute(self, course: Course) -> Course:
        return self.repository.add(course)
