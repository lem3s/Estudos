package controller;

import java.net.URL;
import java.util.ResourceBundle;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.control.MenuItem;
import javafx.scene.control.Tab;

import model.Repositorios;
import view.AppView;

/**
 * Controlador da janela principal. Não conhece nenhuma entidade: apenas
 * carrega um FXML por aba, cada um com o seu próprio controlador CRUD.
 */
public class AppController implements Initializable {

    @FXML private Tab tabDiretor;
    @FXML private Tab tabFilme;

    @FXML private MenuItem sairMenuItem;

    private final AppView appView;

    public AppController() {
        this.appView = new AppView();
    }

    public static void main(String[] args) throws Exception {
        AppController appController = new AppController();
        appController.appView.run(args);
    }

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        try {
            FXMLLoader diretorLoader = new FXMLLoader(getClass().getResource("/view/diretor.fxml"));
            Parent diretorContent = diretorLoader.load();
            tabDiretor.setContent(diretorContent);

            FXMLLoader filmeLoader = new FXMLLoader(getClass().getResource("/view/filme.fxml"));
            Parent filmeContent = filmeLoader.load();
            tabFilme.setContent(filmeContent);

            // Um diretor cadastrado na primeira aba precisa aparecer no ComboBox
            // da segunda sem reiniciar a aplicação
            FilmeController filmeController = filmeLoader.getController();
            tabFilme.setOnSelectionChanged(event -> {
                if (tabFilme.isSelected()) {
                    filmeController.recarregarDiretores();
                }
            });
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @FXML
    public void onSairMenuItemAction() {
        Repositorios.DATABASE.close();
        System.exit(0);
    }
}
