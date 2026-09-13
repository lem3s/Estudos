package com.controlefinanceiro.dao;

import com.controlefinanceiro.model.Usuario;
import com.j256.ormlite.dao.BaseDaoImpl;
import com.j256.ormlite.support.ConnectionSource;
import java.sql.SQLException;

public class UsuarioDao extends BaseDaoImpl<Usuario, Long> {

    public UsuarioDao(ConnectionSource connectionSource) throws SQLException {
        super(connectionSource, Usuario.class);
    }
}
