#ifndef __TRATADORES_H__
#define __TRATADORES_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"


void exibirAluno(Aluno *aluno);
void exibirProfessor(Professor *professor);
void exibirTurma(Turma *turma);
void salvarAlunos(Aluno **alunos, int qtd_atual_aluno);
void salvarProfessores(Professor **professores, int qtd_atual_professor);
void salvarTurmas(Turma **turmas, int qtd_atual_turma);
void encerrarPrograma(Aluno **alunos, int qtd_atual_aluno, Professor **professores, int qtd_atual_professor, Turma **turmas, int qtd_atual_turma);
void lerAlunos(Aluno ***alunos, int *qtd_atual_aluno, int *qtd_max_aluno);
void lerProfessores(Professor ***professores, int *qtd_atual_professor, int *qtd_max_professor);
void lerTurmas(Turma ***turmas, int *qtd_atual_turma, int *qtd_max_turma, Professor **professores, int qtd_atual_professor);
float calcularMediaNotasTurmas(Turma** turmas, int qtd_atual_turma);
Endereco* criarEndereco(char *logradouro, char *bairro, char *cidade, char *estado, char *numero);
Aluno* criarAluno(const char* matriculaAluno, const char* cpf, const char* nome, Endereco *end);
Professor* criarProfessor(const char* matricula, const char* cpf, const char* nome, Endereco *end);
Turma* criarTurma(const char* codigo, Professor* professor, const char* nota);

#endif