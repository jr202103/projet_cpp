#include <iostream>
#include <ctime>
#include "Clients.h"
#include "Particuliers.h"
#include <sstream>

using namespace std;


string dateCurrentF()    //aaaa-mm-jj
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    ostringstream oss;
    oss.width(4);
    oss.fill('0');
    oss << (now->tm_year + 1900)<<'-';
    oss.width(2);
    oss << (now->tm_mon + 1) << '-';
    oss.width(2);
    oss << now->tm_mday;
    return oss.str();
}


int main()
{
    cout << dateCurrentF() <<endl;
    try
    {

        //identifiant NOM
        //adrLibelle adrComplem adrCodPost adrVILLE mail
        Clients *c1 = new Clients(
            1,
            "nom",
            "adrLib",
            "adrComp",
            31000,
            "Ville",
            "mail@domain");
        cout << "c1->ToString() = "<<c1->ToString() <<endl;
        if(c1 != nullptr)
            delete c1;

        //identifiant NOM
        //adrLibelle adrComplem adrCodPost adrVILLE mail
        //parDateNA parDateNM parDateNJ parPrenom parSexe
        Particuliers *p1 = new Particuliers(
            1,
            "nom",
            "adrLib",
            "adrComp",
            31000,
            "Ville",
            "mail@domain",
            2020,
            4,
            28,
            "preNom",
            'F'
        );
        cout << "p1->ToString() = "<<p1->ToString() <<endl;
        cout << "p1->anniversaire() = "<<p1->anniversaire() <<endl;
        cout << "p1->age() = "<<p1->age() <<endl;

        if(c1 != nullptr)
            delete c1;

    }//try
    catch(range_error &e)
    {
        cout<<"Exception : "<<e.what();
    }
    catch(...)
    {
        cout<<"Exception : inconnue."<<endl;
    }

    return 0;
}
