#include "tratadores.h"  // Inclui o arquivo de cabeçalho "tratadores.h"
#include "menus.h"  // Inclui o arquivo de cabeçalho "menus.h"
#include <stdio.h>  // Inclui a biblioteca de entrada/saída padrão
#include "constantes.h"  // Inclui o arquivo de cabeçalho "constantes.h"
#include <string.h>  // Inclui a biblioteca para manipulação de strings
#include "dados.h"  // Inclui o arquivo de cabeçalho "dados.h"
#include <stdlib.h>  // Inclui a biblioteca padrão do C para alocação dinâmica de memória
#include "turmas.c"

void salvarDados(Aluno** alunos, int qtd_atual_aluno, Professor** professores, int qtd_atual_prof, Turmas** turmas, int qtd_atual_turma)
{
    FILE* arquivo;  // Declara um ponteiro para o arquivo
    arquivo = fopen("dados.bin", "wb");  // Abre o arquivo "dados.bin" no modo de escrita binária ("wb")
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");  // Exibe uma mensagem de erro se não for possível abrir o arquivo
        return;
    }

    fwrite(&qtd_atual_aluno, sizeof(int), 1, arquivo);  // Escreve a quantidade atual de alunos no arquivo
    for (int i = 0; i < qtd_atual_aluno; i++) {
        if (alunos[i] != NULL) {
            fwrite(alunos[i], sizeof(Aluno), 100, arquivo);  // Escreve os dados de cada aluno no arquivo
        }
    }

    fwrite(&qtd_atual_prof, sizeof(int), 1, arquivo);  // Escreve a quantidade atual de professores no arquivo
    for (int i = 0; i < qtd_atual_prof; i++) {
        if (professores[i] != NULL) {
            fwrite(professores[i], sizeof(Professor), 100, arquivo);  // Escreve os dados de cada professor no arquivo
        }
    }

    //turmas
    fwrite(&qtd_atual_turma, sizeof(int), 1, arquivo);  // Escreve a quantidade atual de turmas no arquivo
    for (int i = 0; i < qtd_atual_turma; i++) {
        if (turmas[i] != NULL) {
            fwrite(turmas[i], sizeof(Turmas), 100, arquivo);  // Escreve os dados de cada turma no arquivo
        }
    }

    fclose(arquivo);  // Fecha o arquivo
    printf("Dados salvos com sucesso!\n");  // Exibe uma mensagem informando que os dados foram salvos com sucesso
}

void carregarDados(Aluno** alunos, int* qtd_atual_aluno, Professor** professores, int* qtd_atual_prof, Turmas** turmas, int qtd_atual_turma)
{
    FILE* arquivo;  // Declara um ponteiro para o arquivo
    arquivo = fopen("dados.bin", "rb");  // Abre o arquivo "dados.bin" no modo de leitura binária ("rb")
    if (arquivo == NULL) {
        printf("Arquivo de dados não encontrado. Criando novo arquivo...\n");  // Exibe uma mensagem informando que o arquivo de dados não foi encontrado
        return;
    }

    fread(qtd_atual_aluno, sizeof(int), 1, arquivo);  // Lê a quantidade atual de alunos do arquivo
    for (int i = 0; i < *qtd_atual_aluno; i++) {
        Aluno* aluno = (Aluno*)malloc(sizeof(Aluno));  // Aloca memória para um aluno
        fread(aluno, sizeof(Aluno), 100, arquivo);  // Lê os dados do aluno do arquivo
        alunos[i] = aluno;  // Armazena o aluno na lista de alunos
    }

    fread(qtd_atual_prof, sizeof(int), 1, arquivo);  // Lê a quantidade atual de professores do arquivo
    for (int i = 0; i < *qtd_atual_prof; i++) {
        Professor* professor = (Professor*)malloc(sizeof(Professor));  // Aloca memória para um professor
        fread(professor, sizeof(Professor), 100, arquivo);  // Lê os dados do professor do arquivo
        professores[i] = professor;  // Armazena o professor na lista de professores
    }
    //turmas
    fread(&qtd_atual_turma, sizeof(int), 1, arquivo);  // Lê a quantidade atual de turmas do arquivo
    for (int i = 0; i < qtd_atual_turma; i++) {
        Turmas* turma = (Turmas*)malloc(sizeof(Turmas));  // Aloca memória para uma turma
        fread(turma, sizeof(Turmas), 100, arquivo);  // Lê os dados da turma do arquivo
        turmas[i] = turma;  // Armazena a turma na lista de turmas
    }

    fclose(arquivo);  // Fecha o arquivo
    printf("Dados carregados com sucesso!\n");  // Exibe uma mensagem informando que os dados foram carregados com sucesso
}

