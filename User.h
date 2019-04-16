#include <iostream>
#include "Markup.h"

using namespace std;

class User{

    string userID;
    string login;
    string password;
    string name;
    string surname;

public:

    void setUserID(int newID);
    void setLogin(string newLogin);
    void setPassword(string newPassword);
    void setName(string newName);
    void setSurname(string newSurname);

    string getUserID();
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();

    string serialize();
    void deserialize(string strSubDoc);
    void view();
};
