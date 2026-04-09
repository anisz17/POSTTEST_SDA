#include <iostream>
#include <string>
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

struct Transaksi
{
    string namaPenumpang;
    int nomorKereta;
    string namaKereta;
    string rute;
    double harga;
};

const int MAX_KERETA = 50;
const int MAX_QUEUE = 100;
const int MAX_STACK = 100;
int jumlahKereta = 4;

Kereta dataKereta[MAX_KERETA] = {
    {101, "Argo Bromo Anggrek", "surabaya", "jakarta", "09:30", 350000},
    {205, "Bima", "surabaya", "bandung", "17:00", 280000},
    {520, "Lodaya", "bandung", "solo", "06:30", 150000},
    {710, "Sancaka", "surabaya", "yogyakarta", "10:00", 175000}};

Transaksi queueTiket[MAX_QUEUE];
int front = -1, rear = -1;

Transaksi stackRiwayat[MAX_STACK];
int top = -1;

void garis(char c = '=', int n = 70)
{
    for (int i = 0; i < n; i++)
        cout << c;
    cout << endl;
}

void headerTabel()
{
    garis('=', 85);
    cout << left << setw(6) << "No" << setw(8) << "No.KA" << setw(22) << "Nama Kereta";
    cout << setw(14) << "Asal" << setw(14) << "Tujuan" << setw(8) << "Jam" << "Harga (Rp)" << endl;
    garis('=', 85);
}

void cetakKereta(Kereta *p, int no)
{
    cout << left << setw(6) << no << setw(8) << p->nomorKereta << setw(22) << p->namaKereta;
    cout << setw(14) << p->asal << setw(14) << p->tujuan << setw(8) << p->jamBerangkat;
    cout << "Rp " << fixed << setprecision(0) << p->hargaTiket << endl;
}

void cetakTransaksi(Transaksi *t)
{
    cout << "Nama Penumpang  : " << t->namaPenumpang << endl;
    cout << "Kereta          : " << t->namaKereta << " (No. " << t->nomorKereta << ")" << endl;
    cout << "Rute            : " << t->rute << endl;
    cout << "Harga           : Rp " << fixed << setprecision(0) << t->harga << endl;
}

void swapKereta(Kereta *a, Kereta *b)
{
    Kereta tmp = *a;
    *a = *b;
    *b = tmp;
}

void tampilSemuaKereta(Kereta *arr, int n)
{
    system("cls");
    cout << "\n";
    garis('=', 85);
    cout << "                        JADWAL KERETA API\n";
    headerTabel();
    for (int i = 0; i < n; i++)
        cetakKereta(arr + i, i + 1);
    garis('=', 85);
    cout << "Total: " << n << " kereta\n";
    system("pause");
}

bool isQueueEmpty() { return front == -1; }
bool isQueueFull() { return rear == MAX_QUEUE - 1; }

void enqueue(string nama, Kereta *k)
{
    if (isQueueFull())
    {
        cout << "Antrian penuh!\n";
        return;
    }
    Transaksi t;
    t.namaPenumpang = nama;
    t.nomorKereta = k->nomorKereta;
    t.namaKereta = k->namaKereta;
    t.rute = k->asal + " -> " + k->tujuan;
    t.harga = k->hargaTiket;

    if (isQueueEmpty())
        front = rear = 0;
    else
        rear++;
    *(queueTiket + rear) = t;
    cout << "\nPemesanan atas nama " << nama << " berhasil!\n";
}

void dequeue()
{
    system("cls");
    if (isQueueEmpty())
    {
        cout << "Antrian kosong!\n";
        system("pause");
        return;
    }

    Transaksi t = *(queueTiket + front);

    system("cls");
    if (top < MAX_STACK - 1)
        *(stackRiwayat + ++top) = t;
    cout << "\n";
    garis();
    cout << "                MEMPROSES TIKET\n";
    garis();
    cetakTransaksi(&t);
    garis();
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        for (int i = front; i < rear; i++)
            *(queueTiket + i) = *(queueTiket + i + 1);
        rear--;
    }
    system("pause");
}

