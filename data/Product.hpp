#include <iostream>
#include <string>

using namespace std;


#ifndef Product_hpp
#define Product_hpp

class Product {
	/// <summary>
	/// User Atrributes
	/// </summary>
private:
	string productID;
	string productName;
    int productCategory;
	bool productDisponibility;
	double productPrice;
public:
    Product();
    Product(string, string, int, double);
    string getProductID();
    string getProductName();
    double getProductPrice();
    int getProductCategory();
    void setProductID(string);
    void setProductName(string);
    void setProductPrice(double);
    void setProductCategory(int);
    ~Product();
};

#endif
