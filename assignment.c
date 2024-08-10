#include <stdio.h>


//Punto 1 Calcular la nota final de un estudiante con promedios ponderados
struct Pesos{
	float lab1, lab2, lab3;
	float par1, par2, par3;

} pesos = { 0.05, 0.15, 0.15, 0.25, 0.2, 0.2 };

float student(float lab1, float par1, float lab2, float par2, float lab3, float par3){
	return lab1*pesos.lab1 + par1*pesos.par1 + lab2*pesos.lab2 + par2*pesos.par2 + lab3*pesos.lab3 + par3 *pesos.par3;
}


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

//Punto 3
int leapyear(int year) { 
	return year%4 == 0;
}

//Punto 4
int my_pow(int n, int exp)
{
	int ans = 1;
	if (exp != 0){
		ans = n*my_pow(n, exp-1);
	}
	return ans;
}

//Punto # Retorna 1 si es par, de lo contrario 0
int par(int val){
	return val%2 == 0;
}

//Punto # Facrorial

int fact(int x){
	int ans = 1;
	if (x == 0){
		return 1;
	}
	else{
		return x * fact(x - 1);
	}		
}

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

int uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

void printWBase(int n, int base)
{
	
	if (base == 8){
		int div = (int)n/base;
		printf("%d, ", div*my_pow(10,div) + (n%base));
	}else if (base == 10){
		printf("%d, ", n);
	}
	else if (base == 16){
		char arr [] = {'A', 'B', 'C', 'D', 'E', 'F'};

		if (n < 10){printf("%d, ", n, base, n);}
		else { printf("%c, ", arr[n-10]); }
			
	}else
	{
		printf("Error en la base");
	}
}

void menu(){
	int opcion;
	do{
		printf("----------------MENU------------------------\n");
		printf("1. Nota final de un estudiante.\n");
		printf("2. Saber si un numero es primo.\n");
		printf("3. Saber si un numero es primo.\n");
		printf("4. Calcular potencia de un numero.\n");
		printf("5. Calcular factorial.\n");
		printf("6. Calcular fibonacci.\n");
		printf("7. Saber si letra es mayuscula.\n");
		printf("8. Saber si letra es minuscula.\n");
		printf("9. Numeros en otra base.\n");
		printf("10. No se.\n");
		printf("11. No se.\n");
		printf("12. No se.\n");
		printf("13. Salir.\n");
		printf("Digite el numero del procedimiento a realizar: ");
		scanf("%d", &opcion);
		printf("\n");
		int n;
		char c;
		switch(opcion){
			case 1:
				int lab1, lab2, lab3, par1, par2, par3;
				printf("Ingrese las notas (lab1, lab2, lab3, par1, par2, par3) separadas por espacios: \n (Ejemplo: 5 5 5 5 5 5)\n");
				scanf("%d %d %d %d %d %d", &lab1, &lab2, &lab3, &par1, &par2, &par3);
				printf("Nota final: %f\n", student(lab1, par1, lab2, par2, lab3, par3));
				break;
			case 2:
				printf("Ingrese un numero: "); scanf("%d", &n);
				printf(prime(n) == 1? "Es primo\n":"No es primo\n");
				break;
			case 3:
				printf("Ingrese un anio: "); scanf("%d", &n);
				printf(leapyear(n) == 1? "Es bisciesto\n":"No es bisciesto\n");
				break;
			case 4:
				int pot;
				printf("Ingrese el numero y la potencia separados por espacioes: \n (Ejemplo: 10 3)\n"); scanf("%d %d", &n, &pot);
				printf("%d elevado a %d = %d\n", n, pot, my_pow(n, pot));
				break;
			case 5:
				printf("Ingrese el numero: "); scanf("%d", &n);
				printf("Factorial de  %d = %d\n", n, fact(n));
				break;
			case 6:
				printf("Ingrese el numero: "); scanf("%d", &n);
				printf("Fibonacci de  de  %d = %d\n", n, fibonacci(n));
				break;
			case 7:
				printf("Ingrese el una letra: "); scanf(" %c", &c);
				printf(uppercase(c) == 1 ? "La letra es mayuscula\n" : "No es una letra mayuscula\n");
				break;
			case 8:
				printf("Ingrese el una letra: "); scanf(" %c", &c);
				printf(lowercase(c) == 1 ? "La letra es minuscula\n" : "No es una letra minuscula\n");
				break;
			case 9:
				printf("Ingrese una de las bases 8, 10, 16: \n(Ejemplo:8)\n"); scanf(" %d", &n);
				printf("Numeros del 1 al 10 en base %d: \n [", n);
				for (int i = 1; i<11; i++) { printWBase(i, n); }
				printf("]\n");
				break;
			case 10:
				break;
			case 11:
				break;
			case 12:
				break;
			case 13:
				printf("----OFF----\n");
				break;
			default:
				printf("Opcion invalida.\n");
				break;
		}
		
	}while(opcion != 13);	
}


int main(){
	
	menu();

	printf("Par de 6 : %d\n", par(6));
	
	printf("Fibo: %d\n", fibonacci(6));
	
	printf("Mayus a: %d\n", uppercase('a'));
	
	printf("Minus a: %d\n", uppercase('a'));

	printf("Numeros del 1 al 10 en base 8\n");
	printf("[");
	for (int i = 1; i<11; i++) { printWBase(i, 8); }
	printf("]\n");

	printf("Numeros del 1 al 10 en base 10\n");
	printf("[");
	for (int i = 1; i<11; i++) { printWBase(i, 10); }
	printf("]\n");
	printf("Numeros del 1 al 10 en base 16\n");

	printf("[");
	for (int i = 1; i<11; i++) { printWBase(i, 16); }
	printf("]\n");
	
	return 0;
}