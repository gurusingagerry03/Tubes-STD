#include "relasi.h"

void createListRelasi(RelasiList &Rl) {
    Rl.first = nullptr;
}

addressRelasi newElementRelasi(addressCustomer down, addressMobil up) {
    addressRelasi p = new elmRelasi;
    p->down = down;
    p->up = up;
    p->next = nullptr;
    return p;
}

void insertLastRelasi(RelasiList &Rl, addressRelasi p) {
    if (Rl.first == nullptr) {
        Rl.first = p;
    } else {
        addressRelasi q = Rl.first;
        while (q->next != nullptr) {
            q = q->next;
        }
        q->next = p;
    }
}

bool createRelation(RelasiList &Rl, addressMobil mobilPtr, addressCustomer customerPtr) {
    if (mobilPtr->infomobil.Stok > 0) {

        mobilPtr->infomobil.Stok--;
        customerPtr->infoCustomer.totalPrice = customerPtr->infoCustomer.totalPrice + mobilPtr->infomobil.Price;
        addressRelasi newRelasi = newElementRelasi(customerPtr, mobilPtr);
        insertLastRelasi(Rl, newRelasi);
        return true;
    } else {
        cout << "Stock for the selected mobil is not available!" << endl;
        return false;
    }
}

void deleteFirstRelasi(RelasiList &Rl, addressRelasi &p) {
    if (Rl.first != nullptr) {
        p = Rl.first;
        Rl.first = Rl.first->next;
        p->next = nullptr;
    }
}

void deleteAfterRelasi(addressRelasi prec, addressRelasi &p) {
    if (prec != nullptr && prec->next != nullptr) {
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    }
}

void showInfoRelasi(RelasiList Rl) {
    addressRelasi p = Rl.first;
    while (p != nullptr) {
        cout << "Customer: " << p->down->infoCustomer.name
             << " - Mobil: " << p->up->infomobil.Merk
             << " - Remaining Stock: " << p->up->infomobil.Stok
             << " - Customer Total Price: " << p->down->infoCustomer.totalPrice<< endl;
        p = p->next;
    }
}

bool findRelation(RelasiList Rl, addressMobil mobilPtr, addressCustomer customerPtr) {
    addressRelasi p = Rl.first;
    while (p != nullptr) {
        if (p->up == mobilPtr && p->down == customerPtr) {
            return true;
        }
        p = p->next;
    }
    return false;
}

void deleteSpecificRelation(RelasiList &Rl, addressMobil mobilPtr, addressCustomer customerPtr) {
    addressRelasi p = Rl.first, prec = nullptr;
    while (p != nullptr) {
        if (p->up == mobilPtr && p->down == customerPtr) {
            if (p == Rl.first) {
                deleteFirstRelasi(Rl, p);
            } else {
                deleteAfterRelasi(prec, p);
            }
            mobilPtr->infomobil.Stok++; // Kembalikan stok mobil
            customerPtr->infoCustomer.totalPrice = customerPtr->infoCustomer.totalPrice - mobilPtr->infomobil.Price;
            delete p;
            return;
        }
        prec = p;
        p = p->next;
    }
}

void showChildFromParent(RelasiList Rl, addressMobil mobilPtr) {
    addressRelasi p = Rl.first;
    while (p != nullptr) {
        if (p->up == mobilPtr) {
            cout << "Customer: " << p->down->infoCustomer.name << endl;
        }
        p = p->next;
    }
}

void showParentFromChild(RelasiList Rl, addressCustomer customerPtr) {
    addressRelasi p = Rl.first;
    while (p != nullptr) {
        if (p->down == customerPtr) {
            cout << "Mobil: " << p->up->infomobil.Merk << endl;
        }
        p = p->next;
    }
}

void showAllParentsWithChildren(RelasiList Rl) {
    addressRelasi p = Rl.first;
    while (p != nullptr) {
        cout << "Mobil: " << p->up->infomobil.Merk
             << " - Customer: " << p->down->infoCustomer.name<< endl;
        p = p->next;
    }
}

void showAllChildrenWithParents(RelasiList Rl) {
    addressRelasi p = Rl.first;
    while (p != nullptr) {
        cout << "Customer: " << p->down->infoCustomer.name
             << " - Mobil: " << p->up->infomobil.Merk<< endl;
        p = p->next;
    }
}

int countChildrenOfParent(RelasiList Rl, addressMobil mobilPtr) {
    int count = 0;
    addressRelasi p = Rl.first;
    while (p != nullptr) {
        if (p->up == mobilPtr) {
            count++;
        }
        p = p->next;
    }
    return count;
}

int countParentsOfChild(RelasiList Rl, addressCustomer customerPtr) {
    int count = 0;
    addressRelasi p = Rl.first;
    while (p != nullptr) {
        if (p->down == customerPtr) {
            count++;
        }
        p = p->next;
    }
    return count;
}

int countChildrenWithoutParents(RelasiList Rl, CustomerList Cl) {
    int count = 0;
    addressCustomer p = Cl.first;
    while (p != nullptr) {
        if (!findRelation(Rl, nullptr, p)) {
            count++;
        }
        p = p->next;
    }
    return count;
}

int countParentsWithoutChildren(RelasiList Rl, MobilList Ml) {
    int count = 0;
    addressMobil p = Ml.first;
    while (p != nullptr) {
        if (!findRelation(Rl, p, nullptr)) {
            count++;
        }
        p = p->next;
    }
    return count;
}

void editRelation(RelasiList &Rl, addressMobil oldMobil, addressCustomer oldCustomer, addressMobil newMobil, addressCustomer newCustomer) {
    addressRelasi p = Rl.first;
    while (p != nullptr) {
        if (p->up == oldMobil && p->down == oldCustomer) {
            oldMobil->infomobil.Stok++;

            if (newMobil->infomobil.Stok > 0) {
                newMobil->infomobil.Stok--;

                double oldPrice = oldMobil->infomobil.Price;
                double newPrice = newMobil->infomobil.Price;
                double currentTotalPrice = newCustomer->infoCustomer.totalPrice;
                oldCustomer->infoCustomer.totalPrice = oldCustomer->infoCustomer.totalPrice-oldPrice;
                newCustomer->infoCustomer.totalPrice = currentTotalPrice - oldPrice + newPrice;


                p->up = newMobil;
                p->down = newCustomer;
            } else {
                cout << "Stock for the new mobil is not available!" << endl;
            }
            return;
        }
        p = p->next;
    }
    cout << "Relation not found!" << endl;
}

