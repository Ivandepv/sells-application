
#include "../data/User.hpp"

User::User() :userID(""), userName(""), userMoneyAmount(0) {};

User::User(string cUserID, string cUserName, double cUserMoneyAmount) {
    userID = cUserID;
    userName = cUserName;
    userMoneyAmount = cUserMoneyAmount;
}

string User::getUserID() {
    return userID;
}

string User::getUserName() {
    return userName;
}

double User::getUserMoneyAmount() {
    return userMoneyAmount;
}

void User::setUserID(string cUserID) {
    userID = cUserID;
}

void User::setUserName(string cUserName) {
    userName = cUserName;
}

void User::setUserMoneyAmount(double cUserMoneyAmount) {
    userMoneyAmount = cUserMoneyAmount;
}

User::~User() {};