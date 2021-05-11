#ifndef PROFESSIONNELS_H
#define PROFESSIONNELS_H

#include "Clients.h"
#include "Adresse.h"
#include <iostream>
#include <sstream>
#include <iomanip>  //setw()

#define SEPARATOR ";"
//#define SEPARATOR "\t"

using namespace std;

#define ARRSTATUS_SIZE 4
const string arrStatus[ARRSTATUS_SIZE]={"SARL", "SA", "SAS", "EURL"};

class Professionnels : public Clients
{
    public:
        //Professionnels();
        Professionnels(
            int, string,
            string, string, int, string, string,
            string, string,
            string, string, int, string );
            //identifiant NOM
            //adrLibelle adrComplem adrCodPost adrVILLE mail
            //proSiret proStatut
            //proAdrLibelle proAdrComplem proAdrCodPost proAdrVILLE
        virtual ~Professionnels();

        void Setsiret(string val);
        string Getsiret() { return siret; }
        void Setstatut(string val);
        string Getstatut() { return statut; }
        //void SetadresseSiege(Adresse val) { adresseSiege = val; }
        Adresse GetadresseSiege() { return *adresseSiege; }
        virtual string ToString() ;//override;

    protected:

    private:
        string siret;
        string statut;
        Adresse *adresseSiege;
};

#endif // PROFESSIONNELS_H
