#include <iostream>
#include <string>
using namespace std;

struct BukuNode
{
    string judulBuku;
    BukuNode *next;

    BukuNode(string judul)
    {
        judulBuku = judul;
        next = nullptr;
    }
};

BukuNode *tambahBuku(BukuNode *head, string judul)
{
    BukuNode *newNode = new BukuNode(judul);
    if (head == nullptr)
    {
        newNode->next = newNode;
        return newNode;
    }

    BukuNode *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

bool cariBuku(BukuNode *head, string judulDicari)
{

    // LANGKAH 1: Cek apakah list kosong
    if (head == nullptr)
    {
        return false; // List kosong, pasti tidak ada buku yang dicari
    }

    // LANGKAH 2: Buat pointer temp untuk traverse list, mulai dari head
    BukuNode *temp = head;

    // LANGKAH 3: Lakukan pencarian menggunakan do-while
    // Mengapa do-while? Karena kita harus cek head dulu sebelum lanjut
    do
    {
        // LANGKAH 4: Bandingkan judul di node saat ini dengan judul yang dicari
        if (temp->judulBuku == judulDicari)
        {
            return true; // Buku ditemukan! Langsung return true
        }

        // LANGKAH 5: Pindah ke node berikutnya
        temp = temp->next;

    } while (temp != head); // LANGKAH 6: Berhenti jika sudah kembali ke head

    // LANGKAH 7: Jika sampai sini berarti sudah satu putaran penuh tapi tidak ketemu
    return false; // Buku tidak ditemukan
}

int main()
{
    BukuNode *head = nullptr;

    head = tambahBuku(head, "Struktur Data dengan C++");
    head = tambahBuku(head, "Pengantar Algoritma");
    head = tambahBuku(head, "Pemrograman Berorientasi Objek");
    head = tambahBuku(head, "Sistem Basis Data");

    string buku1 = "Pengantar Algoritma";
    string buku2 = "Kalkulus Lanjut";

    cout << "Mencari buku '" << buku1 << "': ";
    cout << (cariBuku(head, buku1) ? "Ditemukan" : "Tidak Ditemukan") << endl;

    cout << "Mencari buku '" << buku2 << "': ";
    cout << (cariBuku(head, buku2) ? "Ditemukan" : "Tidak Ditemukan") << endl;

    return 0;
}