import java.util.ArrayList;
import java.util.Scanner;

public class KopiLatte extends MinumanKopi {
    public static ArrayList<KopiLatte> daftarKopiLatte = new ArrayList<>(); // array nampung latte

    private String jenisSusu;
    private String busaSusu;
    private String ekstraShot;

    public KopiLatte(String kode, String namaMinuman, int harga, String ukuran, String jenisBijiKopi, String asalBijiKopi, String kadarKafein, String jenisSusu, String busaSusu, String ekstraShot) {
        super(kode, namaMinuman, harga, ukuran, jenisBijiKopi, asalBijiKopi, kadarKafein);
        this.jenisSusu = jenisSusu;
        this.busaSusu = busaSusu;
        this.ekstraShot = ekstraShot;
    }

    public String getJenisSusu() {
        return this.jenisSusu;
    }

    public String getBusaSusu() {
        return this.busaSusu;
    }

    public String getEkstraShot() {
        return this.ekstraShot;
    }

    public void setJenisSusu(String jenisSusu) {
        this.jenisSusu = jenisSusu;
    }

    public void setBusaSusu(String busaSusu) {
        this.busaSusu = busaSusu;
    }

    public void setEkstraShot(String ekstraShot) {
        this.ekstraShot = ekstraShot;
    }

    // tambah latte baru
    public static void addLatte(Scanner scanner) {
        System.out.println("\n--- Tambah Menu Kopi Latte ---");
        System.out.print("Masukkan Kode (ex: L001): ");
        String kode = scanner.nextLine().trim().toUpperCase();

        // biar kode kaga bentrok
        for (KopiLatte latte : daftarKopiLatte) {
            if (latte.getKode().equals(kode)) {
                System.out.println("Error: Kode latte udah terdaftar mas!");
                return;
            }
        }

        System.out.print("Masukkan Nama Minuman: ");
        String nama = scanner.nextLine().trim();

        int harga = 0;
        System.out.print("Masukkan Harga: ");
        try {
            harga = Integer.parseInt(scanner.nextLine().trim());
        } catch (NumberFormatException e) {
            System.out.println("Error: Harganya pake angka mas");
            return;
        }

        System.out.print("Masukkan Ukuran (S/M/L): ");
        String ukuran = scanner.nextLine().trim().toUpperCase();

        System.out.print("Jenis Biji Kopi (Arabika/Robusta): ");
        String jenisBiji = scanner.nextLine().trim();

        System.out.print("Asal Biji Kopi (ex: Gayo/Toraja): ");
        String asalBiji = scanner.nextLine().trim();

        System.out.print("Kadar Kafein (Tinggi/Sedang/Rendah): ");
        String kafein = scanner.nextLine().trim();

        System.out.print("Jenis Susu (Full Cream/Oat/Almond): ");
        String susu = scanner.nextLine().trim();

        System.out.print("Busa Susu (Tebal/Sedang/Tipis): ");
        String busa = scanner.nextLine().trim();

        System.out.print("Ekstra Shot (Ya/Tidak): ");
        String shot = scanner.nextLine().trim();

        KopiLatte latteBaru = new KopiLatte(kode, nama, harga, ukuran, jenisBiji, asalBiji, kafein, susu, busa, shot);
        daftarKopiLatte.add(latteBaru);
        System.out.println("!! Homre. Kopi Latte berhasil ditambah yah !!");
    }
}