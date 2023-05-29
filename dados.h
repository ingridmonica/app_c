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
    char codigo[10];
    char disciplina[50];
    char matricula_professor_responsavel[10];
    char qtd_alunos_matriculados[3];
    char matricula_alunos[10];
    char media_turma[10];
} Turmas;

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

Turmas *criarTurma(
                    char *codigo,
                    char *disciplina,
                    char *matricula_professor_responsavel,
                    char *numero_alunos,
                    char *matricula_alunos,
                    char *media_turma);



void destruirAluno(Aluno *aluno);
void destruirEndereco(Endereco *end);
void destruirProfessor(Professor *professor);
void destruirTurma(Turmas *turma);
