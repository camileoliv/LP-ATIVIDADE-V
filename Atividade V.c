#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

#define TAM 100

struct produto
{
    char nome[200];
    float preco;
    int estoque;
};

struct dados
{
    char nome[200];
    float preco;
    int estoqueA;
};

void automatizacao(int estoqueA, int vendasQuan)
{
    int estoqueAtualizado;
    estoqueAtualizado = estoqueA - vendasQuan;
    printf("Em estoque: %d \n", estoqueAtualizado);
}

int main()
{
    // Declarando Variáveis
    struct produto entrada[TAM];
    struct produto saida[TAM];
    struct dados atual[TAM];

    int code, quantidade, contador, i, j, g, vendasDaily, vendasQuan, funcionarios;
    char diaReferencia[10], nomeF[200], identificacao[200];
    float ganhos;

    setlocale(LC_ALL, "portuguese");

    do
    {

        printf("Sistema de gerenciamento.\n");
        printf("1- Entrada de produtos. \n");
        printf("2- Saída de produtos. \n");
        printf("3- Inventário. \n");
        printf("4- Funcionários presentes no site. \n");
        printf("5- Sair do programa. \n");
        printf("Resposta: ");
        scanf("%i", &code);
        system("cls || clear");

        switch (code)
        {
        case 1:
            printf("Digite a quantidade de produtos: ");
            scanf("%i", &quantidade);

            for (i = 0; i < quantidade; i++)
            {
                fflush(stdin);
                printf("Digite o %iº produto: ", i + 1);
                gets(entrada[i].nome);
                strcpy(atual[i].nome, entrada[i].nome);

                printf("Digite o preço do %iº produto: ", i + 1);
                scanf("%f", &entrada[i].preco);
                atual[i].preco = entrada[i].preco;

                printf("Digite a quantidade do %iº produto: ", i + 1);
                scanf("%i", &entrada[i].estoque);
                atual[i].estoqueA = entrada[i].estoque;

                system("cls || clear");
                contador++;
            }
            break;

        case 2:
            fflush(stdin);
            printf("Total de produtos vendidos: ");
            scanf("%d", &vendasDaily);

            fflush(stdin);

            printf("Dia de referência (DD/MM/AAAA): ");
            gets(diaReferencia);

            printf("Ganhos totais: ");
            scanf("%f", &ganhos);

            for (j = 0; j < vendasDaily; j++)
            {
                fflush(stdin);

                printf("Qual o nome do %iº produto? ", j + 1);
                gets(saida[j].nome);

                fflush(stdin);

                if (strcmp(saida[j].nome, entrada[j].nome) == 0)
                {
                    printf("Digite a quantidade vendida: ");
                    scanf("%i", &vendasQuan);
                }
                else
                {
                    printf("Produto inválido.");
                }
                break;
            }

            system("cls || clear");

            break;

        case 3:
            fflush(stdin);
            for (i = 0; i < contador; i++)
            {
                printf("Produto: %s\n", atual[i].nome);
                printf("Preço: %.2f\n", atual[i].preco);
                automatizacao(atual[i].estoqueA, vendasQuan);
            }
            break;

        case 4:
            fflush(stdin);
            printf("Quadro de funcionários. \n");

            printf("Quantidade de funcionários trabalhando no estoque: ");
            scanf("%d", &funcionarios);

            for (g = 0; g < funcionarios; g++)
            {
                fflush(stdin);

                printf("Nome do %d funcionário: ", g + 1);
                gets(nomeF);

                fflush(stdin);

                printf("Identificação do crachá: ");
                gets(identificacao);

                printf("\n");
            }

            system("cls || clear");

            break;

        default:
            break;
        }
    } while (code != 5);

    return 0;
}
