#ifndef ADRESSE_H
#define ADRESSE_H

#include <iostream>
#include <sstream>

#define SEPARATOR ";"
//#define SEPARATOR "\t"

using namespace std;

class Adresse
{
    public:
        //Adresse();
        Adresse(string, string, int, string);
                //adrLibelle adrComplem adrCodPost adrVILLE
        virtual ~Adresse();

        string Getlibelle() { return libelle; }
        void Setlibelle(string val) { libelle = val; }
        string Getcomplement() { return complement; }
        void Setcomplement(string val) { complement = val; }
        int Getcode() { return code; }
        void Setcode(int val) { code = val; }
        string Getville() { return ville; }
        //void Setville(string val) { ville = val; }
        void Setville(string);
        string ToString();
    protected:

    private:
        string libelle;
        string complement;
        int code;
        string ville;
};

#endif // ADRESSE_H
