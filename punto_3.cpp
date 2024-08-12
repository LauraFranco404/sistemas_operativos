#include <stdio.h>

//Punto 3 
int leapyear(int year) { 
	return year%4 == 0;
}

void menu(){
	int opcion;
	do{
		printf("----------------MENU------------------------\n");
		printf("1. Verificar si un anio es bisiesto\n");
		printf("0. Salir.\n");
		printf("Digite el numero del procedimiento a realizar: ");
		scanf("%d", &opcion);
		printf("\n");
		int n;
		char c;
		switch(opcion){
			case 1:
				printf("Ingrese un anio: "); scanf("%d", &n);
				printf(leapyear(n) == 1? "Es bisiesto\n":"No es bisiesto\n");
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