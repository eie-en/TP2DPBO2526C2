<?php
require_once "ProdukMinuman.php";

class MinumanKopi extends ProdukMinuman {
    protected string $jenisBijiKopi;
    protected string $asalBijiKopi;
    protected string $kadarKafein;

    public function __construct(string $kode, string $namaMinuman, int $harga, string $ukuran, string $jenisBijiKopi, string $asalBijiKopi, string $kadarKafein, string $fotoProduk = "") {
        parent::__construct($kode, $namaMinuman, $harga, $ukuran, $fotoProduk);
        $this->jenisBijiKopi = $jenisBijiKopi;
        $this->asalBijiKopi = $asalBijiKopi;
        $this->kadarKafein = $kadarKafein;
    }

    public function getJenisBijiKopi(): string { return $this->jenisBijiKopi; }
    public function getAsalBijiKopi(): string { return $this->asalBijiKopi; }
    public function getKadarKafein(): string { return $this->kadarKafein; }

    public function setJenisBijiKopi(string $jenis): void { $this->jenisBijiKopi = $jenis; }
    public function setAsalBijiKopi(string $asal): void { $this->asalBijiKopi = $asal; }
    public function setKadarKafein(string $kadar): void { $this->kadarKafein = $kadar; }
}