
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "User.hpp"
#include "Order.hpp"
#include "Product.hpp"
using namespace std;



#ifndef Company_hpp
#define Company_hpp

class Company {

private:
	string companyName;
    double companyFunds;
	vector<User> users;
    tuple <vector<Product>, vector<int>> tupleProduct;
	vector<Order> orders;

public:

    Company();
    Company(string, vector<User>, tuple<vector<Product>, vector<int>>, vector<Order>, double);
    //getters
    string getCompanyName();
    vector<User> getUsers();
    tuple< vector<Product>, vector<int>> getTupleProduct();
    vector<Order> getOrders();
    double getCompanyFunds();
    //setters
    void setUsers(vector<User>);
    void setTupleProduct(tuple<vector<Product>, vector<int>>);
    void setOrders(vector<Order>);
    void setCompanyName(string);
    void setCompanyFunds(double);
    // vectorAdders
    void addUser(User);
    void addProduct(Product, int);
    void addOrder(Order);
    //functionalities
    void purchaseOrder(User, Order);
    User findUserByID(string);
    void refillProduct(string);
    tuple<tuple<Product, int>, int> findProductByID(string);
    Order findOrderByID(string);

    ~Company();
};

#endif