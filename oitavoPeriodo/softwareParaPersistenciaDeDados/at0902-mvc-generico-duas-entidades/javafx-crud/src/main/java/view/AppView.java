package view;

import java.net.URL;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

public class AppView extends Application {

    private final FXMLLoader loader;
    private URL url;
    private Stage primaryStage;

    public AppView() {
        this.loader = new FXMLLoader();
        this.url = AppView.class.getResource("/view/app.fxml");
        if (this.url == null) {
            System.err.println("Erro: /view/app.fxml não encontrado no classpath");
        }
        this.loader.setLocation(this.url);
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
        try {
            Pane pane = loader.<Pane>load();
            Scene scene = new Scene(pane);
            this.primaryStage = primaryStage;
            this.primaryStage.setTitle("CRUD de Cinema - JavaFX + ORMLite + SQLite");
            this.primaryStage.setScene(scene);
            this.primaryStage.show();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public void stop() {
        System.exit(0);
    }

    public void run(String[] args) {
        Application.launch(args);
    }

    public Stage getPrimaryStage() {
        return primaryStage;
    }
}
