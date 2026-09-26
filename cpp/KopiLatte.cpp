#pragma once
#include <iostream>
#include <vector>
#include "MinumanKopi.cpp"

using namespace std;

// Child Class (Level 3) - Multilevel Inherit dari MinumanKopi
class KopiLatte : public MinumanKopi {
private:
    string jenisSusu;
    string busaSusu;
    string ekstraShot;

public:
    static vector<KopiLatte> daftarKopiLatte; // array nampung latte

    KopiLatte() : MinumanKopi() {
        this->jenisSusu = "";
        this->busaSusu = "";
        this->ekstraShot = "";
    }

    // panggil constructor parent (MinumanKopi)
    KopiLatte(string kode, string namaMinuman, int harga, string ukuran, string jenisBijiKopi, string asalBijiKopi, string kadarKafein, string jenisSusu, string busaSusu, string ekstraShot)
        : MinumanKopi(kode, namaMinuman, harga, ukuran, jenisBijiKopi, asalBijiKopi, kadarKafein) {
        this->jenisSusu = jenisSusu;
        this->busaSusu = busaSusu;
        this->ekstraShot = ekstraShot;
    }

    ~KopiLatte() {}

    string getJenisSusu() {
        return this->jenisSusu;
    }

    string getBusaSusu() {
        return this->busaSusu;
    }

    string getEkstraShot() {
        return this->ekstraShot;
    }

    void setJenisSusu(string jenis) {
        this->jenisSusu = jenis;
    }

    void setBusaSusu(string busa) {
        this->busaSusu = busa;
    }

    void setEkstraShot(string shot) {
        this->ekstraShot = shot;
    }

    // tambah latte baru
    static void addLatte() {
        cout << "\n--- Tambah Menu Kopi Latte ---" << endl;
        cout << "Masukkan Kode (ex: L001): ";
        string kode;
        getline(cin, kode);
        for (int i = 0; i < kode.length(); i++) {
            kode[i] = toupper(kode[i]);
        }

        // biar kode kaga bentrok
        for (int i = 0; i < daftarKopiLatte.size(); i++) {
            if (daftarKopiLatte[i].getKode() == kode) {
                cout << "Error: Kode latte udah terdaftar mas!" << endl;
                return;
            }
        }

        cout << "Masukkan Nama Minuman: ";
        string nama;
        getline(cin, nama);

        int harga;
        cout << "Masukkan Harga: ";
        if (!(cin >> harga)) {
            cout << "Error: Harganya pake angka mas" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }
        cin.ignore();

        cout << "Masukkan Ukuran (S/M/L): ";
        string ukuran;
        getline(cin, ukuran);
        for (int i = 0; i < ukuran.length(); i++) {
            ukuran[i] = toupper(ukuran[i]);
        }

        cout << "Jenis Biji Kopi (Arabika/Robusta): ";
        string jenis_biji;
        getline(cin, jenis_biji);

        cout << "Asal Biji Kopi (ex: Gayo/Toraja): ";
        string asal_biji;
        getline(cin, asal_biji);

        cout << "Kadar Kafein (Tinggi/Sedang/Rendah): ";
        string kafein;
        getline(cin, kafein);

        cout << "Jenis Susu (Full Cream/Oat/Almond): ";
        string susu;
        getline(cin, susu);

        cout << "Busa Susu (Tebal/Sedang/Tipis): ";
        string busa;
        getline(cin, busa);

        cout << "Ekstra Shot (Ya/Tidak): ";
        string shot;
        getline(cin, shot);

        KopiLatte latte_baru(kode, nama, harga, ukuran, jenis_biji, asal_biji, kafein, susu, busa, shot);
        daftarKopiLatte.push_back(latte_baru);
        cout << "!! Homre. Kopi Latte berhasil ditambah yah !!" << endl;
    }
};

// inisialisasi array static
vector<KopiLatte> KopiLatte::daftarKopiLatte;