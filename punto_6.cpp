#include <stdio.h>

//Punto 6 Retorna 1 si es par, de lo contrario 0
int par(int val){
	return val%2 == 0;
}

void menu(){
	int opcion;
	do{
		printf("----------------MENU------------------------\n");
		printf("1. Verificar si un numero es par o impar\n");
		printf("0. Salir.\n");
		printf("Digite el numero del procedimiento a realizar: ");
		scanf("%d", &opcion);
		printf("\n");
		int n;
		char c;
		switch(opcion){
			case 1:
				printf("Ingrese un numero: "); scanf("%d", &n);
				printf(par(n) == 1? "Es par\n":"Es impar\n");
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