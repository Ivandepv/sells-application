// Aplicacion de Ventas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// 
// Maria Paula Rodríguez Muñoz A01254734 
// Jorge Ivan Coronado Villegas A01254785
// Ramón Alberto Gómez Urquídez A01254784
// 01/12/2022

#include <iostream>
#include <string>
#include <tuple>
#include "functions/User.cpp"
#include "functions/Company.cpp"
#include "functions/Product.cpp"
#include "functions/Order.cpp"
#include "functions/functions.cpp"

using namespace std;

int main() {
    
    system("cls");

    // Instancias
    Company FreddyFazbear;
    Product mask("0001", "cubrebocas G-95", 0, 20); // Categoria 0, cubrebocas de 20 pesos
    Product pill("0002", "Paracetamol", 1, 30); // Categoria 1,  Paracetamol de 30 pesos
    Product gel("0003", "Gel desinfectante", 2, 50); // Categoria 2, Gel Desinfectante de 50 pesos
    Product takis("0006", "Takis", 5, 15); // Categoria 5, Sabritas Takis

    // Cambiar dinero, 3er parametro tipo double para hacer prueba falta de dinero
    User user1("0001", "Feddy", 20000);

    //Solamente cambiara el precio para la prueba, 4to atributo
    Product apple("0004", "manzana", 3, 8); 

    Product lentesSol("0005", "Lentes de sol", 4, 400); // Categoria 4, Lentes de sol 400 pesos
    Order appleOrder("0001", user1, apple, 5, "28 / November / 2022"); // 5 manzanas

    tuple< vector<Product>, vector<int>>  productTuple;


    // Anadiendo los objetos a los vectores
    FreddyFazbear.addUser(user1);
    FreddyFazbear.addProduct(apple, 15);
    FreddyFazbear.addProduct(mask, 15);
    FreddyFazbear.addProduct(pill, 15);
    FreddyFazbear.addProduct(gel, 15);
    FreddyFazbear.addProduct(takis, 15);
    FreddyFazbear.addProduct(lentesSol, 15);
    FreddyFazbear.addOrder(appleOrder);

    int option;
    string wait;
    string refillId;

    do {
  
        system("cls");
        cout << "1.- Hacer Una Compra  2.- Imprimir lista de productos  3.- Buscador de ID. 4.- Refill 0.- Salir" << endl;
        cin >> option;

        switch (option) {

        case 1:
  
            // Se prueba la primera funcionalidad 
            // Hacer una compra
            FreddyFazbear.purchaseOrder(FreddyFazbear.getUsers().at(0), appleOrder);
            cout << "Ingrese Cualquier letra para contiuar....";
            cin >> wait;
            break;

        case 2:
            // Se prueba la segunda funcionalidad
            cout << "Ordenados por Importancia" << endl << "0.- Cubrebocas 1.- Medicamentos 2.- Desinfectantes 3.- Comida 4.- Accesorios 5.- Comida Chatarra" << endl;
            // Ordenar por medio de una categoria
                //0.- Cubrebocas
                //1.- Medicamentos
                //2.- Desinfectantes 
                //3.- Comida
                //4.- Accesorios 
                //5.- Comida Chatarra
            productTuple = FreddyFazbear.getTupleProduct();
            cout << "******************************" << endl;
            orden(productTuple);
            cout << "******************************" << endl;
            cout << "Ingrese Cualquier letra para contiuar....";
            cin >> wait;
            break;

        case 3:
            // Se prueba la tercera funcionalidad
            // Buscar instancias por ID
            buscadorID(FreddyFazbear);
            cout << "Ingrese Cualquier letra para contiuar....";
            cin >> wait;
            break;

        case 4:
            // Se prueba la cuarta funcionalidad
            //Refil
            cout << "Ingresa el id para abastecer el producto" << endl;
            cin >> refillId;
            FreddyFazbear.refillProduct(refillId);
            cout << "Ingrese Cualquier letra para continuar....";
            cin >> wait;
            break;
        case 0:
            cout << "Saliendo de la aplicacion";
            break;
        default:
            cout << "Ingrese una opcion valida" << endl;

            break;

        }
  

       
    } while (option != 0);

 



}
