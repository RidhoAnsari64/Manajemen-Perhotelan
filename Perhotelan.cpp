#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int pil;

void checkin()
{
    string nama;
    int telepon;
    cout << "Masukkan nama Anda = ";
    cin >> nama;
    cout << "Masukkan nomor telepon Anda = ";
    cin >> telepon;
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