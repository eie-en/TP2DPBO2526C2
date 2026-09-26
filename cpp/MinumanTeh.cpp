#pragma once
#include <iostream>
#include "ProdukMinuman.cpp"

using namespace std;

// Parent 2 (Teh)
class MinumanTeh : public ProdukMinuman {
private:
    string jenisDaunTeh;
    string asalDaunTeh;
    string tingkatKemanisan;

public:
    MinumanTeh() : ProdukMinuman() {
        this->jenisDaunTeh = "";
        this->asalDaunTeh = "";
        this->tingkatKemanisan = "";
    }

    MinumanTeh(string kode, string namaMinuman, int harga, string ukuran, string jenisDaunTeh, string asalDaunTeh, string tingkatKemanisan) 
        : ProdukMinuman(kode, namaMinuman, harga, ukuran) {
        this->jenisDaunTeh = jenisDaunTeh;
        this->asalDaunTeh = asalDaunTeh;
        this->tingkatKemanisan = tingkatKemanisan;
    }

    virtual ~MinumanTeh() {}

    string getJenisDaunTeh() {
        return this->jenisDaunTeh;
    }

    string getAsalDaunTeh() {
        return this->asalDaunTeh;
    }

    string getTingkatKemanisan() {
        return this->tingkatKemanisan;
    }

    void setJenisDaunTeh(string jenis) {
        this->jenisDaunTeh = jenis;
    }

    void setAsalDaunTeh(string asal) {
        this->asalDaunTeh = asal;
    }

    void setTingkatKemanisan(string tingkatKemanisan) {
        this->tingkatKemanisan = tingkatKemanisan;
    }
};