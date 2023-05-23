
#include "../data/Company.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>
using namespace std;

Company::Company() :companyName(""), users{}, tupleProduct{}, orders{}, companyFunds(0) {};
//Company::Company(){};
Company::Company(string cCompanyName, vector<User> cUsers, tuple<vector<Product>, vector<int>> cProducts, vector<Order> cOrders, double cCompanyFunds) : companyName(cCompanyName), users(cUsers), tupleProduct(cProducts), orders(cOrders), companyFunds(cCompanyFunds) {};
Company::~Company(){};

//getters
vector<User> Company::getUsers() {
	return users;
};
tuple<vector<Product>, vector<int>> Company::getTupleProduct() {
	return tupleProduct;
};
vector<Order> Company::getOrders() {
	return orders;
};

string Company::getCompanyName() {
	return companyName;
};

double Company::getCompanyFunds() {
	return companyFunds;
};

//setters
void Company::setCompanyName(string cCompanyName) {
	companyName = cCompanyName;
};

void Company::setCompanyFunds(double cCompanyFunds) {
	companyFunds = cCompanyFunds;
};

//vectorAdders
void Company::addOrder(Order cOrder) {
	double residue = users.at(0).getUserMoneyAmount() - cOrder.getOrderTotalPrice();;
	users.at(0).setUserMoneyAmount(residue);
	orders.push_back(cOrder);

}
void Company::addProduct(Product cProduct, int cCantity) {

	vector<Product> products = get<0>(tupleProduct);
	vector<int> cantities = get<1>(tupleProduct);

	//Agregar producto al vector

	products.push_back(cProduct);
	cantities.push_back(cCantity);

	tupleProduct = make_tuple(products, cantities);


	// Realiza la funcionalidad de categorización por medio de la importancia. Para esto se ejecuta un algoritmo de bubble-sort
	if (products.size() != 0) {

		// Loop para acceder a cada elementro del arreglo
		for (int i = 0; i < products.size(); i++) {

			// Loop para comparar elementos de los arreglpos
			for (int j = 0; j < products.size() - 1; j++) {

				// Checa si los dos elementos están ordenados correctamente, en caso de que sí se asigna a la tupla
				if (products.at(j).getProductCategory() > products.at(j + 1).getProductCategory()) {

					// En caso de que no, se realizará el algoritmo de bubblesort
					Product temp = products.at(j);
					int temp2 = cantities.at(j);
					products.at(j) = products.at(j + 1);
					products.at(j + 1) = temp;

					cantities.at(j) = cantities.at(j + 1);
					cantities.at(j + 1) = temp2;
				}
			}
		tupleProduct = make_tuple(products, cantities);

		}
	}
		
}

void Company::addUser(User cUser) {
	users.push_back(cUser);
}
 

//Funcionalidad de refil

void Company::refillProduct(string id) {

	int productIndex = get<1>(findProductByID(id));
	cout << productIndex << endl;
	if ( get<0>(get<0>(findProductByID(id))).getProductName() != "" ) {
		get<1>(tupleProduct).at(productIndex) += 10;
		cout << "El producto " << get<0>(get<0>(findProductByID(id))).getProductName() << " ha sido rellenado con " << get<1>(tupleProduct).at(productIndex) << endl;
	}
	else {
		cout << "El producto no existe" << endl;
	}

}

//Funcionalidad de comprar orden

void Company::purchaseOrder(User user, Order order) {
	double residue = user.getUserMoneyAmount() - order.getOrderTotalPrice();
	tuple<tuple<Product, int>, int> productPurchasedIndex = findProductByID(order.getOrderProduct().getProductID());
	tuple<Product, int> productPurchased = get<0>(productPurchasedIndex);


	if ( get<1>(productPurchased) < order.getOrderProductAmount() || residue < 0) {
		cout << "Compra Denegada! ";
		if (residue < 0) {
			cout << "No tienes fondos suficientes." << endl;
		}
		else {
			cout << "El producto que quiere comprar es mayor que el existente." << endl;
		}	
	
	}
	else {
		int index = get<1>(productPurchased);
		system("cls");

		double productResidue = get<1>(tupleProduct).at(get<1>(productPurchasedIndex)) - order.getOrderProductAmount();
		get<1>(tupleProduct).at(get<1>(productPurchasedIndex)) = productResidue;

		Order orderNew("0002", user, order.getOrderProduct(), 5, "28 / November / 2022");
		addOrder(orderNew);

		companyFunds += order.getOrderTotalPrice();
		cout << "******************************" << endl;
		cout << "Compra Hecha!!" << endl;
		cout << "Tu monedero: $" << user.getUserMoneyAmount() << endl;
		cout << "Usted ha comprado: " << order.getOrderProductAmount() <<" "<< order.getOrderProduct().getProductName() << "s" << endl;
		cout << "Producto restante:  " << productResidue << endl;
		cout << " Los fondos de la compania son: " << companyFunds<< endl;
		cout << "******************************" << endl;

	}

};

//Funcionalidad de encontrar usuario por ID


User Company::findUserByID(string cUserID) {

	User userFind;

	for (User user: users) {
		if (user.getUserID() == cUserID)
		{
			userFind = user;
		};
	}
	return userFind;
}

//Funcionalidad de buscar orden por ID


Order Company::findOrderByID(string cOrderID) {

	Order orderFind;

	for (Order order : orders) {
		if (order.getOrderID() == cOrderID)
		{
			orderFind = order;
		};
	}
	return orderFind;
}

//Funcionalidad de buscar producto por ID

tuple<tuple<Product, int>, int> Company::findProductByID(string cProductID) {

	tuple<tuple<Product, int>, int> productTupleIndex;
	tuple<Product, int> productTuple;
	vector<Product> products = get<0>(tupleProduct);


	for (int i = 0; i < products.size(); i++) {

		if (products.at(i).getProductID() == cProductID)
		{
			get<1>(productTupleIndex) = i;


;			productTuple = make_tuple(products.at(i), get<1>(tupleProduct).at(i));
			get<0>(productTupleIndex) = productTuple;
			get<1>(productTupleIndex) = i;
		};
	}

	
	return productTupleIndex;
}





