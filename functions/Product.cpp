

#include "../data/Product.hpp"
#include <string>

Product::Product() :productID(""), productName(""), productPrice(0), productCategory(0), productDisponibility(true) {};

Product::Product(string cProductID, string cProduct, int cProductCategory, double cProductPrice ) {
    productID = cProductID;
    productName = cProduct;
    productPrice = cProductPrice;
    productCategory = cProductCategory;

}

string Product::getProductID() {
    return productID;
}

string Product::getProductName() {
    return productName;
}

double Product::getProductPrice() {
    return productPrice;
}

int Product::getProductCategory() {
    return productCategory;
}

void Product::setProductID(string cProductID) {
    productID = cProductID;
}

void Product::setProductName(string cProduct) {
    productName = cProduct;
}

void Product::setProductPrice(double cProductPrice) {
    productPrice = cProductPrice;
}

void Product::setProductCategory(int cProductCategory) {
    productCategory = cProductCategory;
}

Product::~Product() {};
