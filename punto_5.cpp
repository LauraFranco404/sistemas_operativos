#include <stdio.h>

//Punto 5

int my_pow(int n, int exp)
{
	int ans = 1;
	if (exp != 0){
		ans = n*my_pow(n, exp-1);
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