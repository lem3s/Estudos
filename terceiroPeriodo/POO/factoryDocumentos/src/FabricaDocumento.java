public class FabricaDocumento extends Fabrica{
    @Override
    public Documento criaDocumento(TipoDocumento tipoDocumento) {
        if (tipoDocumento == TipoDocumento.carta){
            return new Carta();
        }
        if (tipoDocumento == TipoDocumento.notificacao){
            return new Notificacao();
        }
        if (tipoDocumento == TipoDocumento.telegrama){
            return new Telegrama();
        }
        return null;
    }
}
