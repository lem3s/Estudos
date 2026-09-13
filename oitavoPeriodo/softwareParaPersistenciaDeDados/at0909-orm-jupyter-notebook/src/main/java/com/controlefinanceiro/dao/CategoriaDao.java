package com.controlefinanceiro.dao;

import com.controlefinanceiro.model.Categoria;
import com.j256.ormlite.dao.BaseDaoImpl;
import com.j256.ormlite.support.ConnectionSource;
import java.sql.SQLException;

public class CategoriaDao extends BaseDaoImpl<Categoria, Long> {

    public CategoriaDao(ConnectionSource connectionSource) throws SQLException {
        super(connectionSource, Categoria.class);
    }
}
