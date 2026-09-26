public class MinumanTeh extends ProdukMinuman {
    private String jenisDaunTeh;
    private String asalDaunTeh;
    private String tingkatKemanisan;

    public MinumanTeh(String kode, String namaMinuman, int harga, String ukuran, String jenisDaunTeh, String asalDaunTeh, String tingkatKemanisan) {
        super(kode, namaMinuman, harga, ukuran);
        this.jenisDaunTeh = jenisDaunTeh;
        this.asalDaunTeh = asalDaunTeh;
        this.tingkatKemanisan = tingkatKemanisan;
    }

    public String getJenisDaunTeh() {
        return this.jenisDaunTeh;
    }

    public String getAsalDaunTeh() {
        return this.asalDaunTeh;
    }

    public String getTingkatKemanisan() {
        return this.tingkatKemanisan;
    }

    public void setJenisDaunTeh(String jenisDaunTeh) {
        this.jenisDaunTeh = jenisDaunTeh;
    }

    public void setAsalDaunTeh(String asalDaunTeh) {
        this.asalDaunTeh = asalDaunTeh;
    }

    public void setTingkatKemanisan(String tingkatKemanisan) {
        this.tingkatKemanisan = tingkatKemanisan;
    }
}