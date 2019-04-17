#include <iostream>
#include "UsersFile.h"

using namespace std;

vector <User> UsersFile::loadUsersFromFile(){
    User user;
    vector <User> users;
    CMarkup xml;

    xml.Load( USERS_FILE_NAME.c_str() );

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem() ){
        user.deserialize(xml.GetSubDoc());
        users.push_back(user);
    }

    return users;
}

void UsersFile::writeAllUsersToFile(vector <User> &users){

    CMarkup xml;
    xml.AddElem( "users" );
    xml.IntoElem();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++){
        xml.AddSubDoc(itr->serialize());
    }

    xml.OutOfElem();
    xml.Save( USERS_FILE_NAME.c_str() );
}
