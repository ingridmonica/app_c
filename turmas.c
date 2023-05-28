#include "tratadores.h"
#include "menus.h"
#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"
#include <string.h>
#include "turmas.h"



Turmas * construir_turma()
{
    Turmas turma;
    printf("Digite o codigo da turma: ");
    fgets(turma.codigo, 9, stdin);
    printf("Digite o nome da disciplina: ");
    fgets(turma.disciplina, 50, stdin);
    printf("Digite a matricula do professor responsavel: ");
    fgets(turma.matricula_professor_responsavel, 9, stdin);
    printf("Digite o numero de alunos: ");
    fgets(turma.numero_alunos, 9, stdin);
    printf("Digite a matricula dos alunos: ");
    fgets(turma.matricula_alunos, 9, stdin);
    printf("Digite a media da turma: ");
    fgets(turma.media_turma, 9, stdin);
}

void imprimir_turma(Turmas *turma)
{
    printf("Codigo da turma: %s\n", turma->codigo);
    printf("Nome da disciplina: %s\n", turma->disciplina);
    printf("Matricula do professor responsavel: %s\n", turma->matricula_professor_responsavel);
    printf("Numero de alunos: %s\n", turma->numero_alunos);
    printf("Matricula dos alunos: %s\n", turma->matricula_alunos);
    printf("Media da turma: %s\n", turma->media_turma);
}

void destruir_turma(Turmas *turma)
{
    free(turma);
}