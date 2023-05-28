#include "dados.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Aluno *criarAluno(char *matricula,
                  char *cpf,
                  char *nome,
                  Endereco *end)
{
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
    if (aluno)
    {
        strcpy(aluno->matricula, matricula); // Copia matricula para aluno->matricula
        strcpy(aluno->cpf, cpf);
        strcpy(aluno->nome, nome);
        aluno->endereco = end;
    }
    else
    {
        perror("Não há memória disponível. Encerrando\n\n");
    }
    return aluno;
}

Atualizar_aluno *atualizarAluno(char *matricula,
                                char *cpf,
                                char *nome,
                                Endereco *end);
{
    Aluno *atualizarAluno = (Atualizar_aluno *)malloc(sizeof(Atualizar_aluno));
    if (atualizarAluno)
    {
        strcpy(atualizarAluno->matricula, matricula);
        strcpy(atualizarAluno->cpf, cpf);
        strcpy(atualizarAluno->nome, nome);
        atualizarAluno->endereco = end;
    }
    else
    {
        perror("Erro na atualização. Encerrando\n\n");
    }
    return atualizarAluno;
}

Endereco *criarEndereco(char *logradouro,
                        char *bairro,
                        char *cidade,
                        char *estado,
                        char *numero)
{
    Endereco *endereco = (Endereco *)malloc(sizeof(Endereco));
    if (endereco)
    {
        strcpy(endereco->logradouro, logradouro);
        strcpy(endereco->bairro, bairro);
        strcpy(endereco->cidade, cidade);
        strcpy(endereco->estado, estado);
        strcpy(endereco->numero, numero);
    }
    else
    {
        perror("Não há memória disponível. Encerrando\n\n");
    }
    return endereco;
}

Professor *criarProfessor(char *matricula,
                          char *cpf,
                          char *nome,
                          Endereco *end)
{
    Professor *professor = (Professor *)malloc(sizeof(Professor));
    if (professor)
    {

        strcpy(professor->matricula, matricula);
        strcpy(professor->cpf, cpf);
        strcpy(professor->nome, nome);
        professor->endereco = end;
    }
    else
    {
        perror("Não há memória disponível. Encerrando\n\n");
    }
    return professor;
}

Turma *criarTurma(char *codigo,
                  char *nome_disciplina,
                  char *matriculaProf,
                  char *lista_alunos,
                  char media_turma)
{
    Turma *turma = (Turma *)malloc(sizeof(Turma));
    if (turma)
    {
        strcpy(turma->codigo, codigo);
        strcpy(turma->nome_disciplina, nome_disciplina);
        strcpy(turma->matriculaProf, matriculaProf);
        turma->lista_alunos = lista_alunos;
        turma->media_turma = media_turma;
    }
    else
    {
        perror("Não há memória disponível. Encerrando\n\n");
    }
    return turma;
}


void destruirAluno(Aluno *aluno)
{
    if (aluno)
    {
        Endereco *end = aluno->endereco;
        destruirEndereco(end);
        free(aluno);
    }
}

void destruirEndereco(Endereco *endereco)
{
    if (endereco)
        free(endereco);
}

void destruirProfessor(Professor *professor)
{
    if (professor)
        free(professor);
}

void destruirTurma(Turma *turma)
{
    if (turma)
        free(turma);
}
