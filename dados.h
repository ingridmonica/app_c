#ifndef _DADOS_H_
#define _DADOS_H_

typedef struct
{
    char logradouro[50];
    char bairro[50];
    char cidade[50];
    char estado[10];
    char numero[10];
} Endereco;

typedef struct
{
    char matricula[10];
    char cpf[12];
    char nome[50];
    Endereco *endereco;
} Aluno;

typedef struct
{
    char matricula[10];
    char cpf[12];
    char nome[50];
    Aluno *atualizarAluno;
} Atualizar_aluno;

Endereco *criarEndereco(char *logradouro,
                        char *bairro,
                        char *cidade,
                        char *estado,
                        char *numero);

Aluno *criarAluno(char *matricula,
                  char *cpf,
                  char *nome,
                  Endereco *end);

Atualizar_aluno *atualizarAluno(char *matricula,
                                char *cpf,
                                char *nome,
                                Endereco *end);


void destruirAluno(Aluno *aluno);
void destruirEndereco(Endereco *);
void atualizarAluno(Atualizar_aluno *aluno);

#endif