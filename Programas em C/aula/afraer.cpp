#include <stdio.h>
#include <stdlib.h>

int main()
{
    int idade;
    char nome[30];
    float altura;

    printf("Qual suas idade ? \n");
    scanf("%i", &idade);

    printf("Qual seu nome ? \n");
    scanf("%s", &nome);

    printf("Qual a sua altura ? \n");
    scanf("%f", &altura);

    printf("minha idade = %i, meu nome = %s, minha altura = %.2f", idade, nome, altura);

    return 0;
}

