#include "Adresse.h"

/*
Adresse::Adresse()
{
}
*/

Adresse::Adresse(string l, string c, int cp, string v)
{
    Setlibelle(l);
    Setcomplement(c);
    Setcode(cp);
    Setville(v);
}

Adresse::~Adresse()
{
}

void Adresse::Setville(string val)
{
    if (val.length() > 0)
    {
        for (auto & c: val) c=toupper(c);
        this->ville = val;
    }
    else
    {
        this->ville = "";
        ostringstream oss;
        oss<<"Erreur ville : \""<< val<<"\". Absente."<<endl;
        throw invalid_argument(oss.str());
    }
}

string Adresse::ToString()
{
    ostringstream oss;
    oss <<Getlibelle()
        <<SEPARATOR<<Getcomplement()
        <<SEPARATOR<<Getcode()
        <<SEPARATOR<<Getville()
        ;
    return oss.str();
}
