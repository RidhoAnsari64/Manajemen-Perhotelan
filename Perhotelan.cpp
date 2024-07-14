#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int pil;
const int MAX_KAMAR = 20;
const int MAX_TAMU = 20;

struct Tamu {
    string nama, telepon, JenisKamar;
    int NomorKamar;
};

struct Kamar {
    int NomorKamar;
    bool Tersedia;
    Tamu tamu;
};

void DataTamu(Tamu tamu1[], Kamar kamar1[], int &JumlahTamu)
{
        if (JumlahTamu >= MAX_TAMU)
    {
        cout << "Batas maksimum tamu telah tercapai!" << endl;
        return;
    }

    string nama, telepon, JenisKamar;
    int NomorKamar;
    cout << "Masukkan nama Anda = ";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukkan nomor telepon Anda = ";
    getline(cin, telepon);
    cout << "Pilih jenis kamar Anda" << endl;
    cout << "1. Standar" << endl;
    cout << "2. VIP" << endl;
    cout << "Masukkan Jenis Kamar = ";
    getline(cin, JenisKamar);
    cout << "Masukkan Nomor Kamar = ";
    cin >> NomorKamar;
    system("cls");

    if (NomorKamar < 1 || NomorKamar > MAX_KAMAR || !kamar1[NomorKamar - 1].Tersedia)
    {
        cout << "Kamar Telah Terisi!\n" << endl;
        return;
    }

    tamu1[JumlahTamu] = {nama, telepon, JenisKamar, NomorKamar};
    kamar1[NomorKamar - 1].Tersedia = false;
    kamar1[NomorKamar - 1].tamu = tamu1[JumlahTamu];
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
        cout << "Jenis Kamar = " << kamar.tamu.JenisKamar << endl;
        return;
    }
    cout << endl;
};

int main()
{
    Tamu tamu1[MAX_TAMU];
    Kamar kamar1[MAX_KAMAR];
    int JumlahTamu = 0;
    int JumlahKamar = MAX_KAMAR;

    for (int i = 0; i < JumlahKamar; ++i)
    {
        kamar1[i].NomorKamar = i + 1;
        kamar1[i].Tersedia = true;
    }

    do {
    cout << "============== Selamat Datang di Hotel RR ===================" << endl;
    cout << "1. Data Tamu." << endl;
    cout << "2. Data Kamar." << endl;
    cout << "3. Exit." << endl;
    cout << "Masukkan pilihan Anda = ";
    cin >> pil;
    system ("cls");
    switch (pil)
    {
        case 1:
        DataTamu(tamu1, kamar1, JumlahTamu);
        break;
        case 2:
        DataKamar(kamar1, JumlahKamar);
        break;
        case 3:
        cout << "Keluar dari program." << endl;
        break;
        default:
        cout << "Pilihan yang salah. Mohon untuk memilih sesuai data di atas.\n" << endl;
    }
    }while (pil != 3);

    return 0;
}