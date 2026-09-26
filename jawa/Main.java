import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    // fungsi buat nampilin tabel gabungan dari semua data kelas
    public static void displayTabelSemuaData() {
        ArrayList<String[]> semuaData = new ArrayList<>();

        // tarik data latte
        for (KopiLatte k : KopiLatte.daftarKopiLatte) {
            semuaData.add(new String[]{
                k.getKode(), k.getNamaMinuman(), "Rp" + k.getHarga(), k.getUkuran(),
                "Kopi Latte", k.getJenisBijiKopi() + " (" + k.getAsalBijiKopi() + ")", k.getKadarKafein(),
                "-", "-", k.getJenisSusu(), k.getBusaSusu(), k.getEkstraShot(), "-", "-"
            });
        }

        // tarik data boba
        for (BobaMilkTea b : BobaMilkTea.daftarBoba) {
            semuaData.add(new String[]{
                b.getKode(), b.getNamaMinuman(), "Rp" + b.getHarga(), b.getUkuran(),
                "Boba Milk Tea", "-", "-",
                b.getJenisDaunTeh() + " (" + b.getAsalDaunTeh() + ")", b.getTingkatKemanisan(),
                b.getJenisSusu(), "-", "-", b.getTopping(), b.getIceLevel()
            });
        }

        if (semuaData.isEmpty()) {
            System.out.println("\nData minuman masih kosong mas.");
            return;
        }

        String[] headers = {
            "Kode", "Nama Minuman", "Harga", "Size", "Kategori", 
            "Biji Kopi (Asal)", "Kafein", "Daun Teh (Asal)", "Manis", 
            "Jenis Susu", "Busa Susu", "Ex Shot", "Topping", "Ice"
        };

        // hitung lebar kolom dinamis
        int[] colWidths = new int[headers.length];
        for (int i = 0; i < headers.length; i++) {
            colWidths[i] = headers[i].length();
        }

        for (String[] row : semuaData) {
            for (int i = 0; i < row.length; i++) {
                colWidths[i] = Math.max(colWidths[i], row[i].length());
            }
        }

        // pembatas garis tabel
        StringBuilder border = new StringBuilder("+");
        for (int w : colWidths) {
            border.append("-".repeat(w + 2)).append("+");
        }

        System.out.println("\n" + border);

        // print header
        System.out.print("| ");
        for (int i = 0; i < headers.length; i++) {
            System.out.printf("%-" + colWidths[i] + "s | ", headers[i]);
        }
        System.out.println("\n" + border);

        // print isi data
        for (String[] row : semuaData) {
            System.out.print("| ");
            for (int i = 0; i < row.length; i++) {
                System.out.printf("%-" + colWidths[i] + "s | ", row[i]);
            }
            System.out.println();
        }

        System.out.println(border + "\n");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // data dummy 5 biji diawal
        // 3 latte
        KopiLatte.daftarKopiLatte.add(
            new KopiLatte("L001", "Caramel Macchiato", 35000, "M", "Arabika", "Gayo", "Sedang", "Full Cream", "Tebal", "Ya")
        );
        KopiLatte.daftarKopiLatte.add(
            new KopiLatte("L002", "Oat Vanilla Latte", 40000, "L", "Arabika", "Kintamani", "Rendah", "Oat", "Sedang", "Tidak")
        );
        KopiLatte.daftarKopiLatte.add(
            new KopiLatte("L003", "Double Shot Latte", 38000, "S", "Robusta", "Toraja", "Tinggi", "Full Cream", "Tipis", "Ya")
        );

        // 2 boba
        BobaMilkTea.daftarBoba.add(
            new BobaMilkTea("B001", "Brown Sugar Boba", 30000, "L", "Black Tea", "Assam", "100%", "Boba", "Normal", "Fresh Milk")
        );
        BobaMilkTea.daftarBoba.add(
            new BobaMilkTea("B002", "Jasmine Milk Tea", 25000, "M", "Jasmine", "Ciwidey", "50%", "Pudding", "Less Ice", "Condensed")
        );

        // menu pilihan
        System.out.println("pilih aja ini menu masih template tp 1 : ");
        while (true) {
            System.out.println("1. Show");
            System.out.println("2. Add Latte");
            System.out.println("3. Add Boba");
            System.out.println("ketik 'malas' untuk keluar program");
            System.out.println("---------------------------------------");
            System.out.print("Select: ");

            if (!scanner.hasNextLine()) break;
            String select = scanner.nextLine().toLowerCase().trim();

            switch (select) {
                case "malas":
                    System.out.println("oke dadah");
                    scanner.close();
                    return;
                case "show":
                case "1":
                    displayTabelSemuaData();
                    break;
                case "add latte":
                case "2":
                    KopiLatte.addLatte(scanner);
                    System.out.println("---------------------------------------\n");
                    break;
                case "add boba":
                case "3":
                    BobaMilkTea.addBoba(scanner);
                    System.out.println("---------------------------------------\n");
                    break;
                default:
                    System.out.println("kamu goy, itu pilihan apa\n");
                    break;
            }
        }
    }
}