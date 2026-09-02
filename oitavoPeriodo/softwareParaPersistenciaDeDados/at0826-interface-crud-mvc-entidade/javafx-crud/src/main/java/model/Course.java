package model;

import java.util.Date;

import com.j256.ormlite.field.DataType;
import com.j256.ormlite.field.DatabaseField;
import com.j256.ormlite.table.DatabaseTable;

@DatabaseTable(tableName = "course")
public class Course {

    @DatabaseField(generatedId = true)
    private int id;

    @DatabaseField(dataType = DataType.STRING)
    private String name;

    @DatabaseField(dataType = DataType.STRING)
    private String professorName;

    @DatabaseField(dataType = DataType.INTEGER)
    private int hourLoad;

    @DatabaseField(dataType = DataType.DATE)
    private Date beginDate;

    @DatabaseField(dataType = DataType.DATE)
    private Date endDate;

    public Course() {
        super();
    }

    public Course(String name, String professorName, int hourLoad, Date beginDate, Date endDate) {
        this.name = name;
        this.professorName = professorName;
        this.hourLoad = hourLoad;
        this.beginDate = beginDate;
        this.endDate = endDate;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getProfessorName() {
        return professorName;
    }

    public void setProfessorName(String professorName) {
        this.professorName = professorName;
    }

    public int getHourLoad() {
        return hourLoad;
    }

    public void setHourLoad(int hourLoad) {
        this.hourLoad = hourLoad;
    }

    public Date getBeginDate() {
        return beginDate;
    }

    public void setBeginDate(Date beginDate) {
        this.beginDate = beginDate;
    }

    public Date getEndDate() {
        return endDate;
    }

    public void setEndDate(Date endDate) {
        this.endDate = endDate;
    }

    @Override
    public String toString() {
        return "Course [id=" + id + ", name=" + name + ", professorName=" + professorName
                + ", hourLoad=" + hourLoad + ", beginDate=" + beginDate + ", endDate=" + endDate + "]";
    }
}
