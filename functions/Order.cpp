#include <iostream>
#include <string>
#include <iomanip>
#include "../data/Order.hpp"
#include "../data/Product.hpp"
#include "../data/User.hpp"

Order::Order() :orderID(""), orderUser{}, orderProduct{}, date(""), orderProductAmount(0), orderTotalPrice(0) {};

Order::Order(string cOrderID, User cOrderUser, Product cOrderProduct, double cOrderProductAmount, string cDate) {
    orderID = cOrderID;
    orderUser = cOrderUser;
    orderProduct = cOrderProduct;
    date = cDate;
    orderProductAmount = cOrderProductAmount;
    orderTotalPrice = orderProductAmount * orderProduct.getProductPrice();
    
   // orderTotalPrice = cOrderTotalPrice;
}

string Order::getOrderID() {
    return orderID;
}
User Order::getOrderUser() {
    return orderUser;
}

Product Order::getOrderProduct() {
    return orderProduct;
}

string Order::getDate() {
    return date;
}

double Order::getOrderProductAmount() {
    return orderProductAmount;
}

double Order::getOrderTotalPrice() {
    return orderTotalPrice;
}

void Order::setOrderID(string cOrderID) {
    orderID = cOrderID;
}

void Order::setOrderProduct(Product cOrderProduct) {
    orderProduct = cOrderProduct;
}

void Order::setOrderUser(User cOrderUser) {
    orderUser = cOrderUser;
}

void Order::setDate(string cDate) {
    date = cDate;
}

void Order::setOrderProductAmount(double cOrderProductAmount) {
    orderProductAmount = cOrderProductAmount;
}

void Order::setOrderTotalPrice() {
    orderTotalPrice = orderProduct.getProductPrice() * orderProductAmount;
};

Order::~Order() {};
