package at0708;

import com.j256.ormlite.dao.DaoManager;
import com.j256.ormlite.dao.Dao;
import java.sql.SQLException;
import com.j256.ormlite.table.TableUtils;
import java.util.List;

import javax.xml.bind.JAXBException;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.util.ArrayList;

public class CourseRepository {
    private static Database database;
    private static Dao<Course, Integer> dao;
    private List<Course> loadedCourses;
    private Course loadedCourse;
    private CourseSerializerHelper serializerHelper;

    public CourseRepository(Database database, CourseSerializerHelper courseSerializerHelper) {
        CourseRepository
            .setDatabase(database);
        this.serializerHelper = courseSerializerHelper;
        loadedCourses = new ArrayList<Course>();
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

    public Course create(Course Course) {
        int nrows = 0;
        try {
            nrows = dao.create(Course);
            if ( nrows == 0 )
                throw new SQLException("Error: object not saved");
            this.loadedCourse = Course;
            loadedCourses.add(Course);
        } catch (SQLException e) {
            System.out.println(e);
        }
        return Course;
    }

    public Course update(Course Course) {
        int nrows = 0;
        try {
            nrows = dao.update(Course);
            if ( nrows == 0 )
                throw new SQLException("Error: object not updated");
            this.loadedCourse = Course;
        } catch (SQLException e) {
            System.out.println(e);
        }
        return Course;
    }

    public void delete(Course Course) {
        int nrows = 0;
        try {
            nrows = dao.delete(Course);
            if ( nrows == 0 )
                throw new SQLException("Error: object not deleted");
            loadedCourses.remove(Course);
        } catch (SQLException e) {
            System.out.println(e);
        }
    }

    public Course loadFromId(int id) {
        try {
            this.loadedCourse = dao.queryForId(id);
            if (this.loadedCourse != null)
                this.loadedCourses.add(this.loadedCourse);
        } catch (SQLException e) {
            System.out.println(e);
        }
        return this.loadedCourse;
    }

    public List<Course> loadAll() {
        try {
            this.loadedCourses = dao.queryForAll();
            if (this.loadedCourses.size() != 0)
                this.loadedCourse = this.loadedCourses.get(0);
        } catch (SQLException e) {
            System.out.println(e);
        }
        return this.loadedCourses;
    }

    public String dumpData(String format) throws JAXBException {
        var allCourses = loadAll();

        if (format.equalsIgnoreCase("json")) {
            return serializerHelper.toJson(allCourses);
        }

        if (format.equalsIgnoreCase("xml")) {
            return serializerHelper.toXml(allCourses);
        }

        return null;
    }

    public boolean dumpFile(String format, File file) {
        try {
            String data = dumpData(format);
            if (data == null) {
                return false;
            }
            try (FileWriter writer = new FileWriter(file)) {
                writer.write(data);
            }
            return true;
        } catch (IOException | JAXBException e) {
            System.out.println(e);
            return false;
        }
    }

    public Course createFromJSON(String json) {
        Course course = serializerHelper.fromJson(json);
        return create(course);
    }

    public Course createFromXML(String xml) throws JAXBException {
        Course course = serializerHelper.fromXml(xml);
        return create(course);
    }

    public int importData(String format, String data) throws JAXBException {
        List<Course> courses;

        if (format.equalsIgnoreCase("json")) {
            courses = serializerHelper.fromJsonList(data);
        } else if (format.equalsIgnoreCase("xml")) {
            courses = serializerHelper.fromXmlList(data);
        } else {
            return 0;
        }

        if (courses == null) {
            return 0;
        }

        int imported = 0;
        for (Course course : courses) {
            course.setId(0);
            if (create(course) != null) {
                imported++;
            }
        }
        return imported;
    }

    public int importFile(String format, File file) throws JAXBException, IOException {
        String data = Files.readString(file.toPath());
        return importData(format, data);
    }
}
