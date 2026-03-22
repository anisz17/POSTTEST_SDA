#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

struct Kereta
{
    int nomorKereta;
    string namaKereta;
    string asal;
    string tujuan;
    string jamBerangkat;
    double hargaTiket;
};

const int MAX_KERETA = 50;
int jumlahKereta = 0;

Kereta dataKereta[MAX_KERETA] = {
    {101, "Argo Bromo Anggrek", "surabaya", "jakarta", "09:30", 350000},
    {205, "Bima", "surabaya", "bandung", "17:00", 280000},
    {520, "Lodaya", "bandung", "solo", "06:30", 150000},
    {710, "Sancaka", "surabaya", "yogyakarta", "10:00", 175000}};

void garis(char line = '=', int panjang = 70)
{
    for (int i = 0; i < panjang; i++)
        cout << line;
    cout << endl;
}

void headerTabel()
{
    garis('=', 85);
    cout << left << setw(6) << "No" << setw(8) << "No.KA" << setw(22) << "Nama Kereta" << setw(14) << "Asal";
    cout << setw(14) << "Tujuan" << setw(8) << "Jam" << setw(12) << "Harga (Rp)" << endl;
    garis('=', 85);
}

void cetakkereta(Kereta *p, int nomor)
{
    cout << left << setw(6) << nomor << setw(8) << p->nomorKereta << setw(22) << p->namaKereta;
    cout << setw(14) << p->asal << setw(14) << p->tujuan << setw(8) << p->jamBerangkat;
    cout << "Rp " << fixed << setprecision(0) << p->hargaTiket << endl;
}

void swapKereta(Kereta *a, Kereta *b)
{
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void jadwalkereta(Kereta *arr, int n)
{
    system("cls");
    cout << "\n";
    garis('=', 85);
    cout << "                           JADWAL KERETA API\n";
    garis('=', 85);
    headerTabel();

    for (int i = 0; i < n; i++)
    {
        cetakkereta(arr + i, i + 1);
    }
    garis('=', 85);
    cout << "Total kereta: " << n << " kereta\n";
    system("pause");
}

void tambahkereta(Kereta *arr, int &n)
{
    system("cls");
    if (n >= MAX_KERETA)
    {
        cout << "Data penuh! Tidak bisa menambah kereta.\n";
        return;
    }
    garis();
    cout << "                   TAMBAHKAN DATA KERETA BARU\n";
    garis();

    Kereta baru;
    cout << "Nomor Kereta  : ";
    cin >> baru.nomorKereta;
    cin.ignore();
    cout << "Nama Kereta   : ";
    getline(cin, baru.namaKereta);
    cout << "Kota Asal     : ";
    getline(cin, baru.asal);
    cout << "Kota Tujuan   : ";
    getline(cin, baru.tujuan);
    cout << "Jam Berangkat : ";
    getline(cin, baru.jamBerangkat);
    cout << "Harga Tiket   : Rp ";
    cin >> baru.hargaTiket;
    *(arr + n) = baru;
    n++;
    cout << "Data kereta berhasil ditambahkan!\n";
    system("pause");
}

void rute(Kereta *arr, int n)
{
    system("cls");
    string asal, tujuan;
    cin.ignore();
    garis();
    cout << "             CARI KERETA BERDASARKAN RUTE\n";
    garis();
    cout << "Kota Asal   : ";
    getline(cin, asal);
    cout << "Kota Tujuan : ";
    getline(cin, tujuan);
    garis();
    bool found = false;
    int count = 0;
    /*
        PROSES ITERASI LINEAR SEARCH:
        1. Dimulai dari indeks 0 hingga n-1 (urutan satu per satu)
        2. Setiap iterasi: bandingkan arr[i].asal dan arr[i].tujuan dengan kunci pencarian (asal & tujuan yang diinput oleh pengguna)
            - Jika cocok => tandai ketemu dan tambah jumlahnya
            - Jika tidak => lanjut ke indeks berikutnya
        3. Kompleksitas: O(n)
    */
    for (int i = 0; i < n; i++)
    {
        cout << "  Iterasi " << (i + 1) << ": Cek ";
        cout << (arr + i)->namaKereta << " " << (arr + i)->asal << " -> " << (arr + i)->tujuan;
        if ((arr + i)->asal == asal && (arr + i)->tujuan == tujuan)
        {
            cout << "   ==>  Cocok\n";
            found = true;
            count++;
        }
        else
        {
            cout << "   ==>  Tidak cocok\n";
        }
    }
    garis();
    if (found)
    {
        cout << "Ditemukan " << count << " kereta untuk rute " << asal << " -> " << tujuan << ":\n";
        headerTabel();
        int urut = 1;
        for (int i = 0; i < n; i++)
        {
            if ((arr + i)->asal == asal && (arr + i)->tujuan == tujuan)
            {
                cetakkereta(arr + i, urut++);
            }
        }
        garis('=', 85);
    }
    else
    {
        cout << "\nTidak ada kereta untuk rute " << asal << " -> " << tujuan << ".\n";
    }
    system("pause");
}

void urutnomor(Kereta *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if ((arr + j)->nomorKereta < (arr + idx)->nomorKereta)
                idx = j;
        }
        if (idx != i)
            swapKereta(arr + i, arr + idx);
    }
}

