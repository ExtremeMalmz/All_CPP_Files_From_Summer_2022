//Uppgift 6 del 1

#ifndef REALADDER_H_INCLUDED
#define REALADDER_H_INCLUDED

#include <iostream>
#include <cmath>

using namespace std;

int const MAX_PERSONER = 100;

class PersonLista
 {
 private:

   int    antal_personer;
   Person personer[MAX_PERSONER];

 public:
   PersonLista();
   ~PersonLista();
   void   laggTill(Person ny_person);
   void   skrivUtOchFixa(ostream &os);
   double summaSkyldig();
   double summaBetalat();
   bool   finnsPerson(const string& namn);
  // ...eventuellt div. annat...
 };

PersonLista::PersonLista(){
    antal_personer = 0;

}

PersonLista::~PersonLista(){
    //cout << "Destroyed Personlista" << endl;
}

void PersonLista::laggTill(Person ny_person){
    //cout << "add to the personer array" << endl;
    //SEND IN THE PERSON HERE AND PUT IT INTO THE ARRAY LIST
    //ny_person("Eric",2,2);

    personer[antal_personer] = ny_person;
    antal_personer++;
}

void PersonLista::skrivUtOchFixa(ostream &os){
    //cout << "dubbelkollar att beloppet skyldig ar samma som folk har gett" << endl;

    double betalatForAndrasSumma = 0, skyldigForAndrasSumma = 0;

    betalatForAndrasSumma = round(summaSkyldig());

    skyldigForAndrasSumma = round(summaBetalat());

    if(betalatForAndrasSumma == skyldigForAndrasSumma){
        cout << "Den summan som folk har betalat for andras ar exakt den som folk ar skyldiga" << endl;
    }
    else{
        cout << "Summan betalat for andras stammer inte med den som folk ar skyldiga" << endl;
    }

    for(int i = 0;i < antal_personer;i++){
        personer[i].skrivUt(cout);
    }

}

double PersonLista::summaSkyldig(){
    //cout << "raknar ut SUMMAN som folk ar SKYLDIGA for skrivutochfixa" << endl;

    double skyldigSumma = 0;

    for(int i = 0;i < antal_personer;i++){
        skyldigSumma = skyldigSumma + personer[i].hamtaSkyldig();
    }
    return skyldigSumma;
}

double PersonLista::summaBetalat(){
    //cout << "raknar ut SUMMAN som folk har BETALAT for skrivutochfixa" << endl;

    double betalatSumma = 0;

    for(int i = 0;i < antal_personer;i++){
        betalatSumma = betalatSumma + personer[i].hamtaBetalat();
    }
    return betalatSumma;
}

bool PersonLista::finnsPerson(const string &namn){
    //cout << "kollar om en person finns i listan for att undvika dubletter" << endl;

    for(int i = 0;i < antal_personer;i++){
        //cout << "Checking for name: " << personer[i].hamtaNamn() << endl;

        if(namn == personer[i].hamtaNamn()){
            //cout << "found in the list!" << endl;
            return true;
        }
    }

    return false;

}

#endif // REALADDER_H_INCLUDED