//menu alunos

void tratador_menu_aluno(Aluno** alunos, int* qtd_atual_aluno)
{
    int opcao = menu_crud_aluno();  // Chama a função para exibir o menu de operações do aluno e obter a opção selecionada
    Aluno* aluno = NULL;
    switch (opcao)
    {
    case 1:
        if (*qtd_atual_aluno >= MAX_ALUNO)
        {
            printf("Número máximo de alunos atingido\n");  // Exibe uma mensagem informando que o número máximo de alunos foi atingido
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
            Aluno* aluno = construir_aluno();  // Chama a função para construir um novo aluno
            alunos[i] = aluno;  // Armazena o novo aluno na lista de alunos
            *qtd_atual_aluno++;  // Incrementa a quantidade atual de alunos
        }
        break;
    case 2:
    {
        int posicao = 0;
        aluno = buscar_aluno(alunos, &posicao);  // Chama a função para buscar um aluno
        if (aluno)
        {
            imprimir_aluno(aluno);  // Chama a função para imprimir os dados do aluno encontrado
        }
        else
        {
            printf("Aluno nao encontrado!!\n");  // Exibe uma mensagem informando que o aluno não foi encontrado
        }
    }
    break;
    case 3:
    {
        int posicao = 0;
        aluno = buscar_aluno(alunos, &posicao);  // Chama a função para buscar um aluno
        if (aluno)
        {
            imprimir_aluno(aluno);  // Chama a função para imprimir os dados do aluno encontrado
            printf("Atualizar aluno\n");
            printf("Nova Matricula\t> ");
            fgets(aluno->matricula, 9, stdin);  // Lê a nova matrícula do aluno
            printf("Novo CPF\t> ");
            fgets(aluno->cpf, 9, stdin);  // Lê o novo CPF do aluno
            printf("Novo Nome\t> ");
            fgets(aluno->nome, 49, stdin);  // Lê o novo nome do aluno
            aluno->endereco = construir_endereco();  // Chama a função para construir um novo endereço para o aluno
            printf("Aluno atualizado!\n");  // Exibe uma mensagem informando que o aluno foi atualizado com sucesso
        }
        else
        {
            printf("Aluno nao encontrado!!\n");  // Exibe uma mensagem informando que o aluno não foi encontrado
        }
    }
    break;
    case 4:
    {
        int posicao = 0;
        aluno = buscar_aluno(alunos, &posicao);  // Chama a função para buscar um aluno
        if (aluno)
        {
            destruirAluno(aluno);  // Chama a função para destruir o aluno encontrado
            alunos[posicao] = NULL;  // Define a posição do aluno como NULL na lista de alunos
            printf("Aluno destruido\n");  // Exibe uma mensagem informando que o aluno foi destruído com sucesso
        }
        else
        {
            printf("Aluno nao encontrado!!\n");  // Exibe uma mensagem informando que o aluno não foi encontrado
        }
    }
    break;
    default:
        printf("Retornando ao menu principal\n");  // Exibe uma mensagem informando que o programa está retornando ao menu principal
        break;
    }
}

