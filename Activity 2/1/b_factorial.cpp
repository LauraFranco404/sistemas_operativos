#include <iostream>

using namespace std;
//MACRO PARA IMPRIMIR UN STRING SIMPLE
#define PR(X) cout<<X;


//Calculo del factorial que permite resultados grandes
unsigned long long fact(int x){
	unsigned long long ans = 1;
	if (x != 0)
	{
		ans = x * fact(x - 1);
	}
	return ans;
}



void menu(){
	int opcion;
	
	do{
		int x;
		
		PR("-----MENU-----\n");
		PR("1. Calcular factorial.\n");
		PR("0. Salir.\n");
		PR("Digite el numero del procedimiento a realizar: ");
		cin>>opcion;
		PR("\n");
		
		switch(opcion){
			case 1:
				PR("Ingrese el numero (maximo 20): \n");
				cin>>x;
				if (x > 20 || x < 0)
				{
					cout<<"Numero no valido, saliendo..."<<endl;
				}else{
					cout<<"Factorial de "<< x << " = "<< fact(x)<<endl;
				}
				break;
			case 0:
				PR("----OFF----\n");
				break;
			default:
				PR("Opcion invalida.\n");
				break;
		}
		
	}while(opcion != 0);	
}

int main(){
	
	menu();
	
	return 0;
}