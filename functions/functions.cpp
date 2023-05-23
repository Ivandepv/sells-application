#include <iostream>
#include <string>
#include <tuple>

using namespace std;

// Funcion ordenar
void orden(tuple< vector<Product>, vector<int>> productos) {

    for (Product producto : get<0>(productos)) {

        cout << producto.getProductName() << "(id: " << producto.getProductID() << " )" << endl;
    }
}

//Funcion Buscar por id
void buscadorID(Company company) {
    system("cls");
    string id;
    int option;

    User userFind;
    tuple<tuple<Product, int>, int> productTupleFindIndex;
    tuple<Product, int> productTupleFind;
    Product productFind = get<0>(productTupleFind);

    Order orderFind;


    cout << "1.- Buscar Usuario 2.- Buscar Producto  3.- Buscar Una orden " << endl;
    cin >> option;

    switch (option) {

    case 1:

        cout << "Ingrese el id que desea buscar: " << endl;

        cin >> id;

        //BUSCADOR POR ID EN VECTOR USUARIO
        userFind = company.findUserByID(id);


        if (userFind.getUserID() != "") {
            cout << "El usuario " << userFind.getUserName() << " tiene " << userFind.getUserMoneyAmount() << " Pesos" << endl;
        }
        else {
            cout << "El usuario con el id no existe" << endl;
        }

        break;

    case 2:

        cout << "Ingrese el id que desea buscar: " << endl;

        cin >> id;

        // BUSCADOR POR ID EN TUPLA PRODUCT
        productTupleFindIndex = company.findProductByID(id);
        productTupleFind = get<0>(productTupleFindIndex);
        productFind = get<0>(productTupleFind);

        if (productFind.getProductID() != "") {
            cout << "Quedan " << get<1>(productTupleFind) << " " << productFind.getProductName() << "s " << endl;
        }
        else {
            cout << "El producto con el id no existe" << endl;
        }


        break;
    case 3:
        cout << "Ingrese el id que desea buscar: " << endl;

        cin >> id;

        //BUSCADOR POR ID EN VECTOR ORDER
        orderFind = company.findOrderByID(id);

        if (orderFind.getOrderID() != "") {
            cout << "La orden " << orderFind.getDate() << endl;
        }
        else {
            cout << "La orden con el id no existe" << endl;
        }


        break;

    default:
        cout << "Ingrese una opcion valida" << endl;
    }

    
}

