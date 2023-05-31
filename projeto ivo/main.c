#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
#include "tratadores.h"
#include "wchar.h"

//a gente fez o codigo corrido e depois tentou modularizar, não conseguimos fazer tão dividido quanto o exemplo
//a main ficou bem maior, os menus foram incorporados a ela
//decidimos mudar alguns nomes de variáveis, principalmente a de destruir aluno que era muito ameaçadora

int main() {

Aluno **alunos;
int qtd_atual_aluno = 0;
int qtd_max_aluno = 10;

Professor **professores;
int qtd_atual_professor = 0;
int qtd_max_professor = 10;

Turma **turmas;
int qtd_atual_turma = 0;
int qtd_max_turma = 10;

int opcao;
// a parte da leitura do que seria a pertinencia, infelizmente ainda estamos com problema pra ler... 
//só conseguimos salvar
lerAlunos(&alunos, &qtd_atual_aluno, &qtd_max_aluno);
lerProfessores(&professores, &qtd_atual_professor, &qtd_max_professor);
lerTurmas(&turmas, &qtd_atual_turma, &qtd_max_turma, professores, qtd_atual_professor);


do {
    printf("Menu Principal:\n");
    printf("1. Aluno\n");
    printf("2. Professor\n");
    printf("3. Turma\n");
    printf("4. Estatisticas\n");
    printf("5. Sair\n");
    printf("Digite uma opção: ");
    scanf("%d", &opcao);

switch (opcao) {
    case 1: {
    int opcao_aluno;

    do {
        printf("\nMenu Aluno:\n");
        printf("1. Cadastrar Aluno\n");
        printf("2. Listar Alunos\n");
        printf("3. Atualizar Aluno\n");
        printf("4. Deletar Aluno\n");
        printf("5. Voltar\n");
        printf("Digite uma opção: ");
        scanf("%d", &opcao_aluno);

    switch (opcao_aluno) {
    case 1: {
    char matriculaAluno[10];
    char cpf[12];
    char nome[100];
    Endereco *end;

    printf("Matricula do aluno: ");
    scanf("%s", matriculaAluno);

    printf("CPF do aluno: ");
    scanf("%s", cpf);
    //uma das restrições aqui
    // essa verifica se o CPF já está cadastrado
    int aluno_encontrado = -1;
    for (int i = 0; i < qtd_atual_aluno; i++) {
    if (strcmp(alunos[i]->cpf, cpf) == 0) {
    aluno_encontrado = i;
    break;
    }
    }

    if (aluno_encontrado == -1) {
    printf("Nome do aluno: ");
    scanf(" %[^\n]", nome);

    if (qtd_atual_aluno == qtd_max_aluno) {
    // Aumenta a capacidade do array de alunos
    qtd_max_aluno *= 2;
    alunos = (Aluno**) realloc(alunos, qtd_max_aluno * sizeof(Aluno*));
    }

    alunos[qtd_atual_aluno] = criarAluno(matriculaAluno, cpf, nome, end);
    qtd_atual_aluno++;

    printf("Aluno cadastrado com sucesso.\n");
    } else {
    printf("Erro: Aluno já cadastrado com esse CPF.\n");
    }

    break;
    }
    case 2:
    if (qtd_atual_aluno > 0) {
    printf("Lista de Alunos:\n");
    for (int i = 0; i < qtd_atual_aluno; i++) {
    exibirAluno(alunos[i]);
    printf("--------\n");
    }
    } else {
    printf("Nenhum aluno cadastrado.\n");
    }
    break;
    case 3:
    if (qtd_atual_aluno > 0) {
    char matriculaAluno[10];

    printf("Digite a matrícula do aluno que deseja atualizar: ");
    scanf("%s", matriculaAluno);

    // Busca o aluno pela matricula
    int aluno_encontrado = -1;
    for (int i = 0; i < qtd_atual_aluno; i++) {
    if (strcmp(alunos[i]->matriculaAluno, matriculaAluno) == 0) {
    aluno_encontrado = i;
    break;
    }
    }

    if (aluno_encontrado != -1) {
    char novo_nome[100];
    char novo_cpf[100];
    Endereco *end;

    printf("Digite o novo nome do aluno: ");
    scanf(" %[^\n]", novo_nome);
    strcpy(alunos[aluno_encontrado]->nome, novo_nome);
    printf("Digite o novo CPF do aluno");
    scanf("%s", alunos[aluno_encontrado]->cpf);
    printf("Digite o novo endereço do aluno");
    scanf("%s", alunos[aluno_encontrado]->endereco);


    printf("Aluno atualizado com sucesso.\n");
    } else {
    printf("Erro: Aluno não encontrado.\n");
    }
    } else {
    printf("Nenhum aluno cadastrado.\n");
    }
    break;
    case 4:
    if (qtd_atual_aluno > 0) {
    char matriculaAluno[10];
    char cpf[12];

    printf("Digite a matricula do aluno que deseja deletar: ");
    scanf("%s", matriculaAluno);

    // Busca o aluno pela matricula
    int aluno_encontrado = -1;
    for (int i = 0; i < qtd_atual_aluno; i++) {
    if (strcmp(alunos[i]->matriculaAluno, matriculaAluno) == 0) {
    aluno_encontrado = i;
    break;
    }
    }

    if (aluno_encontrado != -1) {
    // verificando se o aluno está em alguma turma
    int aluno_em_turma = 0;
    for (int i = 0; i < qtd_atual_turma; i++) {
    if (strcmp(alunos[aluno_encontrado]->cpf, turmas[i]->aluno->cpf) == 0) {
    aluno_em_turma = 1;
    break;
    }
    }

    if (aluno_em_turma) {
    printf("Erro: O aluno está associado a uma turma. Não é possível deletá-lo.\n");
    } else {
    free(alunos[aluno_encontrado]);
    for (int i = aluno_encontrado; i < qtd_atual_aluno - 1; i++) {
    alunos[i] = alunos[i + 1];
    }
    qtd_atual_aluno--;

    printf("Aluno deletado com sucesso.\n");
    }
    } else {
    printf("Erro: Aluno não encontrado.\n");
    }
    } else {
    printf("Nenhum aluno cadastrado.\n");
    }
    break;
    case 5:
    printf("Retornando ao menu principal...\n");
    break;
    default:
    printf("Opção inválida.\n");
    break;
    }
    } while (opcao_aluno != 5);

    break;
    }
    case 2: {
    int opcao_professor;

    do {
    printf("\nMenu Professor:\n");
    printf("1. Cadastrar Professor\n");
    printf("2. Listar Professores\n");
    printf("3. Atualizar Professor\n");
    printf("4. Deletar Professor\n");
    printf("5. Voltar\n");
    printf("Digite uma opção: ");
    scanf("%d", &opcao_professor);

    switch (opcao_professor) {
    case 1: {
    char matricula[10];
    char cpf[12];
    char nome[100];
    Endereco *end;

    printf("Digite a matrícula do professor: ");
    scanf("%s", matricula);

    printf("Digite o CPF do professor: ");
    scanf("%s", cpf);

    // verifica se o CPF já está cadastrado
    int professor_encontrado = -1;
    for (int i = 0; i < qtd_atual_professor; i++) {
    if (strcmp(professores[i]->cpf, cpf) == 0) {
    professor_encontrado = i;
    break;
    }
    }

    if (professor_encontrado == -1) {
    printf("Digite o nome do professor: ");
    scanf(" %[^\n]", nome);

    printf("Digite o endereço do professor: ");
    scanf(" %[^\n]", end);

    if (qtd_atual_professor == qtd_max_professor) {
    // Aumenta a capacidade do array de professores
    qtd_max_professor *= 2;
    professores = (Professor**) realloc(professores, qtd_max_professor * sizeof(Professor*));
    }

    professores[qtd_atual_professor] = criarProfessor(matricula, cpf, nome, end);
    qtd_atual_professor++;

    printf("Professor cadastrado com sucesso.\n");
    } else {
    printf("Erro: Professor já cadastrado com esse CPF.\n");
    }

    break;
    }
    case 2:
    if (qtd_atual_professor > 0) {
    printf("Lista de Professores:\n");
    for (int i = 0; i < qtd_atual_professor; i++) {
    exibirProfessor(professores[i]);
    printf("--------\n");
    }
    } else {
    printf("Nenhum professor cadastrado.\n");
    }
    break;
    case 3:
    if (qtd_atual_professor > 0) {
    char cpf[12];

    printf("Digite o CPF do professor que deseja atualizar: ");
    scanf("%s", cpf);

    // Busca o professor pelo CPF
    int professor_encontrado = -1;
    for (int i = 0; i < qtd_atual_professor; i++) {
    if (strcmp(professores[i]->cpf, cpf) == 0) {
    professor_encontrado = i;
    break;
    }
    }

    if (professor_encontrado != -1) {
    char novo_nome[100];

    printf("Digite o novo nome do professor: ");
    scanf(" %[^\n]", novo_nome);

    strcpy(professores[professor_encontrado]->nome, novo_nome);

    printf("Professor atualizado com sucesso.\n");
    } else {
    printf("Erro: Professor não encontrado.\n");
    }
    } else {
    printf("Nenhum professor cadastrado.\n");
    }
    break;
    case 4:
    if (qtd_atual_professor > 0) {
    char cpf[12];

    printf("Digite o CPF do professor que deseja deletar: ");
    scanf("%s", cpf);

    // Busca o professor pelo CPF
    int professor_encontrado = -1;
    for (int i = 0; i < qtd_atual_professor; i++) {
    if (strcmp(professores[i]->cpf, cpf) == 0) {
    professor_encontrado = i;
    break;
    }
    }

    if (professor_encontrado != -1) {
    // Verifica se o professor está associado a uma turma
    int professor_em_turma = 0;
    for (int i = 0; i < qtd_atual_turma; i++) {
    if (strcmp(professores[professor_encontrado]->cpf, turmas[i]->professor->cpf) == 0) {
    professor_em_turma = 1;
    break;
    }
    }

    if (professor_em_turma) {
    printf("Erro: O professor está associado a uma turma. Não é possível deletá-lo.\n");
    } else {
    free(professores[professor_encontrado]);
    for (int i = professor_encontrado; i < qtd_atual_professor - 1; i++) {
    professores[i] = professores[i + 1];
    }
    qtd_atual_professor--;

    printf("Professor deletado com sucesso.\n");
    }
    } else {
    printf("Erro: Professor não encontrado.\n");
    }
    } else {
    printf("Nenhum professor cadastrado.\n");
    }
    break;
    case 5:
    printf("Retornando ao menu principal...\n");
    break;
    default:
    printf("Opção inválida.\n");
    break;
    }
    } while (opcao_professor != 5);

    break;
    }
    case 3: {
    int opcao_turma;

    do {
    printf("\nMenu Turma:\n");
    printf("1. Cadastrar Turma\n");
    printf("2. Listar Turmas\n");
    printf("3. Atualizar Turma\n");
    printf("4. Deletar Turma\n");
    printf("5. Voltar\n");
    printf("Digite uma opção: ");
    scanf("%d", &opcao_turma);

    switch (opcao_turma) {
    case 1: {
    char codigo[10];
    char cpf_professor[12];
    Professor *professor;
    char nota[30];

    printf("Digite o código da turma: ");
    scanf("%s", codigo);

    // Verifica se o código da turma já está cadastrado
    int turma_encontrada = -1;
    for (int i = 0; i < qtd_atual_turma; i++) {
    if (strcmp(turmas[i]->codigo, codigo) == 0) {
    turma_encontrada = i;
    break;
    }
    }

    if (turma_encontrada == -1) {
    printf("Digite o CPF do professor responsável: ");
    scanf("%s", cpf_professor);

    // Busca o professor pelo CPF
    int professor_encontrado = -1;
    for (int i = 0; i < qtd_atual_professor; i++) {
    if (strcmp(professores[i]->cpf, cpf_professor) == 0) {
    professor_encontrado = i;
    break;
    }
    }

    if (professor_encontrado != -1) {
    professor = professores[professor_encontrado];

    if (qtd_atual_turma == qtd_max_turma) {
    // Aumenta a capacidade do array de turmas
    qtd_max_turma *= 2;
    turmas = (Turma**) realloc(turmas, qtd_max_turma * sizeof(Turma*));
    }

    turmas[qtd_atual_turma] = criarTurma(codigo, professor, nota);
    qtd_atual_turma++;

    printf("Turma cadastrada com sucesso.\n");
    } else {
    printf("Erro: Professor não encontrado.\n");
    }
    } else {
    printf("Erro: Turma já cadastrada com esse código.\n");
    }

    break;
    }
    case 2:
    if (qtd_atual_turma > 0) {
    printf("Lista de Turmas:\n");
    for (int i = 0; i < qtd_atual_turma; i++) {
    exibirTurma(turmas[i]);
    printf("--------\n");
    }
    } else {
    printf("Nenhuma turma cadastrada.\n");
    }
    break;
    case 3:
    if (qtd_atual_turma > 0) {
    char codigo[10];

    printf("Digite o código da turma que deseja atualizar: ");
    scanf("%s", codigo);

    // Busca a turma pelo código
    int turma_encontrada = -1;
    for (int i = 0; i < qtd_atual_turma; i++) {
    if (strcmp(turmas[i]->codigo, codigo) == 0) {
    turma_encontrada = i;
    break;
    }
    }

    if (turma_encontrada != -1) {
    char novo_codigo[10];

    printf("Digite o novo código da turma: ");
    scanf("%s", novo_codigo);

    // Verifica se o novo código já está cadastrado
    int codigo_repetido = 0;
    for (int i = 0; i < qtd_atual_turma; i++) {
    if (i != turma_encontrada && strcmp(turmas[i]->codigo, novo_codigo) == 0) {
    codigo_repetido = 1;
    break;
    }
    }

    if (!codigo_repetido) {
    strcpy(turmas[turma_encontrada]->codigo, novo_codigo);

    printf("Turma atualizada com sucesso.\n");
    } else {
    printf("Erro: Código de turma já cadastrado.\n");
    }
    } else {
    printf("Erro: Turma não encontrada.\n");
    }
    } else {
    printf("Nenhuma turma cadastrada.\n");
    }
    break;
    case 4:
    if (qtd_atual_turma > 0) {
    char codigo[10];

    printf("Digite o código da turma que deseja deletar: ");
    scanf("%s", codigo);

    // Busca a turma pelo código
    int turma_encontrada = -1;
    for (int i = 0; i < qtd_atual_turma; i++) {
    if (strcmp(turmas[i]->codigo, codigo) == 0) {
    turma_encontrada = i;
    break;
    }
    }

    if (turma_encontrada != -1) {
    free(turmas[turma_encontrada]);
    for (int i = turma_encontrada; i < qtd_atual_turma - 1; i++) {
    turmas[i] = turmas[i + 1];
    }
    qtd_atual_turma--;

    printf("Turma deletada com sucesso.\n");
    } else {
    printf("Erro: Turma não encontrada.\n");
    }
    } else {
    printf("Nenhuma turma cadastrada.\n");
    }
    break;
    case 5:
    printf("Retornando ao menu principal...\n");
    break;
    default:
    printf("Opção inválida.\n");
    break;
    }
    } while (opcao_turma != 5);

    break;
    }
    case 4: { 
        
    int opcao_estatistica;

    do {
    printf("\nMenu Estatística:\n");
    printf("1. Imprimir nome dos professores\n");
    printf("2. Imprimir matrículas dos professores que não estão em nenhuma turma\n");
    printf("3. Calcular nota média de todas as turmas\n");
    printf("4. Voltar\n");
    printf("Digite uma opção: ");
    scanf("%d", &opcao_estatistica);

    switch (opcao_estatistica) {
    case 1:
    if (qtd_atual_professor > 0) {
    printf("Lista de Professores:\n");
    for (int i = 0; i < qtd_atual_professor; i++) {
    exibirProfessor(professores[i]);
    printf("--------\n");
    }
    } else {
    printf("Nenhum professor cadastrado.\n");
    }
    break;                       
    break;
    case 2:
    if (qtd_atual_professor > 0) {
    printf("Lista de Professores:\n");
    for (int i = 0; i < qtd_atual_professor; i++) {
    exibirProfessor(professores[i]);
    printf("--------\n");
    }
    } else {
    printf("Nenhum professor cadastrado.\n");
    }
    break;
    case 3:
    // if (qtd_atual_turma > 0) {
    
    // float calcularMediaNotasTurmas(Turma** turmas, int qtd_atual_turma) 
    // {
    // float soma_notas = 0.0;
    // int total_notas = 0;

    // for (int i = 0; i < qtd_atual_turma; i++) {
    // Turma* turma = turmas[i];
    // for (int j = 0; j < turma->qtd_alunos; j++) {
    // Aluno* aluno = turma->alunos[j];
    // soma_notas += aluno->nota;
    // total_notas++;
    // }
    // }

    // if (total_notas > 0) {
    // return soma_notas / total_notas;
    // } else {
    // return 0.0;
    // }
    // }}
    break;
    case 4:
    printf("Retornando ao menu principal...\n");
    break;
    default:
    printf("Opção inválida.\n");
    break;
    }
    } while (opcao_estatistica != 4);

    break;
    }
    case 5:
    printf("Encerrando o programa...\n");
    salvarAlunos(alunos, qtd_atual_aluno);
    salvarProfessores(professores, qtd_atual_professor);
    salvarTurmas(turmas, qtd_atual_turma);
    encerrarPrograma(alunos, qtd_atual_aluno, professores, qtd_atual_professor, turmas, qtd_atual_turma);
    return 0;
    default:
    printf("Opção inválida.\n");
    break;
    }
    } while (1);

    return 0;
    }
