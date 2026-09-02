from fastapi import APIRouter, HTTPException
from pydantic import BaseModel

from Data.CourseRepository import CourseRepository
from Domain.Entities.Course import Course
from Usecase.CreateCourseUseCase import CreateCourseUseCase
from Usecase.ListCoursesUseCase import ListCoursesUseCase

router = APIRouter(prefix="/courses", tags=["courses"])

repository = CourseRepository()
create_course = CreateCourseUseCase(repository)
list_courses = ListCoursesUseCase(repository)


class CourseRequest(BaseModel):
    name: str
    code: str
    workload: int
    description: str


class CourseResponse(BaseModel):
    id: int
    name: str
    code: str
    workload: int
    description: str

    @classmethod
    def from_entity(cls, course: Course) -> "CourseResponse":
        return cls(
            id=course.id,
            name=course.name,
            code=course.code,
            workload=course.workload,
            description=course.description,
        )


@router.post("", response_model=CourseResponse, status_code=201)
def create(payload: CourseRequest) -> CourseResponse:
    course = Course(
        name=payload.name,
        code=payload.code,
        workload=payload.workload,
        description=payload.description,
    )
    created = create_course.execute(course)
    return CourseResponse.from_entity(created)


@router.get("", response_model=list[CourseResponse])
def read_all() -> list[CourseResponse]:
    courses = list_courses.execute()
    return [CourseResponse.from_entity(c) for c in courses]


@router.get("/{course_id}", response_model=CourseResponse)
def read_one(course_id: int) -> CourseResponse:
    course = list_courses.execute_by_id(course_id)
    if course is None:
        raise HTTPException(status_code=404, detail="Curso não encontrado")
    return CourseResponse.from_entity(course)
