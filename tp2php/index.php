<?php
require_once "KopiLatte.php";
require_once "BobaMilkTea.php";
session_start();

$pesan = "";

// Buat folder foto_produk jika belum ada
if (!is_dir(__DIR__ . '/foto_produk')) {
    mkdir(__DIR__ . '/foto_produk', 0777, true);
}

// Inisialisasi data dummy awal ke session
if (!isset($_SESSION['daftar_minuman'])) {
    $_SESSION['daftar_minuman'] = [
        new KopiLatte("L001", "Caramel Macchiato", 35000, "M", "Arabika", "Gayo", "Sedang", "Full Cream", "Tebal", "Ya", "foto_produk/Caramel Macchiato"),
        new KopiLatte("L002", "Oat Vanilla Latte", 40000, "L", "Arabika", "Kintamani", "Rendah", "Oat", "Sedang", "Tidak", "foto_produk/Oat Vanilla Latte"),
        new KopiLatte("L003", "Double Shot Latte", 38000, "S", "Robusta", "Toraja", "Tinggi", "Full Cream", "Tipis", "Ya", "foto_produk/Double Shot Latte"),
        new BobaMilkTea("B001", "Brown Sugar Boba", 30000, "L", "Black Tea", "Assam", "100%", "Boba", "Normal", "Fresh Milk", "foto_produk/Brown Sugar Boba"),
        new BobaMilkTea("B002", "Jasmine Milk Tea", 25000, "M", "Jasmine", "Ciwidey", "50%", "Pudding", "Less Ice", "Condensed", "foto_produk/Jasmine Milk Tea")
    ];
}

// Helper Pencari Foto Otomatis (Mendukung .jpg, .jpeg, .png, .webp)
function dapatkanPathFoto($path_sistem): string {
    if (empty($path_sistem)) return "";
    
    $full_path = __DIR__ . "/" . $path_sistem;
    
    // Jika path file langsung ketemu
    if (file_exists($full_path) && !is_dir($full_path)) {
        return $path_sistem;
    }
    
    // Coba tambahkan ekstensi umum secara otomatis
    $ekstensi = ['.jpg', '.jpeg', '.png', '.webp', '.JPG', '.PNG'];
    foreach ($ekstensi as $ext) {
        if (file_exists($full_path . $ext)) {
            return $path_sistem . $ext;
        }
    }
    
    return "";
}

// Helper Upload Foto
function uploadFoto(): string {
    if (isset($_FILES['foto_produk']) && $_FILES['foto_produk']['error'] === UPLOAD_ERR_OK) {
        $nama_file = time() . "_" . basename($_FILES['foto_produk']['name']);
        $target_file = __DIR__ . "/foto_produk/" . $nama_file;
        if (move_uploaded_file($_FILES['foto_produk']['tmp_name'], $target_file)) {
            return "foto_produk/" . $nama_file;
        }
    }
    return "";
}

// Handler Tambah Data
if (isset($_POST['aksi']) && $_POST['aksi'] === 'add') {
    $kode = strtoupper(trim($_POST['kode']));
    $kategori = $_POST['kategori'];

    foreach ($_SESSION['daftar_minuman'] as $item) {
        if ($item->getKode() === $kode) {
            $pesan = "Error: Kode minuman sudah terdaftar mas!";
            break;
        }
    }

    if (empty($pesan) && !is_numeric($_POST['harga'])) {
        $pesan = "Error: Harganya angka mas";
    }

    if (empty($pesan)) {
        $path_foto = uploadFoto();

        if ($kategori === 'latte') {
            $_SESSION['daftar_minuman'][] = new KopiLatte(
                $kode, trim($_POST['nama']), (int)$_POST['harga'], strtoupper(trim($_POST['ukuran'])),
                trim($_POST['jenis_biji']), trim($_POST['asal_biji']), trim($_POST['kafein']),
                trim($_POST['susu']), trim($_POST['busa']), trim($_POST['shot']), $path_foto
            );
        } else {
            $_SESSION['daftar_minuman'][] = new BobaMilkTea(
                $kode, trim($_POST['nama']), (int)$_POST['harga'], strtoupper(trim($_POST['ukuran'])),
                trim($_POST['jenis_teh']), trim($_POST['asal_teh']), trim($_POST['manis']),
                trim($_POST['topping']), trim($_POST['ice']), trim($_POST['susu_teh']), $path_foto
            );
        }
        $pesan = "!! Homre. Minuman berhasil ditambah yah !!";
    }
}

$hasil_tampil = $_SESSION['daftar_minuman'];
?>

