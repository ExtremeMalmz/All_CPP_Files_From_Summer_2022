//Uppgift 6 del 1

#ifndef TRANSAKTIONSLISTA_H_INCLUDED
#define TRANSAKTIONSLISTA_H_INCLUDED


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int const MAX_TRANSAKTIONER = 100;


 class TransaktionsLista
 {
 private:
   int antal_transaktioner;
   Transaktion transaktionerr[MAX_TRANSAKTIONER];

 public:
   TransaktionsLista();
   ~TransaktionsLista();
   void   lasIn(istream & is);
   void   skrivUt(ostream & os);
   void   laggTill(Transaktion & t);
   double totalKostnad();
   double liggerUteMed(const string &namnet);
   double arSkyldig(const string &namnet);
   PersonLista fixaPersoner(){
       //call to it like this
       //creates a list of how much people have paid and how much they owe

       //just call to the personlista header while doing it
       // cout << "Fixar personer har" << endl;
       string namn = "";

        double liggerUt = 0, skyldigAv = 0;
        PersonLista personlista;

        //
        for(int i = 0;i < antal_transaktioner;i++){
            namn = transaktionerr[i].hamtaNamn();
            //cout << namn <<  endl;

            if(personlista.finnsPerson(namn)==false){
                //cout << "ligger ute med " << liggerUteMed(namn) << endl;

                //cout << "skyldig med " << arSkyldig(namn) << endl;
                liggerUt = liggerUteMed(namn);
                skyldigAv = arSkyldig(namn);

                Person person(namn,liggerUt,skyldigAv);

                personlista.laggTill(person);

            }
        }
        //Ska bara kolla att skyldig och betalat_andras ar samma summa.
        //personlista.skrivUtOchFixa(cout);

        return personlista;

   }

 };

TransaktionsLista::TransaktionsLista(){
    antal_transaktioner = 0;
    Transaktion transaktioner[MAX_TRANSAKTIONER] = {};
}

TransaktionsLista::~TransaktionsLista(){
     //cout << "Destroyed TransaktionsLista" << endl;
}



void TransaktionsLista::lasIn(istream & is){
    //seems like some of the stuff here should be moved to bool lasin() in the Transaktion class
    //Throw the stuff that got in here into the Transaktion array
    string input;
    string text;
    string text2;


        //Transaktion testTrans("DATUM","TYP","namn",500.0,19,"nobody");

    //good idea when seperating the rows is to put in a "check" for the new row?
    while (getline(is,input)){
        string datum = "";
        string typ = "";
        string namn = "";
        double belopp = 0.0;
        int antal_kompisar = 0;
        string kompis_namn = "";
        string kompisArr[MAX_PERSONER] = {};

        int antalGangerLooped = 0;
        char x = ' ';
        int arrayPosition = 0;
        //int antalTrans;


        //cout << input << endl;




        for(int i = 0;i < input.length();i++){
            //Transaktion transaktion;
            //transaktion("007","Mat","Ama",5000,1,"Ama");
            //cout << input[i] << endl;

            //rewrite this


            x = input[i];
            if(x != ' '){
                text = text + x;
            }
            else{
                //continue;
            }

            //cout << text;
            //cout << "X is: " << x << endl;


            if(x==' ' && text != ""){
                //cout << "space! String is: " << text << endl;

                if(antalGangerLooped == 0 && text!= " "){
                    //erases all whitespace from the thing (we dont want this)
                    text.erase(remove(text.begin(), text.end(), ' '), text.end());
                    //cout << text << " is datum" << endl;

                    datum = text;


                    antalGangerLooped++;
                    text = "";
                }
                    else if(antalGangerLooped == 1){
                        //erases all whitespace from the thing (we dont want this)
                        text.erase(remove(text.begin(), text.end(), ' '), text.end());
                        //cout << text << " is typ" << endl;

                        typ = text;

                        antalGangerLooped++;
                        text = "";
                        }
                        else if(antalGangerLooped == 2){
                            //erases all whitespace from the thing (we dont want this)
                            text.erase(remove(text.begin(), text.end(), ' '), text.end());
                            //cout << text << " is namn" << endl;

                            namn = text;

                            antalGangerLooped++;
                            text = "";
                        }
                            else if(antalGangerLooped == 3){
                                //erases all whitespace from the thing (we dont want this)
                                text.erase(remove(text.begin(), text.end(), ' '), text.end());
                                //cout << text << " is belopp" << endl;

                                belopp = stod(text);

                                antalGangerLooped++;
                                text = "";
                            }
                                    else if(antalGangerLooped == 4){
                                        //erases all whitespace from the thing (we dont want this)
                                        text.erase(remove(text.begin(), text.end(), ' '), text.end());
                                        //cout << text << " is antal kompisar" << endl;

                                        antal_kompisar = stoi(text);

                                        antalGangerLooped++;
                                        text = "";
                                    }
                                        else if(antalGangerLooped <= 5){
                                            //cout << "Vann: " << text << endl;
                                            kompisArr[arrayPosition] = text;
                                            arrayPosition++;

                                            kompis_namn = kompis_namn + " " + text;

                                            text = "";


                                        }


                else{
                    //cout << "somethings wrong";

                }
            }


            if(i==input.length()-1){

                //cout << "END OF LINE! List of friends are: " << text << endl;
                kompis_namn = kompis_namn + " " + text;

                kompisArr[arrayPosition] = text;
                text = "";
                /*
                for(int i = 0;i < text.length();i++){
                    x = text[i];

                    text2 = text2 + x;
                    if(x == ' '){
                        cout << "space detected! Current text2 is: " << text2 << endl;
                        text2.erase(remove(text2.begin(), text2.end(), ' '), text2.end());

                        kompisArr[arrayPosition] = text2;
                        arrayPosition++;
                        text2 = "";
                    }
                    else if(i == text.length()-1){
                        cout << "end of text length! Current text2 is: " << text2 << endl;
                        text2.erase(remove(text2.begin(), text2.end(), ' '), text2.end());

                        kompisArr[arrayPosition] = text2;

                        text2 = "";
                        text = "";
                    }






                }
                */
                //    if(namn=="Eric"){
                    //        cout <<"\n\nayoooo: "  << endl;
                    //    }
                //cout << "END OF LOOP - Turning into an object\n" << endl;
                transaktionerr[antal_transaktioner] = Transaktion(datum,typ, namn,belopp,antal_kompisar,kompis_namn,kompisArr);
                antal_transaktioner++;
            }
        }
        //cout << "START";
        //transaktionerr[antal_transaktioner] = Transaktion(datum,typ, namn,belopp,antal_kompisar,kompis_namn,kompisArr);
        //cout << "STOP";
        //transaktionerr[antal_transaktioner] = input;
        //antal_transaktioner++;
        //this is how we could do it, this actually checks when a new row is started, instead of a whitespace




    }



  //puts whats in the file into the transaktion class. TBD
}

