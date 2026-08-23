from datetime import date

from fastapi import APIRouter, HTTPException
from pydantic import BaseModel

from Data.StudentRepository import StudentRepository
from Domain.Entities.Student import Student
from Usecase.CreateStudentUseCase import CreateStudentUseCase
from Usecase.ListStudentsUseCase import ListStudentsUseCase

router = APIRouter(prefix="/students", tags=["students"])

repository = StudentRepository()
create_student = CreateStudentUseCase(repository)
list_students = ListStudentsUseCase(repository)


class StudentRequest(BaseModel):
    name: str
    birth_date: date
    mother_name: str
    cpf: str
    registration: str


class StudentResponse(BaseModel):
    id: int
    name: str
    birth_date: date
    mother_name: str
    cpf: str
    registration: str

    @classmethod
    def from_entity(cls, student: Student) -> "StudentResponse":
        return cls(
            id=student.id,
            name=student.name,
            birth_date=student.birth_date,
            mother_name=student.mother_name,
            cpf=student.cpf,
            registration=student.registration,
        )


@router.post("", response_model=StudentResponse, status_code=201)
def create(payload: StudentRequest) -> StudentResponse:
    student = Student(
        name=payload.name,
        birth_date=payload.birth_date,
        mother_name=payload.mother_name,
        cpf=payload.cpf,
        registration=payload.registration,
    )
    created = create_student.execute(student)
    return StudentResponse.from_entity(created)


@router.get("", response_model=list[StudentResponse])
def read_all() -> list[StudentResponse]:
    students = list_students.execute()
    return [StudentResponse.from_entity(s) for s in students]


@router.get("/{student_id}", response_model=StudentResponse)
def read_one(student_id: int) -> StudentResponse:
    student = list_students.execute_by_id(student_id)
    if student is None:
        raise HTTPException(status_code=404, detail="Estudante não encontrado")
    return StudentResponse.from_entity(student)
