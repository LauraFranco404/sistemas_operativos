#include <stdio.h>

int fact(int x){
	int ans = 1;
	if (x == 0){
		return 1;
	}
	else{
		return x * fact(x - 1);
	}
}

void menu(){
	int opcion;
	
	do{
		
		int x;
		
		printf("-----MENU-----\n");
		printf("1. Calcular factorial.\n");
		printf("0. Salir.\n");
		printf("Digite el numero del procedimiento a realizar: ");
		scanf("%d", &opcion);
		printf("\n");
		
		switch(opcion){
			case 1:
				printf("Ingrese el numero: ");
				scanf("%d", &x);
				printf("\n");
				printf("Factorial de  %d = %d\n", x, fact(x));
				printf("\n");

				break;
			case 0:
				printf("----OFF----\n");
				break;
			default:
				printf("Opcion invalida.\n");
				break;
		}
		
	}while(opcion != 0);	
}

int main(){
	
	menu();
	
	return 0;
}