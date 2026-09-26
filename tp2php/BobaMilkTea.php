<?php
require_once "MinumanTeh.php";

class BobaMilkTea extends MinumanTeh {
    private string $topping;
    private string $iceLevel;
    private string $jenisSusu;

    public function __construct(string $kode, string $namaMinuman, int $harga, string $ukuran, string $jenisDaunTeh, string $asalDaunTeh, string $tingkatKemanisan, string $topping, string $iceLevel, string $jenisSusu, string $fotoProduk = "") {
        parent::__construct($kode, $namaMinuman, $harga, $ukuran, $jenisDaunTeh, $asalDaunTeh, $tingkatKemanisan, $fotoProduk);
        $this->topping = $topping;
        $this->iceLevel = $iceLevel;
        $this->jenisSusu = $jenisSusu;
    }

    public function getTopping(): string { return $this->topping; }
    public function getIceLevel(): string { return $this->iceLevel; }
    public function getJenisSusu(): string { return $this->jenisSusu; }

    public function setTopping(string $topping): void { $this->topping = $topping; }
    public function setIceLevel(string $ice): void { $this->iceLevel = $ice; }
    public function setJenisSusu(string $susu): void { $this->jenisSusu = $susu; }
}