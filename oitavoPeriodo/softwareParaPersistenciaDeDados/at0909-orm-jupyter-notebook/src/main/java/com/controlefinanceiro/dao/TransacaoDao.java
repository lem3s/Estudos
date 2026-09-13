package com.controlefinanceiro.dao;

import com.controlefinanceiro.model.Transacao;
import com.j256.ormlite.dao.BaseDaoImpl;
import com.j256.ormlite.support.ConnectionSource;
import java.sql.SQLException;

public class TransacaoDao extends BaseDaoImpl<Transacao, Long> {

    public TransacaoDao(ConnectionSource connectionSource) throws SQLException {
        super(connectionSource, Transacao.class);
    }
}
