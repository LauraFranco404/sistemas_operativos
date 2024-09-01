#include <iostream>
#include <math.h>

//Clase que contiene metodos estaticos para imprimir un numero n >= 0 con la base 10 como un numero en base 8 o 16.
class Base{
	public:
	Base() = delete;

	static void base10a8(int n){
		if (n < 8){ 
			std::cout<<n;
		}
		else{
			base10a8((int)n/8);
			std::cout<<(n%8);
		}
	}

	static void base10a16(int n){
		if (n < 16){ 
			int div = (int)n/10;
			printHexa(n);
		}
		else{
			base10a8((int)n/16);
			printHexa(n%16);
		}
	}

	private: 
	//Metodo privado, pues solo necesito que base10a16 acceda a esto
	static void printHexa(int n){
		int index_letra = 'A';
		if (n > 9) {
			std::cout<<(char)('A'+(n-10));
		}else{
			std::cout<<n;
		}
	}

};

//selecciona la base a imprimir
void printWBase(int n, int base)
{
	if (base == 8){
		Base::base10a8(n);
	}
	else if (base == 10){
		std::cout<<n;
	}
	else if (base == 16){
		Base::base10a16(n);	
	}
	else
	{
		printf("Error en la base");
	}
}

void menu(){
	int opcion;
	do{
		printf("----------------MENU------------------------\n");
		printf("1. Numeros en otra base.\n");
		printf("0. Salir.\n");
		printf("Digite el numero del procedimiento a realizar: ");
		scanf("%d", &opcion);
		printf("\n");
		int n;
		char c;
		switch(opcion){
			case 1:
				printf("Ingrese una de las bases 8, 10, 16: \n(Ejemplo:8)\n"); scanf(" %d", &n);
				printf("Numeros del 1 al 10 en base %d: \n [", n);
				for (int i = 1; i<11; i++)
				{
					printWBase(i, n);
					std::cout<< (i == 10 ? "]\n" : ", ");
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