void tratador_menu_professor(Professor** professores, int* qtd_atual_professores)
{
    int opcao = menu_crud_professor();  // Chama a função para exibir o menu de operações do professor e obter a opção selecionada
    Professor* professor = NULL;
    switch (opcao)
    {
    case 1:
        if (*qtd_atual_professores >= MAX_PROFESSOR)
        {
            printf("Número máximo de professores atingido\n");  // Exibe uma mensagem informando que o número máximo de professores foi atingido
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
            Professor* professor = construir_professor();  // Chama a função para construir um novo professor
            professores[i] = professor;  // Armazena o novo professor na lista de professores
            *qtd_atual_professores++;  // Incrementa a quantidade atual de professores
        }
        break;
    case 2:
    {
        int posicao = 0;
        professor = buscar_professor(professores, &posicao);  // Chama a função para buscar um professor
        if (professor)
        {
            imprimir_professor(professor);  // Chama a função para imprimir os dados do professor encontrado
        }
        else
        {
            printf("Professor nao encontrado!!\n");  // Exibe uma mensagem informando que o professor não foi encontrado
        }
    }
    break;
    case 3:
    {
        int posicao = 0;
        professor = buscar_professor(professores, &posicao);  // Chama a função para buscar um professor
        if (professor)
        {
            imprimir_professor(professor);  // Chama a função para imprimir os dados do professor encontrado
            printf("Atualizar professor\n");
            printf("Novo Matricula\t> ");
            fgets(professor->matricula, 9, stdin);  // Lê a nova matrícula do professor
            printf("Novo CPF\t> ");
            fgets(professor->cpf, 9, stdin);  // Lê o novo CPF do professor
            printf("Novo Nome\t> ");
            fgets(professor->nome, 49, stdin);  // Lê o novo nome do professor
            professor->endereco = construir_endereco();  // Chama a função para construir um novo endereço para o professor
            printf("Professor atualizado!\n");  // Exibe uma mensagem informando que o professor foi atualizado com sucesso
        }
        else
        {
            printf("Professor nao encontrado!!\n");  // Exibe uma mensagem informando que o professor não foi encontrado
        }
    }
    break;
    case 4:
    {
        int posicao = 0;
        professor = buscar_professor(professores, &posicao);  // Chama a função para buscar um professor
        if (professor)
        {
            destruirProfessor(professor);  // Chama a função para destruir o professor encontrado
            professores[posicao] = NULL;  // Define a posição do professor como NULL na lista de professores
            printf("Professor destruido\n");  // Exibe uma mensagem informando que o professor foi destruído com sucesso
        }
        else
        {
            printf("Professor nao encontrado!!\n");  // Exibe uma mensagem informando que o professor não foi encontrado
        }
    }
    break;
    default:
        printf("Retornando ao menu principal\n");  // Exibe uma mensagem informando que o programa está retornando ao menu principal
        break;
    }
}

// Função para construir um objeto Endereco
Endereco *construir_endereco()
{
    Endereco endereco;

    printf("Logradouro\t> ");  // Solicita o logradouro ao usuário
    fgets(endereco.logradouro, 49, stdin);  // Lê o logradouro do usuário
    printf("Bairro\t> ");  // Solicita o bairro ao usuário
    fgets(endereco.bairro, 49, stdin);  // Lê o bairro do usuário
    printf("Cidade\t> ");  // Solicita a cidade ao usuário
    fgets(endereco.cidade, 49, stdin);  // Lê a cidade do usuário
    printf("Estado\t> ");  // Solicita o estado ao usuário
    fgets(endereco.estado, 9, stdin);  // Lê o estado do usuário
    printf("Número\t> ");  // Solicita o número ao usuário
    fgets(endereco.numero, 9, stdin);  // Lê o número do usuário
    
    // Cria um objeto Endereco usando os valores fornecidos pelo usuário
    return criarEndereco(endereco.logradouro, endereco.bairro, endereco.cidade, endereco.estado, endereco.numero);
}

// Função para construir um objeto Aluno
Aluno *construir_aluno()
{
    Aluno aluno;
    printf("Matricula\t> ");  // Solicita a matrícula ao usuário
    fgets(aluno.matricula, 9, stdin);  // Lê a matrícula do usuário
    printf("CPF\t> ");  // Solicita o CPF ao usuário
    fgets(aluno.cpf, 9, stdin);  // Lê o CPF do usuário
    printf("Nome\t> ");  // Solicita o nome ao usuário
    fgets(aluno.nome, 49, stdin);  // Lê o nome do usuário
    aluno.endereco = construir_endereco();  // Chama a função construir_endereco() para obter o endereço do aluno
    return criarAluno(aluno.matricula, aluno.cpf, aluno.nome, aluno.endereco);
}

// Função para buscar um aluno pelo número de matrícula
Aluno *buscar_aluno(Aluno **alunos, int *posicao)
{
    char matricula[50];
    printf("Matricula > ");  // Solicita a matrícula ao usuário
    fgets(matricula, 49, stdin);  // Lê a matrícula do usuário
    Aluno *resultado = NULL;
    int pos_resultado = -1;
    for (int i = 0; i < MAX_ALUNO; i++)
    {   
        // Verifica se o aluno existe e se a matricula buscada é igual à matricula do aluno atual
        // strcmp compara strings. Se for 0, indica que são iguais
        if (alunos[i] && !strcmp(matricula, alunos[i]->matricula))
        {
            resultado = alunos[i];
            break;
        }
    }
    *posicao = pos_resultado;
    return resultado;
}

