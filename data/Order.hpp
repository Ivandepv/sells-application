#include <iostream>
#include <string>
#include <vector>
#include "product.hpp"
#include "User.hpp"
using namespace std;


#ifndef Order_hpp
#define Order_hpp

class Order {
private:
	string orderID;
	User orderUser;
	Product orderProduct;
    double orderProductAmount;
    double orderTotalPrice; //added order total price attribute
	string date;

public:
    Order();
    Order(string, User, Product, double, string);
    string getOrderID();
    Product getOrderProduct();
    string getDate();
    double getOrderProductAmount();
    double getOrderTotalPrice();
    User getOrderUser();
    void setOrderID(string);
    void setOrderProduct(Product);
    void setDate(string);
    void setOrderUser(User);
    void setOrderProductAmount(double);
    void setOrderTotalPrice();
    void setOrderUser();
    ~Order();
};

#endif
