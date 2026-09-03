package model;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import com.j256.ormlite.dao.Dao;
import com.j256.ormlite.dao.DaoManager;
import com.j256.ormlite.table.TableUtils;

/**
 * Repositório genérico: implementa as operações CRUD uma única vez, para
 * qualquer entidade de domínio mapeada pelo ORMLite.
 *
 * @param <T>  tipo da entidade de domínio (ex.: model.Filme)
 * @param <ID> tipo da chave primária da entidade (ex.: Integer)
 */
public class Repositorio<T, ID> {

    private Database database;
    private Dao<T, ID> dao;
    private final Class<T> entityClass;
    private List<T> loadedEntities;
    private T loadedEntity;

    public Repositorio(Database database, Class<T> entityClass) {
        this.entityClass = entityClass;
        this.loadedEntities = new ArrayList<T>();
        setDatabase(database);
    }

    public void setDatabase(Database database) {
        this.database = database;
        try {
            this.dao = DaoManager.createDao(database.getConnection(), entityClass);
            TableUtils.createTableIfNotExists(database.getConnection(), entityClass);
        } catch (SQLException e) {
            System.out.println(e);
        }
    }

    public T create(T entity) throws SQLException {
        int nrows = dao.create(entity);
        if (nrows == 0) {
            throw new SQLException("Erro: objeto não foi salvo");
        }
        this.loadedEntity = entity;
        this.loadedEntities.add(entity);
        return entity;
    }

    public T update(T entity) throws SQLException {
        int nrows = dao.update(entity);
        if (nrows == 0) {
            throw new SQLException("Erro: objeto não foi atualizado");
        }
        this.loadedEntity = entity;
        return entity;
    }

    public void delete(T entity) throws SQLException {
        int nrows = dao.delete(entity);
        if (nrows == 0) {
            throw new SQLException("Erro: objeto não foi removido");
        }
        this.loadedEntities.remove(entity);
    }

    public T loadFromId(ID id) throws SQLException {
        this.loadedEntity = dao.queryForId(id);
        if (this.loadedEntity != null) {
            this.loadedEntities.add(this.loadedEntity);
        }
        return this.loadedEntity;
    }

    public List<T> loadAll() throws SQLException {
        this.loadedEntities = dao.queryForAll();
        if (!this.loadedEntities.isEmpty()) {
            this.loadedEntity = this.loadedEntities.get(0);
        }
        return this.loadedEntities;
    }

    public Database getDatabase() {
        return database;
    }

    public T getLoadedEntity() {
        return loadedEntity;
    }

    public List<T> getLoadedEntities() {
        return loadedEntities;
    }
}
