#include "tratadores.h"
#include "menus.h"
#include <stdio.h>
#include "constantes.h"
#include <string.h>
#include "dados.h"

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
            printf("Aluno não encontrado!!\n");
        }
    }
    break;
    case 3:
    {
        int posicao = 0;
        Atualizar_aluno *atualizarAluno = NULL;
        atualizarAluno = buscar_aluno(alunos, &posicao);
        if (aluno)
        {
            // Atualiza as informações do aluno 
            printf("Nova matrícula: ");
            fgets(aluno->matricula, 9, stdin);
            
            printf("Novo CPF: ");
            fgets(aluno->cpf, 11, stdin);
        
            printf("Novo nome: ");
            fgets(aluno->nome, 49, stdin);
        
            printf("Aluno atualizado com sucesso!\n");
        }
        else
        {
            printf("Aluno não encontrado!\n");
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
            printf("Aluno não encontrado!!\n");
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
    printf("Matrícula\t> ");
    fgets(aluno.matricula, 9, stdin);
    printf("CPF\t> ");
    fgets(aluno.cpf, 9, stdin);
    printf("Nome\t> ");
    fgets(aluno.nome, 49, stdin);
    aluno.endereco = construir_endereco();
    return criarAluno(aluno.matricula, aluno.cpf, aluno.nome, aluno.endereco);
}

Atualizar_aluno *atualizarAluno()
{
    Atualizar_aluno atualizarAluno;
    // Atualiza as informações do aluno 
    printf("Nova matrícula: \t> ");
    fgets(aluno.matricula, 9, stdin);
    printf("CPF\t> ");
    fgets(aluno.cpf, 9, stdin);
    printf("Nome\t> ");
    fgets(aluno.nome, 49, stdin);
    Atualizar_aluno.endereco = construir_endereco();
    return atualizarAluno(aluno.matricula, aluno.cpf, aluno.nome, aluno.endereco);
}

Aluno *buscar_aluno(Aluno **alunos, int *posicao)
{
    char matricula[50];
    printf("Matrícula > ");
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

void imprimir_aluno(Aluno *aluno)
{
    printf("Matrícula: %s", aluno->matricula);
    printf("Nome: %s", aluno->nome);
    printf("CPF: %s", aluno->cpf);
    imprimir_endereco(aluno->endereco);
}

void imprimir_endereco(Endereco *endereco)
{
    printf("Logradouro: %s", endereco->logradouro);
    printf("Número: %s", endereco->numero);
    printf("Bairro: %s", endereco->bairro);
    printf("Cidade: %s", endereco->cidade);
    printf("Estado: %s", endereco->estado);
}

void imprimir_aluno_atualizado(Atualizar_aluno *atualizarAluno)
{
    printf("Matrícula: %s", atualizarAluno->matricula);
    printf("Nome: %s", atualizarAluno->nome);
    printf("CPF: %s", atualizarAluno->cpf);
    imprimir_endereco(atualizarAluno->endereco);
}
