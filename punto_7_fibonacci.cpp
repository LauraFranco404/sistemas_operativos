#include <iostream>
#include <map>
using namespace std;

//diccionario para memorizacion con resultados grandes
map<int, unsigned long long> memo = { {0, 1}, {1, 1} };

//calculo de fibonacci utilizando programacion dinamica con el metodo de memorizacion.
unsigned long long fibonacci(int n)
{
	unsigned long long ans = -1;
	if (memo.find(n) != memo.end()) //si ya lo calculo, no lo vuelva a calcular y use el diccionario
	{
		ans = memo[n];
	}else{ //calculo recursivo de fibonacci
		ans = fibonacci(n-2) + fibonacci(n-1);
		memo[n] = ans;
	}
	return ans;
}

void menu(){
	int opcion;
	do{
		cout<<"----------------MENU------------------------\n";
		cout<<"1. Calcular la serie de fibonacci.\n";
		cout<<"0. Salir.\n";
		cout<<"Digite el numero del procedimiento a realizar: ";
		cin>>opcion;
		cout<<"\n";
		int n;
		char c;
		switch(opcion){
			case 1:
				cout<<"Ingrese el numero (MAXIMO 93): ";
				cin>>n;
				if (n > 93 || n < 1)
				{
					cout<<"Valor no valido, saliendo...\n";
				}else{
					cout<<"Secuencia fibonacci \n [";
					//imprime como si fuera un arreglo la secuencia fibonacci
					for(int i = 0; i<n; i++){
						cout<<fibonacci(i)<< (i < n-1 ? ", " : "]\n");
					}
				}
				
				break;
			case 0:
				cout<<"----OFF----\n";
				break;
			default:
				cout<<"Opcion invalida.\n";
				break;
		}
		cout<<"\n";
	}while(opcion != 0);	
}
int main(){
	menu();
	return 0;
}