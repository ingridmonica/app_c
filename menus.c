#include "menus.h"  // Inclui o arquivo de cabeçalho "menus.h"
#include <stdio.h>  // Inclui a biblioteca de entrada/saída padrão

int menu_principal()
{
    int opcao = 0;  // Declara e inicializa a variável 'opcao' com o valor 0

    do
    {
        printf("== Menu principal==\n\n");  // Exibe o título do menu principal
        printf("1 - Menu aluno\n");  // Exibe a opção para acessar o menu de aluno
        printf("2 - Menu professor\n");  // Exibe a opção para acessar o menu de professor
        printf("3 - Menu turma\n");  // Exibe a opção para acessar o menu de turma
        printf("4 - Estatisticas\n");  // Exibe a opção para acessar o menu de estatísticas
        printf("5 - Sair\n");  // Exibe a opção para sair do programa
        printf("Opcao > ");  // Solicita ao usuário que digite a opção desejada
        scanf("%d", &opcao);  // Lê a opção digitada pelo usuário e a armazena na variável 'opcao'
        getchar();  // Consome o caractere de nova linha deixado pelo 'scanf()'

        if (opcao > 0 && opcao < 6)  // Verifica se a opção selecionada está entre 1 e 5 (inclusive)
        {
            return opcao;  // Retorna a opção selecionada
        }
        else
        {
            printf("Opcao inválida!! Tente novamente\n\n");  // Exibe uma mensagem de erro para uma opção inválida
        }
    } while (1);  // Loop infinito para garantir que o menu seja exibido até que uma opção válida seja selecionada
}

int menu_crud_aluno()
{
    int opcao = 0;
    do
    {
        printf("== Menu aluno==\n\n");
        printf("1 - Criar aluno\n");
        printf("2 - Ler aluno\n");
        printf("3 - Atualizar aluno\n");
        printf("4 - Deletar aluno\n");
        printf("5 - Voltar menu anterior\n");
        printf("Opcao > ");
        scanf("%d", &opcao);
        getchar();
        if (opcao > 0 && opcao < 6)
        {
            return opcao;
        } else {
        printf("Opcao inválida!! Tente novamente\n\n");
        }
    } while (1);
}

int menu_crud_professor()
{
    int opcao = 0;
    do
    {
        printf("== Menu professor==\n\n");
        printf("1 - Criar professor\n");
        printf("2 - Ler professor\n");
        printf("3 - Atualizar professor\n");
        printf("4 - Deletar professor\n");
        printf("5 - Voltar menu anterior\n");
        printf("Opcao > ");
        scanf("%d", &opcao);
        getchar();
        if (opcao > 0 && opcao < 6)
        {
            return opcao;
        }
        printf("Opcao inválida!! Tente novamente\n\n");

    } while (1);
}

int menu_crud_turma()
{
    int opcao = 0;
    do
    {
        printf("== Menu turma==\n\n");
        printf("1 - Criar turma\n");
        printf("2 - Ler turma\n");
        printf("3 - Atualizar turma\n");
        printf("4 - Deletar turma\n");
        printf("5 - Voltar menu anterior\n");
        printf("Opcao > ");
        scanf("%d", &opcao); 
        getchar();
        if (opcao > 0 && opcao < 6)
        {
            return opcao;
        } else {
        printf("Opcao inválida!! Tente novamente\n\n");}

    } while (1);
}

int menu_estatistica()
{
    int opcao = 0;
    do
    {
        printf("== Menu estatisticas==\n\n");
        printf("1 - Lista de Professores\n");
        printf("2 - Professores sem turma\n");
        printf("3 - Media de notas geral\n");
        printf("4 - Voltar menu anterior\n");
        printf("Opcao > ");
        scanf("%d", &opcao);
        getchar();
        if (opcao > 0 && opcao < 4)
        {
            return opcao;
        }
        printf("Opcao inválida!! Tente novamente\n\n");

    } while (1);
}
