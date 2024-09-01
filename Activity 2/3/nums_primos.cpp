#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//Punto 2 retorna 1 si es primo, 0 de lo contrario.

//Clase con metodo estatico para evitar crear una instancia de la misma
class Primo{
	public:
	static int esPrimo(int n){
		int count = 0;
		if (n > 1)
		{
			for (int i = 1; i<n; i++)
			{
				if (n % i == 0) { 
					count++;
				}
			}
		}else{
			count = 2;
		}
		return count <= 1;	
	};


	static void sonPrimos(int * arr, int len){
		for (int i = 0; i<len; i++)
		{
			printf("%d ", arr[i]);
			printf(Primo::esPrimo(arr[i]) == 1? "Es primo\n":"No es primo\n");
		}
	};

	static void primosRange(int a, int b)
	{
		for (int i = a; i<=b; i++)
		{
			printf("%d ", i);
			printf(Primo::esPrimo(i) == 1? "Es primo\n":"No es primo\n");
		}
	}
	
	Primo() = delete;
};

void menu(){
	int opcion;
	do{
		printf("----------------MENU------------------------\n");
		printf("1. Verificar si un numero es primo\n");
		printf("2. Numeros primos en una lista\n");
		printf("3. Numeros primos en rango\n");
		printf("0. Salir.\n");
		printf("Digite el numero del procedimiento a realizar: ");
		scanf("%d", &opcion);
		printf("\n");
		int n;
		int a, b;
		char c;

		int *arr;
		switch(opcion){
			case 1:
				printf("Ingrese un numero: "); scanf("%d", &n);
				printf(Primo::esPrimo(n) == 1? "Es primo\n":"No es primo\n");
				break;
			case 2:
				printf("Ingrese el numero de elementos: ");
				scanf("%d", &n);
				arr = (int*)malloc(sizeof(int)*n);
				for (int i = 0; i < n; i++) {
					printf("Ingrese el elemento %d: ", i+1);
					scanf("%d", &arr[i]); // Read each element and store it in the array
				}
				Primo::sonPrimos(arr, 10);
				break;
			case 3:
				printf("Ingresando un intervalo [a, b]\n");
				printf("ingrese a: "); scanf("%d", &a);
				printf("ingrese b: "); scanf("%d", &b);
				Primo::primosRange(a,b);
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