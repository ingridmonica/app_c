#include "tratadores.h"
#include "menus.h"
#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"
#include <string.h>
#include "dados.h"



Turmas *construir_turma()
{
    Turmas turma;
    printf("Digite o codigo da turma: ");
    fgets(turma.codigo, 9, stdin);
    printf("Digite o nome da disciplina: ");
    fgets(turma.disciplina, 50, stdin);
    printf("Digite a matricula do professor responsavel: ");
    fgets(turma.matricula_professor_responsavel, 9, stdin);
    printf("Digite o numero de alunos: ");
    fgets(turma.qtd_alunos_matriculados, 9, stdin);
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
    printf("Numero de alunos: %s\n", turma->qtd_alunos_matriculados);
    printf("Matricula dos alunos: %s\n", turma->matricula_alunos);
    printf("Media da turma: %s\n", turma->media_turma);
}

void destruir_turma(Turmas *turma)
{
    free(turma);
}

void tratar_menu_turmas(Turmas **turma, int *qtd_alunos_matriculados) {
    int opcao = menu_crud_turma();
    switch (opcao) {
        case 1: {
            if (*qtd_alunos_matriculados >= MAX_ALUNOS_TURMA) {
                printf("Número máximo de alunos atingido\n");
            } else {
                // Passo 1: buscar posição disponível
                int i = 0;
                for (; i < *qtd_alunos_matriculados; i++) {
                    if (turma[i] == NULL) {
                        // significa que esta posição está livre para uso
                        break;
                    }
                }
                Turmas *nova_turma = construir_turma();
                turma[i] = nova_turma;
                (*qtd_alunos_matriculados)++;
            }
            break;
        }
        case 2: {
            char codigo[9];
            printf("Digite o código da turma: ");
            fgets(codigo, 9, stdin);

            // Procurar a turma pelo código fornecido
            for (int i = 0; i < *qtd_alunos_matriculados; i++) {
                if (turma[i] != NULL && strcmp(turma[i]->codigo, codigo) == 0) {
                    imprimir_turma(turma[i]);
                    return;
                }
            }

            printf("Turma não encontrada.\n");
            break;
        }
        case 3: {
            char codigo[9];
            printf("Digite o código da turma que deseja atualizar: ");
            fgets(codigo, 9, stdin);

            // Procurar a turma pelo código fornecido
            for (int i = 0; i < *qtd_alunos_matriculados; i++) {
                if (turma[i] != NULL && strcmp(turma[i]->codigo, codigo) == 0) {
                    // Atualizar os dados da turma
                    Turmas *turma_atualizada = turma[i];
                    printf("Digite o novo código da turma (ou deixe em branco para não atualizar): ");
                    fgets(turma_atualizada->codigo, 9, stdin);
                    printf("Digite a nova disciplina (ou deixe em branco para não atualizar): ");
                    fgets(turma_atualizada->disciplina, 50, stdin);
                    printf("Deseja atualizar o professor responsável? (s/n): ");
                    char opcao[2];
                    fgets(opcao, 2, stdin);
                    if (opcao[0] == 's' || opcao[0] == 'S') {
                        printf("Digite a nova matrícula do professor responsável: ");
                        fgets(turma_atualizada->matricula_professor_responsavel, 9, stdin);
                    }
                    printf("Digite o novo número de alunos (ou deixe em branco para não atualizar): ");
                    fgets(turma_atualizada->qtd_alunos_matriculados, 9, stdin);
                    printf("Digite as novas matrículas dos alunos (ou deixe em branco para não atualizar): ");
                    fgets(turma_atualizada->matricula_alunos, 9, stdin);
                    printf("Digite a nova média da turma (ou deixe em branco para não atualizar): ");
                    fgets(turma_atualizada->media_turma, 9, stdin);

                    printf("Turma atualizada com sucesso.\n");
                    return;
                }
            }
            printf("Turma não encontrada.\n");
            break;
        }
    }
}