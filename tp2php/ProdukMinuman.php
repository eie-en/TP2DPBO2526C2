<?php

class ProdukMinuman {
    protected string $kode;
    protected string $namaMinuman;
    protected int $harga;
    protected string $ukuran;
    protected string $fotoProduk;

    public function __construct(string $kode, string $namaMinuman, int $harga, string $ukuran, string $fotoProduk = "") {
        $this->kode = $kode;
        $this->namaMinuman = $namaMinuman;
        $this->harga = $harga;
        $this->ukuran = $ukuran;
        $this->fotoProduk = $fotoProduk;
    }

    public function getKode(): string { return $this->kode; }
    public function getNamaMinuman(): string { return $this->namaMinuman; }
    public function getHarga(): int { return $this->harga; }
    public function getUkuran(): string { return $this->ukuran; }
    public function getFotoProduk(): string { return $this->fotoProduk; }

    public function setKode(string $kode): void { $this->kode = $kode; }
    public function setNamaMinuman(string $namaMinuman): void { $this->namaMinuman = $namaMinuman; }
    public function setHarga(int $harga): void { $this->harga = $harga; }
    public function setUkuran(string $ukuran): void { $this->ukuran = $ukuran; }
    public function setFotoProduk(string $fotoProduk): void { $this->fotoProduk = $fotoProduk; }
}