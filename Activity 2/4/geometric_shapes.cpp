#include <iostream>
#include <string.h>
#include <math.h>
# define M_PI           3.14159265358979323846
using namespace std;


class Shape{
    public:
    string color;
    Shape(string color) { this->color = color; }

    float Area() { return 0; }
    float Perimeter() { return 0; }

    void printData() { 
        cout<<"Shape data: "<<endl;
        cout<<"Color: "<<color<<endl;
        cout<<"Area: "<<Area()<< "| Perimetro: "<< Perimeter()<<endl;
    }
};


//triangulo isosceles
class Triangle : public Shape {
    public:
    int base;
    int height;

    Triangle(string color,int base, int height) : Shape(color){
        this->base = base; this->height = height;
    }

    float Area() { return (base*height)/2; }
    float Perimeter() { return base + 2*sqrt(pow(base/2,2)+pow(height,2));  }

    void printData() { 
        cout<<"Triangle data: "<<endl;
        cout<<"Color: "<<color<<endl;
        cout<<"Base: "<<base<< " Height: "<<height<<endl;
        cout<<"Area: "<<Area()<< "| Perimetro: "<< Perimeter()<<endl;
    }
};

class Square : public Triangle {
    public:
    Square(string color,int base) : Triangle(color, base, base){
    }

    float Area() { return base*base; }
    float Perimeter() { return 4*base; }

    void printData() { 
        cout<<"Square data: "<<endl;
        cout<<"Color: "<<color<<endl;
        cout<<"Base: "<<base<< " Height: "<<height<<endl;
        cout<<"Area: "<<Area()<< "| Perimetro: "<< Perimeter()<<endl;
    }
};

class Rectangle : Triangle {
    public:
    Rectangle(string color, int base, int height) : Triangle(color, base, height){
    }
    float Area() { return base*height; }
    float Perimeter() { return 2*base+2*height; }
    void printData() { 
        cout<<"Rectangle data: "<<endl;
        cout<<"Color: "<<color<<endl;
        cout<<"Base: "<<base<< " Height: "<<height<<endl;
        cout<<"Area: "<<Area()<< "| Perimetro: "<< Perimeter()<<endl;
    }
};

class Circle : Shape {
    public:
    float radius;
    Circle(string color, float radius) : Shape(color){
        this->radius = radius;
    }
    float Area() { return M_PI*pow(radius,2); }
    float Perimeter() { return 2*M_PI*radius; }
    void printData() { 
        cout<<"Circle data: "<<endl;
        cout<<"Color: "<<color<<endl;
        cout<<"Radio: "<<radius<<endl;
        cout<<"Area: "<<Area()<< "| Perimetro: "<< Perimeter()<<endl;
    }
};

void menu(){
	int opcion;

	do{
		printf("---------DATOS SOBRE FIGURAS GEOMETRICAS------------\n");
		printf("1. Crear un triangulo\n");
        printf("2. Crear un cuadrado\n");
        printf("3. Crear un rectangulo\n");
        printf("4. Crear un circulo\n");
		printf("0. Salir.\n");
		printf("Digite el numero del procedimiento a realizar: ");
		scanf("%d", &opcion);
		printf("\n");
		float h, b, r;
		char c;
        string color;
        Triangle * tr;
        Square * sqr;
        Rectangle * rctngl;
        Circle * crql;


		int *arr;
		switch(opcion){
			case 1:
                printf("Escriba el color del triangulo: "); cin>>color;
				printf("Ingrese la base del triangulo: "); scanf("%f", &b);
                printf("Ingrese la altura del triangulo: "); scanf("%f", &h);
                tr = new Triangle(color, b, h);
                tr->printData();
				break;
			case 2:
                printf("Escriba el color del cuadrado: "); cin>>color;
                printf("Ingrese el lado del cuadrado: "); scanf("%f", &b);
                sqr = new Square(color, b);
                sqr->printData();
				break;
            case 3:
                printf("Escriba el color del rectangulo: "); cin>>color;
                printf("Ingrese la base del rectangulo: "); scanf("%f", &b);
                printf("Ingrese la altura del rectangulo: "); scanf("%f", &h);
                rctngl = new Rectangle(color, b, h);
                rctngl->printData();
				break;
            case 4:
                printf("Escriba el color del circulo: "); cin>>color;
                printf("Ingrese el radio del circulo: "); scanf("%f", &r);
                crql = new Circle(color, r);
                crql->printData();
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