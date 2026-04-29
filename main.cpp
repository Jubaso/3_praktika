#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct menuItemType {
    string menuItem;
    double menuPrice;
};

const int dydis = 8;
menuItemType menuList[dydis];

void getData() { //gauna meniu info
    ifstream failas("menu.txt");

    if (!failas) {
        cout << "menu.txt nerastas..." << endl;
        return;
    }

    for (int i = 0; i < dydis; i++) {
        getline(failas, menuList[i].menuItem,' ');
        failas >> menuList[i].menuPrice;
        failas.ignore();
    }
    failas.close();
}

void showMenu() { //rodo meniu
    cout << endl << "     PUSRYCIU MENIU     " << endl;
    cout << fixed << setprecision(2);

    for (int i = 0; i < dydis; i++) {
        cout << i + 1 << ". "
        << menuList[i].menuItem
        << " - "
        << menuList[i].menuPrice << " EUR" << endl;
    }
    cout << "0. Iseiti" << endl;
}

void printCheck(int pasirinkti[], int porcijos[], int kiekPasirinkta) { //sukuria ceki
    ofstream failas("receipt.txt");
    cout << "Skanaus!" << endl;
    failas << "Skanaus!" << endl;

    cout << fixed << setprecision(2);
    failas << fixed << setprecision(2);

    double suma = 0;

    for (int i =0; i < kiekPasirinkta; i++) {
        int index = pasirinkti[i];
        double kaina = menuList[index].menuPrice * porcijos[i];
        suma += kaina;

        cout << porcijos[i] << "x "
        << menuList[index].menuItem
        << " " << kaina << " EUR" << endl;

        failas << porcijos[i] << "x "
        << menuList[index].menuItem
        << " " << kaina << " EUR" << endl;
    }
    double pvm = suma * 0.21;
    double galutine = suma + pvm;

    cout << "PVM: " << pvm << " EUR" << endl;
    cout << "Galutine suma: " << galutine << " EUR" << endl;
    failas << "PVM: " << pvm << " EUR" << endl;
    failas << "Galutine: " << galutine << " EUR" << endl;
    failas.close();
    cout << "Saskaita issaugota faile receipt.txt" << endl;
}