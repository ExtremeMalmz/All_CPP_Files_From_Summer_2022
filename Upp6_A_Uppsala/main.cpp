//Uppgift 6 del 1

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <typeinfo>
#include<algorithm>

#include "Person1.h"
#include "PersonLista1.h"
#include "Transaktion1.h"
#include "TransaktionsLista1.h"





using namespace std;

int main()
{
  cout << "Vi startar med att lasa från en fil." << endl;

  TransaktionsLista transaktioner;
  //transaktioner.FixaPersoner();

  //PersonLista objekt skapas i Transaktionslista
  //Person personer;


  std::ifstream is("C:\\Users\\ericm\\Documents\\resa.txt"); //use this and put it in lasIn

  transaktioner.lasIn(is);



  int operation = 1;
  while (operation != 0)
    {
      cout << endl;
      cout << "Valj i menyn nedan:" << endl;
      cout << "0. Avsluta. Alla transaktioner sparas på fil." << endl;
      cout << "1. Skriv ut information om alla transaktioner." << endl;
      cout << "2. Las in en transaktion från tangentbordet." << endl;
      cout << "3. Berakna totala kostnaden." << endl;
      cout << "4. Hur mycket ärr en viss person skyldig?" << endl;
      cout << "5. Hur mycket ligger en viss person ute med?" << endl;
      cout << "6. Lista alla personer mm och FIXA" << endl;

      cin >> operation;
      cout << endl;


      switch (operation)
        {
          case 1: //done
            {
              transaktioner.skrivUt(cout);
              break;
            }

          case 2: //done
            {

              Transaktion transaktion;
              cout << "Ange transaktion i följande format" << endl;
              transaktion.skrivTitel(cout);
              transaktion.lasIn(cin);
              //transaktion.printVannLista();

              //cout << "transaktion naamn: " << transaktion.hamtaNamn();
              transaktioner.laggTill(transaktion);
              break;
            }

          case 3: //done!
            {
              //you will most likely have to strip (get rid of whitespaces) when your calculating stuff

              cout << "Den totala kostnanden för resan var "
                   << transaktioner.totalKostnad() << endl;
              break;
            }

          case 4:// done
            {
              cout << "Ange personen: ";
              string namn;
              cin >> namn;
              double ar_skyldig = transaktioner.arSkyldig(namn);
              if (ar_skyldig == 0.)
                cout << "Kan inte hitta personen " << namn << endl;
              else
                cout << namn << " är skyldig " << ar_skyldig << endl;
              break;
            }

          case 5: // done
            {
              cout << "Ange personen: ";
              string namn;
              cin >> namn;
              double ligger_ute_med = transaktioner.liggerUteMed(namn);
              if (ligger_ute_med == 0.)
                cout << "Kan inte hitta personen " << namn << endl;
              else
                cout << namn << " ligger ute med " << ligger_ute_med << endl;
              break;
            }

          case 6: //done
            {
              cout << "Nu skapar vi en personarray och reder ut det hela!" << endl;
              PersonLista lista = transaktioner.fixaPersoner();
              lista.skrivUtOchFixa(cout);
              break;
            }
        }
    }


//write out the transactions one last time
  std::ofstream os("resa.txt");
  transaktioner.skrivUt(os);


  return 0;
}
