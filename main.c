#include "menus.h"
#include "tratadores.h"
#include "dados.h"
#include <stdio.h>
#include "constantes.h"


int main(int argc, char const *argv[])
{
    int op_menu_principal = 0;
    Aluno *alunos[MAX_ALUNO] = {NULL};
    Professor *professores[MAX_PROFESSOR] = {NULL};
    Turma *turmas[MAX_TURMA] = {NULL};

    int qtd_atual_aluno = 0;
    int qtd_atual_prof = 0;
    int qtd_atual_turma = 0;

    do
    {
        op_menu_principal = menu_principal();
        switch (op_menu_principal)
        {
        case 1:
            tratador_menu_aluno(alunos, &qtd_atual_aluno);
            break;
        case 2:
            printf("Calma que o menu do prof ja vem");
            tratador_menu_prof(professores, &qtd_atual_prof);
            break;
        case 3:
            tratador_menu_turma(turmas, &qtd_atual_turma, professores, &qtd_atual_prof);
            break;
        case 4:
            printf("Calma q as estatisticas ja vem\n");
            //tratador_menu_estatisticas();
            break;
        case 5:
            printf("Finalizando app...\n\n");
        }
    } while (op_menu_principal>0 && op_menu_principal<6 );
    return 0;
}
