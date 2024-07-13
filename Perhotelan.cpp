#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int pil;
const int MAX_KAMAR = 20;
const int MAX_TAMU = 20;

struct Tamu {
    string nama;
    int telepon, kamar, tamu;
};

struct Kamar {
    int NomorKamar;
    bool Tersedia;
    Tamu tamu;
};

void DataTamu(Tamu tamu1[], Kamar kamar1[])
{
    string nama;
    int telepon, kamar, tamu;
    cout << "Masukkan nama Anda = ";
    cin.ignore();
    cin >> nama;
    cout << "Masukkan nomor telepon Anda = ";
    cin >> telepon;
    system("cls");
    cout << "Pilih jenis kamar Anda" << endl;
    cout << "1. Standar" << endl;
    cout << "2. VIP" << endl;
    cout << "Masukkan pilihan Anda = ";
    cin >> kamar;
    switch (kamar)
    {
        case 1:
        cout << "Anda telah memilih kamar Standar.";
        break;
        case 2:
        cout << "Anda telah memilih kamar VIP.";
        break;
    }
    system("cls");
    cout << "Masukkan jumlah tamu = ";
    cin >> tamu;
    cout << "Tamu Berhasil Ditambahkan!\n" << endl;
};

void DataKamar()
{

};

int main()
{
    Tamu tamu1[MAX_TAMU];
    Kamar kamar1[MAX_KAMAR];
    int tamu = 0;
    int jumlahKamar = MAX_KAMAR;

    do {
    cout << "============== Selamat Datang di Hotel RR ===================" << endl;
    cout << "Apakah Anda ingin check in atau check out?" << endl;
    cout << "1. Check in." << endl;
    cout << "2. Check out." << endl;
    cout << "Masukkan pilihan Anda = ";
    cin >> pil;
    system ("cls");
    switch (pil)
    {
        case 1:
        DataTamu(tamu1, kamar1);
        break;
    }
    }while (pil != 3);

    return 0;
}