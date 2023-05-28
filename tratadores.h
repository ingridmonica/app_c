#ifndef _TRATADORES_H_
#define _TRATADORES_H_

#include "dados.h"

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


#endif