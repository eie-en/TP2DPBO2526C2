from KopiLatte import KopiLatte
from BobaMilkTea import BobaMilkTea

# fungsi buat nampilin tabel gabungan dari semua data kelas
def displayTabelSemuaData():
    semua_data = []

    # tarik data latte
    for k in KopiLatte.daftarKopiLatte:
        semua_data.append([
            k.getKode(), k.getNamaMinuman(), f"Rp{k.getHarga()}", k.getUkuran(),
            "Kopi Latte", f"{k.getJenisBijiKopi()} ({k.getAsalBijiKopi()})", k.getKadarKafein(),
            "-", "-", k.getJenisSusu(), k.getBusaSusu(), k.getEkstraShot(), "-", "-"
        ])

    # tarik data boba
    for b in BobaMilkTea.daftarBoba:
        semua_data.append([
            b.getKode(), b.getNamaMinuman(), f"Rp{b.getHarga()}", b.getUkuran(),
            "Boba Milk Tea", "-", "-",
            f"{b.getJenisDaunTeh()} ({b.getAsalDaunTeh()})", b.getTingkatKemanisan(),
            b.getJenisSusu(), "-", "-", b.getTopping(), b.getIceLevel()
        ])

    if not semua_data:
        print("\nData minuman masih kosong mas.")
        return

    headers = [
        "Kode", "Nama Minuman", "Harga", "Size", "Kategori", 
        "Biji Kopi (Asal)", "Kafein", "Daun Teh (Asal)", "Manis", 
        "Jenis Susu", "Busa Susu", "Ex Shot", "Topping", "Ice"
    ]

    # hitung lebar kolom dinamis
    col_widths = [len(h) for h in headers]
    for row in semua_data:
        for i, val in enumerate(row):
            col_widths[i] = max(col_widths[i], len(str(val)))

    # pembatas garis tabel
    border = "+" + "+".join("-" * (w + 2) for w in col_widths) + "+"

    print("\n" + border)
    header_row = "| " + " | ".join(f"{headers[i]:<{col_widths[i]}}" for i in range(len(headers))) + " |"
    print(header_row)
    print(border)

    for row in semua_data:
        data_row = "| " + " | ".join(f"{str(row[i]):<{col_widths[i]}}" for i in range(len(row))) + " |"
        print(data_row)

    print(border + "\n")


def main():
    # data dummy 5 biji diawal
    # 3 latte
    KopiLatte.daftarKopiLatte.append(
        KopiLatte("L001", "Caramel Macchiato", 35000, "M", "Arabika", "Gayo", "Sedang", "Full Cream", "Tebal", "Ya")
    )
    KopiLatte.daftarKopiLatte.append(
        KopiLatte("L002", "Oat Vanilla Latte", 40000, "L", "Arabika", "Kintamani", "Rendah", "Oat", "Sedang", "Tidak")
    )
    KopiLatte.daftarKopiLatte.append(
        KopiLatte("L003", "Double Shot Latte", 38000, "S", "Robusta", "Toraja", "Tinggi", "Full Cream", "Tipis", "Ya")
    )

    # 2 boba
    BobaMilkTea.daftarBoba.append(
        BobaMilkTea("B001", "Brown Sugar Boba", 30000, "L", "Black Tea", "Assam", "100%", "Boba", "Normal", "Fresh Milk")
    )
    BobaMilkTea.daftarBoba.append(
        BobaMilkTea("B002", "Jasmine Milk Tea", 25000, "M", "Jasmine", "Ciwidey", "50%", "Pudding", "Less Ice", "Condensed")
    )

    # menu pilihan
    print("pilih aja ini menu masih template tp 1 : ")
    while True:
        print("1. Show")
        print("2. Add Latte")
        print("3. Add Boba")
        print("ketik 'malas' untuk keluar program")
        print("---------------------------------------")

        select = input("Select: ").lower().strip()

        match select:
            case "malas":
                print("oke dadah")
                break
            case "show" | "1":
                displayTabelSemuaData()
            case "add latte" | "2":
                KopiLatte.addLatte()
                print("---------------------------------------\n")
            case "add boba" | "3":
                BobaMilkTea.addBoba()
                print("---------------------------------------\n")
            case _:
                print("kamu goy, itu pilihan apa\n")

if __name__ == "__main__":
    main()