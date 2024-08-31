#include <stdio.h>

#include <stdlib.h>



int main()

{

    float N1,N2,N3,N4,notaPonderada,EX;



    printf("Qual a primeira nota ?");

    scanf("%f", &N1);



    printf("Qual a segunda nota ?");

    scanf("%f", &N2);



    printf("Qual a terceira nota ?");

    scanf("%f", &N3);



    printf("Qual a quarta nota ?");

    scanf("%f", &N4);



    notaPonderada = ( N1 * 2 + N2 * 3 + N3 * 4 + N4 * 1 ) / 10;



    if ( notaPonderada >= 7) {

        printf("Aluno foi aprovado");

    }

    else if (notaPonderada <= 5) {

        printf("Aluno foi reprovado");

    }

    else if (notaPonderada < 7 && notaPonderada > 5) {



        printf("Qual a nota do exame ?");

        scanf("%f",&EX);



        float resultado = (EX + notaPonderada) / 2;



        if ( resultado >= 7) {

            printf("Aluno foi aprovado");

        }else {

            printf("Aluno foi reprovado");

        }

    }

}