void tampilAntrian()
{
    system("cls");
    if (isQueueEmpty())
    {
        cout << "Antrian kosong!\n";
        system("pause");
        return;
    }

    cout << "\n";
    garis('=', 90);
    cout << "                    DAFTAR ANTRIAN PEMBELIAN TIKET\n";
    garis('=', 90);
    cout << left << setw(6) << "No" << setw(20) << "Nama" << setw(25) << "Kereta" << setw(25) << "Rute" << "Harga" << endl;
    garis('=', 90);

    for (int i = front; i <= rear; i++)
    {
        Transaksi *t = queueTiket + i;
        cout << left << setw(6) << (i - front + 1) << setw(20) << t->namaPenumpang << setw(25) << t->namaKereta;
        cout << setw(25) << t->rute << "Rp " << fixed << setprecision(0) << t->harga << endl;
    }
    garis('=', 90);
    cout << "Total antrian: " << (rear - front + 1) << " penumpang\n";
    system("pause");
}

bool isStackEmpty()
{
    return top == -1;
}

void popRiwayat()
{
    system("cls");
    if (isStackEmpty())
    {
        cout << "Riwayat kosong!\n";
        system("pause");
        return;
    }

    Transaksi t = *(stackRiwayat + top--);
    cout << "\n";
    garis();
    cout << "         TRANSAKSI DIBATALKAN\n";
    garis();
    cetakTransaksi(&t);
    garis();
    cout << "Transaksi terakhir berhasil dibatalkan.\n";
    system("pause");
}

void tampilRiwayat()
{
    system("cls");
    if (isStackEmpty())
    {
        cout << "Belum ada riwayat!\n";
        system("pause");
        return;
    }

    cout << "\n";
    garis('=', 90);
    cout << "                      RIWAYAT TRANSAKSI TIKET\n";
    garis('=', 90);
    cout << left << setw(6) << "No" << setw(20) << "Nama" << setw(25) << "Kereta" << setw(25);
    cout << "Rute" << "Harga" << endl;
    garis('=', 90);

    for (int i = top; i >= 0; i--)
    {
        Transaksi *t = stackRiwayat + i;
        cout << left << setw(6) << (top - i + 1) << setw(20) << t->namaPenumpang;
        cout << setw(25) << t->namaKereta << setw(25) << t->rute;
        cout << "Rp " << fixed << setprecision(0) << t->harga << endl;
    }
    garis('=', 90);
    cout << "Total riwayat: " << (top + 1) << " transaksi\n";
    system("pause");
}

void peekData()
{
    system("cls");
    cout << "\n";
    garis();
    cout << "          ANTRIAN TERDEPAN & TRANSAKSI TERAKHIR\n";
    garis();

    cout << "\nAntrian Terdepan:\n";
    garis('-');
    if (isQueueEmpty())
        cout << "Antrian kosong!\n";
    else
        cetakTransaksi(queueTiket + front);

    cout << "\nTransaksi Terakhir:\n";
    garis('-');
    if (isStackEmpty())
        cout << "Riwayat kosong!\n";
    else
        cetakTransaksi(stackRiwayat + top);
    garis();
    system("pause");
}

void pesanTiket()
{
    system("cls");
    cout << "\n";
    garis('=', 85);
    cout << "                    PEMESANAN TIKET KERETA\n";
    headerTabel();
    for (int i = 0; i < jumlahKereta; i++)
        cetakKereta(dataKereta + i, i + 1);
    garis('=', 85);

    int pilih;
    cout << "\nPilih Nomor: ";
    cin >> pilih;
    if (pilih < 1 || pilih > jumlahKereta)
    {
        cout << "Dibatalkan.\n";
        system("pause");
        return;
    }

    Kereta *k = dataKereta + (pilih - 1);
    string nama;
    cin.ignore();
    cout << "Nama Penumpang: ";
    getline(cin, nama);
    enqueue(nama, k);
    system("pause");
}

