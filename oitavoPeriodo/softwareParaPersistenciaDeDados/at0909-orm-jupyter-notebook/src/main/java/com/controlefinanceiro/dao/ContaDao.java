package com.controlefinanceiro.dao;

import com.controlefinanceiro.model.Conta;
import com.j256.ormlite.dao.BaseDaoImpl;
import com.j256.ormlite.support.ConnectionSource;
import java.sql.SQLException;

public class ContaDao extends BaseDaoImpl<Conta, Long> {

    public ContaDao(ConnectionSource connectionSource) throws SQLException {
        super(connectionSource, Conta.class);
    }
}
