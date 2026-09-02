package view;

import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;

public class Course {

    private final SimpleIntegerProperty id;
    private final SimpleStringProperty name;
    private final SimpleStringProperty professorName;
    private final SimpleIntegerProperty hourLoad;
    private final SimpleStringProperty beginDate;
    private final SimpleStringProperty endDate;

    public Course(int id, String name, String professorName, int hourLoad,
                  String beginDate, String endDate) {
        this.id = new SimpleIntegerProperty(id);
        this.name = new SimpleStringProperty(name);
        this.professorName = new SimpleStringProperty(professorName);
        this.hourLoad = new SimpleIntegerProperty(hourLoad);
        this.beginDate = new SimpleStringProperty(beginDate);
        this.endDate = new SimpleStringProperty(endDate);
    }

    public int getId() {
        return this.id.get();
    }

    public void setId(int id) {
        this.id.set(id);
    }

    public String getName() {
        return this.name.get();
    }

    public void setName(String name) {
        this.name.set(name);
    }

    public String getProfessorName() {
        return this.professorName.get();
    }

    public void setProfessorName(String professorName) {
        this.professorName.set(professorName);
    }

    public int getHourLoad() {
        return this.hourLoad.get();
    }

    public void setHourLoad(int hourLoad) {
        this.hourLoad.set(hourLoad);
    }

    public String getBeginDate() {
        return this.beginDate.get();
    }

    public void setBeginDate(String beginDate) {
        this.beginDate.set(beginDate);
    }

    public String getEndDate() {
        return this.endDate.get();
    }

    public void setEndDate(String endDate) {
        this.endDate.set(endDate);
    }
}
