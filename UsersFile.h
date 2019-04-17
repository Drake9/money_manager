#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "User.h"

using namespace std;

class UsersFile{

    const string USERS_FILE_NAME;

public:

    UsersFile(string usersFileName): USERS_FILE_NAME(usersFileName){};
    vector <User> loadUsersFromFile();
    void writeAllUsersToFile(vector <User> &users);
};
