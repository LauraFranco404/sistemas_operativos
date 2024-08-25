#include <stdio.h>

int uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}


void menu(){
	int opcion;
	do{
		printf("----------------MENU------------------------\n");
		printf("1. Determinar si una letra es mayuscula\n");
		printf("0. Salir.\n");
		printf("Digite el numero del procedimiento a realizar: ");
		scanf("%d", &opcion);
		printf("\n");
		int n;
		char c;
		switch(opcion){
			case 1:
				printf("Ingrese una letra: "); scanf(" %c", &c);
				printf(uppercase(c) == 1 ? "La letra es mayuscula\n" : "No es una letra mayuscula\n");
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