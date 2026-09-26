# Grandparent Class
class ProdukMinuman:
    def __init__(self, kode: str, namaMinuman: str, harga: int, ukuran: str):
        self.__kode = str(kode) # kode unik
        self.__namaMinuman = str(namaMinuman)
        self.__harga = int(harga)
        self.__ukuran = str(ukuran)

    # getter dulu mas
    def getKode(self) -> str:
        return self.__kode

    def getNamaMinuman(self) -> str:
        return self.__namaMinuman

    def getHarga(self) -> int:
        return self.__harga

    def getUkuran(self) -> str:
        return self.__ukuran

    # setter urutannya samain aja
    def setKode(self, kode: str) -> None:
        self.__kode = str(kode)

    def setNamaMinuman(self, namaMinuman: str) -> None:
        self.__namaMinuman = str(namaMinuman)

    def setHarga(self, harga: int) -> None:
        self.__harga = int(harga)

    def setUkuran(self, ukuran: str) -> None:
        self.__ukuran = str(ukuran)