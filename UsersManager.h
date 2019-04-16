#include <iostream>
#include <vector>
#include <windows.h>
#include "UsersFile.h"

using namespace std;

class UsersManager{

    int loggedInUserID;
    vector <User> users;
    UsersFile usersFile;

    int getNewUserID();
    bool ifLoginExists(string login);
    User inputNewUserData();

public:

    UsersManager(string usersFileName): usersFile(usersFileName){
        loggedInUserID = 0;
        users = usersFile.loadUsersFromFile();
    };
    bool ifUserIsLoggedIn();
    int getLoggedInUserID();
    void registerUser();
    void printAllUsers();
    void logUserIn();
    void logUserOut();
    void changeUserPassword();
};
