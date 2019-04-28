#include "UsersManager.h"

using namespace std;

bool UsersManager::ifUserIsLoggedIn(){
    if(loggedInUserID > 0)
        return true;
    else
        return false;
}

int UsersManager::getLoggedInUserID(){
    return loggedInUserID;
}

void UsersManager::registerUser(){
    User user = inputNewUserData();

    users.push_back(user);
    usersFile.writeAllUsersToFile(users);

    cout << endl << "Konto zostalo zalozone pomyslnie." << endl << endl;
    system("pause");
}

User UsersManager::inputNewUserData(){
    User user;
    string login = "", password = "", name = "", surname = "";

    user.setUserID(getNewUserID());

    do{
        cout <<  "Podaj login: ";
        login = SupportiveMethods::inputLine();
    } while(ifLoginExists(login) == true || login == "");
    user.setLogin(login);

    cout << "Podaj haslo: ";
    password = SupportiveMethods::inputLine();
    user.setPassword(password);

    cout << "Podaj imie: ";
    name = SupportiveMethods::inputLine();
    name = SupportiveMethods::changeFirstLetterToUppercaseAndOtherToLowercase(name);
    user.setName(name);

    cout << "Podaj nazwisko: ";
    surname = SupportiveMethods::inputLine();
    surname = SupportiveMethods::changeFirstLetterToUppercaseAndOtherToLowercase(surname);
    user.setSurname(surname);

    return user;
}

int UsersManager::getNewUserID(){
    if (users.empty() == true)
        return 1;
    else
        return (users.back().getUserID() + 1);
}

bool UsersManager::ifLoginExists(string login){
    for (int i=0; i<users.size(); i++){
        if (users[i].getLogin() == login){
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl << endl;
            return true;
        }
    }
    return false;
}

void UsersManager::printAllUsers(){
    for (int i=0; i<users.size(); i++){
        users[i].print();
    }
}

void UsersManager::logUserIn(){
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = SupportiveMethods::inputLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int attempts = 3; attempts > 0; attempts--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << attempts << ": ";
                password = SupportiveMethods::inputLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedInUserID = itr -> getUserID();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UsersManager::logUserOut(){
    loggedInUserID = 0;
}

void UsersManager::changeUserPassword(){
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = SupportiveMethods::inputLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getUserID() == loggedInUserID)
        {
            itr -> setPassword(newPassword);
            break;
        }
    }
    usersFile.writeAllUsersToFile(users);
    cout << "Haslo zostalo zmienione." << endl << endl;
    system("pause");
}
