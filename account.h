//
// Created by Chris Sandvik on 2/13/18.
//

#ifndef PROJECT_3_ACCOUNT_H
#define PROJECT_3_ACCOUNT_H

#include <iostream>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

/**
 *  account class used to store the information associated with a user account
 */
class Account {
private:
    string first_name;
    string last_name;
    string user_name;
    string password;
    int score;

public:



    /**
     * Default Constructor
     * Requires: nothing
     * Modifies: first name, last name, username, password
     * Effects: sets all values to an empty string
     */
    Account();

    /**
     * Non-Default Constructor One
     * Requires: account string
     * Modifies: first name, last name, username, password
     * Effects: sets all values to values in the account string read from file
     */
    Account(string accountStr);

    /**
     * Non-Default Constructor Two
     * Requires: first name, last name, username, password
     * Modifies: first name, last name, username, password
     * Effects: sets all variables to given values
     */
    Account(string first, string last, string user, string pass, int sc);

    /**
     * First Name Getter
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns first name as a string
     */
    string getFirstName();

    /**
     * First Name Setter
     * Requires: first name string
     * Modifies: first name
     * Effects: sets first name to given value
     */
    void setFirstName(string firstName);

    /**
     * Last Name Getter
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns last name as a string
     */
    string getLastName();

    /**
     * Last Name Setter
     * Requires: last name string
     * Modifies: last name
     * Effects: sets last name variable to given value
     */
    void setLastName(string lastName);

    /**
     * User Name Getter
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns user name variable as a string
     */
    string getUserName();

    /**
     * User Name Setter
     * Requires: user name string
     * Modifies: user name
     * Effects: sets user name varable to given value
     */
    void setUserName(string userName);

    /**
     * Password Getter
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns password as a string
     */
    string getPassword();

    /**
     * Password Setter
     * Requires: password string
     * Modifies: password
     * Effects: sets password to given variable
     */
    void setPassword(string pass);

    /**
     * Score Getter
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns password as an int
     */
    int getScore();

    /**
     * Password Setter
     * Requires: password string
     * Modifies: password
     * Effects: sets score to given int
     */
    void setScore(int score);

    /**
     * Censored Password Getter
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns string of stars the same length as the password
     */
    string getCensoredPassword();

    /**
     * Display Account Details
     * Requires: nothing
     * Modifies: nothing
     * Effects: outputs account details to the console
     */
    void outputAccountDetails();

};


#endif //PROJECT_3_ACCOUNT_H
