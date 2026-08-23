package at0708;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;
import java.util.ArrayList;
import java.util.List;

@XmlRootElement(name = "courses")
@XmlAccessorType(XmlAccessType.FIELD)
public class CourseList {

    @XmlElement(name = "course")
    private List<Course> courses = new ArrayList<Course>();

    public CourseList() {
        super();
    }

    public CourseList(List<Course> courses) {
        this.courses = courses;
    }

    public List<Course> getCourses() {
        return courses;
    }

    public void setCourses(List<Course> courses) {
        this.courses = courses;
    }
}
