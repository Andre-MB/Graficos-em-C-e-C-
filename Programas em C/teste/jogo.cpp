#include <stdio.h>

int main () {
    float a, b, h;

    printf ("Qual o valor da base ? \n");
    scanf  ("%f", &b);

    printf ("Qual o valor da altura ? \n");
    scanf  ("%f", &h);

    a = b * h / 2;

    printf  ("area = %.2f \n",a);

    return 0;
}
