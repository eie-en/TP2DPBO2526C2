#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "KopiLatte.cpp"
#include "BobaMilkTea.cpp"

using namespace std;

// fungsi buat nampilin tabel gabungan dari semua data kelas
void displayTabelSemuaData() {
    vector<vector<string>> semua_data;

    // tarik data latte
    for (int i = 0; i < KopiLatte::daftarKopiLatte.size(); i++) {
        semua_data.push_back({
            KopiLatte::daftarKopiLatte[i].getKode(), 
            KopiLatte::daftarKopiLatte[i].getNamaMinuman(), 
            "Rp" + to_string(KopiLatte::daftarKopiLatte[i].getHarga()), 
            KopiLatte::daftarKopiLatte[i].getUkuran(),
            "Kopi Latte", 
            KopiLatte::daftarKopiLatte[i].getJenisBijiKopi() + " (" + KopiLatte::daftarKopiLatte[i].getAsalBijiKopi() + ")", 
            KopiLatte::daftarKopiLatte[i].getKadarKafein(),
            "-", "-", 
            KopiLatte::daftarKopiLatte[i].getJenisSusu(), 
            KopiLatte::daftarKopiLatte[i].getBusaSusu(), 
            KopiLatte::daftarKopiLatte[i].getEkstraShot(), 
            "-", "-"
        });
    }

    // tarik data boba
    for (int i = 0; i < BobaMilkTea::daftarBoba.size(); i++) {
        semua_data.push_back({
            BobaMilkTea::daftarBoba[i].getKode(), 
            BobaMilkTea::daftarBoba[i].getNamaMinuman(), 
            "Rp" + to_string(BobaMilkTea::daftarBoba[i].getHarga()), 
            BobaMilkTea::daftarBoba[i].getUkuran(),
            "Boba Milk Tea", "-", "-",
            BobaMilkTea::daftarBoba[i].getJenisDaunTeh() + " (" + BobaMilkTea::daftarBoba[i].getAsalDaunTeh() + ")", 
            BobaMilkTea::daftarBoba[i].getTingkatKemanisan(),
            BobaMilkTea::daftarBoba[i].getJenisSusu(), 
            "-", "-", 
            BobaMilkTea::daftarBoba[i].getTopping(), 
            BobaMilkTea::daftarBoba[i].getIceLevel()
        });
    }

    if (semua_data.empty()) {
        cout << "\nData minuman masih kosong mas." << endl;
        return;
    }

    vector<string> headers = {
        "Kode", "Nama Minuman", "Harga", "Size", "Kategori", 
        "Biji Kopi (Asal)", "Kafein", "Daun Teh (Asal)", "Manis", 
        "Jenis Susu", "Busa Susu", "Ex Shot", "Topping", "Ice"
    };

    // hitung lebar kolom dinamis
    vector<int> col_widths(headers.size());
    for (int i = 0; i < headers.size(); i++) {
        col_widths[i] = headers[i].length();
    }

    for (int i = 0; i < semua_data.size(); i++) {
        for (int j = 0; j < semua_data[i].size(); j++) {
            if (semua_data[i][j].length() > col_widths[j]) {
                col_widths[j] = semua_data[i][j].length();
            }
        }
    }

    // pembatas garis tabel
    string border = "+";
    for (int i = 0; i < col_widths.size(); i++) {
        border += string(col_widths[i] + 2, '-') + "+";
    }

    cout << "\n" << border << endl;
    cout << "| ";
    for (int i = 0; i < headers.size(); i++) {
        cout << headers[i];
        for (int space = 0; space < col_widths[i] - headers[i].length(); space++) {
            cout << " ";
        }
        cout << " | ";
    }
    cout << "\n" << border << endl;

    for (int i = 0; i < semua_data.size(); i++) {
        cout << "| ";
        for (int j = 0; j < semua_data[i].size(); j++) {
            cout << semua_data[i][j];
            for (int space = 0; space < col_widths[j] - semua_data[i][j].length(); space++) {
                cout << " ";
            }
            cout << " | ";
        }
        cout << endl;
    }

    cout << border << "\n" << endl;
}

int main() {
    // data dummy 5 biji diawal
    // 3 latte
    KopiLatte::daftarKopiLatte.push_back(
        KopiLatte("L001", "Caramel Macchiato", 35000, "M", "Arabika", "Gayo", "Sedang", "Full Cream", "Tebal", "Ya")
    );
    KopiLatte::daftarKopiLatte.push_back(
        KopiLatte("L002", "Oat Vanilla Latte", 40000, "L", "Arabika", "Kintamani", "Rendah", "Oat", "Sedang", "Tidak")
    );
    KopiLatte::daftarKopiLatte.push_back(
        KopiLatte("L003", "Double Shot Latte", 38000, "S", "Robusta", "Toraja", "Tinggi", "Full Cream", "Tipis", "Ya")
    );

    // 2 boba
    BobaMilkTea::daftarBoba.push_back(
        BobaMilkTea("B001", "Brown Sugar Boba", 30000, "L", "Black Tea", "Assam", "100%", "Boba", "Normal", "Fresh Milk")
    );
    BobaMilkTea::daftarBoba.push_back(
        BobaMilkTea("B002", "Jasmine Milk Tea", 25000, "M", "Jasmine", "Ciwidey", "50%", "Pudding", "Less Ice", "Condensed")
    );

    // menu pilihan
    cout << "pilih aja ini menu masih template tp 1 : " << endl;
    while (true) {
        cout << "1. Show" << endl;
        cout << "2. Add Latte" << endl;
        cout << "3. Add Boba" << endl;
        cout << "ketik 'malas' untuk keluar program" << endl;
        cout << "---------------------------------------" << endl;

        cout << "Select: ";
        string select;
        getline(cin, select);
        for (int i = 0; i < select.length(); i++) {
            select[i] = tolower(select[i]);
        }

        // buat nentuin apa yang dipake
        if (select == "malas") {
            cout << "oke dadah" << endl;
            break;
        } else if (select == "show" || select == "1") {
            displayTabelSemuaData();
        } else if (select == "add latte" || select == "2") {
            KopiLatte::addLatte();
            cout << "---------------------------------------\n" << endl;
        } else if (select == "add boba" || select == "3") {
            BobaMilkTea::addBoba();
            cout << "---------------------------------------\n" << endl;
        } else {
            cout << "kamu goy, itu pilihan apa\n" << endl;
        }
    }

    return 0;
}