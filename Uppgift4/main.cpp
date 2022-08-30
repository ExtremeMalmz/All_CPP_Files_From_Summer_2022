#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <algorithm>

using namespace std;

const int ANTAL_BOKSTAVER = 26;
int poang_array[ANTAL_BOKSTAVER] = {};
string bokstav_array[ANTAL_BOKSTAVER]={};

void skriv_histogram(int totalaBokstaver){
    cout << "Totala bokstaver ar: " << totalaBokstaver << endl;
    for(int i=0;i<26;i++){
        cout << bokstav_array[i] << ": " << poang_array[i] << endl;
    }
}

int berakna_histogram_abs(string text){
    string alfabet = "abcdefghijklmnopqrstuvwxyz";
    string tecken1 = "",tecken2 = "";
    int totalaBokstaver = 0;

    for(int i=0;i<ANTAL_BOKSTAVER;i++){
        bokstav_array[i] = alfabet[i];
    }

    for(int i = 0;i<text.length();i++){
        tecken1 = text[i];
        for(int j = 0;j<ANTAL_BOKSTAVER;j++){
            tecken2 = bokstav_array[j];
            if(tecken1.compare(tecken2)==0){
                poang_array[j] = poang_array[j]+1;
                totalaBokstaver += 1;
            }
        }
    }
    return totalaBokstaver;
}

int main()
{
    string text = "";
    cout << "AAnge en text:";
    getline(cin,text);
    //makes it lowercase
    std::transform(text.begin(), text.end(), text.begin(),
    [](unsigned char c){ return std::tolower(c); });

    int totalaBokstaver = berakna_histogram_abs(text);
    skriv_histogram(totalaBokstaver);

    return 0;
}
