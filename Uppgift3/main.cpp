#include <iostream>
using namespace std;

void skrivInfo(){
    cout << "Du anger två tal. Sedan väljer du vad du vill göra med de.\nDu kan Multiplicera med M, Addition med A och Kvadratsumman med K" << endl;
}

int lasEttTal(int tal){
    cout << "Ange ett heltal" << endl;
    cin >> tal;
    return tal;
}

string lasOp(string op){
    cout << "Ange ditt val (M) (A) (K)" << endl;
    cin >> op;
    return op;
}

void ordna(int &tal1, int &tal2){
    int talhallare = 0;

    if(tal1 > tal2){
        talhallare = tal1;
        tal1 = tal2;
        tal2 = talhallare;
    }
}

int berakna(int tal1, int tal2, string op){
    int static summa = 1;

    if(op == "M" || op ==  "m"){
        for(int i = tal1; i < tal2;i++){
            summa = summa * i;
        }
        summa = (summa * tal2);
        return summa;
    }
    else if(op == "A" || op == "a"){
        for(int i = tal1; i < tal2;i++){
            summa = summa + i;
        }
        summa = (summa + tal2)-1;
        return summa;
    }


    else if(op == "K"|| op == "k"){
        if(tal1 > 0 && tal2 > 0){
            for(int i = tal1;i < tal2;i++){
                summa = summa + (i*i);
            }
            summa = summa + (tal2 * tal2)-1;
            return summa;
        }
    }
}

void skrivResultat(int svar){
    cout << "Det blev: " << svar << endl;
}



int main()
{
    int tal1 = 0, tal2 = 0, svar = 0;
    string op = "";

    skrivInfo( );

    tal1 = lasEttTal(tal1);
    cout << "Ditt nummer ar: " << tal1 << endl;


    tal2 = lasEttTal(tal2);
    cout << "Ditt nummer ar: " << tal2 << endl;

    op = lasOp(op);

    ordna(tal1,tal2);

    svar = berakna(tal1, tal2, op);

    skrivResultat(svar);

}
// Definitioner av funktionerna
