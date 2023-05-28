#ifndef _TRATADORES_H_
#define _TRATADORES_H_

#include "dados.h"

int menu_principal_turmas();
int menu_crud_turma();
{
    int opcao = 0;
    do
    {
        printf("\n\n");
        printf("1 - Inserir turma\n");
        printf("2 - Buscar turma\n");
        printf("3 - Atualizar turma\n");
        printf("4 - Excluir turma\n");
        printf("5 - Listar turmas\n");
        printf("0 - Voltar\n");
        printf("\n\n");
        printf("Opcao > ");
        scanf("%d", &opcao);
        getchar();
    } while (opcao < 0 || opcao > 5);
    return opcao;
}

