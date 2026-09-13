package com.controlefinanceiro.dao;

import com.controlefinanceiro.model.TransacaoCategoria;
import com.j256.ormlite.dao.BaseDaoImpl;
import com.j256.ormlite.support.ConnectionSource;
import java.sql.SQLException;

public class TransacaoCategoriaDao extends BaseDaoImpl<TransacaoCategoria, Long> {

    public TransacaoCategoriaDao(ConnectionSource connectionSource) throws SQLException {
        super(connectionSource, TransacaoCategoria.class);
    }
}
