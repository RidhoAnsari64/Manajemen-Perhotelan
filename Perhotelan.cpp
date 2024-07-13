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
    cout << "Tamu Berhasil Ditambahkan!\n" << endl;
};

void DataKamar(Kamar kamar1[], int JumlahKamar)
{
    int NomorKamar;
    cout << "Masukkan nomor kamar untuk mencek = ";
    cin >> NomorKamar;

    if (NomorKamar < 1 || NomorKamar > JumlahKamar)
    {
        cout << "Nomor kamar tidak tersedia." << endl;
        return;
    }

    Kamar kamar = kamar1[NomorKamar - 1];
    cout << "Nomor Kamar = " << kamar.NomorKamar << endl;
    cout << "Status Kamar = " << (kamar.Tersedia ? "Tersedia" : "Telah Terisi") << endl;
    if (!kamar.Tersedia) 
    {
        cout << "Nama Tamu = " << kamar.tamu.nama << endl;
        cout << "Nomor Telepon Tamu = " << kamar.tamu.telepon << endl;
        return;
    }
};

int main()
{
    Tamu tamu1[MAX_TAMU];
    Kamar kamar1[MAX_KAMAR];
    int tamu = 0;
    int JumlahKamar = MAX_KAMAR;

    do {
    cout << "============== Selamat Datang di Hotel RR ===================" << endl;
    cout << "1. Data Tamu." << endl;
    cout << "2. Data Kamar." << endl;
    cout << "Masukkan pilihan Anda = ";
    cin >> pil;
    system ("cls");
    switch (pil)
    {
        case 1:
        DataTamu(tamu1, kamar1);
        break;
        case 2:
        DataKamar(kamar1, JumlahKamar);
        break;
        case 3:
        cout << "Keluaran dari program." << endl;
        break;
        default:
        cout << "Pilihan yang salah. Mohon untuk memilih sesuai data di atas.\n" << endl;
    }
    }while (pil != 3);

    return 0;
}