//////////////////////////////////////
void tratador_menu_turmas(Turmas** turmas, int* qtd_atual_turmas)
{
    int opcao = menu_crud_turma();  // Chama a função para exibir o menu de operações das turmas e obter a opção selecionada
    Turmas* turma = NULL;
    switch (opcao)
    {
    case 1:
        if (*qtd_atual_turmas >= MAX_TURMA)
        {
            printf("Número máximo de turmas atingido\n");  // Exibe uma mensagem informando que o número máximo de turmas foi atingido
        }
        else
        {
            // Passo 1: buscar posicao disponível
            int i = 0;
            for (; i < *qtd_atual_turmas; i++)
            {
                if (turmas[i] != NULL)
                {
                    // significa que esta posição está livre para uso
                    break;
                }
            }
            Turmas* turma = construir_turma();  // Chama a função para construir uma nova turma
            turmas[i] = turma;  // Armazena a nova turma na lista de turmas
            *qtd_atual_turmas++;  // Incrementa a quantidade atual de turmas
        }
        break;
    case 2:
    {
        int posicao = 0;
        turma = buscar_turma(turmas, &posicao);  // Chama a função para buscar uma turma
        if (turma)
        {
            imprimir_turma(turma);  // Chama a função para imprimir os dados da turma encontrada
        }
        else
        {
            printf("Turma nao encontrada!!\n");  // Exibe uma mensagem informando que a turma não foi encontrada
        }
    }
    break;
    case 3:
    {
        int posicao = 0;
        turma = buscar_turma(turmas, &posicao);  // Chama a função para buscar uma turma
        if (turma)
        {
            imprimir_turma(turma);  // Chama a função para imprimir os dados da turma encontrada
            printf("Atualizar turma\n");
            printf("Novo Codigo\t> ");
            fgets(turma->codigo, 9, stdin);  // Lê o novo código da turma
            printf("Novo Nome\t> ");
            fgets(turma->disciplina, 49, stdin);  // Lê o novo nome da turma
            printf("Turma atualizada!\n");  // Exibe uma mensagem informando que a turma foi atualizada com sucesso
        }
        else
        {
            printf("Turma nao encontrada!!\n");  // Exibe uma mensagem informando que a turma não foi encontrada
        }
    }
    break;
    case 4:
    {
        int posicao = 0;
        turma = buscar_turma(turmas, &posicao);  // Chama a função para buscar uma turma
        if (turma)
        {
            destruirTurma(turma);  // Chama a função para destruir a turma encontrada
            turmas[posicao] = NULL;  // Define a posição da turma como NULL na lista de turmas
            printf("Turma destruida\n");  // Exibe uma mensagem informando que a turma foi destruída com sucesso
        }
        else
        {
            printf("Turma nao encontrada!!\n");  // Exibe uma mensagem informando que a turma não foi encontrada
        }
    }
    break;
    default:
        printf("Retornando ao menu principal\n");  // Exibe uma mensagem informando que o programa está retornando ao menu principal
        break;
    }
}

// Função que lida com o menu de estatísticas
void tratador_menu_estatisticas(Aluno** alunos, int numAlunos, Professor** professores, int numProfessores, Turmas** turmas, int numTurmas)
{
    int opcao = menu_estatistica();
    switch (opcao)
    {
    case 1:
        listarProfessores(&professores, numProfessores);
        break;
    case 2:
        listarProfessoresSemTurmas(&professores, numProfessores, turmas, numTurmas);
        break;
    case 3:
        calcularMediaGeralTurmas(&turmas, numTurmas);
        break;
    default:
        printf("Opcao invalida!!\n");
        break;
    }
}

// Função para imprimir as informações de um aluno
void imprimir_aluno(Aluno *aluno)
{
    printf("Matricula: %s", aluno->matricula);  // Imprime a matrícula do aluno
    printf("Nome: %s", aluno->nome);  // Imprime o nome do aluno
    printf("CPF: %s", aluno->cpf);  // Imprime o CPF do aluno
    imprimir_endereco(aluno->endereco);  // Chama a função para imprimir o endereço do aluno
}

// Função para imprimir as informações de um endereço
void imprimir_endereco(Endereco *endereco)
{
    printf("Logradouro: %s", endereco->logradouro);  // Imprime o logradouro do endereço
    printf("Numero: %s", endereco->numero);  // Imprime o número do endereço
    printf("Bairro: %s", endereco->bairro);  // Imprime o bairro do endereço
    printf("Cidade: %s", endereco->cidade);  // Imprime a cidade do endereço
    printf("Estado: %s", endereco->estado);  // Imprime o estado do endereço
}

