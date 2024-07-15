#include <iostream>
#include <string>
#include <limits>

using namespace std;

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
    cout << "Masukkan nama Anda: ";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukkan nomor telepon Anda: ";
    getline(cin, telepon);

    int jenisKamarPilihan;
    cout << "Pilih jenis kamar Anda:" << endl;
    cout << "1. Standar" << endl;
    cout << "2. VIP" << endl;
    cout << "Masukkan pilihan (1 atau 2): ";
    cin >> jenisKamarPilihan;

    if (jenisKamarPilihan == 1)
        JenisKamar = "Standar";
    else if (jenisKamarPilihan == 2)
        JenisKamar = "VIP";
    else
    {
        cout << "Pilihan jenis kamar tidak valid!" << endl;
        return;
    }

    cout << "Masukkan Nomor Kamar: ";
    cin >> NomorKamar;

    if (NomorKamar < 1 || NomorKamar > MAX_KAMAR || !kamar1[NomorKamar - 1].Tersedia)
    {
        cout << "Kamar tidak tersedia!" << endl;
        return;
    }

    tamu1[JumlahTamu] = {nama, telepon, JenisKamar, NomorKamar};
    kamar1[NomorKamar - 1].Tersedia = false;
    kamar1[NomorKamar - 1].tamu = tamu1[JumlahTamu];
    JumlahTamu++;

    cout << "\nSelamat datang Tuan " << nama << endl;
    cout << "Kamar yang anda isi adalah kamar " << NomorKamar << " (" << JenisKamar << ")" << endl;
    cout << "Silahkan terima kunci dari resepsionis hotel" << endl;
    cout << "Semoga hari anda menyenangkan\n" << endl;

    cout << "Tekan tombol sembarang untuk kembali ke menu utama...";
    cin.ignore(); 
    cin.get();
}

void DataKamar(Kamar kamar1[], int JumlahKamar)
{
    int NomorKamar;
    cout << "Masukkan nomor kamar untuk mengecek: ";
    cin >> NomorKamar;

    if (NomorKamar < 1 || NomorKamar > JumlahKamar)
    {
        cout << "Nomor kamar tidak tersedia." << endl;
        return;
    }

    Kamar kamar = kamar1[NomorKamar - 1];
    cout << "Nomor Kamar: " << kamar.NomorKamar << endl;
    cout << "Status Kamar: " << (kamar.Tersedia ? "Tersedia" : "Telah Terisi") << endl;
    if (!kamar.Tersedia)
    {
        cout << "Nama Tamu: " << kamar.tamu.nama << endl;
        cout << "Nomor Telepon Tamu: " << kamar.tamu.telepon << endl;
        cout << "Jenis Kamar: " << kamar.tamu.JenisKamar << endl;
    }
    cout << endl;
}

void CheckOut(Tamu tamu1[], Kamar kamar1[], int &JumlahTamu)
{
    int NomorKamar;
    string nama;
    cout << "Masukkan nomor kamar untuk check-out: ";
    cin >> NomorKamar;
    cin.ignore();
    cout << "Masukkan nama tamu: ";
    getline(cin, nama);

    if (NomorKamar < 1 || NomorKamar > MAX_KAMAR || kamar1[NomorKamar - 1].Tersedia)
    {
        cout << "Nomor kamar tidak valid atau kamar belum terisi!" << endl;
        return;
    }

    if (kamar1[NomorKamar - 1].tamu.nama != nama)
    {
        cout << "Nama tamu tidak cocok dengan data kamar!" << endl;
        return;
    }

    cout << "\nKonfirmasi Check Out" << endl;
    cout << "Nomor Kamar: " << NomorKamar << endl;
    cout << "Nama Tamu: " << nama << endl;

    kamar1[NomorKamar - 1].Tersedia = true;
    kamar1[NomorKamar - 1].tamu = {};
    for (int i = 0; i < JumlahTamu; i++)
    {
        if (tamu1[i].NomorKamar == NomorKamar && tamu1[i].nama == nama)
        {
            for (int j = i; j < JumlahTamu - 1; j++)
            {
                tamu1[j] = tamu1[j + 1];
            }
            JumlahTamu--;
            break;
        }
    }

    cout << "Terimakasih telah menginap di Hotel Citra" << endl;
    cout << "Semoga hari anda menyenangkan\n" << endl;

    cout << "Tekan tombol sembarang untuk kembali ke menu utama...";
    cin.get();
}

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

    int pil;
    do
    {
        cout << "============== Selamat Datang di Hotel RR ===================" << endl;
        cout << "1. Check In." << endl;
        cout << "2. Data Kamar." << endl;
        cout << "3. Check Out." << endl;
        cout << "4. Exit." << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> pil;

        switch (pil)
        {
        case 1:
            DataTamu(tamu1, kamar1, JumlahTamu);
            break;
        case 2:
            DataKamar(kamar1, JumlahKamar);
            break;
        case 3:
            CheckOut(tamu1, kamar1, JumlahTamu);
            break;
        case 4:
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Pilihan yang salah. Mohon untuk memilih sesuai data di atas." << endl;
        }
    } while (pil != 4);

    return 0;
}