<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <title>Sistem Manajemen Minuman</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 20px; }
        table { border-collapse: collapse; width: 100%; margin-top: 15px; font-size: 13px; }
        th, td { border: 1px solid #999; padding: 6px; text-align: left; }
        th { background-color: #f2f2f2; }
        img { width: 60px; height: auto; display: block; border-radius: 4px; }
        .section { margin-bottom: 20px; padding: 15px; border: 1px solid #ddd; }
        .alert { padding: 10px; background-color: #eef; border-left: 4px solid #33a; margin-bottom: 15px; }
        input[type="text"], input[type="number"], select { padding: 5px; margin-right: 5px; margin-bottom: 5px; }
    </style>
</head>
<body>

    <h2>Daftar Menu Minuman (Kopi & Tea)</h2>

    <?php if (!empty($pesan)): ?>
        <div class="alert"><strong>Pemberitahuan:</strong> <?= htmlspecialchars($pesan) ?></div>
    <?php endif; ?>

    <!-- Tabel Output -->
    <div class="section">
        <h3>Daftar Minuman</h3>
        <?php if (empty($hasil_tampil)): ?>
            <p>Data minuman kosong.</p>
        <?php else: ?>
            <table>
                <thead>
                    <tr>
                        <th>Foto</th>
                        <th>Kode</th>
                        <th>Nama</th>
                        <th>Harga</th>
                        <th>Size</th>
                        <th>Kategori</th>
                        <th>Biji Kopi (Asal)</th>
                        <th>Kafein</th>
                        <th>Daun Teh (Asal)</th>
                        <th>Manis</th>
                        <th>Jenis Susu</th>
                        <th>Busa Susu</th>
                        <th>Ex Shot</th>
                        <th>Topping</th>
                        <th>Ice</th>
                    </tr>
                </thead>
                <tbody>
                    <?php foreach ($hasil_tampil as $item): ?>
                        <tr>
                            <td>
                                <?php 
                                $foto_valid = dapatkanPathFoto($item->getFotoProduk());
                                if (!empty($foto_valid)): 
                                ?>
                                    <img src="<?= htmlspecialchars($foto_valid) ?>" alt="Foto">
                                <?php else: ?>
                                    <em>No Foto</em>
                                <?php endif; ?>
                            </td>
                            <td><?= htmlspecialchars($item->getKode()) ?></td>
                            <td><?= htmlspecialchars($item->getNamaMinuman()) ?></td>
                            <td>Rp<?= number_format($item->getHarga(), 0, ',', '.') ?></td>
                            <td><?= htmlspecialchars($item->getUkuran()) ?></td>
                            <td><?= ($item instanceof KopiLatte) ? 'Kopi Latte' : 'Boba Milk Tea' ?></td>
                            <td><?= ($item instanceof KopiLatte) ? htmlspecialchars($item->getJenisBijiKopi() . ' (' . $item->getAsalBijiKopi() . ')') : '-' ?></td>
                            <td><?= ($item instanceof KopiLatte) ? htmlspecialchars($item->getKadarKafein()) : '-' ?></td>
                            <td><?= ($item instanceof BobaMilkTea) ? htmlspecialchars($item->getJenisDaunTeh() . ' (' . $item->getAsalDaunTeh() . ')') : '-' ?></td>
                            <td><?= ($item instanceof BobaMilkTea) ? htmlspecialchars($item->getTingkatKemanisan()) : '-' ?></td>
                            <td><?= htmlspecialchars($item->getJenisSusu()) ?></td>
                            <td><?= ($item instanceof KopiLatte) ? htmlspecialchars($item->getBusaSusu()) : '-' ?></td>
                            <td><?= ($item instanceof KopiLatte) ? htmlspecialchars($item->getEkstraShot()) : '-' ?></td>
                            <td><?= ($item instanceof BobaMilkTea) ? htmlspecialchars($item->getTopping()) : '-' ?></td>
                            <td><?= ($item instanceof BobaMilkTea) ? htmlspecialchars($item->getIceLevel()) : '-' ?></td>
                        </tr>
                    <?php endforeach; ?>
                </tbody>
            </table>
        <?php endif; ?>
    </div>

    <!-- Add Kopi Latte -->
    <div class="section">
        <h3>--- Tambah Kopi Latte ---</h3>
        <form method="POST" enctype="multipart/form-data">
            <input type="hidden" name="aksi" value="add">
            <input type="hidden" name="kategori" value="latte">
            <input type="text" name="kode" placeholder="Kode (ex: L004)" required>
            <input type="text" name="nama" placeholder="Nama Minuman" required>
            <input type="number" name="harga" placeholder="Harga" required>
            <input type="text" name="ukuran" placeholder="Ukuran (S/M/L)" required>
            <input type="text" name="jenis_biji" placeholder="Jenis Biji Kopi" required>
            <input type="text" name="asal_biji" placeholder="Asal Biji" required>
            <input type="text" name="kafein" placeholder="Kadar Kafein" required>
            <input type="text" name="susu" placeholder="Jenis Susu" required>
            <input type="text" name="busa" placeholder="Busa Susu" required>
            <input type="text" name="shot" placeholder="Ekstra Shot (Ya/Tidak)" required>
            <br>
            <label>Foto Produk: <input type="file" name="foto_produk" accept="image/*"></label>
            <br><br>
            <button type="submit">Tambah Kopi Latte</button>
        </form>
    </div>

    <!-- Add Boba Milk Tea -->
    <div class="section">
        <h3>--- Tambah Boba Milk Tea ---</h3>
        <form method="POST" enctype="multipart/form-data">
            <input type="hidden" name="aksi" value="add">
            <input type="hidden" name="kategori" value="boba">
            <input type="text" name="kode" placeholder="Kode (ex: B003)" required>
            <input type="text" name="nama" placeholder="Nama Minuman" required>
            <input type="number" name="harga" placeholder="Harga" required>
            <input type="text" name="ukuran" placeholder="Ukuran (S/M/L)" required>
            <input type="text" name="jenis_teh" placeholder="Jenis Daun Teh" required>
            <input type="text" name="asal_teh" placeholder="Asal Daun Teh" required>
            <input type="text" name="manis" placeholder="Tingkat Kemanisan" required>
            <input type="text" name="topping" placeholder="Topping" required>
            <input type="text" name="ice" placeholder="Ice Level" required>
            <input type="text" name="susu_teh" placeholder="Jenis Susu" required>
            <br>
            <label>Foto Produk: <input type="file" name="foto_produk" accept="image/*"></label>
            <br><br>
            <button type="submit">Tambah Boba Milk Tea</button>
        </form>
    </div>

</body>
</html>