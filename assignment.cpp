#include <stdio.h>
//Punto 1
float student(float lab1, float par1, float lab2, float par2, float lab3, float par3){
	return lab1*0.05 + par1*0.25 + lab2*0.15 + par2*0.2 + lab3*0.15 + par3 * 0.2;
}


//Punto 2
bool primo(int n){
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
void leapyear(int year) { 
	if (year%4 == 0){
		printf("Es bisiesto\n");
	}else{
		printf("No es bisiesto\n");
	}
}

//Punto 4
int pow(int n, int exp)
{
	int ans = 1;
	if (exp != 0){
		ans = n*pow(n, exp-1);
	}
	return ans;
}

bool par(int val){
	return val%2 == 0;
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

void changeBase(int n, int base)
{
	if (base == 8){
		int val = (int)
	}else if (base == 10){
		
	}
	else if (base == 16){
		
	}else
	{
		printf("Error en la base");
	}
}



int main(){
	printf("student: %f\n", student(5, 5, 5, 5, 5, 5));
	
	if (primo(6)){
		printf("Primo");
	}
	
	leapyear(1804);
	
	printf("Potencia: %d \n", pow(2, 3));
	
	printf("Par de 6 : %d\n", par(6));
	
	printf("Fibo: %d\n", fibonacci(6));
	
	printf("Mayus a: %d", uppercase('a'));
	
	printf("Minus a: %d", uppercase('a'));
	printf()
	
	return 0;
}