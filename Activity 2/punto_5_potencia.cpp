#include <stdio.h>

//Punto 5

//calcula x^n con un algoritmo O(log(n)) con n >= 0
int my_pow(int x, int n)
{
	int ans = 1;
	if (n > 0 && n % 2 == 0)
	{
		ans = my_pow(x*x, n / 2);
	}else if (n > 0 && n % 2 != 0)
	{
		ans = x*my_pow(x, n-1);
	}
	return ans;
}


void menu(){
	int opcion;
	do{
		printf("----------------MENU------------------------\n");
		printf("1. Calcular potencia de un numero.\n");
		printf("0. Salir.\n");
		printf("Digite el numero del procedimiento a realizar: ");
		scanf("%d", &opcion);
		printf("\n");
		int n;
		char c;
		switch(opcion){
			case 1:
				int pot;
				printf("Ingrese el numero y la potencia separados por espacioes: \n (Ejemplo: 10 3)\n"); scanf("%d %d", &n, &pot);
				printf("%d elevado a %d = %d\n", n, pot, my_pow(n, pot));
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