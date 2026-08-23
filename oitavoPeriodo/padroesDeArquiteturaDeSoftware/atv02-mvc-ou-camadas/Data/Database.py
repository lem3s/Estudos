import sqlite3

DB_PATH = "students.db"


def get_connection() -> sqlite3.Connection:
    connection = sqlite3.connect(DB_PATH)
    connection.row_factory = sqlite3.Row
    return connection


def init_db() -> None:
    with get_connection() as connection:
        connection.execute(
            """
            CREATE TABLE IF NOT EXISTS students (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                name TEXT NOT NULL,
                birth_date TEXT NOT NULL,
                mother_name TEXT NOT NULL,
                cpf TEXT NOT NULL,
                registration TEXT NOT NULL
            )
            """
        )
