#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include <iostream>
using namespace std;

struct CustomerInfo {
    string name;
    string address;
    string phoneNumber;
    double totalPrice;
};


typedef CustomerInfo infotypeCustomer;
typedef struct elmCustomer * addressCustomer;

struct elmCustomer {
    infotypeCustomer infoCustomer;
    addressCustomer next;
    addressCustomer prev;
};

struct CustomerList {
    addressCustomer first;
    addressCustomer last;
};

addressCustomer newElementCustomer(infotypeCustomer x);
void createListCustomer(CustomerList &Cl);
bool isEmptyCustomer(CustomerList Cl);
addressCustomer findElementCustomer(CustomerList Cl, string name);
void insertLastCustomer(CustomerList &Cl, addressCustomer p);
void deleteFirstCustomer(CustomerList &Cl, addressCustomer &p);
void deleteLastCustomer(CustomerList &Cl, addressCustomer &p);
void deleteAfterCustomer(addressCustomer prec, addressCustomer &p);
void removeCustomer(CustomerList &Cl, string name);
void printInfoCustomer(CustomerList Cl);

#endif // CUSTOMER_H_INCLUDED
