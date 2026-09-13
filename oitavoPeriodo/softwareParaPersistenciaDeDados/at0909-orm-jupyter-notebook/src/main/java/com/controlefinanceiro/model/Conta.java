package com.controlefinanceiro.model;

import com.j256.ormlite.field.DatabaseField;
import com.j256.ormlite.table.DatabaseTable;
import java.math.BigDecimal;

@DatabaseTable(tableName = "contas")
public class Conta {

    @DatabaseField(generatedId = true)
    private Long id;

    @DatabaseField(canBeNull = false)
    private String nome;

    @DatabaseField(canBeNull = false)
    private String tipo;

    @DatabaseField(canBeNull = false)
    private BigDecimal saldo;

    @DatabaseField(foreign = true, foreignAutoRefresh = true, columnName = "usuario_id", canBeNull = false)
    private Usuario usuario;

    public Conta() {}

    public Conta(String nome, String tipo, BigDecimal saldo, Usuario usuario) {
        this.nome = nome;
        this.tipo = tipo;
        this.saldo = saldo;
        this.usuario = usuario;
    }

    public Long getId() { return id; }
    public void setId(Long id) { this.id = id; }

    public String getNome() { return nome; }
    public void setNome(String nome) { this.nome = nome; }

    public String getTipo() { return tipo; }
    public void setTipo(String tipo) { this.tipo = tipo; }

    public BigDecimal getSaldo() { return saldo; }
    public void setSaldo(BigDecimal saldo) { this.saldo = saldo; }

    public Usuario getUsuario() { return usuario; }
    public void setUsuario(Usuario usuario) { this.usuario = usuario; }
}
