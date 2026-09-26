<?php
require_once "ProdukMinuman.php";

class MinumanTeh extends ProdukMinuman {
    protected string $jenisDaunTeh;
    protected string $asalDaunTeh;
    protected string $tingkatKemanisan;

    public function __construct(string $kode, string $namaMinuman, int $harga, string $ukuran, string $jenisDaunTeh, string $asalDaunTeh, string $tingkatKemanisan, string $fotoProduk = "") {
        parent::__construct($kode, $namaMinuman, $harga, $ukuran, $fotoProduk);
        $this->jenisDaunTeh = $jenisDaunTeh;
        $this->asalDaunTeh = $asalDaunTeh;
        $this->tingkatKemanisan = $tingkatKemanisan;
    }

    public function getJenisDaunTeh(): string { return $this->jenisDaunTeh; }
    public function getAsalDaunTeh(): string { return $this->asalDaunTeh; }
    public function getTingkatKemanisan(): string { return $this->tingkatKemanisan; }

    public function setJenisDaunTeh(string $jenis): void { $this->jenisDaunTeh = $jenis; }
    public function setAsalDaunTeh(string $asal): void { $this->asalDaunTeh = $asal; }
    public function setTingkatKemanisan(string $tingkat): void { $this->tingkatKemanisan = $tingkat; }
}