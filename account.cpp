//
// Created by Chris Sandvik on 2/13/18.
//

#include "account.h"

Account::Account() {
    user_name = "";
    password = "";
    first_name = "";
    last_name = "";
    score = 0;
}

Account::Account(string accountStr) {
    vector<string> accountInfo;
    string token;
    istringstream tokenStream(accountStr);
    while (getline(tokenStream, token, ',')) {
        accountInfo.push_back(token);
    }

    user_name = accountInfo.at(0);
    password = accountInfo.at(1);
    first_name = accountInfo.at(2);
    last_name = accountInfo.at(3);
    stringstream newSStream(accountInfo.at(4));
    newSStream >> score;
}

Account::Account(string first, string last, string user, string pass, int sc) {
    first_name = first;
    last_name = last;
    user_name = user;
    password = pass;
    score = sc;
}

string Account::getFirstName() {
    return first_name;
}

void Account::setFirstName(string first) {
    Account::first_name = first;
}

string Account::getLastName() {
    return last_name;
}

void Account::setLastName(string last) {
    Account::last_name = last;
}

string Account::getUserName() {
    return user_name;
}

void Account::setUserName(string user) {
    Account::user_name = user;
}

string Account::getPassword() {
    return password;
}

void Account::setPassword(string pass) {
    Account::password = pass;
}

int Account::getScore() {
    return score;
}

void Account::setScore(int score) {
    Account::score = score;
}

string Account::getCensoredPassword() {
    string censoredString = "";
    for (int i = 0; i < password.length(); i++) {
        censoredString += '*';
    }
    return censoredString;
}

void Account::outputAccountDetails() {
    cout << "First Name: " << first_name << endl;
    cout << "Last Name: " << last_name << endl;
    cout << "User Name: " << user_name << endl;
    cout << "Password: " << password << endl;
    cout << "High Score: " << score << endl;
}
