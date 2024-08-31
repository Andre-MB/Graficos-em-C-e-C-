#include <stdio.h>

int main()
{
    int idade;
	char str[50];
	float altura;

	printf("Qual é a sua idade ?");
	scanf ("%i", &idade);
	fgets( str,50,stdin);

	printf("Qual é o seu nome ?");
	fgets( str,50,stdin);


	printf( "meu nome é %s, minha idade é %i, minha altura é %f \n", str, idade, altura );

	return 0;
}
