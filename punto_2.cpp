#include <stdio.h>
//Punto 2 retorna 1 si es primo, 0 de lo contrario.

int prime(int n){
	int count = 0;
	for (int i = 1; i<n; i++)
	{
		if (n % i == 0) { 
			count++;
		}
	}
	return count <= 1;
}
void menu(){
	int opcion;
	do{
		printf("----------------MENU------------------------\n");
		printf("1. Verificar si un numero es primo\n");
		printf("0. Salir.\n");
		printf("Digite el numero del procedimiento a realizar: ");
		scanf("%d", &opcion);
		printf("\n");
		int n;
		char c;
		switch(opcion){
			case 1:
				printf("Ingrese un numero: "); scanf("%d", &n);
				printf(prime(n) == 1? "Es primo\n":"No es primo\n");

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