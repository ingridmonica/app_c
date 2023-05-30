#include "tratadores.h"
#include "menus.h"
#include <stdio.h>
#include "constantes.h"
#include <string.h>
#include "dados.h"
#include <stdlib.h>

void salvarDados(Aluno** alunos, int qtd_atual_aluno, Professor** professores, int qtd_atual_professores, Turmas** turmas, int qtd_atual_turmas)
{
    FILE* arquivo = fopen("dados.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    fwrite(&qtd_atual_aluno, sizeof(int), 1, arquivo);
    for (int i = 0; i < qtd_atual_aluno; i++) {
        if (alunos[i] != NULL) {
            fwrite(alunos[i], sizeof(Aluno), 1, arquivo);
        }
    }

    fwrite(&qtd_atual_professores, sizeof(int), 1, arquivo);
    for (int i = 0; i < qtd_atual_professores; i++) {
        if (professores[i] != NULL) {
            fwrite(professores[i], sizeof(Professor), 1, arquivo);
        }
    }

    //turmas
    fwrite(&qtd_atual_turmas, sizeof(int), 1, arquivo);
    for (int i = 0; i < qtd_atual_turmas; i++) {
        if (turmas[i] != NULL) {
            fwrite(turmas[i], sizeof(Turmas), 1, arquivo);
        }
    }

    fclose(arquivo);
    printf("Dados salvos com sucesso!\n");
}

void carregarDados(Aluno** alunos, int* qtd_atual_aluno, Professor** professores, int* qtd_atual_professores, Turmas** turmas, int qtd_atual_turmas)
{
    FILE* arquivo = fopen("dados.bin", "rb");
    if (arquivo == NULL) {
        printf("Arquivo de dados não encontrado. Criando novo arquivo...\n");
        return;
    }

    fread(qtd_atual_aluno, sizeof(int), 1, arquivo);
    for (int i = 0; i < *qtd_atual_aluno; i++) {
        Aluno* aluno = (Aluno*)malloc(sizeof(Aluno));
        fread(aluno, sizeof(Aluno), 1, arquivo);
        alunos[i] = aluno;
    }

    fread(qtd_atual_professores, sizeof(int), 1, arquivo);
    for (int i = 0; i < *qtd_atual_professores; i++) {
        Professor* professor = (Professor*)malloc(sizeof(Professor));
        fread(professor, sizeof(Professor), 1, arquivo);
        professores[i] = professor;
    }
    //turmas
    fread(qtd_atual_turmas, sizeof(int), 1, arquivo);
    for (int i = 0; i < qtd_atual_turmas; i++) {
        Turmas* turma = (Turmas*)malloc(sizeof(Turmas));
        fread(turma, sizeof(Turmas), 1, arquivo);
        turmas[i] = turma;
    }


    fclose(arquivo);
    printf("Dados carregados com sucesso!\n");
}

//menu alunos

void tratador_menu_aluno(Aluno **alunos, int *qtd_atual_aluno)
{
    int opcao = menu_crud_aluno();
    Aluno *aluno = NULL;
    switch (opcao)
    {
    case 1:
        if (*qtd_atual_aluno >= MAX_ALUNO)
        {
            printf("Número máximo de alunos atingido\n");
        }
        else
        {
            // Passo 1: buscar posicao disponível
            int i = 0;
            for (; i < *qtd_atual_aluno; i++)
            {
                if (alunos[i] != NULL)
                {
                    // significa que esta posição está livre para uso
                    break;
                }
            }
            Aluno *aluno = construir_aluno();
            alunos[i] = aluno;
            *qtd_atual_aluno++;
        }
        break;
    case 2:
    {
        int posicao = 0;
        aluno = buscar_aluno(alunos, &posicao);
        if (aluno)
        {
            imprimir_aluno(aluno);
        }
        else
        {
            printf("Aluno nao encontrado!!\n");
        }
    }
    break;
    case 3:
    {
        int posicao = 0;
        aluno = buscar_aluno(alunos, &posicao);

        if (aluno)
        {
            imprimir_aluno(aluno);
            printf("Atualizar aluno\n");
            printf("Nova Matricula\t> ");
            fgets(aluno->matricula, 9, stdin);
            printf("Novo CPF\t> ");
            fgets(aluno->cpf, 9, stdin);
            printf("Novo Nome\t> ");
            fgets(aluno->nome, 49, stdin);
            aluno->endereco = construir_endereco();
            printf("Aluno atualizado!\n");
        }
        else
        {
            printf("Aluno nao encontrado!!\n");
        }
        
    }

    break;
    case 4:
    {
        int posicao = 0;
        aluno = buscar_aluno(alunos, &posicao);
        if (aluno)
        {
            destruirAluno(aluno);
            alunos[posicao] = NULL;
            printf("Aluno destruido\n");
        }
        else
        {
            printf("Aluno nao encontrado!!\n");
        }
    }

    break;
    default:
        printf("Retornando ao menu principal\n");
        break;
    }
}

void tratador_menu_professor(Professor **professores, int *qtd_atual_professores)
{
    int opcao = menu_crud_professor();
    Professor *professor = NULL;
    switch (opcao)
    {
    case 1:
        if (*qtd_atual_professores >= MAX_PROFESSOR)
        {
            printf("Número máximo de professores atingido\n");
        }
        else
        {
            // Passo 1: buscar posicao disponível
            int i = 0;
            for (; i < *qtd_atual_professores; i++)
            {
                if (professores[i] != NULL)
                {
                    // significa que esta posição está livre para uso
                    break;
                }
            }
            Professor *professor = construir_professor();
            professores[i] = professor;
            *qtd_atual_professores++;
        }
        break;
    case 2:
    {
        int posicao = 0;
        professor = buscar_professor(professores, &posicao);
        if (professor)
        {
            imprimir_professor(professor);
        }
        else
        {
            printf("Professor não encontrado!!\n");
        }
    }
    break;
    case 3:
    {
        printf("Implementar a atualização de professor\n");
    }

    break;
    case 4:
    {
        int posicao = 0;
        professor = buscar_professor(professores, &posicao);
        if (professor)
        {
            destruirProfessor(professor);
            professores[posicao] = NULL;
            printf("Professor destruido\n");
        }
        else
        {
            printf("Professor não encontrado!!\n");
        }
    }

    break;
    default:
        printf("Retornando ao menu principal\n");
        break;
    }
}


Endereco *construir_endereco()
{
    Endereco endereco;

    printf("Logradouro\t> ");
    fgets(endereco.logradouro, 49, stdin);
    printf("Bairro\t> ");
    fgets(endereco.bairro, 49, stdin);
    printf("Cidade\t> ");
    fgets(endereco.cidade, 49, stdin);
    printf("Estado\t> ");
    fgets(endereco.estado, 9, stdin);
    printf("Número\t> ");
    fgets(endereco.numero, 9, stdin);

    return criarEndereco(endereco.logradouro, endereco.bairro, endereco.cidade, endereco.estado, endereco.numero);
}

Aluno *construir_aluno()
{
    Aluno aluno;
    printf("Matricula\t> ");
    fgets(aluno.matricula, 9, stdin);
    printf("CPF\t> ");
    fgets(aluno.cpf, 9, stdin);
    printf("Nome\t> ");
    fgets(aluno.nome, 49, stdin);
    aluno.endereco = construir_endereco();
    return criarAluno(aluno.matricula, aluno.cpf, aluno.nome, aluno.endereco);
}

Aluno *buscar_aluno(Aluno **alunos, int *posicao)
{
    char matricula[50];
    printf("Matricula > ");
    fgets(matricula, 49, stdin);
    Aluno *resultado = NULL;
    int pos_resultado = -1;
    for (int i = 0; i < MAX_ALUNO; i++)
    {
        // Vamos testar se o aluno existe e se a matricula e a buscada
        // strcmp compara strings. Se for 0 indica que são iguais
        if (alunos[i] && !strcmp(matricula, alunos[i]->matricula))
        {
            resultado = alunos[i];
            break;
        }
    }
    *posicao = pos_resultado;
    return resultado;
}

void tratador_estatistica()
{
    int opcao = menu_estatistica();
}

void imprimir_aluno(Aluno *aluno)
{
    printf("Matricula: %s", aluno->matricula);
    printf("Nome: %s", aluno->nome);
    printf("CPF: %s", aluno->cpf);
    imprimir_endereco(aluno->endereco);
}

void imprimir_endereco(Endereco *endereco)
{
    printf("Logradouro: %s", endereco->logradouro);
    printf("Numero: %s", endereco->numero);
    printf("Bairro: %s", endereco->bairro);
    printf("Cidade: %s", endereco->cidade);
    printf("Estado: %s", endereco->estado);
}

Professor *construir_professor()
{
    Professor professor;
    printf("Matrícula\t> ");
    fgets(professor.matricula, 9, stdin);
    printf("CPF\t> ");
    fgets(professor.cpf, 9, stdin);
    printf("Nome\t> ");
    fgets(professor.nome, 49, stdin);
    printf("Endereço\t> \n");
    professor.endereco = construir_endereco();
    
    return criarProfessor(professor.matricula, professor.cpf, professor.nome, professor.endereco);
}

Professor *buscar_professor(Professor **professores, int *posicao)
{
    char matricula[50];
    printf("Matricula > ");
    fgets(matricula, 49, stdin);
    Professor *resultado = NULL;
    int pos_resultado = -1;
    for (int i = 0; i < MAX_PROFESSOR; i++)
    {

        if (professores[i] && !strcmp(matricula, professores[i]->matricula))
        {
            resultado = professores[i];
            break;
        }
    }
    *posicao = pos_resultado;
    return resultado;
}

void imprimir_professor(Professor *professor)
{
    printf("Matricula: %s", professor->matricula);
    printf("Nome: %s", professor->nome);
    printf("CPF: %s", professor->cpf);
    imprimir_endereco(professor->endereco);
}

void tratador_menu_prof(Professor **professores, int *qtd_atual_prof){
    int opcao = menu_crud_professor();
    Professor *professor = NULL;
    switch (opcao)
    {
    case 1:
        if (*qtd_atual_prof >= MAX_PROFESSOR)
        {
            printf("Número máximo de professores atingido\n");
        }
        else
        {
            int i = 0;
            for (; i < *qtd_atual_prof; i++)
            {
                if (professores[i] != NULL)
                {
                    break;
                }
            }
            Professor *professor = construir_professor();
            professores[i] = professor;
            (*qtd_atual_prof)++;
        }
        break;
    case 2:
    {
        int posicao = 0;
        professor = buscar_professor(professores, &posicao);
        if (professor)
        {
            imprimir_professor(professor);
        }
        else
        {
            printf("Professor nao encontrado!!\n");
        }
    }
    break;
    case 3:
    {
        int posicao = 0;
        professor = buscar_professor(professores, &posicao);

        if (professor)
        {
            imprimir_professor(professor);
            printf("Atualizar professor\n");
            printf("Nova Matricula\t> ");
            fgets(professor->matricula, 9, stdin);
            printf("Novo CPF\t> ");
            fgets(professor->cpf, 9, stdin);
            printf("Novo Nome\t> ");
            fgets(professor->nome, 49, stdin);
            professor->endereco = construir_endereco();
            printf("Professor atualizado!\n");
        }
        else
        {
            printf("Professor nao encontrado!!\n");
        }
        
    }

    break;
    case 4:
    {
        int posicao = 0;
        professor = buscar_professor(professores, &posicao);
        if (professor)
        {
            destruirProfessor(professor);
            professores[posicao] = NULL;
            printf("Professor destruido\n");
        }
        else
        {
            printf("Professor nao encontrado!!\n");
        }
    }

    break;
    default:
        printf("Retornando ao menu principal\n");

}
}

void listarProfessores(const Professor* professores, int numProfessores) 
    {
    printf("Lista de professores:\n");
    for (int i = 0; i < numProfessores; i++) {
        printf("Professor %d:\n", i + 1);
        printf("Matrícula: %d\n", professores[i].matricula);
        printf("CPF: %s\n", professores[i].cpf);
        printf("Nome: %s\n", professores[i].nome);
    }
    }

void listarProfessoresSemTurmas(const Professor* professores, int numProfessores, const Turmas* turmas, int numTurmas) {
    printf("Matrículas dos professores sem turmas:\n");
    for (int i = 0; i < numProfessores; i++) {
        int possuiTurma = 0;
        for (int j = 0; j < numTurmas; j++) {
            if (turmas[j].matricula_professor_responsavel == professores[i].matricula) {
                possuiTurma = 1;
                break;
            }
        }
        if (!possuiTurma) {
            printf("Matrícula: %d\n", professores[i].matricula);
        }
    }
    }

    void calcularMediaGeralTurmas(const Turmas* turmas, int numTurmas) {
    float somaNotas = 0;
    int numTurmasValidas = 0;
    int i = 0;
    int notaMedia = atoi(turmas[i].media_turma);
    for (int i = 0; i < numTurmas; i++) {
        if (notaMedia != 0) {
            somaNotas += notaMedia;
            numTurmasValidas++;
        }
    }
    if (numTurmasValidas > 0) {
        float mediaGeral = somaNotas / numTurmasValidas;
        printf("Média geral das turmas: %.2f\n", mediaGeral);
    } else {
        printf("Não há turmas cadastradas com notas.\n");
    }
    }


void tratador_menu_estatisticas(Aluno** alunos, int numAlunos, Professor** professores, int numProfessores, Turmas** turmas, int numTurmas)
{
    int opcao = menu_estatistica();
    switch (opcao)
    {
    case 1:
        {
          void listarProfessores(const Professor* professores, int numProfessores);
        }
        break;

    case 2:
    {
        void listarProfessoresSemTurmas(const Professor* professores, int numProfessores, const Turmas* turmas, int numTurmas);
        }
        break;
    case 3:
    {
        void calcularMediaGeralTurmas(const Turmas* turmas, int numTurmas);
    }
        break;
}
}