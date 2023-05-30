#ifndef _TRATADORES_H_
#define _TRATADORES_H_

#include "dados.h"
//include "turmas.c"

void carregarDados(Aluno** alunos, int* qtd_atual_aluno, Professor** professores, int* qtd_atual_professores, Turmas** turmas, int qtd_atual_turmas);
void salvarDados(Aluno** alunos, int qtd_atual_aluno, Professor** professores, int qtd_atual_professores, Turmas** turmas, int qtd_atual_turmas);

//alunos 
void tratador_menu_aluno(Aluno **alunos, int *qtd_atual_aluno);

Aluno *construir_aluno();

Aluno *buscar_aluno(Aluno **alunos, int *posicao);

void imprimir_aluno(Aluno *aluno);

//endereço

Endereco *construir_endereco();

void imprimir_endereco(Endereco *endereco);

//professores

void tratador_menu_prof(Professor **professores, int *qtd_atual_prof);

Professor *construir_professor();

Professor *buscar_professor(Professor **professores, int *posicao);

void imprimir_professor(Professor *professor);

//turmas
void tratar_menu_turmas(Turmas **turmas, int *qtd_alunos_matriculados);

//estatisticas
void tratador_menu_estatisticas(Aluno** alunos, int numAlunos, Professor** professores, int numProfessores, Turmas** turmas, int numTurmas);
void listarProfessores(const Professor* professores, int numProfessores);
void listarProfessoresSemTurmas(const Professor* professores, int numProfessores, const Turmas* turmas, int numTurmas);
void calcularMediaGeralTurmas(const Turmas* turmas, int numTurmas);
#endif