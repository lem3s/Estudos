from fastapi import FastAPI

from Data.Database import init_db
from WebApi.CourseController import router as course_router
from WebApi.StudentController import router as student_router
from WebApi.TeacherController import router as teacher_router

app = FastAPI(title="Layered Architecture - Student API")
app.include_router(student_router)
app.include_router(teacher_router)
app.include_router(course_router)


@app.on_event("startup")
def on_startup() -> None:
    init_db()


def main():
    import uvicorn

    init_db()
    uvicorn.run(app, host="127.0.0.1", port=8000)


if __name__ == "__main__":
    main()
