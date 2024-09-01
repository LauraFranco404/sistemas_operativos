#include <stdio.h>

int lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

void menu(){
	int opcion;
	do{
		printf("----------------MENU------------------------\n");
		printf("1. Determinar si una letra es minuscula\n");
		printf("0. Salir.\n");
		printf("Digite el numero del procedimiento a realizar: ");
		scanf("%d", &opcion);
		printf("\n");
		int n;
		char c;
		switch(opcion){
			case 1:
				printf("Ingrese una letra: "); scanf(" %c", &c);
				printf(lowercase(c) == 1 ? "La letra es minuscula\n" : "No es una letra minuscula\n");
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