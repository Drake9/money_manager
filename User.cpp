#include <iostream>
#include "User.h"

using namespace std;

void User::setUserID(int newID){
    if(newID >= 0)
        userID = newID;
};

void User::setLogin(string newLogin){
    login = newLogin;
};

void User::setPassword(string newPassword){
    password = newPassword;
};

void User::setName(string newName){
    name = newName;
};

void User::setSurname(string newSurname){
    surname = newSurname;
};

/****************************************/

int User::getUserID(){
    return userID;
};

string User::getLogin(){
    return login;
};

string User::getPassword(){
    return password;
};

string User::getName(){
    return name;
};

string User::getSurname(){
    return surname;
};

/******************************************/

string User::serialize(){
    CMarkup xml;
    xml.AddElem( "user" );
    xml.IntoElem();
    xml.AddElem( "userID", SupportiveMethods::convertIntToString(userID) );
    xml.AddElem( "login", login );
    xml.AddElem( "password", password );
    xml.AddElem( "name", name );
    xml.AddElem( "surname", surname );
    xml.OutOfElem();

    return xml.GetDoc();
}

void User::deserialize(string strSubDoc){

    CMarkup xml( strSubDoc );
    xml.FindElem(); // user
    xml.IntoElem();

    if ( xml.FindElem("userID" ) )
        userID = SupportiveMethods::convertStringToInt(xml.GetData());
    else
        userID = 0;

    if ( xml.FindElem("login") )
        login = xml.GetData();
    else
        login = "";

    if ( xml.FindElem("password") )
        password = xml.GetData();
    else
        password = "";

    if ( xml.FindElem("name") )
        name = xml.GetData();
    else
        name = "";

    if ( xml.FindElem("surname") )
        surname = xml.GetData();
    else
        surname = "";
}

void User::view(){
    cout << endl << "userID: " << userID << endl;
    cout << "login: " << login << endl;
    cout << "password: " << password << endl;
    cout << "name: " << name << endl;
    cout << "surname: " << surname << endl;
}
