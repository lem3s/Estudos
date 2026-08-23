package at0708;

import java.io.StringReader;
import java.io.StringWriter;
import java.lang.reflect.Type;
import java.util.ArrayList;
import java.util.List;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBException;
import javax.xml.bind.Marshaller;
import javax.xml.bind.Unmarshaller;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.reflect.TypeToken;

public class CourseSerializerHelper{
  private Gson gson;
  private JAXBContext jaxbContext;

  public CourseSerializerHelper() throws JAXBException {
    gson = new GsonBuilder()
                      .setDateFormat("yyyy-MM-dd")
                      .setPrettyPrinting()
                      .create();

    jaxbContext = JAXBContext.newInstance(Course.class, CourseList.class);
  }

  public String toJson(Course course){
    return gson.toJson(course);
  }

  public String toJson(List<Course> courses){
    return gson.toJson(courses);
  }

  public Course fromJson(String json){
    return gson.fromJson(json, Course.class);
  }

  public List<Course> fromJsonList(String json){
    Type listType = new TypeToken<ArrayList<Course>>(){}.getType();
    return gson.fromJson(json, listType);
  }

  public String toXml(Course course) throws JAXBException {
    Marshaller marshaller = jaxbContext.createMarshaller();
    marshaller.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, Boolean.TRUE);
    StringWriter sw = new StringWriter();
    marshaller.marshal(course, sw);
    return sw.toString();
  }

  public String toXml(List<Course> courses) throws JAXBException {
    Marshaller marshaller = jaxbContext.createMarshaller();
    marshaller.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, Boolean.TRUE);
    StringWriter sw = new StringWriter();
    marshaller.marshal(new CourseList(courses), sw);
    return sw.toString();
  }

  public Course fromXml(String xml) throws JAXBException {
    Unmarshaller unmarshaller = jaxbContext.createUnmarshaller();
    StringReader sr = new StringReader(xml);
    return (Course) unmarshaller.unmarshal(sr);
  }

  public List<Course> fromXmlList(String xml) throws JAXBException {
    Unmarshaller unmarshaller = jaxbContext.createUnmarshaller();
    StringReader sr = new StringReader(xml);
    CourseList courseList = (CourseList) unmarshaller.unmarshal(sr);
    return courseList.getCourses();
  }
}
