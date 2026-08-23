package at0708;

import com.j256.ormlite.field.DataType;
import com.j256.ormlite.field.DatabaseField;

import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlRootElement;
import javax.xml.bind.annotation.XmlAccessType;
import java.util.Date;

@XmlRootElement(name = "course")
@XmlAccessorType(XmlAccessType.FIELD)
public class Course {
    public Course() {
        super();
    }

    public Course(
            String name,
            String professorName,
            int hourLoad,
            Date beginDate,
            Date endDate) {
        this.name = name;
        this.professorName = professorName;
        this.hourLoad = hourLoad;
        this.beginDate = beginDate;
        this.endDate = endDate;
    }

    @DatabaseField(generatedId = true)
    private int id;

    @DatabaseField
    private String name;

    @DatabaseField
    private String professorName;

    @DatabaseField
    public int hourLoad;

    @DatabaseField(dataType = DataType.DATE)
    public Date beginDate;

    @DatabaseField(dataType = DataType.DATE)
    public Date endDate;

    public void setId(int id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setProfessorName(String professorName) {
        this.professorName = professorName;
    }

    public void setHourLoad(int hourLoad) {
        this.hourLoad = hourLoad;
    }

    public void setBeginDate(Date beginDate) {
        this.beginDate = beginDate;
    }

    public void setEndDate(Date endDate) {
        this.endDate = endDate;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getProfessorName() {
        return professorName;
    }

    public int getHourLoad() {
        return hourLoad;
    }

    public Date getBeginDate() {
        return beginDate;
    }

    public Date getEndDate() {
        return endDate;
    }

    @Override
    public String toString() {
        return "Course [id=" + id + ", name=" + name + ", professorName=" + professorName + ", hourLoad=" + hourLoad
                + ", beginDate=" + beginDate + ", endDate=" + endDate + "]";
    }
}
