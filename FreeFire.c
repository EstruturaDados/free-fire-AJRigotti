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

    //definindo uma variavel pra dizer quantos itens tem na mochila
    int quantidade_itens = 0;

    //variavel que armazena a opcao escolhida do menu
    int opcao_menu;

    //usando o do para exibir o menu varias vezes ate o usuario decidir sair
    do
    {
        printf("Bem vindo!!\n");
        printf("Escolha uma das opcoes abaixo para organizar sua mochila:\n");
        printf("\n");

        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Sair\n");
        printf("\n");

        printf("Digite uma opcao:\n");
        scanf("%d", &opcao_menu);


        //para evitar que fique em loop infinito caso o usuario digite algo diferente de um numero
        if (scanf("%d", &opcao_menu) != 1) 
        {
        printf("Entrada invalida! Digite apenas numeros\n");
        printf("\n");
        while (getchar() != '\n'); //limpa o caractere do scanf
        }
        continue;


        switch (opcao_menu)
    {
    case 1:
        
        if (quantidade_itens <= 10)
        {
            printf("Vamos adicionar um item!\n");
            printf("\n");
            printf("Qual sera o nome do seu item?\n");
            scanf("%s", &mochila[quantidade_itens].nome_item);

            printf("Qual é o tipo do seu item?\n");
            scanf("%s", &mochila[quantidade_itens].tipo_item); 

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

        break;

    case 3:

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