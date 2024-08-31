#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome[10];
    int dep;
    float sal,salnovo;

    printf("Qual é o seu nome ?");
    fgets(nome,10,stdin);

    printf("Qual o seu salario ?");
    scanf("%f", &sal);

    printf("Quantos depedentes ?");
    scanf("%i", &dep);

    if (sal< 2000 && dep>2){
        salnovo = sal + (25.5 * sal)/100;
    }

    else if ( sal > 2000 && dep == 1 ){
        salnovo = sal + (15 * sal)/100;
    }

    else if (dep==0) {
        salnovo = sal + (7.5 * sal)/100;
    }

    printf("O seu nome e %s e o seu salario novo e %f",nome,salnovo);


    return 0;
}

