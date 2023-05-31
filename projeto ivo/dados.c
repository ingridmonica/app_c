#include "dados.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "wchar.h"

//nessa parte a gente se baseou muito no código exemplo

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
        perror("Não há memória disponível. Finalizando...\n\n");
    }
    return endereco;}

Aluno *criarAluno(char *matriculaAluno, char *cpf, char *nome, Endereco *end)
{
    Aluno *aluno = (Aluno*) malloc(sizeof(Aluno));
    strcpy(aluno->matriculaAluno, matriculaAluno);
    strcpy(aluno->cpf, cpf);
    strcpy(aluno->nome, nome);
    aluno->endereco = end;
    return aluno;
}

Professor *criarProfessor(char *matricula, char *cpf, char *nome,Endereco *end) {
    Professor *professor = (Professor*) malloc(sizeof(Professor));
    strcpy(professor->matricula, matricula);
    strcpy(professor->cpf, cpf);
    strcpy(professor->nome, nome);
    professor->endereco = end;
    return professor;
}

Turma *criarTurma(char *codigo, Professor *professor, Aluno *aluno, char *nota) {
    Turma *turma = (Turma*) malloc(sizeof(Turma));
    strcpy(turma->codigo, codigo);
    turma->professor = professor;
    turma->aluno = aluno;
    strcpy(turma->nota, nota);
    return turma;
}

