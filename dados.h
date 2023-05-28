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
    Endereco *endereco;
} Professor;

typedef struct
{
    char codigo[6];
    char nome_disciplina[50];
    char matriculaProf[10];
    char lista_alunos;
    char media_turma;
} Turma;

#endif 

Endereco *criarEndereco(char *logradouro,
                        char *bairro,
                        char *cidade,
                        char *estado,
                        char *numero);

Aluno *criarAluno(char *matricula,
                  char *cpf,
                  char *nome,
                  Endereco *end);

Professor *criarProfessor( 
                            char *matricula,
                            char *cpf,
                            char *nome,
                            Endereco *end);

Turma *criarTurma(
                char *codigo,
                char *nome_disciplina,
                char *matriculaProf,
                char *lista_alunos,
                char media_turma);



void destruirAluno(Aluno *aluno);
void destruirEndereco(Endereco *end);
void destruirProfessor(Professor *professor);
void destruirTurma(Turma *turma);
