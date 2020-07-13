#include <iostream>
#include <cstring>

using namespace std;

const int longCad = 21;//Longitud maxima del nombre del producto 
int* cant = new int[1];//Cantidad de productos a registrar

//ESTRUCUTA DE CADA ACTICULO
struct costoPorArticulo{
    char nombreArticulo[longCad+1];
    int cantidad;
    float precio;
    float total;

};
//////////////////////////////

void agregarArticulos(costoPorArticulo*);
void calculoTotalArticulo(costoPorArticulo*);
void factura(costoPorArticulo*);
string llenarCadena(int,string);
float total (costoPorArticulo*);


int main(){
    float totalP;
    cout << "-----------FACTURACION DE TUS PODRUCTOS-------------" << endl;
    cout << "CUANTOS ARTICULOS FACTURARA?"<< endl << " ";
    cin >> *cant;
    /*Antes se habia declarado la memoria para está variable pero se
     pide al usuario que ingrese ese valor */

    costoPorArticulo *articulos = new costoPorArticulo[*cant];//Arreglo de los articulos a registrar 

    /////EN ESTA SECCION SE MODIFICA Y AGREGAN LOS VALORES AL ARREGLO ///
    agregarArticulos(articulos);
    calculoTotalArticulo(articulos);
    factura(articulos);
    totalP = total(articulos);
    //////////////////////////////////////////////////////////////////////
    
    cout<<"EL COSTO DE SU COMPRA ES: " << totalP << " USD "<< endl; 
    
    /////SE DEBE ELIMINAR DE MEMORIA TODAS LAS VARIABLES GENERADAS DINAMICAMENTE
    delete [] cant;
    delete [] articulos;
    *cant = NULL;
    
    return 0;
}
//SE LLAMA ESTÁ FUNCION PARA AGREGAR TODOS LOS ARTICULOS AL ARREGLO
void agregarArticulos(costoPorArticulo *articulos){
    int cantidad;
    char nombre[longCad+1];
    float precio;

    //BUCLE PARA AGREGAR LOS ARTICULOS AL ARREGLO
    for(int i = 0; i<*cant; i++){

        cout << "Nombre del producto " << i+1 << ": " << endl << " "; cin >> nombre;
        cout << "Cantidad de " << nombre << " :" << endl<< " "; cin >> cantidad;
        cout << "Precio ? " << endl << " "; cin >> precio;

        articulos[i].cantidad = cantidad;
        /*
        Se agrega el nombre que se registró a la casilla del arreglo con el metodo strcpy() 
        que copia un arreglo a otro
        */
        strcpy(articulos[i].nombreArticulo, nombre);
        articulos[i].precio = precio;
        
        cout << "--------------------"<<endl;
        cout << endl;
    }
}

//SE CALCULA EL TODAL DE CADA PRODUCTO
void calculoTotalArticulo (costoPorArticulo *articulos){
    /*
        A CADA ARTICULO SE LE AGREGA EL VALOR TOTAL, MULTIPLICANDO 
        LA CANITDAD POR EL PRECIO UNITARIO 
    */
    for (int i = 0; i<*cant; i++){
        articulos[i].total = articulos[i].cantidad * articulos[i].precio;
    }

}

//SE IMPRIME UNA FACTURA A TRAVES DE ESTÁ FUNCION 
void factura(costoPorArticulo *articulos){
    
    //INTENTO DE GENERARAR UN CUADRO PARA LA FACTURA
    cout << "-------------------------------------SU FACTURA------------------------------------"<<endl;
    cout << "-----------------------------------------------------------------------------------"<<endl;
    cout << "|PRODUCTO-------------|" <<"CANTIDAD-----------|"<<"PRECIO (USD)-------|"<<"PRECIO TOTAl (USD)-|"<<endl;  
    for(int i = 0; i<*cant; i++){
        
        //LLAMO A LA FUNCION llenarCadena(), para generar un cuadro perfectamente calculado
        //Y SE ENVIA CADA VALOR DE LA ESTRUCTURA (NOMBRE, CANTIDAD, PRECIO, TOTAL)  
        cout <<"|"<< llenarCadena(22,articulos[i].nombreArticulo);
            /*
                Se envia como parametro to_string() para convertir 
                numeros int o float hacia string, sin embargo, con 
                los tipo float genera 0´s extra  
            */
        cout << llenarCadena(20,to_string(articulos[i].cantidad));
        cout << llenarCadena(20,to_string(articulos[i].precio));
        cout << llenarCadena(20,to_string(articulos[i].total))<<endl;
        
    }
    cout << "-----------------------------------------------------------------------------------"<<endl<<endl;

}

//ESTA FUNCION ES COMPLETAMENTE CON UN FIN ESTETICO
string llenarCadena(int cantidadF, string cadena){
    
    string salida = " "+cadena;
    //El número 2 ahí hacer cuadrar las casillas con los bordes de las columnas
    int tamano = cadena.length();
    /*
        Agrega espacios a cada cadena para generar una
        casilla de un cuadro de la factura 
    */
    for(int i = tamano; i < cantidadF-2; i++){
        salida += " ";
    }
    //Limites de la casilla
    salida += '|';
    return salida;
}

//SE CALCULA EL TOTAL DE LA COMPRA, SUMANDO TODOS LOS TOTALES DE LOS PRODUCTOS
float total (costoPorArticulo *articulos){
    float precioTotal = 0.00;
    for(int i = 0; i<*cant; i++){
        precioTotal += articulos[i].total;
    }
    return precioTotal;
}