void tambahKereta()
{
    system("cls");
    if (jumlahKereta >= MAX_KERETA)
    {
        cout << "Maaf! Data penuh.\n";
        system("pause");
        return;
    }

    garis();
    cout << "              TAMBAH DATA KERETA BARU\n";
    garis();
    Kereta b;
    cin.ignore();
    cout << "Nomor Kereta  : ";
    cin >> b.nomorKereta;
    cin.ignore();
    cout << "Nama Kereta (huruf awal harus KAPITAL)   : ";
    getline(cin, b.namaKereta);
    cout << "Kota Asal     : ";
    getline(cin, b.asal);
    cout << "Kota Tujuan   : ";
    getline(cin, b.tujuan);
    cout << "Jam Berangkat : ";
    getline(cin, b.jamBerangkat);
    cout << "Harga Tiket   : Rp ";
    cin >> b.hargaTiket;
    *(dataKereta + jumlahKereta++) = b;
    cout << "Data berhasil ditambahkan!\n";
    system("pause");
}

void cariRute()
{
    system("cls");
    string asal, tujuan;
    cin.ignore();
    garis();
    cout << "          CARI KERETA BERDASARKAN RUTE\n";
    garis();
    cout << "Kota Asal   : ";
    getline(cin, asal);
    cout << "Kota Tujuan : ";
    getline(cin, tujuan);
    garis();

    bool found = false;
    int count = 0;
    for (int i = 0; i < jumlahKereta; i++)
    {
        Kereta *k = dataKereta + i;
        cout << "  Iterasi " << (i + 1) << ": " << k->namaKereta << " " << k->asal << " -> " << k->tujuan;
        if (k->asal == asal && k->tujuan == tujuan)
        {
            cout << " ==> Cocok\n";
            found = true;
            count++;
        }
        else
            cout << " ==> Tidak cocok\n";
    }
    garis();
    if (found)
    {
        cout << "Ditemukan " << count << " kereta:\n";
        headerTabel();
        int no = 1;
        for (int i = 0; i < jumlahKereta; i++)
            if ((dataKereta + i)->asal == asal && (dataKereta + i)->tujuan == tujuan)
                cetakKereta(dataKereta + i, no++);
        garis('=', 85);
    }
    else
        cout << "Tidak ada kereta untuk rute tersebut.\n";
    system("pause");
}

void selectionSortNomor(Kereta *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int idx = i;
        for (int j = i + 1; j < n; j++)
            if ((arr + j)->nomorKereta < (arr + idx)->nomorKereta)
                idx = j;
        if (idx != i)
            swapKereta(arr + i, arr + idx);
    }
}

void cariNomor()
{
    system("cls");
    int target;
    garis();
    cout << "        CARI KERETA BERDASARKAN NOMOR KERETA\n";
    garis();
    cout << "Masukkan Nomor Kereta: ";
    cin >> target;
    Kereta temp[MAX_KERETA];
    for (int i = 0; i < jumlahKereta; i++)
        temp[i] = *(dataKereta + i);
    selectionSortNomor(temp, jumlahKereta);

    int n = jumlahKereta;
    int step = 2;
    int prev = 0;

    cout << "\nCari Nomor: " << target << "\n";
    garis('-');
    while (prev < n && temp[min(step, n) - 1].nomorKereta < target)
    {
        cout << "  Lompat ke indeks " << min(step, n) - 1 << " (Nomor: " << temp[min(step, n) - 1].nomorKereta << ")\n";
        prev = step;
        step += 2;
        if (prev >= n)
            break;
    }

    bool found = false;
    for (int i = prev; i < min(step, n); i++)
    {
        cout << "  Cek indeks " << i << " (Nomor: " << temp[i].nomorKereta << ") ";
        if (temp[i].nomorKereta == target)
        {
            cout << "==> Ditemukan\n";
            found = true;
            garis('-');
            cout << "\nKereta ditemukan:\n";
            headerTabel();
            cetakKereta(&temp[i], 1);
            garis('=', 85);
            break;
        }
        else
            cout << "(bukan)\n";
    }
    if (!found)
        cout << "\nNomor kereta " << target << " tidak ditemukan.\n";
    system("pause");
}