void nomor(Kereta *arr, int n)
{
    system("cls");
    int targetNomor;
    garis();
    cout << "             CARI KERETA BERDASARKAN NOMOR KERETA\n";
    garis();
    cout << "Masukkan Nomor Kereta: ";
    cin >> targetNomor;
    Kereta temp[MAX_KERETA];
    for (int i = 0; i < n; i++)
        temp[i] = *(arr + i);
    urutnomor(temp, n);
    cout << "\nCari Nomor Kereta: " << targetNomor << "\n";
    garis('-');
    int step = (int)sqrt((double)n);
    int prev = 0;
    cout << "  step = sqrt(" << n << ") = " << step << "\n\n";
    while (prev < n && temp[min(step, n) - 1].nomorKereta < targetNomor)
    {
        int batas = min(step, n) - 1;
        cout << "  Lompat ke indeks " << batas << " (Nomor: " << temp[batas].nomorKereta << ")\n";
        prev = step;
        step += (int)sqrt((double)n);
        if (prev >= n)
            break;
    }
    bool found = false;
    for (int i = prev; i < min(step, n); i++)
    {
        cout << "  Cek indeks " << i << " (Nomor: " << temp[i].nomorKereta << ") ";
        if (temp[i].nomorKereta == targetNomor)
        {
            cout << "==> Ditemukan\n";
            found = true;
            garis('-');
            cout << "\nKereta ditemukan:\n";
            headerTabel();
            cetakkereta(&temp[i], 1);
            garis('=', 85);
            break;
        }
        else
        {
            cout << "(bukan)\n";
        }
    }
    if (!found)
    {
        garis('-');
        cout << "\nNomor kereta " << targetNomor << " tidak ditemukan.\n";
    }
    system("pause");
}

void merge(Kereta *arr, int kiri, int tengah, int kanan)
{
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;
    Kereta *kiriArr = new Kereta[n1];
    Kereta *kananArr = new Kereta[n2];
    for (int i = 0; i < n1; i++)
        kiriArr[i] = *(arr + kiri + i);
    for (int j = 0; j < n2; j++)
        kananArr[j] = *(arr + tengah + 1 + j);
    int i = 0, j = 0, k = kiri;
    while (i < n1 && j < n2)
    {
        if (kiriArr[i].namaKereta <= kananArr[j].namaKereta)
        {
            *(arr + k) = kiriArr[i];
            i++;
        }
        else
        {
            *(arr + k) = kananArr[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        *(arr + k) = kiriArr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        *(arr + k) = kananArr[j];
        j++;
        k++;
    }
    delete[] kiriArr;
    delete[] kananArr;
}

void mergeSort(Kereta *arr, int kiri, int kanan)
{
    if (kiri < kanan)
    {
        int tengah = kiri + (kanan - kiri) / 2;
        mergeSort(arr, kiri, tengah);
        mergeSort(arr, tengah + 1, kanan);
        merge(arr, kiri, tengah, kanan);
    }
}

void urutkereta(Kereta *arr, int &n)
{
    cout << "\nMengurutkan nama kereta A-Z...\n";
    mergeSort(arr, 0, n - 1);
    cout << "Selesai!\n\n";
    jadwalkereta(arr, n);
}

void harga(Kereta *arr, int &n)
{
    cout << "\nMengurutkan harga tiket dari termurah...\n";
    for (int i = 0; i < n - 1; i++)
    {
        int idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if ((arr + j)->hargaTiket < (arr + idx)->hargaTiket)
                idx = j;
        }
        if (idx != i)
            swapKereta(arr + i, arr + idx);
    }
    cout << "Selesai!\n\n";
    jadwalkereta(arr, n);
}

void tampilMenu()
{
    system("cls");
    garis();
    cout << "             SISTEM MANAJEMEN KEBERANGKATAN KERETA API\n";
    garis();
    cout << "1. Tampil Semua Jadwal Kereta\n";
    cout << "2. Tambah Data Kereta Baru\n";
    cout << "3. Cari Rute Kereta\n";
    cout << "4. Cari Nomor Kereta\n";
    cout << "5. Urutkan Nama Kereta\n";
    cout << "6. Urutkan Harga Termurah\n";
    cout << "7. Keluar\n";
    garis('-');
    cout << "Pilih Menu: ";
}

int main()
{
    jumlahKereta = 4;
    int pilihan;
    do
    {
        tampilMenu();
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            jadwalkereta(dataKereta, jumlahKereta);
            break;
        case 2:
            tambahkereta(dataKereta, jumlahKereta);
            break;
        case 3:
            rute(dataKereta, jumlahKereta);
            break;
        case 4:
            nomor(dataKereta, jumlahKereta);
            break;
        case 5:
            urutkereta(dataKereta, jumlahKereta);
            break;
        case 6:
            harga(dataKereta, jumlahKereta);
            break;
        case 7:
            cout << "\nTerima kasih. Sampai jumpa!\n";
            break;
        default:
            cout << "\nPilihan tidak valid!\n";
            system("pause");
            continue;
        }
    } while (pilihan != 7);
    return 0;
}