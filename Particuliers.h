#ifndef PARTICULIERS_H
#define PARTICULIERS_H

#include "Clients.h"
#include "Adresse.h"
#include <ctime>
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

        tm GetdateNaissance() { return dateNaissance; }
        string dateNaissanceF();  //aaaa-mm-jj
        void SetdateNaissance(int ,int ,int);//(tm val) { dateNaissance = val; }
        string Getprenom() { return prenom; }
        void Setprenom(string val) ;//{ prenom = val; }
        char Getsexe() { return sexe; }
        void Setsexe(char val) ;//{ sexe = val; }
        virtual string ToString() ;//override;
        bool anniversaire();
        int age();

    protected:

    private:
        tm dateNaissance;
            //tm_year + 1900
            //tm_mon + 1
        string prenom;
        char sexe;
};

#endif // PARTICULIERS_H
