#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tratadores.h"
#include "dados.h"
#include "wchar.h"




void exibirAluno(Aluno *aluno) {
    printf("CPF: %s\n", aluno->cpf);
    printf("Nome: %s\n", aluno->nome);
}

void exibirProfessor(Professor *professor) {
    printf("CPF: %s\n", professor->cpf);
    printf("Nome: %s\n", professor->nome);
}

void exibirTurma(Turma *turma) {
    printf("Código: %s\n", turma->codigo);
    printf("Professor responsável: %s\n", turma->professor->nome);
}

void salvarAlunos(Aluno **alunos, int qtd_atual_aluno) {
    FILE *arquivo = fopen("alunos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < qtd_atual_aluno; i++) {
        Aluno *aluno = alunos[i];
        fprintf(arquivo, "%s\n", aluno->cpf);
        fprintf(arquivo, "%s\n", aluno->nome);
    }

    fclose(arquivo);
}

void salvarProfessores(Professor **professores, int qtd_atual_professor) {
    FILE *arquivo = fopen("professores.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < qtd_atual_professor; i++) {
        Professor *professor = professores[i];
        fprintf(arquivo, "%s\n", professor->cpf);
        fprintf(arquivo, "%s\n", professor->nome);
    }

    fclose(arquivo);
}

void salvarTurmas(Turma **turmas, int qtd_atual_turma) {
    FILE *arquivo = fopen("turmas.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < qtd_atual_turma; i++) {
        Turma *turma = turmas[i];
        fprintf(arquivo, "%s\n", turma->codigo);
        fprintf(arquivo, "%s\n", turma->professor->cpf);
    }

    fclose(arquivo);
}

void encerrarPrograma(Aluno **alunos, int qtd_atual_aluno, Professor **professores, int qtd_atual_professor, Turma **turmas, int qtd_atual_turma) {
    // destruir alunos e liberar memória
    for (int i = 0; i < qtd_atual_aluno; i++) {
        free(alunos[i]);
    }
    free(alunos);

    // destruir professores e liberar memória
    for (int i = 0; i < qtd_atual_professor; i++) {
        free(professores[i]);
    }
    free(professores);

    // destruir turmas e liberar memória
    for (int i = 0; i < qtd_atual_turma; i++) {
        free(turmas[i]);
    }
    free(turmas);
}

void lerAlunos(Aluno ***alunos, int *qtd_atual_aluno, int *qtd_max_aluno) {
    FILE *arquivo = fopen("alunos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de alunos.\n");
        return;
    }

    char matricula[10];
    char cpf[12];
    char nome[100];
    Endereco *end;

    while (fscanf(arquivo, "%s\n", cpf) != EOF) {
        if (fscanf(arquivo, "%[^\n]\n", nome) != 1) {
            printf("Erro ao ler o nome do aluno.\n");
            break;
        }

        if (*qtd_atual_aluno == *qtd_max_aluno) {
            // Aumenta a capacidade do array de alunos para impedir que quebre
            *qtd_max_aluno *= 2;
            *alunos = (Aluno**) realloc(*alunos, *qtd_max_aluno * sizeof(Aluno*));
            if (*alunos == NULL) {
                printf("Erro ao alocar memória.\n");
                break;
            }
        }

        (*alunos)[*qtd_atual_aluno] = criarAluno(matricula, cpf, nome, end);
        if ((*alunos)[*qtd_atual_aluno] == NULL) {
            printf("Erro ao criar aluno.\n");
            break;
        }

        (*qtd_atual_aluno)++;
    }

    fclose(arquivo);
}

void lerProfessores(Professor ***professores, int *qtd_atual_professor, int *qtd_max_professor) {
    FILE *arquivo = fopen("professores.txt", "r");
    if (arquivo == NULL) {
        return;
    }
    char matricula[10];
    char cpf[12];
    char nome[100];
    Endereco *end;

    while (fscanf(arquivo, "%s\n", cpf) != EOF) {
        fscanf(arquivo, "%[^\n]\n", nome);

        if (*qtd_atual_professor == *qtd_max_professor) {
            // Aumenta a capacidade do array de professores
            *qtd_max_professor *= 2;
            *professores = (Professor**) realloc(*professores, *qtd_max_professor * sizeof(Professor*));
        }

        (*professores)[*qtd_atual_professor] = criarProfessor(matricula, cpf, nome, end);
        (*qtd_atual_professor)++;
    }

    fclose(arquivo);
}

void lerTurmas(Turma ***turmas, int *qtd_atual_turma, int *qtd_max_turma, Professor **professores, int qtd_atual_professor) {
    FILE *arquivo = fopen("turmas.txt", "r");
    if (arquivo == NULL) {
        return;
    }

    char codigo[10];
    char cpf_professor[12];
    char nota[3];

    while (fscanf(arquivo, "%s\n", codigo) != EOF) {
        fscanf(arquivo, "%s\n", cpf_professor);

        // Busca o professor pelo CPF
        Professor *professor = NULL;
        for (int i = 0; i < qtd_atual_professor; i++) {
            if (strcmp(professores[i]->cpf, cpf_professor) == 0) {
                professor = professores[i];
                break;
            }
        }

        if (professor != NULL) {
            if (*qtd_atual_turma == *qtd_max_turma) {
                // Aumenta a capacidade do array de turmas
                *qtd_max_turma *= 2;
                *turmas = (Turma**) realloc(*turmas, *qtd_max_turma * sizeof(Turma*));
            }

            (*turmas)[*qtd_atual_turma] = criarTurma(codigo, professor, nota);
            (*qtd_atual_turma)++;
        } else {
            printf("Erro: Professor não encontrado.\n");
        }
    }

    fclose(arquivo);
}


