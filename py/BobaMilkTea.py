from MinumanTeh import MinumanTeh

class BobaMilkTea(MinumanTeh):
    daftarBoba = [] # array boba

    def __init__(self, kode: str, namaMinuman: str, harga: int, ukuran: str, jenisDaunTeh: str, asalDaunTeh: str, tingkatKemanisan: str, topping: str, iceLevel: str, jenisSusu: str):
        super().__init__(kode, namaMinuman, harga, ukuran, jenisDaunTeh, asalDaunTeh, tingkatKemanisan)
        self.__topping = str(topping)
        self.__iceLevel = str(iceLevel)
        self.__jenisSusu = str(jenisSusu)

    def getTopping(self) -> str:
        return self.__topping

    def getIceLevel(self) -> str:
        return self.__iceLevel

    def getJenisSusu(self) -> str:
        return self.__jenisSusu

    def setTopping(self, topping: str) -> None:
        self.__topping = str(topping)

    def setIceLevel(self, ice: str) -> None:
        self.__iceLevel = str(ice)

    def setJenisSusu(self, susu: str) -> None:
        self.__jenisSusu = str(susu)

    # tambah boba
    @classmethod
    def addBoba(cls):
        print("\n--- Tambah Menu Boba Milk Tea ---")
        kode = input("Masukkan Kode (ex: B001): ").strip().upper()

        for boba in cls.daftarBoba:
            if boba.getKode() == kode:
                print("Error: Kode boba udah terdaftar mas!")
                return

        nama = input("Masukkan Nama Minuman: ").strip()
        try:
            harga = int(input("Masukkan Harga: "))
        except ValueError:
            print("Error: Harganya angka mas")
            return

        ukuran = input("Masukkan Ukuran (S/M/L): ").strip().upper()
        jenis_teh = input("Jenis Daun Teh (Black Tea/Jasmine/Earl Grey): ").strip()
        asal_teh = input("Asal Daun Teh (ex: Ciwidey/Assam): ").strip()
        manis = input("Tingkat Kemanisan (0%/50%/100%): ").strip()
        topping = input("Topping (Boba/Pudding/Grass Jelly): ").strip()
        ice = input("Ice Level (No Ice/Less Ice/Normal): ").strip()
        susu = input("Jenis Susu (Full Cream/Condensed/Fresh): ").strip()

        boba_baru = cls(kode, nama, harga, ukuran, jenis_teh, asal_teh, manis, topping, ice, susu)
        cls.daftarBoba.append(boba_baru)
        print("!! Homre. Boba Milk Tea berhasil ditambah yah !!")