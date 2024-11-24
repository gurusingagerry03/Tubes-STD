#include "customer.h"
#include "mobil.h"
#include "Relasi.h"
#include <iostream>

using namespace std;

void tampilkanMenu() {
    cout << "\n==================================================\n";
    cout << "Pilihan Menu:\n";
    cout << "a. Tambahkan beberapa data Mobil (Parent)\n";
    cout << "b. Tambahkan beberapa data Customer (Child)\n";
    cout << "c. Tambahkan beberapa relasi antara Mobil dan Customer\n";
    cout << "d. Hapus data Mobil (Parent)\n";
    cout << "e. Hapus data Customer (Child)\n";
    cout << "f. Hapus relasi antara Mobil dan Customer\n";
    cout << "g. Cari data Mobil (Parent)\n";
    cout << "h. Cari data Customer (Child)\n";
    cout << "i. Periksa relasi antara Mobil tertentu dan Customer tertentu\n";
    cout << "j. Tampilkan semua data Mobil\n";
    cout << "k. Tampilkan semua data Customer\n";
    cout << "l. Tampilkan semua Customer yang terkait dengan Mobil tertentu\n";
    cout << "m. Tampilkan semua Mobil yang terkait dengan Customer tertentu\n";
    cout << "n. Tampilkan semua Mobil beserta Customernya\n";
    cout << "o. Tampilkan semua Customer beserta Mobilnya\n";
    cout << "p. Hitung jumlah Customer dari Mobil tertentu\n";
    cout << "q. Hitung jumlah Mobil dari Customer tertentu\n";
    cout << "r. Hitung jumlah Customer tanpa Mobil\n";
    cout << "s. Hitung jumlah Mobil tanpa Customer\n";
    cout << "t. Edit relasi (ubah Customer untuk Mobil tertentu atau sebaliknya)\n";
    cout << "x. Keluar\n";
    cout << "==================================================\n";
    cout << "Pilih opsi: ";
}

