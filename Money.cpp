#include "Money.h"

using namespace std;

/**-------- CONSTRUCTORS --------**/

Money::Money(){
    amount = 0;
}

Money::Money(int amount){
    this->amount = amount * 100;
}

Money::Money(string text){
    setAmount(text);
}

/**----- GETTERS & SETTERS ------**/

void Money::setAmount(int amount){
    this->amount = amount * 100;
}

void Money::setAmount(string text){
    if(!validateString(text)){
        cout << "Podana kwota: " << text << " jest nieprawidlowa." << endl;
        return;
    }

    int pointPosition = -1;
    for(int i=0; i<text.size(); i++){
        if(text[i] == ',' || text[i] == '.'){
            pointPosition = i;
            break;
        }
    }
    if(pointPosition == -1)
        amount = SupportiveMethods::convertStringToInt(text) * 100;
    else{
        int majors = SupportiveMethods::convertStringToInt(text.substr(0,pointPosition));
        int minors = SupportiveMethods::convertStringToInt(text.substr(pointPosition+1));
        amount = 100 * majors + minors;
    }
}

bool Money::validateString(string text){
    if(text == "")
        return false;

    int numberOfPoints = 0;
    int pointPosition = -1;

    for(int i=0; i<text.size(); i++){
        if(text[i] == ',' || text[i] == '.'){
            numberOfPoints++;
            pointPosition = i;
        }
        else{
            if(text[i] < '0' || text[i] > '9')
                return false;
        }
    }

    if(numberOfPoints > 1)
        return false;
    else if(numberOfPoints == 1 && pointPosition < text.size() - 3)
        return false;
    else
        return true;
}

string Money::getAmountAsString(){
    int majors = amount / 100;
    int minors = amount % 100;

    string output = SupportiveMethods::convertIntToString(majors) + ".";

    if(minors > 9)
        output += SupportiveMethods::convertIntToString(minors);
    else
        output += "0" + SupportiveMethods::convertIntToString(minors);

    return output;
}

/**--------------------------------**/

string Money::serialize(){
    CMarkup xml;
    xml.AddElem( "amount", getAmountAsString());

    return xml.GetDoc();
}

void Money::deserialize(string strSubDoc){

    CMarkup xml( strSubDoc );
    xml.FindElem();

    if ( xml.FindElem("amount" ) )
        setAmount(xml.GetData());
    else
        amount = 0;
}

/**------------ OPERATORS ------------**/

Money operator + (const Money &money1, const Money &money2){
    Money result(money1.amount + money2.amount);
    return result;
}

Money operator - (const Money &money1, const Money &money2){
    Money result(money1.amount - money2.amount);
    return result;
}

Money operator * (const Money &money, const int &number){
    Money result(money.amount * number);
    return result;
}

Money operator * (const int &number, const Money &money){
    Money result(money.amount * number);
    return result;
}

int operator / (const Money &money1, const Money &money2){
    int result = (money1.amount / money2.amount);
    return result;
}

Money operator / (const Money &money, const int &number){
    Money result(money.amount / number);
    return result;
}

bool operator == (const Money &money1, const Money &money2){
    return (money1.amount == money2.amount);
}

Money & Money::operator = (const Money &money2){
    this->amount = money2.amount;
}
