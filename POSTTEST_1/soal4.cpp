#include <iostream>
using namespace std;

void tukarnilai(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int varA, varB;

    cout << "============================================" << endl;
    cout << "       MENUKAR NILAI DUA VARIABEL" << endl;
    cout << "============================================" << endl;

    cout << "Masukkan Nilai Variabel A: ";
    cin >> varA;
    cout << "Masukkan Nilai Variabel B: ";
    cin >> varB;

    cout << endl;
    cout << "-----------ANGKA SEBELUM DITUKAR-----------" << endl;
    cout << "Nilai Variabel A: " << varA << endl;
    cout << "Nilai Variabel B: " << varB << endl;

    tukarnilai(&varA, &varB);
    cout << endl;
    cout << "-----------ANGKA SESUDAH DITUKAR-----------" << endl;
    cout << "Nilai Variabel A: " << varA << endl;
    cout << "Nilai Variabel B: " << varB << endl;
    return 0;
}