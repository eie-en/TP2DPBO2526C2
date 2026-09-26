import java.util.ArrayList;
import java.util.Scanner;

public class BobaMilkTea extends MinumanTeh {
    public static ArrayList<BobaMilkTea> daftarBoba = new ArrayList<>(); // array boba

    private String topping;
    private String iceLevel;
    private String jenisSusu;

    public BobaMilkTea(String kode, String namaMinuman, int harga, String ukuran, String jenisDaunTeh, String asalDaunTeh, String tingkatKemanisan, String topping, String iceLevel, String jenisSusu) {
        super(kode, namaMinuman, harga, ukuran, jenisDaunTeh, asalDaunTeh, tingkatKemanisan);
        this.topping = topping;
        this.iceLevel = iceLevel;
        this.jenisSusu = jenisSusu;
    }

    public String getTopping() {
        return this.topping;
    }

    public String getIceLevel() {
        return this.iceLevel;
    }

    public String getJenisSusu() {
        return this.jenisSusu;
    }

    public void setTopping(String topping) {
        this.topping = topping;
    }

    public void setIceLevel(String iceLevel) {
        this.iceLevel = iceLevel;
    }

    public void setJenisSusu(String jenisSusu) {
        this.jenisSusu = jenisSusu;
    }

    // tambah boba
    public static void addBoba(Scanner scanner) {
        System.out.println("\n--- Tambah Menu Boba Milk Tea ---");
        System.out.print("Masukkan Kode (ex: B001): ");
        String kode = scanner.nextLine().trim().toUpperCase();

        for (BobaMilkTea boba : daftarBoba) {
            if (boba.getKode().equals(kode)) {
                System.out.println("Error: Kode boba udah terdaftar mas!");
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
            System.out.println("Error: Harganya angka mas");
            return;
        }

        System.out.print("Masukkan Ukuran (S/M/L): ");
        String ukuran = scanner.nextLine().trim().toUpperCase();

        System.out.print("Jenis Daun Teh (Black Tea/Jasmine/Earl Grey): ");
        String jenisTeh = scanner.nextLine().trim();

        System.out.print("Asal Daun Teh (ex: Ciwidey/Assam): ");
        String asalTeh = scanner.nextLine().trim();

        System.out.print("Tingkat Kemanisan (0%/50%/100%): ");
        String manis = scanner.nextLine().trim();

        System.out.print("Topping (Boba/Pudding/Grass Jelly): ");
        String topping = scanner.nextLine().trim();

        System.out.print("Ice Level (No Ice/Less Ice/Normal): ");
        String ice = scanner.nextLine().trim();

        System.out.print("Jenis Susu (Full Cream/Condensed/Fresh): ");
        String susu = scanner.nextLine().trim();

        BobaMilkTea bobaBaru = new BobaMilkTea(kode, nama, harga, ukuran, jenisTeh, asalTeh, manis, topping, ice, susu);
        daftarBoba.add(bobaBaru);
        System.out.println("!! Homre. Boba Milk Tea berhasil ditambah yah !!");
    }
}