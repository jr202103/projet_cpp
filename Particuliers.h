#ifndef PARTICULIERS_H
#define PARTICULIERS_H

#include "Clients.h"
#include "Adresse.h"
#include <ctime>    //type struct tm
#include <iostream>
#include <sstream>
#include <iomanip>  //setw()

#define SEPARATOR ";"
//#define SEPARATOR "\t"

using namespace std;

class Particuliers : public Clients
{
    public:
        //Particuliers();
        Particuliers(int, string,
                     string, string, int, string, string,
                     int, int, int, string, char);
            //identifiant NOM
            //adrLibelle adrComplem adrCodPost adrVILLE mail
            //parDateNA parDateNM parDateNJ parPrenom parSexe
        virtual ~Particuliers();

        void SetdateNaissance(int ,int ,int);//(tm val) {dateNaissance = val;}
        tm GetdateNaissance() { return dateNaissance; }
        string dateNaissanceF();  //get Formated aaaa-mm-jj
        void Setprenom(string val);
        string Getprenom() { return prenom; }
        void Setsexe(char val);
        char Getsexe() { return sexe; }
        virtual string ToString() ;//override;
        bool anniversaire();
        int age();

    protected:

    private:
        tm dateNaissance;   //type struct tm time
            //tm_year + 1900
            //tm_mon + 1
        string prenom;
        char sexe;
};

#endif // PARTICULIERS_H
