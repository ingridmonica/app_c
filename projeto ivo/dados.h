#ifndef _DADOS_H_
#define _DADOS_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//também baseado no código exemplo, definindo as estruturas de dados

typedef struct
{
    char logradouro[50];
    char bairro[50];
    char cidade[50];
    char estado[10];
    char numero[10];
} Endereco;

typedef struct {
    char matriculaAluno[10];
    char cpf[12];
    char nome[100];
    Endereco *endereco;
} Aluno;

typedef struct { 
    char matricula[10];
    char cpf[12];
    char nome[100];
    Endereco *endereco;
} Professor;

typedef struct {
    char codigo[10];
    Professor *professor;
    Aluno *aluno;
    char nota[3];
} Turma;


#endif

