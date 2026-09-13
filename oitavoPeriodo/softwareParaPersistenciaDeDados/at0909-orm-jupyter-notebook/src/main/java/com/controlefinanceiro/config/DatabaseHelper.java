package com.controlefinanceiro.config;

import com.controlefinanceiro.dao.*;
import com.controlefinanceiro.model.*;
import com.j256.ormlite.jdbc.JdbcConnectionSource;
import com.j256.ormlite.support.ConnectionSource;
import com.j256.ormlite.table.TableUtils;
import java.sql.SQLException;

public class DatabaseHelper {

    private static final String DATABASE_URL = "jdbc:sqlite:financeiro.db";

    private ConnectionSource connectionSource;

    private UsuarioDao usuarioDao;
    private ContaDao contaDao;
    private CategoriaDao categoriaDao;
    private TransacaoDao transacaoDao;
    private OrcamentoDao orcamentoDao;
    private TransacaoCategoriaDao transacaoCategoriaDao;

    public DatabaseHelper() throws SQLException {
        connectionSource = new JdbcConnectionSource(DATABASE_URL);
        criarTabelas();
        inicializarDaos();
    }

    private void criarTabelas() throws SQLException {
        TableUtils.createTableIfNotExists(connectionSource, Usuario.class);
        TableUtils.createTableIfNotExists(connectionSource, Conta.class);
        TableUtils.createTableIfNotExists(connectionSource, Categoria.class);
        TableUtils.createTableIfNotExists(connectionSource, Transacao.class);
        TableUtils.createTableIfNotExists(connectionSource, Orcamento.class);
        TableUtils.createTableIfNotExists(connectionSource, TransacaoCategoria.class);
    }

    private void inicializarDaos() throws SQLException {
        usuarioDao = new UsuarioDao(connectionSource);
        contaDao = new ContaDao(connectionSource);
        categoriaDao = new CategoriaDao(connectionSource);
        transacaoDao = new TransacaoDao(connectionSource);
        orcamentoDao = new OrcamentoDao(connectionSource);
        transacaoCategoriaDao = new TransacaoCategoriaDao(connectionSource);
    }

    public void fechar() throws Exception {
        if (connectionSource != null) {
            connectionSource.close();
        }
    }

    public ConnectionSource getConnectionSource() { return connectionSource; }

    public UsuarioDao getUsuarioDao() { return usuarioDao; }
    public ContaDao getContaDao() { return contaDao; }
    public CategoriaDao getCategoriaDao() { return categoriaDao; }
    public TransacaoDao getTransacaoDao() { return transacaoDao; }
    public OrcamentoDao getOrcamentoDao() { return orcamentoDao; }
    public TransacaoCategoriaDao getTransacaoCategoriaDao() { return transacaoCategoriaDao; }
}
