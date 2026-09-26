public class MinumanKopi extends ProdukMinuman {
    private String jenisBijiKopi;
    private String asalBijiKopi;
    private String kadarKafein;

    public MinumanKopi(String kode, String namaMinuman, int harga, String ukuran, String jenisBijiKopi, String asalBijiKopi, String kadarKafein) {
        super(kode, namaMinuman, harga, ukuran);
        this.jenisBijiKopi = jenisBijiKopi;
        this.asalBijiKopi = asalBijiKopi;
        this.kadarKafein = kadarKafein;
    }

    public String getJenisBijiKopi() {
        return this.jenisBijiKopi;
    }

    public String getAsalBijiKopi() {
        return this.asalBijiKopi;
    }

    public String getKadarKafein() {
        return this.kadarKafein;
    }

    public void setJenisBijiKopi(String jenisBijiKopi) {
        this.jenisBijiKopi = jenisBijiKopi;
    }

    public void setAsalBijiKopi(String asalBijiKopi) {
        this.asalBijiKopi = asalBijiKopi;
    }

    public void setKadarKafein(String kadarKafein) {
        this.kadarKafein = kadarKafein;
    }
}