// Função para construir um objeto Professor
Professor *construir_professor()
{
    Professor professor;
    printf("Matrícula\t> ");  // Solicita a matrícula ao usuário
    fgets(professor.matricula, 9, stdin);  // Lê a matrícula do usuário
    printf("CPF\t> ");  // Solicita o CPF ao usuário
    fgets(professor.cpf, 9, stdin);  // Lê o CPF do usuário
    printf("Nome\t> ");  // Solicita o nome ao usuário
    fgets(professor.nome, 49, stdin);  // Lê o nome do usuário
    printf("Endereço\t> \n");  // Imprime a mensagem para o usuário inserir o endereço
    professor.endereco = construir_endereco();  // Chama a função para construir o endereço do professor
    
    // Cria um objeto Professor usando os valores fornecidos pelo usuário
    return criarProfessor(professor.matricula, professor.cpf, professor.nome, professor.endereco);
}


// Função para buscar um professor pela matrícula
Professor *buscar_professor(Professor **professores, int *posicao)
{
    char matricula[50];
    printf("Matricula > ");  // Solicita a matrícula ao usuário
    fgets(matricula, 49, stdin);  // Lê a matrícula do usuário
    Professor *resultado = NULL;
    int pos_resultado = -1;
    for (int i = 0; i < MAX_PROFESSOR; i++)
    {
        // Verifica se o professor existe e se a matricula buscada é igual à matricula do professor atual
        // strcmp compara strings. Se for 0, indica que são iguais
        if (professores[i] && !strcmp(matricula, professores[i]->matricula))
        {
            resultado = professores[i];
            break;
        }
    }
    *posicao = pos_resultado;
    return resultado;
}

// Função para imprimir as informações de um professor
void imprimir_professor(Professor *professor)
{
    printf("Matricula: %s", professor->matricula);  // Imprime a matrícula do professor
    printf("Nome: %s", professor->nome);  // Imprime o nome do professor
    printf("CPF: %s", professor->cpf);  // Imprime o CPF do professor
    imprimir_endereco(professor->endereco);  // Chama a função para imprimir o endereço do professor
}


// Função que lida com o menu CRUD de professores
void tratador_menu_prof(Professor **professores, int *qtd_atual_prof)
{
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

// Função para listar os professores
void listarProfessores(const Professor* professores, int numProfessores)
{
    printf("Lista de professores:\n");
    for (int i = 0; i < numProfessores; i++)
    {
        printf("Professor %d:\n", i + 1);
        printf("Matrícula: %d\n", professores[i].matricula);
        printf("CPF: %s\n", professores[i].cpf);
        printf("Nome: %s\n", professores[i].nome);
    }
}

// Função para listar os professores sem turmas
void listarProfessoresSemTurmas(const Professor* professores, int numProfessores, const Turmas* turmas, int numTurmas)
{
    printf("Matrículas dos professores sem turmas:\n");
    for (int i = 0; i < numProfessores; i++)
    {
        int possuiTurma = 0;
        for (int j = 0; j < numTurmas; j++)
        {
            if (turmas[j].matricula_professor_responsavel == professores[i].matricula)
            {
                possuiTurma = 1;
                break;
            }
        }
        if (!possuiTurma)
        {
            printf("Matrícula: %d\n", professores[i].matricula);
        }
    }
}

// Função para calcular a média geral das turmas
void calcularMediaGeralTurmas(const Turmas* turmas, int numTurmas)
{
    float somaNotas = 0;
    int numTurmasValidas = 0;
    int i = 0;
    int notaMedia = atoi(turmas[i].media_turma);
    for (int i = 0; i < numTurmas; i++)
    {
        if (notaMedia != 0)
        {
            somaNotas += notaMedia;
            numTurmasValidas++;
        }
    }
    if (numTurmasValidas > 0)
    {
        float mediaGeral = somaNotas / numTurmasValidas;
        printf("Média geral das turmas: %.2f\n", mediaGeral);
    }
    else
    {
        printf("Não há turmas cadastradas com notas.\n");
    }
}


// Função para lidar com o menu principal
void tratador_menu_principal(Aluno** alunos, int* numAlunos, Professor** professores, int* numProfessores, Turmas** turmas, int* numTurmas)
{
    int opcao = menu_principal();
    switch (opcao)
    {
    case 1:
        tratador_menu_aluno(alunos, numAlunos);
        break;
    case 2:
        tratador_menu_prof(professores, numProfessores);
        break;
    case 3:
        tratador_menu_turmas(turmas, numTurmas, professores, numProfessores);
        break;
    case 4:
        tratador_menu_estatisticas(alunos, *numAlunos, professores, *numProfessores, turmas, *numTurmas);
        break;
    default:
        printf("Saindo do programa\n");
    }
}
