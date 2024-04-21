import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        ArrayList <ProgramaTV> programas = new ArrayList <ProgramaTV>();

        ProgramaTV p = new ProgramaTV("O outro lado do paraíso","Novela");
        p.diretor = new Pessoa("Diretor 1", "Brasileiro");
        p.setArtistas(new Pessoa("Artista 1", "Brasileiro"));
        p.setArtistas(new Pessoa("Artista 2", "Brasileiro"));
        programas.add(p);

        p = new ProgramaTV("Orgulho e Paixão","Novela");
        p.diretor = new Pessoa("Diretor 2", "Brasileiro");
        p.setArtistas(new Pessoa("Artista 3", "Brasileiro"));
        p.setArtistas(new Pessoa("Artista 4", "Brasileiro"));
        programas.add(p);

        p = new ProgramaTV("Marley e eu","Filme");
        p.diretor = new Pessoa("Diretor 3", "Brasileiro");
        p.setArtistas(new Pessoa("Artista 5", "Brasileiro"));
        p.setArtistas(new Pessoa("Artista 6", "Brasileiro"));
        programas.add(p);

        p = new ProgramaTV("Show Ivete Sangalo","Show");
        p.diretor = new Pessoa("Diretor 4", "Brasileiro");
        p.setArtistas(new Pessoa("Artista 7", "Brasileiro"));
        p.setArtistas(new Pessoa("Artista 8", "Brasileiro"));
        programas.add(p);

        p = new Serie("O mundo mágico de Gumbledore", "Serie", 8, 45);
        p.diretor = new Pessoa("Diretor 5", "Gringo");
        p.setArtistas(new Pessoa("Artista 9", "Marroquino"));
        p.setArtistas(new Pessoa("Artista 10", "Marroquino"));
        programas.add(p);

        p = new Serie("O Senhor dos Pasteis", "Serie", 2, 18);
        p.diretor = new Pessoa("Diretor 6", "Tailandês");
        p.setArtistas(new Pessoa("Artista 11", "Faina"));
        p.setArtistas(new Pessoa("Artista 12", "Tuvalu"));
        p.setArtistas(new Pessoa("Artista 13", "Chique Chique - Bahia"));
        programas.add(p);

        for (int i=0;i<programas.size();i++) {
            System.out.println(programas.get(i));
        }

    }

}
