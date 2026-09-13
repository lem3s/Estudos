package com.controlefinanceiro.model;

import com.j256.ormlite.field.DatabaseField;
import com.j256.ormlite.table.DatabaseTable;
import java.math.BigDecimal;

@DatabaseTable(tableName = "transacao_categorias")
public class TransacaoCategoria {

    @DatabaseField(generatedId = true)
    private Long id;

    @DatabaseField(canBeNull = false)
    private BigDecimal valorRateado;

    @DatabaseField(foreign = true, foreignAutoRefresh = true, columnName = "transacao_id", canBeNull = false)
    private Transacao transacao;

    @DatabaseField(foreign = true, foreignAutoRefresh = true, columnName = "categoria_id", canBeNull = false)
    private Categoria categoria;

    public TransacaoCategoria() {}

    public TransacaoCategoria(BigDecimal valorRateado, Transacao transacao, Categoria categoria) {
        this.valorRateado = valorRateado;
        this.transacao = transacao;
        this.categoria = categoria;
    }

    public Long getId() { return id; }
    public void setId(Long id) { this.id = id; }

    public BigDecimal getValorRateado() { return valorRateado; }
    public void setValorRateado(BigDecimal valorRateado) { this.valorRateado = valorRateado; }

    public Transacao getTransacao() { return transacao; }
    public void setTransacao(Transacao transacao) { this.transacao = transacao; }

    public Categoria getCategoria() { return categoria; }
    public void setCategoria(Categoria categoria) { this.categoria = categoria; }
}