int main() {
       MobilList mobilList;
    CustomerList customerList;
    RelasiList relasiList;

    createListMobil(mobilList);
    createListCustomer(customerList);
    createListRelasi(relasiList);

    char pilihan;
    do {
        tampilkanMenu();
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 'a': {
                int n;
                cout << "Jumlah Mobil yang ingin ditambahkan: ";
                cin >> n;
                cin.ignore();
                for (int i = 0; i < n; i++) {
                    infotypeMobil mobil;
                    cout << "Masukkan Merk Mobil: ";
                    getline(cin, mobil.Merk);
                    cout << "Masukkan Tahun Mobil: ";
                    getline(cin, mobil.Year);
                    cout << "Masukkan Harga Mobil: ";
                    cin >> mobil.Price;
                    cout << "Masukkan Stok Mobil: ";
                    cin >> mobil.Stok;
                    cin.ignore();
                    insertLastMobil(mobilList, newElementMobil(mobil));
                }
                break;
            }
            case 'b': {
                int n;
                cout << "Jumlah Customer yang ingin ditambahkan: ";
                cin >> n;
                cin.ignore();
                for (int i = 0; i < n; i++) {
                    infotypeCustomer customer;
                    cout << "Masukkan Nama Customer: ";
                    getline(cin, customer.name);
                    cout << "Masukkan Alamat Customer: ";
                    getline(cin, customer.address);
                    cout << "Masukkan Nomor Telepon Customer: ";
                    getline(cin, customer.phoneNumber);
                    customer.totalPrice = 0;
                    insertLastCustomer(customerList, newElementCustomer(customer));
                }
                break;
            }
            case 'c': {
                string mobilMerk, customerName;
                cout << "Masukkan Merk Mobil: ";
                getline(cin, mobilMerk);
                cout << "Masukkan Nama Customer: ";
                getline(cin, customerName);
                addressMobil mobilPtr = findElementMobil(mobilList, mobilMerk);
                addressCustomer customerPtr = findElementCustomer(customerList, customerName);
                if (mobilPtr && customerPtr) {
                    if (createRelation(relasiList, mobilPtr, customerPtr)) {
                        cout << "Relasi berhasil ditambahkan.\n";
                    }
                } else {
                    cout << "Mobil atau Customer tidak ditemukan.\n";
                }
                break;
            }
            case 'd': {
                string mobilMerk;
                cout << "Masukkan Merk Mobil yang akan dihapus: ";
                getline(cin, mobilMerk);
                removeMobil(mobilList, mobilMerk);
                break;
            }
            case 'e': {
                string customerName;
                cout << "Masukkan Nama Customer yang akan dihapus: ";
                getline(cin, customerName);
                removeCustomer(customerList, customerName);
                break;
            }
            case 'f': {
                string mobilMerk, customerName;
                cout << "Masukkan Merk Mobil: ";
                getline(cin, mobilMerk);
                cout << "Masukkan Nama Customer: ";
                getline(cin, customerName);
                addressMobil mobilPtr = findElementMobil(mobilList, mobilMerk);
                addressCustomer customerPtr = findElementCustomer(customerList, customerName);
                if (mobilPtr && customerPtr) {
                    deleteSpecificRelation(relasiList, mobilPtr, customerPtr);
                } else {
                    cout << "Relasi tidak ditemukan.\n";
                }
                break;
            }
            case 'g': {
                string mobilMerk;
                cout << "Masukkan Merk Mobil yang akan dicari: ";
                getline(cin, mobilMerk);
                addressMobil mobilPtr = findElementMobil(mobilList, mobilMerk);
                if (mobilPtr) {
                    cout << "Mobil ditemukan: " << mobilPtr->infomobil.Merk << endl;
                } else {
                    cout << "Mobil tidak ditemukan.\n";
                }
                break;
            }
            case 'h': {
                string customerName;
                cout << "Masukkan Nama Customer yang akan dicari: ";
                getline(cin, customerName);
                addressCustomer customerPtr = findElementCustomer(customerList, customerName);
                if (customerPtr) {
                    cout << "Customer ditemukan: " << customerPtr->infoCustomer.name << endl;
                } else {
                    cout << "Customer tidak ditemukan.\n";
                }
                break;
            }
            case 'i': {
                string mobilMerk, customerName;
                cout << "Masukkan Merk Mobil: ";
                getline(cin, mobilMerk);
                cout << "Masukkan Nama Customer: ";
                getline(cin, customerName);
                addressMobil mobilPtr = findElementMobil(mobilList, mobilMerk);
                addressCustomer customerPtr = findElementCustomer(customerList, customerName);
                if (findRelation(relasiList, mobilPtr, customerPtr)) {
                    cout << "Relasi ditemukan.\n";
                } else {
                    cout << "Relasi tidak ditemukan.\n";
                }
                break;
            }
            case 'j': {
                printInfoMobil(mobilList);
                break;
            }
            case 'k': {
                printInfoCustomer(customerList);
                break;
            }
            case 'l': {
                string mobilMerk;
                cout << "Masukkan Merk Mobil: ";
                getline(cin, mobilMerk);
                addressMobil mobilPtr = findElementMobil(mobilList, mobilMerk);
                if (mobilPtr) {
                    showChildFromParent(relasiList, mobilPtr);
                } else {
                    cout << "Mobil tidak ditemukan.\n";
                }
                break;
            }
            case 'm': {
                string customerName;
                cout << "Masukkan Nama Customer: ";
                getline(cin, customerName);
                addressCustomer customerPtr = findElementCustomer(customerList, customerName);
                if (customerPtr) {
                    showParentFromChild(relasiList, customerPtr);
                } else {
                    cout << "Customer tidak ditemukan.\n";
                }
                break;
            }
            case 'n': {
                showAllParentsWithChildren(relasiList);
                break;
            }
            case 'o': {
                showAllChildrenWithParents(relasiList);
                break;
            }
            case 'p': {
                string mobilMerk;
                cout << "Masukkan Merk Mobil: ";
                getline(cin, mobilMerk);
                addressMobil mobilPtr = findElementMobil(mobilList, mobilMerk);
                if (mobilPtr) {
                    cout << "Jumlah Customer: " << countChildrenOfParent(relasiList, mobilPtr) << endl;
                } else {
                    cout << "Mobil tidak ditemukan.\n";
                }
                break;
            }
            case 'q': {
                string customerName;
                cout << "Masukkan Nama Customer: ";
                getline(cin, customerName);
                addressCustomer customerPtr = findElementCustomer(customerList, customerName);
                if (customerPtr) {
                    cout << "Jumlah Mobil: " << countParentsOfChild(relasiList, customerPtr) << endl;
                } else {
                    cout << "Customer tidak ditemukan.\n";
                }
                break;
            }
            case 'r': {
                cout << "Jumlah Customer tanpa Mobil: " << countChildrenWithoutParents(relasiList, customerList) << endl;
                break;
            }
            case 's': {
                cout << "Jumlah Mobil tanpa Customer: " << countParentsWithoutChildren(relasiList, mobilList) << endl;
                break;
            }
            case 't': {
                string oldMobil, oldCustomer, newMobil, newCustomer;
                cout << "Masukkan Merk Mobil Lama: ";
                getline(cin, oldMobil);
                cout << "Masukkan Nama Customer Lama: ";
                getline(cin, oldCustomer);
                cout << "Masukkan Merk Mobil Baru: ";
                getline(cin, newMobil);
                cout << "Masukkan Nama Customer Baru: ";
                getline(cin, newCustomer);
                addressMobil oldMobilPtr = findElementMobil(mobilList, oldMobil);
                addressCustomer oldCustomerPtr = findElementCustomer(customerList, oldCustomer);
                addressMobil newMobilPtr = findElementMobil(mobilList, newMobil);
                addressCustomer newCustomerPtr = findElementCustomer(customerList, newCustomer);
                if (oldMobilPtr && oldCustomerPtr && newMobilPtr && newCustomerPtr) {
                    editRelation(relasiList, oldMobilPtr, oldCustomerPtr, newMobilPtr, newCustomerPtr);
                } else {
                    cout << "Data tidak ditemukan.\n";
                }
                break;
            }
            case 'x': {
                cout << "Keluar dari program.\n";
                break;
            }
            default: {
                cout << "Pilihan tidak valid.\n";
                break;
            }
        }
    } while (pilihan != 'x');

    return 0;
}
