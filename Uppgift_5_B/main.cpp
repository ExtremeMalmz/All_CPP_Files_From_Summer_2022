#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

const int ANTAL_BOKSTAVER = 26;  // A-Z
const int ANTAL_SPRAK = 4;
const double sprak_array[ANTAL_SPRAK][ANTAL_BOKSTAVER]=
       {{8.27,1.48,2.94,4.03,11.78,2.22,1.72,6.77, // engelska
         7.39,0.12,0.81,3.76,2.85,6.71,7.79,1.54,
         0.05,5.95,6.69,9.07,2.66,1.13,2.14,0.19,
         1.89,0.03},
        {7.97,1.40,3.55,3.79,16.89,1.02,1.00,0.75, // franska
         7.08,0.38,0.04,5.51,2.82,8.11,5.19,2.78,
         1.01,6.69,8.35,7.22,6.09,1.35,0.02,0.54,
         0.30,0.15},
        {9.50,1.11,1.53,5.30,8.94,1.74,3.57,3.94,  // svenska
         3.98,0.89,3.26,4.93,3.41,8.46,5.01,1.77,
         0.00,6.73,5.56,9.20,1.94,2.42,0.00,0.05,
         0.45,0.00},
        {5.12,1.95,3.57,5.07,16.87,1.35,3.00,5.79, // tyska
         8.63,0.19,1.14,3.68,3.12,10.64,1.74,0.42,
         0.01,6.30,6.99,5.19,3.92,0.77,1.79,0.01,
         0.69,1.24}};

class Text{
    private:
        string inText; //denna ar textstrangen som ska analyseras
        int poang_array[ANTAL_BOKSTAVER] = {0};//array of matchande poang
        string bokstav_array[ANTAL_BOKSTAVER]; //raknar totalabokstaver
        string poang_array_men_string[ANTAL_BOKSTAVER];
        int totalaBokstaver = 0;
        double kvadratEng,kvadratFra,kvadratSve,kvadratTys;

    public:
        Text(string Text);
        void setText(const string &nyText);
        bool beraknaHistogramAbs();
        void skrivHistogramAbs();
        void abs_till_rel();
        void plotta_histogram_rel();
        string tolka();
};

Text::Text(string text){
    inText = text;
}

void Text::setText(const string &nyText){
    inText = nyText;
}

bool Text::beraknaHistogramAbs(){
    string alfabet = "abcdefghijklmnopqrstuvwxyz";
    string tecken1 = "",tecken2 = "";
    totalaBokstaver = 0;

    for(int i=0;i<ANTAL_BOKSTAVER;i++){
        bokstav_array[i] = alfabet[i];
    }

    for(int i = 0;i<inText.length();i++){
        tecken1 = inText[i];
        for(int j = 0;j<ANTAL_BOKSTAVER;j++){
            tecken2 = bokstav_array[j];
            if(tecken1.compare(tecken2)==0){
                poang_array[j] = poang_array[j]+1;
                totalaBokstaver += 1;
            }
        }
    }
    const int totalaBokstaverKonst = totalaBokstaver; //sa att det inte blir ett annat tal efter rakningen

    if(totalaBokstaver != 0){
        abs_till_rel();
        plotta_histogram_rel();
    }
    else{
        cout << "Det fanns inga bokstaver A-Z!\nAvslutar Programmet!";
        exit(EXIT_FAILURE);
    }
}

void Text::abs_till_rel(){
    double totalPoang = 0.0;
    double poangFranArray = 0.0, procentPoang = 0.0,procent1 = 0.0,score1 = 0.0;

    for(int i = 0;i<ANTAL_BOKSTAVER;i++){   //hittar alla poang som finns i poang array
        totalPoang = poang_array[i] + totalPoang;
    }

    for(int i = 0;i<ANTAL_BOKSTAVER;i++){
        /*
        d_poang = poang[c];
        procent_poang = (d_poang/total)*100;
        procent_1 = TOLK_HJALP[d][c];
        score_1 = (procent_poang-procent_1)*(procent_poang-procent_1);
        totalscore_1 = score_1 + totalscore_1;
        */

        //WIP
        poangFranArray = poang_array[i];   //kalkylerar hur mycket varenda tecken uppkommer
        procentPoang = (poangFranArray/totalPoang)*100;

        procent1 = sprak_array[]

        poangFranArray = round(poangFranArray*2);  //here we round it into the nearest 0.5
        poang_array[i] = poangFranArray;   //add it into the array
    }
}

