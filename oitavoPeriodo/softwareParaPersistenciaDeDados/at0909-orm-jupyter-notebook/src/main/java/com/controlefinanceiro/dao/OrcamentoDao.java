package com.controlefinanceiro.dao;

import com.controlefinanceiro.model.Orcamento;
import com.j256.ormlite.dao.BaseDaoImpl;
import com.j256.ormlite.support.ConnectionSource;
import java.sql.SQLException;

public class OrcamentoDao extends BaseDaoImpl<Orcamento, Long> {

    public OrcamentoDao(ConnectionSource connectionSource) throws SQLException {
        super(connectionSource, Orcamento.class);
    }
}
