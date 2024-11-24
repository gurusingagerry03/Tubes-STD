#include "Customer.h"

addressCustomer newElementCustomer(infotypeCustomer x) {
    addressCustomer p = new elmCustomer;
    p->infoCustomer = x;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}

void createListCustomer(CustomerList &Cl) {
    Cl.first = nullptr;
    Cl.last = nullptr;
}

bool isEmptyCustomer(CustomerList Cl) {
    return Cl.first == nullptr && Cl.last == nullptr;
}

addressCustomer findElementCustomer(CustomerList Cl, string name) {
    addressCustomer p = Cl.first;
    while (p != nullptr) {
        if (p->infoCustomer.name == name) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void insertLastCustomer(CustomerList &Cl, addressCustomer p) {
    if (isEmptyCustomer(Cl)) {
        Cl.first = p;
        Cl.last = p;
    } else {
        Cl.last->next = p;
        p->prev = Cl.last;
        Cl.last = p;
    }
}

void deleteFirstCustomer(CustomerList &Cl, addressCustomer &p) {
    if (!isEmptyCustomer(Cl)) {
        p = Cl.first;
        if (Cl.first == Cl.last) {
            Cl.first = nullptr;
            Cl.last = nullptr;
        } else {
            Cl.first = Cl.first->next;
            Cl.first->prev = nullptr;
        }
        p->next = nullptr;
    }
}

void deleteLastCustomer(CustomerList &Cl, addressCustomer &p) {
    if (!isEmptyCustomer(Cl)) {
        p = Cl.last;
        if (Cl.first == Cl.last) {
            Cl.first = nullptr;
            Cl.last = nullptr;
        } else {
            Cl.last = Cl.last->prev;
            Cl.last->next = nullptr;
        }
        p->prev = nullptr;
    }
}

void deleteAfterCustomer(addressCustomer prec, addressCustomer &p) {
    if (prec != nullptr && prec->next != nullptr) {
        p = prec->next;
        prec->next = p->next;
        if (p->next != nullptr) {
            p->next->prev = prec;
        }
        p->next = nullptr;
        p->prev = nullptr;
    }
}

void removeCustomer(CustomerList &Cl, string name) {
    addressCustomer p = findElementCustomer(Cl, name);
    if (p != nullptr) {
        if (p == Cl.first) {
            deleteFirstCustomer(Cl, p);
        } else if (p == Cl.last) {
            deleteLastCustomer(Cl, p);
        } else {
            addressCustomer prec = p->prev;
            deleteAfterCustomer(prec, p);
        }
        delete p;
    }
}

void printInfoCustomer(CustomerList Cl) {
    if (isEmptyCustomer(Cl)) {
        cout << "The customer list is empty!" << endl;
    } else {
        addressCustomer p = Cl.first;
        while (p != nullptr) {
            cout << "Name: " << p->infoCustomer.name << endl;
            cout << "Address: " << p->infoCustomer.address << endl;
            cout << "Phone Number: " << p->infoCustomer.phoneNumber << endl;
            cout << "Total Price: " << p->infoCustomer.totalPrice << endl;
            cout << "-----------------------------" << endl;
            p = p->next;
        }
    }
}
