#include "tratadores.h"
#include "menus.h"
#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"
#include <string.h>
#include "turmas.h"


Turma * construir_turma()
{
    Turma turma;
    printf("Código\t> ");
    fgets(turma.codigo, 9, stdin);
    printf("Nome da disciplina\t> ");
    fgets(turma.nome_disciplina, 49, stdin);
    printf("Professor\t> ");
    fgets(turma.matriculaProf, 49, stdin);
    printf("Lista de Alunos\t> ");
    fgets(turma.lista_alunos, 49, stdin);
    printf("Média da turma\t> ");
    fgets(turma.media_turma, 49, stdin);

    return criarTurma(turma.codigo, turma.nome_disciplina, turma.matriculaProf, turma.lista_alunos, turma.media_turma);
}


void imprimir_turma(Turma *turma)
{
    printf("Código: %s", turma->codigo);
    printf("Nome da disciplina: %s", turma->nome_disciplina);
    printf("Professor: %s", turma->matriculaProf);
    printf("Lista de Alunos: %s", turma->lista_alunos);
    printf("Média da turma: %s", turma->media_turma);
}

void destruir_turma(Turma *turma)
{
    free(turma);
}