void merge(Kereta *arr, int kiri, int tengah, int kanan)
{
    int n1 = tengah - kiri + 1, n2 = kanan - tengah;
    Kereta kiriArr[MAX_KERETA], kananArr[MAX_KERETA];

    for (int i = 0; i < n1; i++)
        kiriArr[i] = *(arr + kiri + i);
    for (int j = 0; j < n2; j++)
        kananArr[j] = *(arr + tengah + 1 + j);

    int i = 0, j = 0, k = kiri;
    while (i < n1 && j < n2)
        *(arr + k++) = (kiriArr[i].namaKereta <= kananArr[j].namaKereta) ? kiriArr[i++] : kananArr[j++];
    while (i < n1)
        *(arr + k++) = kiriArr[i++];
    while (j < n2)
        *(arr + k++) = kananArr[j++];
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

void urutNama()
{
    cout << "\nMengurutkan nama kereta A-Z...\n";
    mergeSort(dataKereta, 0, jumlahKereta - 1);
    cout << "Selesai!\n";
    tampilSemuaKereta(dataKereta, jumlahKereta);
}

void urutHarga()
{
    cout << "\nMengurutkan harga dari termurah...\n";
    for (int i = 0; i < jumlahKereta - 1; i++)
    {
        int idx = i;
        for (int j = i + 1; j < jumlahKereta; j++)
            if ((dataKereta + j)->hargaTiket < (dataKereta + idx)->hargaTiket)
                idx = j;
        if (idx != i)
            swapKereta(dataKereta + i, dataKereta + idx);
    }
    cout << "Selesai!\n";
    tampilSemuaKereta(dataKereta, jumlahKereta);
}

void tampilMenu()
{
    system("cls");
    garis('=', 75);
    cout << "           SISTEM MANAJEMEN KEBERANGKATAN KERETA API\n";
    garis('=', 75);
    cout << "1. Tampil Semua Jadwal Kereta\n"
         << "2. Tambah Data Kereta Baru\n"
         << "3. Cari Rute Kereta\n"
         << "4. Cari Nomor Kereta\n"
         << "5. Urutkan Nama Kereta (A-Z)\n"
         << "6. Urutkan Harga Termurah\n"
         << "7. Pesan Tiket\n"
         << "8. Memroses Tiket\n"
         << "9. Tampil Semua Antrian\n"
         << "10.Tampil Riwayat Transaksi\n"
         << "11.Batalkan Transaksi Terakhir\n"
         << "12.Antrian Terdepan & Transaksi Terakhir\n";
    cout << "0. Keluar\n";
    garis('=', 75);
    cout << "Pilih Menu: ";
}

int main()
{
    int pilihan;
    do
    {
        tampilMenu();
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            tampilSemuaKereta(dataKereta, jumlahKereta);
            break;
        case 2:
            tambahKereta();
            break;
        case 3:
            cariRute();
            break;
        case 4:
            cariNomor();
            break;
        case 5:
            urutNama();
            break;
        case 6:
            urutHarga();
            break;
        case 7:
            pesanTiket();
            break;
        case 8:
            dequeue();
            break;
        case 9:
            tampilAntrian();
            break;
        case 10:
            tampilRiwayat();
            break;
        case 11:
            popRiwayat();
            break;
        case 12:
            peekData();
            break;
        case 0:
            cout << "\nTerima kasih. Sampai Jumpa!\n";
            break;
        default:
            cout << "\nPilihan Anda Tidak Valid!\n";
            system("pause");
        }
    } while (pilihan != 0);
    return 0;
}