<?php
require_once "MinumanKopi.php";

class KopiLatte extends MinumanKopi {
    private string $jenisSusu;
    private string $busaSusu;
    private string $ekstraShot;

    public function __construct(string $kode, string $namaMinuman, int $harga, string $ukuran, string $jenisBijiKopi, string $asalBijiKopi, string $kadarKafein, string $jenisSusu, string $busaSusu, string $ekstraShot, string $fotoProduk = "") {
        parent::__construct($kode, $namaMinuman, $harga, $ukuran, $jenisBijiKopi, $asalBijiKopi, $kadarKafein, $fotoProduk);
        $this->jenisSusu = $jenisSusu;
        $this->busaSusu = $busaSusu;
        $this->ekstraShot = $ekstraShot;
    }

    public function getJenisSusu(): string { return $this->jenisSusu; }
    public function getBusaSusu(): string { return $this->busaSusu; }
    public function getEkstraShot(): string { return $this->ekstraShot; }

    public function setJenisSusu(string $jenis): void { $this->jenisSusu = $jenis; }
    public function setBusaSusu(string $busa): void { $this->busaSusu = $busa; }
    public function setEkstraShot(string $shot): void { $this->ekstraShot = $shot; }
}