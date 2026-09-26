#pragma once
#include <iostream>
#include "ProdukMinuman.cpp"

using namespace std;

// Parent Class (Level 2) - Inherit dari ProdukMinuman
class MinumanKopi : public ProdukMinuman {
private:
    string jenisBijiKopi;
    string asalBijiKopi;
    string kadarKafein;

public:
    MinumanKopi() : ProdukMinuman() {
        this->jenisBijiKopi = "";
        this->asalBijiKopi = "";
        this->kadarKafein = "";
    }

    // panggil constructor parent
    MinumanKopi(string kode, string namaMinuman, int harga, string ukuran, string jenisBijiKopi, string asalBijiKopi, string kadarKafein) 
        : ProdukMinuman(kode, namaMinuman, harga, ukuran) {
        this->jenisBijiKopi = jenisBijiKopi;
        this->asalBijiKopi = asalBijiKopi;
        this->kadarKafein = kadarKafein;
    }

    ~MinumanKopi() {}

    string getJenisBijiKopi() {
        return this->jenisBijiKopi;
    }

    string getAsalBijiKopi() {
        return this->asalBijiKopi;
    }

    string getKadarKafein() {
        return this->kadarKafein;
    }

    void setJenisBijiKopi(string jenis) {
        this->jenisBijiKopi = jenis;
    }

    void setAsalBijiKopi(string asal) {
        this->asalBijiKopi = asal;
    }

    void setKadarKafein(string kadar) {
        this->kadarKafein = kadar;
    }
};