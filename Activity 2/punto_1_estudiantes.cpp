#include <stdio.h>
//Punto 1 Calcular la nota final de un estudiante con promedios ponderados

struct Pesos{
	float lab1, lab2, lab3;
	float par1, par2, par3;

} 
pesos = { 0.05, 0.15, 0.15, 0.25, 0.2, 0.2 };

float student(float lab1, float par1, float lab2, float par2, float lab3, float par3){
	return lab1*pesos.lab1 + par1*pesos.par1 + lab2*pesos.lab2 + par2*pesos.par2 + lab3*pesos.lab3 + par3 *pesos.par3;
}
void menu(){
	int opcion;
	do{
		printf("----------------MENU------------------------\n");
		printf("1. Nota final de un estudiante.\n");
		printf("0. Salir.\n");
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