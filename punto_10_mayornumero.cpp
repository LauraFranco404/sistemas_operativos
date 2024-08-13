#include <stdio.h>

//Calcula el mayor de los numeros x, y, z
int mayor(int x, int y, int z){
	
	int A[3];
	
	A[0] = x; A[1] = y; A[2] = z;
	
	int max = -(1<<31-1); //minimo entero posible
	
	for (int i=0; i < 3; i++ ){
		if (max < A[i]){
			max = A[i];
		}
	}
		
	return max;
		
}

void menu(){
	int opcion;
	
	do{
		
		int x; int y; int z;
		
		printf("-----MENU-----\n");
		printf("1. Buscar mayor entre tres numeros.\n");
		printf("2. Salir.\n");
		printf("Digite el numero del procedimiento a realizar: ");
		scanf("%d", &opcion);
		printf("\n");
		
		switch(opcion){
			case 1:
				printf("Digite el primer numero: ");
				scanf("%d", &x);
				printf("Digite el segundo numero: ");
				scanf("%d", &y);
				printf("Digite el tercer numero: ");
				scanf("%d", &z);
				printf("\n");
				printf("%d\n", mayor(x,y,z));
				break;
			case 2:
				printf("----OFF----\n");
				break;
			default:
				printf("Opcion invalida.\n");
				break;
		}
		
	}while(opcion != 2);	
}

int main(){
	
	menu();
	
	return 0;
}