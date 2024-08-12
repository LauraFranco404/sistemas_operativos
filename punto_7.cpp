#include <stdio.h>
int fibonacci(int n)
{
	if (n == 0){
		return 0;
	}
	else if (n == 1){
		return 1;
	}
	return fibonacci(n-2) + fibonacci(n-1);	
}

void menu(){
	int opcion;
	do{
		printf("----------------MENU------------------------\n");
		printf("1. Calcular la serie de fibonacci.\n");
		printf("0. Salir.\n");
		printf("Digite el numero del procedimiento a realizar: ");
		scanf("%d", &opcion);
		printf("\n");
		int n;
		char c;
		switch(opcion){
			case 1:
				printf("Ingrese el numero: "); scanf("%d", &n);
				for(int i = 0; i<=n; i++){
					printf("Fibonacci de  de  %d = %d\n", i, fibonacci(i));
				}
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