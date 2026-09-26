from MinumanKopi import MinumanKopi

class KopiLatte(MinumanKopi):
    daftarKopiLatte = [] # array nampung latte

    def __init__(self, kode: str, namaMinuman: str, harga: int, ukuran: str, jenisBijiKopi: str, asalBijiKopi: str, kadarKafein: str, jenisSusu: str, busaSusu: str, ekstraShot: str):
        super().__init__(kode, namaMinuman, harga, ukuran, jenisBijiKopi, asalBijiKopi, kadarKafein)
        self.__jenisSusu = str(jenisSusu)
        self.__busaSusu = str(busaSusu)
        self.__ekstraShot = str(ekstraShot)

    def getJenisSusu(self) -> str:
        return self.__jenisSusu

    def getBusaSusu(self) -> str:
        return self.__busaSusu

    def getEkstraShot(self) -> str:
        return self.__ekstraShot

    def setJenisSusu(self, jenis: str) -> None:
        self.__jenisSusu = str(jenis)

    def setBusaSusu(self, busa: str) -> None:
        self.__busaSusu = str(busa)

    def setEkstraShot(self, shot: str) -> None:
        self.__ekstraShot = str(shot)

    # tambah latte baru
    @classmethod
    def addLatte(cls):
        print("\n--- Tambah Menu Kopi Latte ---")
        kode = input("Masukkan Kode (ex: L001): ").strip().upper()

        # biar kode kaga bentrok
        for latte in cls.daftarKopiLatte:
            if latte.getKode() == kode:
                print("Error: Kode latte udah terdaftar mas!")
                return

        nama = input("Masukkan Nama Minuman: ").strip()
        try:
            harga = int(input("Masukkan Harga: "))
        except ValueError:
            print("Error: Harganya pake angka mas")
            return

        ukuran = input("Masukkan Ukuran (S/M/L): ").strip().upper()
        jenis_biji = input("Jenis Biji Kopi (Arabika/Robusta): ").strip()
        asal_biji = input("Asal Biji Kopi (ex: Gayo/Toraja): ").strip()
        kafein = input("Kadar Kafein (Tinggi/Sedang/Rendah): ").strip()
        susu = input("Jenis Susu (Full Cream/Oat/Almond): ").strip()
        busa = input("Busa Susu (Tebal/Sedang/Tipis): ").strip()
        shot = input("Ekstra Shot (Ya/Tidak): ").strip()

        latte_baru = cls(kode, nama, harga, ukuran, jenis_biji, asal_biji, kafein, susu, busa, shot)
        cls.daftarKopiLatte.append(latte_baru)
        print("!! Homre. Kopi Latte berhasil ditambah yah !!")