void   TransaktionsLista::skrivUt(ostream & os){

    os << "Skriver ut alla transaktioner" << endl;
    os << "Antal transaktioner: " << antal_transaktioner << endl;
    for(int i = 0;i < antal_transaktioner;i++)
    {
        transaktionerr[i].skrivUt();
    }
}

void TransaktionsLista::laggTill(Transaktion & t){
    //cout << "lagger till en transaktion SIST  i arrayen transaktioner" << endl;
    //string friendArray[1] = {"Dwane"};
    //Transaktion X("2000","Mat","Eric",200,1,"Dwane",friendArray);

    transaktionerr[antal_transaktioner] = t;
    antal_transaktioner++;

}

double TransaktionsLista::totalKostnad(){
    //cout << "beraknar och returnerar summan pa hela resan" << endl;
    double totalaKostnad = 0.0,transaktionKostnad = 0.0;

    for(int i = 0;i < antal_transaktioner;i++){
        transaktionKostnad = transaktionerr[i].hamtaBelopp();
        totalaKostnad = totalaKostnad + transaktionKostnad;
    }


    return totalaKostnad;
}

double TransaktionsLista::liggerUteMed(const string &namnet){
    //cout << "raknar ut hur mycket nagon med inparametern namnet har betalat for resan - Ga genom alla transaktioner men SKA MINUS DET SOM DE HAR BETALAT" << endl;
       double summa = 0.;
   for (int i = 0; i < antal_transaktioner; i++)
     if (transaktionerr[i].hamtaNamn() == namnet)
       summa += transaktionerr[i].hamtaBelopp() *
                (1.0 - 1.0 / (transaktionerr[i].hamtaAntalKompisar() + 1));
   return summa;

}

double TransaktionsLista::arSkyldig(const string &namnet){
    //cout << "raknar ut hur mycket nagon med inparametern namnet ar skyldig for resan" << endl;
    string loopNamn = "";
    int antalKompisar = 0;
    double totalSumma = 0, relativSumma = 0;
    bool hittatNamnet = false;


    //cout << "\nFUNCTION Börjar" << endl;
    //cout << "Namnet ar: " << namnet << endl;

    //you have to loop thru friends and when u find it u divide the sum of what the original paid by the amount of friends
    for(int i = 0;i<antal_transaktioner;i++){
        antalKompisar = transaktionerr[i].hamtaAntalKompisar();
        //cout << "Antal kompisar ar: " << antalKompisar << endl;

        hittatNamnet = transaktionerr[i].finnsIarray(namnet);

        if(hittatNamnet == true){
            //cout << "namnet ar hittat i kompis listan" << endl;
            relativSumma = transaktionerr[i].hamtaBelopp();
            antalKompisar = antalKompisar+1;

            relativSumma = relativSumma/antalKompisar;
            totalSumma = relativSumma + totalSumma;
        }
        else{
            //cout << "inte i array" << endl;
        }
    }

    return totalSumma;

}

//how tf do u write this? <-- Look in the uppsala <-- couldnt find so its defined in the class
/*
TransaktionsLista::PersonLista::FixaPersoner(){
    cout << "skapar object Personlista med alla unika namn och hur mycket det ska betalas"
}

*/
#endif // TRANSAKTIONSLISTA_H_INCLUDED
