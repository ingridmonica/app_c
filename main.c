#include "menus.h"
#include "tratadores.h"
#include "dados.h"
#include <stdio.h>
#include "constantes.h"

int main(int argc, char const *argv[])
{
    // Declaração de variáveis
    int op_menu_principal = 0;
    Aluno *alunos[MAX_ALUNO] = {NULL};
    Professor *professores[MAX_PROFESSOR] = {NULL};
    Turmas *turmas[MAX_TURMA] = {NULL};

    int qtd_atual_aluno = 0;
    int qtd_atual_prof = 0;
    int qtd_atual_turma = 0;
    int qtd_alunos_matriculados = 0;
    int numAlunos = 0;
    int numProfessores = 0;
    int numTurmas = 0;

    // Carrega os dados
    carregarDados(alunos, &qtd_atual_aluno, professores, &qtd_atual_prof, turmas, qtd_atual_turma);

    // Loop principal do programa
    do
    {
        // Exibe o menu principal e recebe a opção escolhida
        op_menu_principal = menu_principal();

        // Executa as ações com base na opção escolhida
        switch (op_menu_principal)
        {
        case 1:
            // Chama o tratador do menu aluno
            tratador_menu_aluno(alunos, &qtd_atual_aluno);
            break;
        case 2:
            // Chama o tratador do menu professor
            tratador_menu_prof(professores, &qtd_atual_prof);
            break;
        case 3:
            // Chama o tratador do menu turmas
            tratar_menu_turmas(turmas, &qtd_alunos_matriculados);
            break;
        case 4:
            // Chama o tratador do menu estatísticas
            tratador_menu_estatisticas(alunos, numAlunos, professores, numProfessores, turmas, numTurmas);
            break;
        case 5:
            // Finaliza o programa
            printf("Finalizando app...\n\n");
        }
    } while (op_menu_principal > 0 && op_menu_principal < 5);

    // Salva os dados
    salvarDados(alunos, qtd_atual_aluno, professores, qtd_atual_prof, turmas, qtd_atual_turma);

    return 0;
}
