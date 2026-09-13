package com.controlefinanceiro.model;

import com.j256.ormlite.field.DatabaseField;
import com.j256.ormlite.table.DatabaseTable;
import java.math.BigDecimal;

@DatabaseTable(tableName = "orcamentos")
public class Orcamento {

    @DatabaseField(generatedId = true)
    private Long id;

    @DatabaseField(canBeNull = false)
    private BigDecimal valorLimite;

    @DatabaseField(canBeNull = false)
    private String mesReferencia;

    @DatabaseField(foreign = true, foreignAutoRefresh = true, columnName = "usuario_id", canBeNull = false)
    private Usuario usuario;

    @DatabaseField(foreign = true, foreignAutoRefresh = true, columnName = "categoria_id", unique = true, canBeNull = false)
    private Categoria categoria;

    public Orcamento() {}

    public Orcamento(BigDecimal valorLimite, String mesReferencia, Usuario usuario, Categoria categoria) {
        this.valorLimite = valorLimite;
        this.mesReferencia = mesReferencia;
        this.usuario = usuario;
        this.categoria = categoria;
    }

    public Long getId() { return id; }
    public void setId(Long id) { this.id = id; }

    public BigDecimal getValorLimite() { return valorLimite; }
    public void setValorLimite(BigDecimal valorLimite) { this.valorLimite = valorLimite; }

    public String getMesReferencia() { return mesReferencia; }
    public void setMesReferencia(String mesReferencia) { this.mesReferencia = mesReferencia; }

    public Usuario getUsuario() { return usuario; }
    public void setUsuario(Usuario usuario) { this.usuario = usuario; }

    public Categoria getCategoria() { return categoria; }
    public void setCategoria(Categoria categoria) { this.categoria = categoria; }
}
