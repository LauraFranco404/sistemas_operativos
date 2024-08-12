#include <stdio.h>
//Punto 2 retorna 1 si es primo, 0 de lo contrario.
int my_pow(int n, int exp)
{
	int ans = 1;
	if (exp != 0){
		ans = n*my_pow(n, exp-1);
	}
	return ans;
}

void printWBase(int n, int base)
{
	if (base == 8){
		int div = (int)n/base;
		printf("%d, ", div*my_pow(10,div) + (n%base));
	}
	else if (base == 10){
		printf("%d, ", n);
	}
	else if (base == 16){
		char arr [] = {'A', 'B', 'C', 'D', 'E', 'F'};

		if (n < 10){printf("%d, ", n, base, n);}
		else { printf("%c, ", arr[n-10]); }
			
	}
	else
	{
		printf("Error en la base");
	}
}

void menu(){
	int opcion;
	do{
		printf("----------------MENU------------------------\n");
		printf("1. Numeros en otra base.\n");
		printf("0. Salir.\n");
		printf("Digite el numero del procedimiento a realizar: ");
		scanf("%d", &opcion);
		printf("\n");
		int n;
		char c;
		switch(opcion){
			case 1:
				printf("Ingrese una de las bases 8, 10, 16: \n(Ejemplo:8)\n"); scanf(" %d", &n);
				printf("Numeros del 1 al 10 en base %d: \n [", n);
				for (int i = 1; i<11; i++)
				{
					printWBase(i, n);
				}
				printf("]\n");
				break;
			case 0:
				printf("----OFF----\n");
				break;
			default:
				printf("Opcion invalida.\n");
				break;
		}
		printf("\n");

	}while(opcion != 0);	
}
int main(){
	
	menu();

	return 0;
}