void Text::plotta_histogram_rel(){
    char symbol = '*';
    int poangFranArray = 0;

    //loop genom poang och gör om det till en sträng array
    for(int i = 0;i<ANTAL_BOKSTAVER;i++){
        poangFranArray = poang_array[i];

        std::string stuff(poangFranArray, symbol);
        poang_array_men_string[i] = stuff;
    }

}

string Text::tolka(){
    double kvadratSumma = 0, totalSumma = 0,minstKvadratsumma = 10000000000,minstKvadratsummaPOS = 0;

    for(int i = 0;i<ANTAL_SPRAK;i++){
        for(int j = 0;j<ANTAL_BOKSTAVER;j++){
            kvadratSumma = (sprak_array[i][j]-poang_array[j])*(sprak_array[i][j]-poang_array[j]);
            totalSumma = kvadratSumma + totalSumma;
        }

        if(i==0){
            kvadratEng = totalSumma;
        }
            else if(i==1){
                kvadratFra = totalSumma;
            }
                else if(i==2){
                    kvadratSve = totalSumma;
                }
                    else if(i==3){
                        kvadratTys = totalSumma;
                    }

        if(totalSumma<minstKvadratsumma){
            minstKvadratsummaPOS = i;
            minstKvadratsumma = totalSumma;
        }
        totalSumma = 0;
    }

    if(minstKvadratsummaPOS == 0){
        return "engelska";
    }
        else if(minstKvadratsummaPOS == 1){
            return "franska";
        }
            else if(minstKvadratsummaPOS == 2){
                return "svenska";
            }
                else if(minstKvadratsumma == 3){
                    return "tyska";
                }
}

void Text::skrivHistogramAbs(){

    cout << "\nResultat for bokstaverna A-Z\n" << endl;

    cout << "Totala antalet bokstaver: " << totalaBokstaver << endl;
    cout << "engelska har kvadratsumma: " << kvadratEng << endl;
    cout << "franksa har kvadratsumma: " << kvadratFra << endl;
    cout << "svenska har kvadratsumma: " << kvadratSve << endl;
    cout << "tyska har kvadratsumma: " << kvadratTys << endl;
    cout << "Det ar mest troligt att spraket ar " << tolka() << ".\n" << endl;


    cout << "Bokstavsfordelning:\n" << endl;
    for(int i=0;i<26;i++){
        cout << bokstav_array[i] << ": " << poang_array_men_string[i] << endl;
    }
}

string namn_pa_fil(){
    string filnamn = "";

    cout << "Ange filen du vill lasa: " << endl;
    getline(cin,filnamn);

    if(filnamn.rfind(".txt")==-1){
        filnamn.append(".txt");
    }
    return filnamn;
}

string inlasning(string filnamn){
    string filAdress = "C:\\Users\\ericm\\Documents\\";
    string filText = "", helaFilText = "";
    ifstream inFile;

    filAdress.append(filnamn);
    inFile.open(filAdress);

    if(!inFile){
        cout << "Ingen fil med namnet finns!" << endl;
        exit(1);
    }
    else{
        while(!inFile.eof()){
            getline(inFile,filText);
            helaFilText = filText + helaFilText;
        }
    }
    std::transform(helaFilText.begin(), helaFilText.end(), helaFilText.begin(),
    [](unsigned char c){ return std::tolower(c); });
    return helaFilText;
}

int main()
{
    string text = "";

    string filnamn = namn_pa_fil();
    text = inlasning(filnamn);

    Text minText(text);  // Ett objekt av typen Text skapas
    minText.setText(text);
    minText.beraknaHistogramAbs();
    minText.tolka();
    minText.skrivHistogramAbs( );

    return 0;
}
