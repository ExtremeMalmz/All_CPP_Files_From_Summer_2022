#include <iostream>
using namespace std;

int konvertTidTillSekunder(int nummer, string tid){
    if(tid == "timme"){
        return (nummer*60)*60;
    }
    else if(tid == "minut"){
        return nummer * 60;
    }
}

int main(){
    int startNummer = 0, startTidTimmar = 0, startTidMinut = 0, startTidSekunder = 0, malTidTimmar = 0, malTidMinut = 0, malTidSekunder = 0, totalStartTid = 0, totalMalTid = 0, totalTid = 0, vinnarNummer = 0, vinnarTid = 86400, vinnarTimmar = 0, vinnarMinuter = 0, vinnarSekunder = 0, counter = 0;
    int sekunderIEnDag = 86400;

    while(1){
        cout << "Startnummer? ";
        cin >> startNummer;

        if(startNummer < 0){
            if(counter == 0){
                printf("Inga tavlande!\nProgrammet avslutas");
                break;
            }
            else{
                cout << "Vinnare är startnummer: " << vinnarNummer << endl;

                while(vinnarTid>= 3600){
                vinnarTid = vinnarTid-3600;
                vinnarTimmar++;
                }

                while(vinnarTid>= 60){
                vinnarTid = vinnarTid-60;
                vinnarMinuter++;
                }

                vinnarSekunder = vinnarTid;

                cout << "Tim : " << vinnarTimmar << " Min: " << vinnarMinuter << " Sek: " << vinnarSekunder << endl;
                cout << "Antal Tävlande: " << counter << "\nProgrammet avslutas" << endl;
                exit(EXIT_FAILURE);
            }
        }
        counter++;

        cout << "Starttid? ";
        cin >> startTidTimmar >> startTidMinut >> startTidSekunder;

        startTidTimmar = konvertTidTillSekunder(startTidTimmar,"timme");
        startTidMinut = konvertTidTillSekunder(startTidMinut,"minut");
        totalStartTid = startTidTimmar + startTidMinut + startTidSekunder;

        cout << "Måltid? ";
        cin >> malTidTimmar >> malTidMinut >> malTidSekunder;

        malTidTimmar = konvertTidTillSekunder(malTidTimmar,"timme");
        malTidMinut = konvertTidTillSekunder(malTidMinut,"minut");
        totalMalTid = malTidTimmar + malTidMinut + malTidSekunder;

        if(totalStartTid>totalMalTid){
            totalStartTid = sekunderIEnDag - (totalStartTid);
            totalTid = totalMalTid + totalStartTid;
        }
        else{
            totalTid = totalMalTid - totalStartTid;
        }

        if(totalTid < vinnarTid){
            vinnarNummer = startNummer;
            vinnarTid = totalTid;
        }
    }
}
