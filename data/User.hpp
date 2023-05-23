
#include <iostream>
#include <string>
using namespace std;


#ifndef User_hpp
#define User_hpp

class User {
private:
	string userID;
	string userName;
	double userMoneyAmount;

public:
	User();
	User(string, string, double);
	string getUserID();
	string getUserName();
	double getUserMoneyAmount();
	void setUserID(string);
	void setUserName(string);
	void setUserMoneyAmount(double);
	~User();
};

#endif
