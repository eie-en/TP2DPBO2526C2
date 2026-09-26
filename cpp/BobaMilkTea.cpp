#pragma once
#include <iostream>
#include <vector>
#include "MinumanTeh.cpp"

using namespace std;

// Child 2 (Boba)
class BobaMilkTea : public MinumanTeh {
private:
    string topping;
    string iceLevel;
    string jenisSusu;

public:
    static vector<BobaMilkTea> daftarBoba; // array boba

    BobaMilkTea() : MinumanTeh() {
        this->topping = "";
        this->iceLevel = "";
        this->jenisSusu = "";
    }

    BobaMilkTea(string kode, string namaMinuman, int harga, string ukuran, string jenisDaunTeh, string asalDaunTeh, string tingkatKemanisan, string topping, string iceLevel, string jenisSusu)
        : MinumanTeh(kode, namaMinuman, harga, ukuran, jenisDaunTeh, asalDaunTeh, tingkatKemanisan) {
        this->topping = topping;
        this->iceLevel = iceLevel;
        this->jenisSusu = jenisSusu;
    }

    ~BobaMilkTea() {}

    string getTopping() {
        return this->topping;
    }

    string getIceLevel() {
        return this->iceLevel;
    }

    string getJenisSusu() {
        return this->jenisSusu;
    }

    void setTopping(string topping) {
        this->topping = topping;
    }

    void setIceLevel(string ice) {
        this->iceLevel = ice;
    }

    void setJenisSusu(string susu) {
        this->jenisSusu = susu;
    }

    // tambah boba
    static void addBoba() {
        cout << "\n--- Tambah Menu Boba Milk Tea ---" << endl;
        cout << "Masukkan Kode (ex: B001): ";
        string kode;
        getline(cin, kode);
        for (int i = 0; i < kode.length(); i++) {
            kode[i] = toupper(kode[i]);
        }

        for (int i = 0; i < daftarBoba.size(); i++) {
            if (daftarBoba[i].getKode() == kode) {
                cout << "Error: Kode boba udah terdaftar mas!" << endl;
                return;
            }
        }

        cout << "Masukkan Nama Minuman: ";
        string nama;
        getline(cin, nama);

        int harga;
        cout << "Masukkan Harga: ";
        if (!(cin >> harga)) {
            cout << "Error: Harganya angka mas" << endl;
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

        cout << "Jenis Daun Teh (Black Tea/Jasmine/Earl Grey): ";
        string jenis_teh;
        getline(cin, jenis_teh);

        cout << "Asal Daun Teh (ex: Ciwidey/Assam): ";
        string asal_teh;
        getline(cin, asal_teh);

        cout << "Tingkat Kemanisan (0%/50%/100%): ";
        string manis;
        getline(cin, manis);

        cout << "Topping (Boba/Pudding/Grass Jelly): ";
        string topping;
        getline(cin, topping);

        cout << "Ice Level (No Ice/Less Ice/Normal): ";
        string ice;
        getline(cin, ice);

        cout << "Jenis Susu (Full Cream/Condensed/Fresh): ";
        string susu;
        getline(cin, susu);

        BobaMilkTea boba_baru(kode, nama, harga, ukuran, jenis_teh, asal_teh, manis, topping, ice, susu);
        daftarBoba.push_back(boba_baru);
        cout << "!! Homre. Boba Milk Tea berhasil ditambah yah !!" << endl;
    }
};

// inisialisasi array static
vector<BobaMilkTea> BobaMilkTea::daftarBoba;