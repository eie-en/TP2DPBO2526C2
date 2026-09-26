from ProdukMinuman import ProdukMinuman

class MinumanTeh(ProdukMinuman):
    def __init__(self, kode: str, namaMinuman: str, harga: int, ukuran: str, jenisDaunTeh: str, asalDaunTeh: str, tingkatKemanisan: str):
        super().__init__(kode, namaMinuman, harga, ukuran)
        self.__jenisDaunTeh = str(jenisDaunTeh)
        self.__asalDaunTeh = str(asalDaunTeh)
        self.__tingkatKemanisan = str(tingkatKemanisan)

    def getJenisDaunTeh(self) -> str:
        return self.__jenisDaunTeh

    def getAsalDaunTeh(self) -> str:
        return self.__asalDaunTeh

    def getTingkatKemanisan(self) -> str:
        return self.__tingkatKemanisan

    def setJenisDaunTeh(self, jenis: str) -> None:
        self.__jenisDaunTeh = str(jenis)

    def setAsalDaunTeh(self, asal: str) -> None:
        self.__asalDaunTeh = str(asal)

    def setTingkatKemanisan(self, tingkatKemanisan: str) -> None:
        self.__tingkatKemanisan = str(tingkatKemanisan)