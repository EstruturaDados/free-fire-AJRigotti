#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//definindo uma variavel para o numero max de caracteres em uma string
#define max_str 50

//definindo e estrutura de um item
struct itens
{
    char nome_item [max_str];
    char tipo_item [max_str];
    int numero_item;
};

int main(){

    //criando nossa mochila com 10 itens
    struct itens mochila[10];

    int quantidade_itens = 0; //definindo uma variavel pra dizer quantos itens tem na mochila

    int opcao_menu; //variavel que armazena a opcao escolhida do menu

    int item_procurado; //variavel para procurar o item para ser removido

    bool encontrado = false; //variavel para definir se o item foi encontrado ou nao


    //usando o do para exibir o menu varias vezes ate o usuario decidir sair
    do
    {
        printf("----------------Bem vindo!!----------------\n");
        printf("Escolha uma das opcoes abaixo para organizar sua mochila:\n");
        printf("\n");

        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Sair\n");
        printf("\n");

        printf("Digite uma opcao:\n");

        //para evitar que fique em loop infinito caso o usuario digite algo diferente de um numero
        if (scanf("%d", &opcao_menu) != 1) 
        {
        printf("Entrada invalida! Digite apenas numeros\n");
        printf("\n");
        while (getchar() != '\n'); //limpa o caractere do scanf
        continue;
        }



        switch (opcao_menu)
    {
    case 1:
        
        if (quantidade_itens < 10)
        {
            printf("----------------Vamos adicionar um item!----------------\n");
            printf("\n");
            printf("Qual sera o nome do seu item?\n");
            scanf("%s", mochila[quantidade_itens].nome_item);

            printf("Qual é o tipo do seu item?\n");
            scanf("%s", mochila[quantidade_itens].tipo_item); 

            printf("Qual o numero desse item?\n"); 
            scanf("%d", &mochila[quantidade_itens].numero_item); 

            printf("Perfeito! seu item foi adicionado\n");
            printf("\n");
            
            quantidade_itens++;

        }   else{
            printf("Sua mochila esta cheia! Nao foi possivel adicionar o item\n");
        }
        
        break;

    case 2:

        printf("----------------Vamos remover um item!----------------\n");
        printf("\n");

        printf("Qual o numero do item que voce quer remover?\n");
        if (scanf("%d", &item_procurado) != 1) //caso seja digitado algo diferente de numeros
        {
        printf("Entrada invalida. Voltando ao menu.\n");
        break;
        }

        printf("Procurando o item...\n");
        

        for (int i = 0; i < quantidade_itens; i++)
        {
            if (mochila[i].numero_item == item_procurado)
            {
                mochila[i] = mochila[quantidade_itens - 1];
                quantidade_itens--;
                encontrado = true;

                printf("Item removido!\n");
            }

        }
        
        if (encontrado == false)
        {
            printf("O item nao foi encontrado, portanto, nao foi removido.\n");
        }

        printf("\n");
        
        break;

    case 3:
        printf("----------------Lista dos seus itens:----------------");
        printf("\n");

        if (quantidade_itens == 0)
        {
            printf("Sua mochila esta vazia!\n");
        } else {

            for (int i = 0; i < quantidade_itens; i++)
            {
                printf("Item %d - Nome: %s \n", i + 1, mochila[i].nome_item);
                printf("Item %d - Tipo: %s \n", i + 1, mochila[i].tipo_item);
                printf("Item %d - Numero: %d \n", i + 1, mochila[i].numero_item);
                printf("\n");
            }
            
        }
        
        break;

    case 4:
    
        printf("Saindo do programa...\n");

        break;

    default:

        printf("Digite uma opcao valida\n");

        break;
    
    }

    } while (opcao_menu != 4);
    
    return 0;
}