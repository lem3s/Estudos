/*
Faculdade:
   Gerenciamento acadêmico de notas e frequência
   Gerenciamento de disciplinas e sala
*/

%   Gerenciamento acadêmico de notas e frequência
% 6 alunos para teste
aluno(juan).
aluno(josé).
aluno(carlos).
aluno(ana).
aluno(júlia).
aluno(maria).
% P.s. isso é tão desnecessário
masculino(juan).
masculino(josé).
masculino(carlos).
feminino(ana).
feminino(júlia).
feminino(maria).

nota_corte(X,Y) :-
    read(Y),
    aluno(X), Y>=0.

presença(X,Y) :-
    read(Y),
    aluno(X), Y>=0.

/*
nota_corte(juan,Y).
presença(josé,Y).
*/

%   Gerenciamento de disciplinas e sala
% variavel anonima verifica se (algum) existe (?????)
% se eu nao definir uma variavel já nao vai existir de qualquer jeito
% definindo disciplinas
disciplina(fmc).
disciplina(lm).

% definindo salas
sala(cab_202).
sala(cab_205).

% correlacionando salas e disciplinas
materia(X,Y) :- disciplina(X) , sala(Y).

/* casos para teste:
materia(X,Y).        == Permutação
materia(fmc,Y).      == cab_202 & cab_205
materia(X,cab_202).  == fmc & lm
materia(X,cab).      == false 
*/