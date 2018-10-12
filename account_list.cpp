//
// Created by Chris Sandvik on 2/13/18.
//

#include "account_list.h"
#include <algorithm>

struct {
    bool operator()(Account a, Account b) const
    {
        return a.getScore() > b.getScore();
    }
} customCompare;

AccountList::AccountList() {
    loadAccountList();
}

Account AccountList::getAccount (int accountIndex) {
    return account_list.at(accountIndex);
}

void AccountList::addAccount(Account account) {
    account_list.push_back(account);
    saveAccountList();
}

void AccountList::deleteAccount(int accountIndex) {
    account_list.erase(account_list.begin() + accountIndex);
    saveAccountList();
}

void AccountList::searchAccountByName(string searchTerm) {
    int numOfResults = 0;
    cout << "\nResults:" << endl;
    cout << left << setw(20) << "First Name"
         << left << setw(20) << "Last Name"
         << left << setw(20) << "Username"
         << left << setw(20) << "Password"
         << left << setw(20) << "High Score" << endl;

    cout << "------------------------------------------------------------------------------------------" << endl;
    for (Account account : account_list) {
        if (account.getFirstName().find(searchTerm) != string::npos || account.getLastName().find(searchTerm) != string::npos) {
            numOfResults += 1;
            cout << left << setw(20) << account.getFirstName()
                 << left << setw(20) << account.getLastName()
                 << left << setw(20) << account.getUserName()
                 << left << setw(20) << account.getCensoredPassword()
                 << left << setw(20) << account.getScore() << endl;
        }
    }
    if (numOfResults == 0) {
        cout << "No results found!" << endl;
    }
    cout << endl;
}

void AccountList::displayHighScores() {

    vector<Account> list_copy = account_list;

    sort(list_copy.begin(), list_copy.end(), customCompare);

    cout << left << "\nLeaderboards:" << endl;
    cout << left << setw(25) << "\n    Name"
         << left << setw(20) << "Username"
         << left << setw(20) << "High Score" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    int i = 1;
    for (Account account : list_copy) {
        cout << left << setw(4) << i
             << left << setw(20) << account.getFirstName() + ' ' + account.getLastName()
             << left << setw(20) << account.getUserName()
             << left << setw(20) << account.getScore() << endl;
        i++;
    }
    cout << endl;
}

vector<vector<string>> AccountList::getHighScores() {
    vector<Account> list_copy = account_list;
    sort(list_copy.begin(), list_copy.end(), customCompare);

    vector<vector<string>> results;

    vector<string> userNames;
    userNames.push_back("User:");

    vector<string> scores;
    scores.push_back("Score:");

    int list_size = list_copy.size();
    if (list_size > 8) {
        list_size = 8;
    }

    for (int i = 0; i < list_size; i++) {
        userNames.push_back(list_copy[i].getUserName());
        scores.push_back(to_string(list_copy[i].getScore()));
    }

    results.push_back(userNames);
    results.push_back(scores);

    return results;

}

void AccountList::saveAccountList() {
    ofstream outFile("accounts.txt");
    if (outFile) {
        // output manipulation
        for (Account account : account_list) {
            outFile << account.getUserName() << ',' << account.getPassword() << ',' << account.getFirstName() << ',' << account.getLastName() << ',' << account.getScore() << endl;
        }
    } else {
        cout << "Error saving accounts to file" << endl;
    }
    outFile.close();
}

void AccountList::loadAccountList() {
    account_list.clear();
    ifstream account_file("accounts.txt");
    string line;
    while(getline(account_file, line)) {
        Account account(line);
        account_list.push_back(account);
    }
}

int AccountList::indexFromUsername(string userName) {
    int index = 0;
    for (Account account: account_list) {
        if (account.getUserName() == userName) {
            return index;
        }
        index++;
    }
    return -1;
}

bool AccountList::passwordMatches(string user, string pass) {
    for (Account account: account_list) {
        if (account.getUserName() == user && account.getPassword() == pass) {
            return true;
        }
    }
    return false;
}

int AccountList::getListLength() {
    return account_list.size();
}