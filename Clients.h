#ifndef CLIENTS_H
#define CLIENTS_H

#include <iostream>
#include <sstream>
#include <string>
#include "Adresse.h"

#define SEPARATOR ";"
//#define SEPARATOR "\t"

using namespace std;

class Clients
{
    public:
        //Clients();
        Clients(int, string, string, string, int, string, string);
                //identifiant NOM
                //adrLibelle adrComplem adrCodPost adrVILLE mail
        virtual ~Clients();

        void Setidentifiant(int val);
        int Getidentifiant();
        string GetidentifiantF();  //Formated 00001
        void Setnom(string val);
        string Getnom() { return nom; }
        //void SetadressePoste(Adresse val) { adressePoste = val; }
        Adresse GetadressePoste() { return *adressePoste; }
        void Setmail(string);
        string Getmail() { return mail; }
        virtual string ToString();
    protected:

    private:
        int identifiant;
        string nom;
        Adresse *adressePoste;
        string mail;
};

#endif // CLIENTS_H
