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

        void Setlibelle(string val) { libelle = val; }
        string Getlibelle() { return libelle; }
        void Setcomplement(string val) { complement = val; }
        string Getcomplement() { return complement; }
        void Setcode(int val) { code = val; }
        int Getcode() { return code; }
        void Setville(string);
        string Getville() { return ville; }
        string ToString();
    protected:

    private:
        string libelle;
        string complement;
        int code;
        string ville;
};

#endif // ADRESSE_H
