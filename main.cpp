#include <iostream>
#include <ctime>
#include "Clients.h"
#include "Particuliers.h"
#include "Professionnels.h"
#include <sstream>

using namespace std;

/*
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
*/

int main()
{
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
            "mail@domain" );
        cout << "c1->ToString() = "<<c1->ToString() <<endl;

        //identifiant NOM
        //adrLibelle adrComplem adrCodPost adrVILLE mail
        //parDateNA parDateNM parDateNJ parPrenom parSexe
        Particuliers *par1 = new Particuliers(
            1,
            "nom",
            "adrLib",
            "adrComp",
            31000,
            "Ville",
            "mail@domain",
            2000,
            04,
            29,
            "preNom",
            'F' );
        cout << "par1->ToString() = "<<par1->ToString() <<endl;
        cout << "par1->anniversaire() = "<<par1->anniversaire() <<endl;
        cout << "par1->age() = "<<par1->age() <<endl;

        //identifiant NOM
        //adrLibelle adrComplem adrCodPost adrVILLE mail
        //proSiret proStatut
        //proAdrLibelle proAdrComplem proAdrCodPost proAdrVILLE
        Professionnels *pro1 = new Professionnels(
            1,
            "nom",
            "adrLib",
            "adrComp",
            31000,
            "Ville",
            "mail@domain",
            "12345678901234",
            "SA",
            "adrProLib",
            "adrProComp",
            31000,
            "VillePro"
        );
        cout << "pro1->ToString() = "<<pro1->ToString() <<endl;

        if(pro1 != nullptr)
        {
            delete pro1;
            pro1=nullptr;
        }
        if(c1 != nullptr)
        {
            delete c1;
            c1=nullptr;
        }
        if(par1 != nullptr)
        {
            delete par1;
            par1=nullptr;
        }

    }//try

    catch(invalid_argument &e)
    {
        cout<<"Exception : "<<e.what();
    }
    catch(...)
    {
        cout<<"Exception : inconnue."<<endl;
    }

    return 0;
}
