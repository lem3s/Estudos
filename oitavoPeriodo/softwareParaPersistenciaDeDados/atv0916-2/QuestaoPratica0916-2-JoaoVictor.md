# Questão prática: Sistema de Pedidos e Controle de Estoque
Aluno: João Victor L. Faria - 202302614

1 - Entidades e mapeamento ORM

@Entity
public class Cliente {
	mappedTo("clientes");

	@Id
	@GeneratedValue
	private Long id;

	private string email;

	@OneToMany
	private List<Pedido> pedidos;
}

@Entity
public class Filamento {
	mappedTo("filamentos");

	@Id
	@GeneratedValue
	private Long id;

	private String tipo;

	private String cor;

	private int estoqueG;
}

@Entity
public class Pedido {
	mappedTo("pedidos");

	@Id
	@GeneratedValue
	private Long id;

	@ForeignKey(refers="clientes.id");
	private long idCliente;

	@ManyToOne
	private Cliente cliente;

	private StatusPedido status;

	private LocalDateTime criadoEm;

	private LocalDateTime confirmadoEm;

	@OneToMany
	private List<ItemPedido> itens;
}

@Entity
public class ItemPedido {
	mappedTo("itens_pedido");

	@Id
	@GeneratedValue
	private Long id;

	@ForeignKey(refers="pedidos.id");
	private long idPedido;

	@ManyToOne
	private Pedido pedido;

	@ForeignKey(refers="filamentos.id");
	private long idFilamento;

	@ManyToOne
	private Filamento filamento;

	private int quantidadeG;
}


public enum StatusPedido {
	PENDENTE,
	CONFIRMADO
}

2 - Repositório

public class Repository<T, ID> : T, ID as class {
	Dao<T, ID> dao;

	public T Create(T entity) {
		return dao.Create(entity);
	}

	public T GetById(ID id) {
		return dao.GetById(id);
	}

	public List<T> GetAll() {
		return dao.GetAll();
	}

	public T Update(T entity) {
		return dao.Update(entity);
	}

	public bool Delete(T entity) {
		return dao.Delete(entity);
	}
}

public class PedidoRepository extends Repository<T, ID> 
	: T as Pedido, ID as long {

}

public class FilamentoRepository extends Repository<T, ID> 
	: T as Filamento, ID as long {

}

3 - Controller e Model

public class PedidoService(PedidoRepository pedidoRepository) {
	private PedidoRepository _pedidoRepository;

	public Pedido CriarPedido(Pedido pedido) {
		_pedidoRepository.Create(pedido);
	}

	public List<Pedido> BuscarListaPedidos() {
		_pedidoRepositoru.GetAll();
	}

	public Pedido BuscarPedidoPorId(long id) {
		return _pedidoRepository.GetById(id);
	}

	public Pedido ConfirmarPedido(long idPedido) {
		var pedido = _pedidoRepository.GetById(id);

		pedido.setStatus(StatusPedido.CONFIRMADO);

		return _pedidoRepository.Update(pedido);
	}
}

public class FilamentoService(FilamentoRepository filamentoRepository) {
	private FilamentoRepository _filamentoRepository;

	public Pedido BuscarFilamentoPorId(long id) {
		return _filamentoRepository.GetById(id);
	}
}

public class PedidoController(PedidoService pedidoService, FilamentoService filamentoService) {
	private PedidoService _pedidoService;
	private FilamentoService _filamentoService;

	public View Index(){
		return View(_pedidoService.GetAll());
	}

	public View CriarPedido(Pedido pedido){
		foreach (var item in pedido.itens) {
			if (item.quantidadeG < 1) {
				return View("Peso invalido do item") 
			}

			var filamento = _filamentoService.GetById(item.idFilamento);

			if (item.quantidadeG > filamento.estoqueG) {
				return View("Estoque insuficiente para o filamento, por favor, selecione outro filamento");
			}
		}

		var pedidoCriado = _pedidoService.Create(pedido);

		return View(pedidoCriado);
	}

	public Action ConfirmarPedido(long pedidoId){
		_pedidoService.ConfirmarPedido(pedidoId)
	}
}

