//
// Created by Chris Sandvik on 2/13/18.
//

#ifndef PROJECT_3_ACCOUNT_LIST_H
#define PROJECT_3_ACCOUNT_LIST_H

#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>

#include "account.h"

using namespace std;

/**
 *  account list class used to store a vector of accounts and interact with them
 */
class AccountList {
private:
    vector<Account> account_list;

public:

    /**
     * Default Constructor
     * Requires: nothing
     * Modifies: account list
     * Effects: calls load accounts function which loads accounts from a file
     */
    AccountList();

    /**
     * Account Getter
     * Requires: account index
     * Modifies: nothing
     * Effects: returns an account at a given index
     */
    Account getAccount (int accountIndex);

    /**
     * Add Account
     * Requires: account
     * Modifies: account list
     * Effects: appends account to the end of account list
     */
    void addAccount (Account account);

    /**
     * Delete Account
     * Requires: account index
     * Modifies: account list
     * Effects: deletes account at a given index from account list
     */
    void deleteAccount(int accountIndex);

    /**
     * Search Accounts
     * Requires: search string
     * Modifies: nothing
     * Effects: searches all account names for the search term and outputs result to the console
     */
    void searchAccountByName(string searchTerm);

    /**
     * Output High Scores
     * Requires: nothing
     * Modifies: nothing
     * Effects: outputs all accounts to the console with censored passwords
     */
    void displayHighScores();

    /**
     * Output High Scores
     * Requires: nothing
     * Modifies: nothing
     * Effects: outputs all accounts to the console with censored passwords
     */
    vector<vector<string>> getHighScores();

    /**
     * Save Account List to File
     * Requires: nothing
     * Modifies: accounts.txt
     * Effects: overwrites output file with current account list
     */
    void saveAccountList();

    /**
     * Load Account List
     * Requires: accounts.txt file
     * Modifies: account list
     * Effects: clears account vector and loads accounts from text file into account list
     */
    void loadAccountList();

    /**
     * Account Index Getter
     * Requires: username
     * Modifies: nothing
     * Effects: returns account index based on username
     */
    int indexFromUsername(string userName);

    /**
     * Password Matching Checker
     * Requires: first name, last name
     * Modifies: nothing
     * Effects: checks to make sure username and password belong to the same account
     */
    bool passwordMatches(string user, string pass);

    /**
     * Account List Length Getter
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns the length of the account list
     */
    int getListLength();

};


#endif //PROJECT_3_ACCOUNT_LIST_H
