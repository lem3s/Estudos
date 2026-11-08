package odm.rest.repository;

import org.springframework.data.mongodb.repository.MongoRepository;

import odm.rest.model.Transacao;

public interface TransacaoRepository extends MongoRepository<Transacao, String> {
}
