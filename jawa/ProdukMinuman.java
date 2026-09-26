public class ProdukMinuman {
    private String kode; // kode unik
    private String namaMinuman;
    private int harga;
    private String ukuran;

    public ProdukMinuman(String kode, String namaMinuman, int harga, String ukuran) {
        this.kode = kode;
        this.namaMinuman = namaMinuman;
        this.harga = harga;
        this.ukuran = ukuran;
    }

    // getter dulu mas
    public String getKode() {
        return this.kode;
    }

    public String getNamaMinuman() {
        return this.namaMinuman;
    }

    public int getHarga() {
        return this.harga;
    }

    public String getUkuran() {
        return this.ukuran;
    }

    // setter urutannya samain aja
    public void setKode(String kode) {
        this.kode = kode;
    }

    public void setNamaMinuman(String namaMinuman) {
        this.namaMinuman = namaMinuman;
    }

    public void setHarga(int harga) {
        this.harga = harga;
    }

    public void setUkuran(String ukuran) {
        this.ukuran = ukuran;
    }
}