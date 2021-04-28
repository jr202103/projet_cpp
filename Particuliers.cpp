#include "Particuliers.h"

/*
Particuliers::Particuliers()
{
}
*/

Particuliers::Particuliers(int id, string n,
                           string l, string c, int cp, string v, string mail,
                           short dateNA, short dateNM,short dateNJ, string p, char s)
//identifiant NOM
//adrLibelle adrComplem adrCodPost adrVILLE mail
//parDateN parPrenom parSexe
    :Clients(id,n,l,c,cp,v,mail)
{
    this->SetdateNaissance(dateNA, dateNM, dateNJ);
    this->Setprenom(p);
    this->Setsexe(s);
}

Particuliers::~Particuliers()
{
}

void Particuliers::SetdateNaissance(short a,short m,short j)
{
    dateNaissance.tm_sec  =0;
    dateNaissance.tm_min  =0;
    dateNaissance.tm_hour =0;
    dateNaissance.tm_mday =j;
    dateNaissance.tm_mon  =m-1;
    dateNaissance.tm_year =a-1900;
    dateNaissance.tm_wday =0;
    dateNaissance.tm_yday =0;
    dateNaissance.tm_isdst=0;
}

string Particuliers::dateNaissanceF()  //aaaa-mm-jj
{
    ostringstream oss;
    oss.width(4);
    oss.fill('0');
    oss << (dateNaissance.tm_year + 1900)<<'-';
    oss.width(2);
    oss << (dateNaissance.tm_mon + 1) << '-';
    oss.width(2);
    oss << dateNaissance.tm_mday;
    return oss.str();
}

void Particuliers::Setprenom(string val)
{
    if ( (val.length() > 0) && (val.length() <= 50) )
    {
        for (auto & c: val) c=tolower(c);
        val[0]=toupper(val[0]);
        this->prenom = val;
    }
    else
    {
        this->prenom = "";
        ostringstream oss;
        oss<<"Erreur prenom : """<< val<<"""."<<endl;
        throw invalid_argument(oss.str());
    }
}

void Particuliers::Setsexe(char val)
{
    val=toupper(val);
    if ( (val == 'F') || (val == 'M' ) )
    {
        this->sexe = val;
    }
    else
    {
        this->sexe = '\0';
        ostringstream oss;
        oss<<"Erreur sexe : """<< val<<"""."<<endl;
        throw invalid_argument(oss.str());
    }
}

string Particuliers::ToString()
{
    ostringstream oss;
    /*
    oss <<Clients::ToString()
        <<SEPARATOR<<dateNaissanceF()
        <<SEPARATOR<<Getprenom()
        <<SEPARATOR<<Getsexe()
        ;
    */
    oss << Clients::ToString() << SEPARATOR;
    oss.width(4);
    oss.fill('0');
    oss << dateNaissance.tm_year+1900 << SEPARATOR;
    oss.width(2);
    oss << dateNaissance.tm_mon+1 << SEPARATOR;
    oss.width(2);
    oss <<dateNaissance.tm_mday;
    oss.width();
    oss << SEPARATOR << Getprenom()
        << SEPARATOR << Getsexe()
        ;
    return oss.str();
}

bool Particuliers::anniversaire()
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    if (    (now->tm_mon == dateNaissance.tm_mon)
         && (now->tm_mday == dateNaissance.tm_mday)
       )
        return true;
    else
        return false;
}

short Particuliers::age()
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    int a=now->tm_year - dateNaissance.tm_year;
    if(    (dateNaissance.tm_mon > now->tm_mon)
        || (    (dateNaissance.tm_mon == now->tm_mon)
             && (dateNaissance.tm_mday >= now->tm_mday)
           )
      )
        return a+1;
    else
        return a;
}
