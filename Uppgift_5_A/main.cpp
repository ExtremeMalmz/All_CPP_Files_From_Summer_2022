#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

const int ANTAL_BOKSTAVER = 26;  // A-Z
const int ANTAL_SPRAK = 4;

class Text{
    private:
        string inText; //denna ar textstrangen som ska analyseras
        int poang_array[ANTAL_BOKSTAVER] = {0};//array of matchande poang
        string bokstav_array[ANTAL_BOKSTAVER]; //raknar totalabokstaver
        int totalaBokstaver;

    public:
        Text(string Text);
        void setText(const string &nyText);
        bool beraknaHistogramAbs();
        void skrivHistogramAbs();
};

Text::Text(string text){
    inText = text;
}

void Text::setText(const string &nyText){
    string inText = nyText;
    std::transform(inText.begin(), inText.end(), inText.begin(),
    [](unsigned char c){ return std::tolower(c); });
}

bool Text::beraknaHistogramAbs(){
    string alfabet = "abcdefghijklmnopqrstuvwxyz";
    string tecken1 = "",tecken2 = "";

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

    if(totalaBokstaver != 0){
        return true;
    }
    else{
        return false;
    }
}

void Text::skrivHistogramAbs(){
    cout << "\nResultat for bokstaverna A-Z\n" << endl;
    cout << "Totala antalet bokstaver: " << totalaBokstaver << endl;
    cout << "Bokstavsfordelning:\n" << endl;
    for(int i=0;i<26;i++){
        cout << bokstav_array[i] << ": " << poang_array[i] << endl;
    }
}

int main()
{
  string text;
  cout <<"Ge en rad med text:" << endl;
  getline(cin,text);

  Text minText(text);  // Ett objekt av typen Text skapas
  minText.setText(text);
  minText.beraknaHistogramAbs();
  minText.skrivHistogramAbs( );
  return 0;
}
