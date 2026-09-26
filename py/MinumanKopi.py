from ProdukMinuman import ProdukMinuman

class MinumanKopi(ProdukMinuman):
    def __init__(self, kode: str, namaMinuman: str, harga: int, ukuran: str, jenisBijiKopi: str, asalBijiKopi: str, kadarKafein: str):
        super().__init__(kode, namaMinuman, harga, ukuran)
        self.__jenisBijiKopi = str(jenisBijiKopi)
        self.__asalBijiKopi = str(asalBijiKopi)
        self.__kadarKafein = str(kadarKafein)

    def getJenisBijiKopi(self) -> str:
        return self.__jenisBijiKopi

    def getAsalBijiKopi(self) -> str:
        return self.__asalBijiKopi

    def getKadarKafein(self) -> str:
        return self.__kadarKafein

    def setJenisBijiKopi(self, jenis: str) -> None:
        self.__jenisBijiKopi = str(jenis)

    def setAsalBijiKopi(self, asal: str) -> None:
        self.__asalBijiKopi = str(asal)

    def setKadarKafein(self, kadar: str) -> None:
        self.__kadarKafein = str(kadar)