void casoDePrueba4() {

    //Muestra de Resultados Iniciales
//vector<Product> products = get<0>(FreddyFazbear.getTupleProduct());
//vector<int> cantities = get<1>(FreddyFazbear.getTupleProduct());

//cout << "******************************" << endl;
//cout << "CREACION DE INSTANCIAS" << endl;
// cout << " El nombre del producto es : " << products.at(0).getProductName() << endl;
 //cout << " La cantidad del producto es: " << cantities.at(0) << endl;
// cout << " El nombre del usuario  es : " << FreddyFazbear.getUsers().at(0).getUserName() << endl;
// cout << " El dinero del usuario  es : " << FreddyFazbear.getUsers().at(0).getUserMoneyAmount() << endl;
// cout << " El Precio Total de la orden es: " << FreddyFazbear.getOrders().at(0).getOrderTotalPrice() << endl;
// cout << "Los fondos de la compania son: " << FreddyFazbear.getCompanyFunds() << endl;
// cout << "******************************" << endl;

 // Adicion de Los elementos a los vectores de Company.

    Company FreddyFazbear;
    User user1("0001", "Ivan", 20000);
    Product mask("0001", "cubrebocas", 0, 8); // Categoria 0, cubrebocas de 8 pesos
    Product pill("0002", "medicamento para la tos", 1, 8); // Categoria 1, pill 8 pesos
    Product gel("0003", "gel desinfectante", 2, 8); // Categoria 2, manzana de 8 pesos
    Product apple("0004", "manzana", 3, 8); // Categoria 0, manzana de 8 pesos
    Order appleOrder("0001", user1, apple, 15, "28 / November / 2022"); // 15 manzanas


    // Adicion de Los elementos a los vectores de Company.
    FreddyFazbear.addUser(user1);
    FreddyFazbear.addProduct(apple, 15);
    FreddyFazbear.addOrder(appleOrder);


    //Muestra de Resultados Iniciales
    vector<Product> products = get<0>(FreddyFazbear.getTupleProduct());
    vector<int> cantities = get<1>(FreddyFazbear.getTupleProduct());

    cout << "******************************" << endl;
    cout << "CREACION DE INSTANCIAS" << endl;
    cout << " El nombre del producto es : " << products.at(0).getProductName() << endl;
    cout << " La cantidad del producto es: " << cantities.at(0) << endl;
    cout << " El nombre del usuario  es : " << FreddyFazbear.getUsers().at(0).getUserName() << endl;
    cout << " El dinero del usuario  es : " << FreddyFazbear.getUsers().at(0).getUserMoneyAmount() << endl;
    cout << " El Precio Total de la orden es: " << FreddyFazbear.getOrders().at(0).getOrderTotalPrice() << endl;
    cout << "Los fondos de la compania son: " << FreddyFazbear.getCompanyFunds() << endl;
    cout << "******************************" << endl;


    // Primera Funcionalidad Hacer una compra
    cout << "DATOS AL REALIZAR COMPRA" << endl;
    FreddyFazbear.purchaseOrder(user1, appleOrder);
    cout << " Los fondos de la compania son: " << FreddyFazbear.getCompanyFunds() << endl;
    cout << "******************************" << endl;




    //Segunda Funcionalidad Ordenar dependiendo de importancia de la categoria (0.- Cubrebocas, 1.- Medicamentos, 2.- Desinfectantes 3.- Comida, 4.- accesorios 5.- Comida Chatarra)
    cout << "Datos al aplicar el orden (2da funcionalidad)" << endl;

    FreddyFazbear.addProduct(mask, 100);
    FreddyFazbear.addProduct(pill, 100);
    FreddyFazbear.addProduct(gel, 100);
    FreddyFazbear.addProduct(apple, 100);


    tuple< vector<Product>, vector<int>>  change = FreddyFazbear.getTupleProduct();
    cout << get<0>(change).at(0).getProductName() << endl;
    cout << get<0>(change).at(1).getProductName() << endl;
    cout << get<0>(change).at(2).getProductName() << endl;
    cout << get<0>(change).at(3).getProductName() << endl;
    cout << "******************************" << endl;



    //BUSCADOR POR ID EN VECTOR USUARIO
    User userFind = FreddyFazbear.findUserByID("0001");
    cout << "DATOS DE LA FUNCIONALIDAD 3" << endl;


    if (userFind.getUserID() != "") {
        cout << "El usuario con id Existe " << userFind.getUserName() << endl;
    }
    else {
        cout << "El usuario con el id no existe" << endl;
    }

    // BUSCADOR POR ID EN TUPLA PRODUCT
    tuple<tuple<Product, int>, int> productTupleFindIndex = FreddyFazbear.findProductByID("0001");
    tuple<Product, int> productTupleFind = get<0>(productTupleFindIndex);
    Product productFind = get<0>(productTupleFind);

    if (productFind.getProductID() != "") {
        cout << "El producto con id Existe " << productFind.getProductName() << endl;
        cout << "La cantidad del producto es " << get<1>(productTupleFind) << endl;
    }
    else {
        cout << "El producto con el id no existe" << endl;
    }


    //BUSCADOR POR ID EN VECTOR ORDER
    Order orderFind = FreddyFazbear.findOrderByID("0001");

    if (orderFind.getOrderID() != "") {
        cout << "La orden con id Existe " << orderFind.getDate() << endl;
    }
    else {
        cout << "La orden con el id no existe" << endl;
    }
    cout << "******************************" << endl;
}