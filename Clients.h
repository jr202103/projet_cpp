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

        int Getidentifiant() ;//{ return identifiant; }
        void Setidentifiant(int val) ;//{ identifiant = val; }
        string Getnom() { return nom; }
        void Setnom(string val) ;//{ nom = val; }
        Adresse GetadressePoste() { return *adressePoste; }
        //void SetadressePoste(Adresse val) { adressePoste = val; }
        string Getmail() { return mail; }
        void Setmail(string) ;//{ mail = val; }
        string GetidentifiantF() ;//format 00001
        virtual string ToString();
    protected:

    private:
        int identifiant;
        string nom;
        Adresse *adressePoste;
        string mail;
};

#endif // CLIENTS_H
