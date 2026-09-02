from datetime import date

from fastapi import APIRouter, HTTPException
from pydantic import BaseModel

from Data.TeacherRepository import TeacherRepository
from Domain.Entities.Teacher import Teacher
from Usecase.CreateTeacherUseCase import CreateTeacherUseCase
from Usecase.ListTeachersUseCase import ListTeachersUseCase

router = APIRouter(prefix="/teachers", tags=["teachers"])

repository = TeacherRepository()
create_teacher = CreateTeacherUseCase(repository)
list_teachers = ListTeachersUseCase(repository)


class TeacherRequest(BaseModel):
    name: str
    birth_date: date
    cpf: str
    subject: str
    registration: str


class TeacherResponse(BaseModel):
    id: int
    name: str
    birth_date: date
    cpf: str
    subject: str
    registration: str

    @classmethod
    def from_entity(cls, teacher: Teacher) -> "TeacherResponse":
        return cls(
            id=teacher.id,
            name=teacher.name,
            birth_date=teacher.birth_date,
            cpf=teacher.cpf,
            subject=teacher.subject,
            registration=teacher.registration,
        )


@router.post("", response_model=TeacherResponse, status_code=201)
def create(payload: TeacherRequest) -> TeacherResponse:
    teacher = Teacher(
        name=payload.name,
        birth_date=payload.birth_date,
        cpf=payload.cpf,
        subject=payload.subject,
        registration=payload.registration,
    )
    created = create_teacher.execute(teacher)
    return TeacherResponse.from_entity(created)


@router.get("", response_model=list[TeacherResponse])
def read_all() -> list[TeacherResponse]:
    teachers = list_teachers.execute()
    return [TeacherResponse.from_entity(t) for t in teachers]


@router.get("/{teacher_id}", response_model=TeacherResponse)
def read_one(teacher_id: int) -> TeacherResponse:
    teacher = list_teachers.execute_by_id(teacher_id)
    if teacher is None:
        raise HTTPException(status_code=404, detail="Professor não encontrado")
    return TeacherResponse.from_entity(teacher)
