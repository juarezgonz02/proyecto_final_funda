#include <iostream>
using namespace std;
const int longCad = 21;
int* cant = new int[10];

struct costoPorArticulo{
    string nombreArticulo;
    int cantidad;
    float precio;
    float total;

};
void agregarArticulos(costoPorArticulo*);
void calculoTotalArticulo(costoPorArticulo*);
void factura(costoPorArticulo*);
float total (costoPorArticulo*);


int main(){

    cout << "CUANTOS ARTICULOS FACTURARA"<< endl;
    cin >> *cant;
    costoPorArticulo articulos;
    
    *articulos = new costoPorArticulo[*cant]; 

    agregarArticulos(articulos);
    calculoTotalArticulo(articulos);
    factura(articulos);

    float totalP = total(articulos);
    cout<<"EL COSTO DE SU COMPRA ES: " << totalP << endl; 
    delete [] cant;
    *cant = NULL;
    return 0;
}

void agregarArticulos(costoPorArticulo *articulos){
    int cantidad;
    string nombre;
    float precio;
 
    for(int i = 0; i<*cant; i++){

        cout << "Nombre del producto" << endl; cin >> nombre;
        cout << "Cantidad de " << nombre << " :" << endl; cin >> cantidad;
        cout << "Precio? " << endl; cin >> precio;

        articulos[i].cantidad = cantidad;
        articulos[i].nombreArticulo = nombre;
        articulos[i].precio = precio;

    }
}

void calculoTotalArticulo (costoPorArticulo *articulos){

    for (int i = 0; i<*cant; i++){
        articulos[i].total = articulos[i].cantidad * articulos[i].precio;
    }

}

void factura(costoPorArticulo *articulos){

    for(int i = 0; i<*cant; i++){
        cout << " PRODUCTO: " << articulos[i].nombreArticulo << endl;
        cout << " CANTIDAD: " << articulos[i].cantidad << endl;
        cout << " PRECIO UNITARIO: " << articulos[i].precio << endl;
        cout << " PRECIO TOTAL: " << articulos[i].total << endl;
        cout << "------------------------------" << endl;
    }

}

float total (costoPorArticulo *articulos){
    float preciototal = 0.0;
    for(int i = 0; i<*cant; i++){
        preciototal += articulos[i].total;
    }
    return preciototal;
}