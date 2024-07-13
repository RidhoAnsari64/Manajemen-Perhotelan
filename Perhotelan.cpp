#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int pil;

void checkin()
{
    string nama;
    int telepon, kamar;
    cout << "Masukkan nama Anda = ";
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
}

int main()
{
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
        checkin();
        break;
    }
}