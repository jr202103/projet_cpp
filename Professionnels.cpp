#include "Professionnels.h"

/*
Professionnels::Professionnels()
{
}
*/

Professionnels::Professionnels(
            int id, string n,
            string l, string c, int cp, string v, string mail,
            string siret, string statut,
            string proL, string proC, int proCp, string proV)
            //identifiant NOM
            //adrLibelle adrComplem adrCodPost adrVILLE mail
            //proSiret proStatut
            //proAdrLibelle proAdrComplem proAdrCodPost proAdrVILLE
    :Clients(id,n,l,c,cp,v,mail)
{
    this->Setsiret(siret);
    this->Setstatut(statut);
    this->adresseSiege = new Adresse(proL, proC, proCp, proV);
}

Professionnels::~Professionnels()
{
    if(adresseSiege != nullptr)
    {
        delete adresseSiege;
        adresseSiege = nullptr;
    }
}

void Professionnels::Setsiret(string val)
{
    //siret: string de 14 char chiffres
    bool b = true;
    int i = 0;
    while ( b && (i<val.length()) )
    {
        b=((val[i]>='0')&&(val[i]<='9'))?true:false;
        i++;
    }
    if ( b && (val.length() == 14) )
    {
        this->siret = val;
    }
    else
    {
        this->siret = "";
        ostringstream oss;
        oss<<"Erreur siret : \""<< val<<"\". Attendu 14 chiffres."<<endl;
        throw invalid_argument(oss.str());
    }
}

void Professionnels::Setstatut(string val)
{
    //const string arrStatus[ARRSTATUS_SIZE]={"SARL", "SA", "SAS", "EURL"};

    for (auto & c: val) c=toupper(c);

    bool b = false;
    int i = 0;
    while ( (b==false) && (i<ARRSTATUS_SIZE) )
    {
        b=(val==arrStatus[i++])?true:false;
    }
    if ( b )
    {
        this->statut = val;
    }
    else
    {
        this->statut = "";
        ostringstream oss;
        oss<<"Erreur statut : \""<< val<<"\". Attendu parmi :";
        for (int i=0; i<ARRSTATUS_SIZE; i++)
            oss<< " " << arrStatus[i];
        oss<<"."<<endl;
        throw invalid_argument(oss.str());
    }
}

string Professionnels::ToString()
{
    ostringstream oss;
    oss << Clients::ToString()
        << SEPARATOR << Getsiret()
        << SEPARATOR << Getstatut()
        << SEPARATOR << GetadresseSiege().ToString()
        ;
    return oss.str();
}
