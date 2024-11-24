#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "customer.h"
#include "mobil.h"
#include <iostream>
using namespace std;

typedef struct elmRelasi * addressRelasi;

struct elmRelasi {
    addressRelasi next;
    addressMobil up;
    addressCustomer down;
};

struct RelasiList {
    addressRelasi first;
};

void createListRelasi(RelasiList &Rl);
addressRelasi newElementRelasi(addressCustomer down, addressMobil up);
void insertLastRelasi(RelasiList &Rl, addressRelasi p);
void deleteFirstRelasi(RelasiList &Rl, addressRelasi &p);
void deleteAfterRelasi(addressRelasi prec, addressRelasi &p);
void showInfoRelasi(RelasiList Rl);
bool findRelation(RelasiList Rl, addressMobil mobilPtr, addressCustomer customerPtr);
void deleteSpecificRelation(RelasiList &Rl, addressMobil mobilPtr, addressCustomer customerPtr);
void showChildFromParent(RelasiList Rl, addressMobil mobilPtr);
void showParentFromChild(RelasiList Rl, addressCustomer customerPtr);
void showAllParentsWithChildren(RelasiList Rl);
void showAllChildrenWithParents(RelasiList Rl);
int countChildrenOfParent(RelasiList Rl, addressMobil mobilPtr);
int countParentsOfChild(RelasiList Rl, addressCustomer customerPtr);
int countChildrenWithoutParents(RelasiList Rl, CustomerList Cl);
int countParentsWithoutChildren(RelasiList Rl, MobilList Ml);
void editRelation(RelasiList &Rl, addressMobil oldMobil, addressCustomer oldCustomer, addressMobil newMobil, addressCustomer newCustomer);
bool createRelation(RelasiList &Rl, addressMobil mobilPtr, addressCustomer customerPtr);
#endif
