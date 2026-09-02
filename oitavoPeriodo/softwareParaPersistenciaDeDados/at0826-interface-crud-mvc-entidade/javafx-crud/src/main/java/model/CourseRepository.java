package model;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import com.j256.ormlite.dao.Dao;
import com.j256.ormlite.dao.DaoManager;
import com.j256.ormlite.table.TableUtils;

public class CourseRepository {

    private static Database database;
    private static Dao<Course, Integer> dao;
    private List<Course> loadedCourses;
    private Course loadedCourse;

    public CourseRepository(Database database) {
        CourseRepository.setDatabase(database);
        this.loadedCourses = new ArrayList<Course>();
    }

    public static void setDatabase(Database database) {
        CourseRepository.database = database;
        try {
            dao = DaoManager.createDao(database.getConnection(), Course.class);
            TableUtils.createTableIfNotExists(database.getConnection(), Course.class);
        } catch (SQLException e) {
            System.out.println(e);
        }
    }

    public Course create(Course course) throws SQLException {
        int nrows = dao.create(course);
        if (nrows == 0) {
            throw new SQLException("Erro: objeto não foi salvo");
        }
        this.loadedCourse = course;
        this.loadedCourses.add(course);
        return course;
    }

    public Course update(Course course) throws SQLException {
        int nrows = dao.update(course);
        if (nrows == 0) {
            throw new SQLException("Erro: objeto não foi atualizado");
        }
        this.loadedCourse = course;
        return course;
    }

    public void delete(Course course) throws SQLException {
        int nrows = dao.delete(course);
        if (nrows == 0) {
            throw new SQLException("Erro: objeto não foi removido");
        }
        this.loadedCourses.remove(course);
    }

    public Course loadFromId(int id) throws SQLException {
        this.loadedCourse = dao.queryForId(id);
        if (this.loadedCourse != null) {
            this.loadedCourses.add(this.loadedCourse);
        }
        return this.loadedCourse;
    }

    public List<Course> loadAll() throws SQLException {
        this.loadedCourses = dao.queryForAll();
        if (!this.loadedCourses.isEmpty()) {
            this.loadedCourse = this.loadedCourses.get(0);
        }
        return this.loadedCourses;
    }

    public Database getDatabase() {
        return database;
    }
}
