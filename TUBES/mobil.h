#ifndef MOBIL_H_INCLUDED
#define MOBIL_H_INCLUDED

#include <iostream>
using namespace std;

struct MobilInfo {
    string Merk;
    string Year;
    double Price;
    int Stok;
};



typedef MobilInfo infotypeMobil;
typedef struct elmMobil * addressMobil;

struct elmMobil {
    infotypeMobil infomobil;
    addressMobil next;
};

struct MobilList {
    addressMobil first;
};

addressMobil newElementMobil(infotypeMobil x);
void createListMobil(MobilList &Ml);
bool isEmptyMobil(MobilList Ml);
addressMobil findElementMobil(MobilList Ml, string model);
void insertLastMobil(MobilList &Ml, addressMobil p);
void deleteFirstMobil(MobilList &Ml, addressMobil &p);
void deleteLastMobil(MobilList &Ml, addressMobil &p);
void deleteAfterMobil(addressMobil prec, addressMobil &p);
void removeMobil(MobilList &Ml, string model);
void printInfoMobil(MobilList Ml);

#endif // MOBIL_H_INCLUDED
