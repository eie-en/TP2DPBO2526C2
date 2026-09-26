#pragma once
#include <iostream>
#include <string>

using namespace std;

// Grandparent Class (Level 1)
class ProdukMinuman {
private:
    string kode; // kode unik
    string namaMinuman;
    int harga;
    string ukuran;

public:
    ProdukMinuman() {
        this->kode = "";
        this->namaMinuman = "";
        this->harga = 0;
        this->ukuran = "";
    }

    ProdukMinuman(string kode, string namaMinuman, int harga, string ukuran) {
        this->kode = kode;
        this->namaMinuman = namaMinuman;
        this->harga = harga;
        this->ukuran = ukuran;
    }

    ~ProdukMinuman() {}

    // getter dulu mas
    string getKode() {
        return this->kode;
    }

    string getNamaMinuman() {
        return this->namaMinuman;
    }

    int getHarga() {
        return this->harga;
    }

    string getUkuran() {
        return this->ukuran;
    }

    // setter
    void setKode(string kode) {
        this->kode = kode;
    }

    void setNamaMinuman(string namaMinuman) {
        this->namaMinuman = namaMinuman;
    }

    void setHarga(int harga) {
        this->harga = harga;
    }

    void setUkuran(string ukuran) {
        this->ukuran = ukuran;
    }
};