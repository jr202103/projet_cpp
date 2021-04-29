#include "Clients.h"

/*
Clients::Clients()
{
}
*/

Clients::Clients(int id, string n, string l, string c, int cp, string v, string mail)
{
    Setidentifiant(id);
    Setnom(n);
    Setmail(mail);
    adressePoste = new Adresse(l, c, cp, v);
}

Clients::~Clients()
{
    if(adressePoste != nullptr)
    {
        delete adressePoste;
        adressePoste = nullptr;
    }
}

int Clients::Getidentifiant()
{
    return identifiant;
}

string Clients::GetidentifiantF()
{
    ostringstream oss;
    oss.width(5);
    oss.fill('0');
    oss<<Getidentifiant();
    return oss.str();
}

void Clients::Setidentifiant(int val)
{
    identifiant = val;
}

void Clients::Setnom(string val)
{
    if ( (val.length() > 0) && (val.length() <= 50) )
    {
        //for (auto & c: val) c=toupper(c);
        this->nom = val;
    }
    else
    {
        this->nom = "";
        ostringstream oss;
        oss<<"Erreur nom : \""<< val<<"\". Absent ou trop long."<<endl;
        throw invalid_argument(oss.str());
    }
}

void Clients::Setmail(string val)
{
    int i1 =val.find('@');
    int i2 =val.find('@', i1+1); //2e @ ?
    //if ( val.find('@') >= 0 )
    //if ( val.find('@') != npos )
    //if ( val.find('@') != std::basic_string::npos )
    if ( (i1 >= 0) && (i2 == -1) )
    {
        this->mail = val;
    }
    else
    {
        this->mail = "";
        ostringstream oss;
        oss<<"Erreur mail : \""<< val<<"\". Attendu avec un arobase."<<endl;
        throw invalid_argument(oss.str());
    }
}

string Clients::ToString()
{
    ostringstream oss;
    oss <<GetidentifiantF()
        <<SEPARATOR<<Getnom()
        <<SEPARATOR<<GetadressePoste().ToString()
        <<SEPARATOR<<Getmail()
        ;
    return oss.str();
}
