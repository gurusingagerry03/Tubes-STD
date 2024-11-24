#include "Mobil.h"

addressMobil newElementMobil(infotypeMobil x) {
    addressMobil p = new elmMobil;
    p->infomobil = x;
    p->next = nullptr;
    return p;
}


void createListMobil(MobilList &Ml) {
    Ml.first = nullptr;
}


bool isEmptyMobil(MobilList Ml) {
    return Ml.first == nullptr;
}

addressMobil findElementMobil(MobilList Ml, string model) {
    addressMobil p = Ml.first;
    while (p != nullptr) {
        if (p->infomobil.Merk == model) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}


void insertLastMobil(MobilList &Ml, addressMobil p) {
    if (isEmptyMobil(Ml)) {
        Ml.first = p;
    } else {
        addressMobil q = Ml.first;
        while (q->next != nullptr) {
            q = q->next;
        }
        q->next = p;
    }
}


void deleteFirstMobil(MobilList &Ml, addressMobil &p) {
    if (!isEmptyMobil(Ml)) {
        p = Ml.first;
        Ml.first = Ml.first->next;
        p->next = nullptr;
    }
}


void deleteLastMobil(MobilList &Ml, addressMobil &p) {
    if (!isEmptyMobil(Ml)) {
        addressMobil q = Ml.first;
        if (q->next == nullptr) {
            p = q;
            Ml.first = nullptr;
        } else {
            while (q->next->next != nullptr) {
                q = q->next;
            }
            p = q->next;
            q->next = nullptr;
        }
    }
}


void deleteAfterMobil(addressMobil prec, addressMobil &p) {
    if (prec != nullptr && prec->next != nullptr) {
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    }
}


void removeMobil(MobilList &Ml, string model) {
    addressMobil p, prec;
    p = findElementMobil(Ml, model);
    if (p != nullptr) {
        if (p == Ml.first) {
            deleteFirstMobil(Ml, p);
        } else {
            prec = Ml.first;
            while (prec->next != p) {
                prec = prec->next;
            }
            deleteAfterMobil(prec, p);
        }
        delete p;
    }
}

void printInfoMobil(MobilList Ml) {
    if (isEmptyMobil(Ml)) {
        cout << "The list is empty!" << endl;
    } else {
        addressMobil p = Ml.first;
        while (p != nullptr) {
            cout << "Merk: " << p->infomobil.Merk << endl;
            cout << "Year: " << p->infomobil.Year << endl;
            cout << "Price: " << p->infomobil.Price << endl;
            cout << "Stok: " << p->infomobil.Stok << endl;
            cout << "------------------------" << endl;
            p = p->next;
        }
    }
}
