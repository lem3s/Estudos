package model;

/**
 * Ponto único de instanciação dos repositórios da aplicação. Cada entidade
 * ganha uma instância do mesmo Repositorio genérico, sem código novo.
 *
 * DIRETOR é declarado antes de FILME para que a tabela referenciada pela
 * chave estrangeira já exista quando a tabela "filme" for criada.
 */
public class Repositorios {

    public static final Database DATABASE = new Database("cinema.db");

    public static final Repositorio<Diretor, Integer> DIRETOR =
            new Repositorio<>(DATABASE, Diretor.class);

    public static final Repositorio<Filme, Integer> FILME =
            new Repositorio<>(DATABASE, Filme.class);
}
