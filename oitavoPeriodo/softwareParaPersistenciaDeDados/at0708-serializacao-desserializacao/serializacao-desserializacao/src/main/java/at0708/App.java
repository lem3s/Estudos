package at0708;
import java.io.File;
import java.text.SimpleDateFormat;
import java.util.Date;

public class App
{
    public static void main( String[] args )
    {
        var database = new Database("school.db");

        try {
            var serializerHelper = new CourseSerializerHelper();
            var courseRepository = new CourseRepository(database, serializerHelper);

            Date startDate = new SimpleDateFormat("yyyy-MM-dd").parse("2026-08-12");
            Date endDate = new SimpleDateFormat("yyyy-MM-dd").parse("2026-12-02");

            var class1 = new Course(
                "Software para persistência de dados",
                "Marcelo Akira",
                64,
                startDate,
                endDate
            );

            var createdEntity = courseRepository.create(class1);
            System.out.println("Entidade criada (CREATE):" + createdEntity.toString());

            var retrievedEntity = courseRepository.loadFromId(createdEntity.getId());
            System.out.println("Entidade lida (READ):" + retrievedEntity.toString());

            retrievedEntity.setHourLoad(128);
            var updatedEntity = courseRepository.update(retrievedEntity);
            System.out.println("Entidade atualizada (UPDATE):" + updatedEntity.toString());

            System.out.println("dumpData(json):");
            String json = courseRepository.dumpData("json");
            System.out.println(json);

            System.out.println("dumpData(xml):");
            String xml = courseRepository.dumpData("xml");
            System.out.println(xml);

            System.out.println("dumpFile:");
            boolean savedJson = courseRepository.dumpFile("json", new File("courses.json"));
            boolean savedXml = courseRepository.dumpFile("xml", new File("courses.xml"));
            System.out.println("courses.json salvo: " + savedJson);
            System.out.println("courses.xml salvo: " + savedXml);

            System.out.println("createFromJSON:");
            String singleJson = serializerHelper.toJson(new Course(
                "Teste de Software", "Edmundo Spoto", 64, startDate, endDate));
            System.out.println("JSON a ser criado:" + singleJson);
            var fromJson = courseRepository.createFromJSON(singleJson);
            System.out.println("Criado a partir de JSON: " + fromJson);

            System.out.println("createFromXML:");
            String singleXml = serializerHelper.toXml(new Course(
                "Computação Ubíqua", "Otávio Calaça", 64, startDate, endDate));
            System.out.println("XML a ser criado:" + singleXml);
            var fromXml = courseRepository.createFromXML(singleXml);
            System.out.println("Criado a partir de XML: " + fromXml);

            System.out.println("importData / importFile:");
            int importedFromString = courseRepository.importData("json", json);
            System.out.println("Objetos importados de String JSON: " + importedFromString);

            int importedFromFile = courseRepository.importFile("xml", new File("courses.xml"));
            System.out.println("Objetos importados do arquivo XML: " + importedFromFile);
        }
        catch (Exception ex) {
            System.err.println("Erro: " + ex.getMessage());
        }
        finally {
            database.close();
        }
    }
}
