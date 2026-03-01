#include <iostream>
using namespace std;

struct Mahasiswa
{
    string nama, nim;
    float ipk;
};

int main()
{
    Mahasiswa mhs[5];

    cout << "============================================" << endl;
    cout << "        MENCARI IPK TERTINGGI" << endl;
    cout << "============================================" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Data Mahasiswa ke-" << i + 1 << endl;
        cout << "Masukkan Nama Anda: ";
        getline(cin, mhs[i].nama);
        cout << "Masukkan NIM Anda: ";
        cin >> mhs[i].nim;
        cout << "Masukkan IPK Anda: ";
        cin >> mhs[i].ipk;

        cin.ignore();
        cout << endl;
    }

    int tertinggi = 0;
    for (int i = 1; i < 5; i++)
    {
        if (mhs[i].ipk > mhs[tertinggi].ipk)
        {
            tertinggi = i;
        }
    }
    cout << "-------------------------------------------------------" << endl;
    cout << "Mahasiswa dengan IPK tertinggi adalah: " << endl;
    cout << "Nama: " << mhs[tertinggi].nama << endl;
    cout << "NIM: " << mhs[tertinggi].nim << endl;
    cout << "IPK: " << mhs[tertinggi].ipk;
    return 0;
}