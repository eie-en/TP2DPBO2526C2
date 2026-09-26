# ⡞⠳⣄⣀⣠⠞⢷ ֹ۪
<p align="center">
  <✦•┈๑⋅⋯ ⋯⋅๑┈•✦>
</p>
    
Saya Aghni Lutvia Sari dengan NIM 2508921 mengerjakan TP2
dalam mata kuliah DPBO untuk keberkahanNya maka saya
tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin

## .✦ ݁˖ Penjelasan Design 
Jadi di sini, aku buat design multilevel inheritance dengan temanya Produk Minuman
<p align="center">
  <img width="319" height="278" alt="image" src="https://github.com/user-attachments/assets/1ea523d0-4d59-457a-8aec-47cc81c4732f" />
</p>

1. ProdukMinuman sebagai Grandparent nya, merupakan kelas dengan tingkat paling atas. Adapun atribut yang digunakan :
   - **Kode**. berfungsi sebagai primary key yang membedakan satu produk dengan lainnnya. Dengan keteranan L berarti Latte dan B berarti boba
   - **NamaMinuman**. atribut nama yang bisa dipakai oleh semua kelas keturunan dari ProdukMinuman
   - **Harga**. yaa harga, u beli minuman u beri uang. Ada harga ada barang
   - **Ukuran**. tersedia ukuran small, medium dan Large.
    
2. MinumanKopi sebagai Parent, kelas tingkat 2. Menggunakan atribut yang lebih spesifik sebagai berikut :
   - **JenisBijiKopi**. Jenis biji kopi yang digunakan pada minuman
   - **AsalBijiKopi**. Biji kopinya asal daerahnya darimanaaaaa
   - **KadarKafein**. kadar kafeinnya rendah/tinggi/sedang, kamu tidak mau kan kalo kastemer tiba tiba kejang karna ga tahan kafein jadi dikasih pilihan.
     
3. KopiLatte sebagai anak dari MinumanKopi/cucu dari ProdukMinuman. Karena dia sebuah produk minuman dan berbahan kopi. Atributnya tentu lebih dipersempit lagi :
   - **JenisSusu**. Latte pake susu, jenis susunya apa oat, atau sapi, atau kambing, atauataauauauaua
   - **BusaSusu**. Ini lebih ke foam tickness, apakah dia tebal, sedang, tipis.
   - **EkstraShot**. Kopinya ekstra shot yes or no. Another kastemer kejang kejang no no

4. MinumanTeh sebagai Parent, kelas tingkat 2. Tidak semua orang suka kopi, jadi kita sediakan teh dengan atribut tentang teh :
   - **JenisDaunTeh**. Jenis daun teh nya apa, melati kah atau apapa oolong gitu
   - **AsalDaunTeh**. Asal daerah daun tehnya
   - **TingkatKemanisan**. Tingkat kemanisan dengan %, paling rendah 0%(tawar) 100% paling manis rek.

5. BobaMilkTea anaknya MinumanTeh. Yaaa atributnya tentu khusus varian boba milk tea hoyeaahhhh
   - **Topping**. Bisa aja kalo mau nambah topping kayak grass jelly whatsoever ataupun ekstra boba wow
   - **IceLevel**. Less ice, full ice apapun itu intinya selera banyak es nya
   - **JenisSusu**. Jenis susunya gajauh beda sama yang kopi, full cream kah, oat kah lalayeyee

## .✦ ݁˖ Method
Berikut adalah penjelasan lengkap mengenai *methods* yang dibuat pada program C++ bertema **Multilevel & Hierarchical Inheritance** produk minuman:

1. **Getter & Setter**.
   Ada di setiap kelas. Karna tiap atributnya private, dibutuhin getter untuk mendapatkan nilai dari atribut dan membutuhkan setter untuk write dari atribut yang ada.

2. **addLatte() di KopiLatte**.
   bisa dipanggil langsung tanpa menginstansiasi objek baru terlebih dahulu. Fungsinya menerima input data dari user untuk nambah objek di kopilatte

3. **addBoba() di BobaMilkTea**.
   Sama kayak addlatte, tapi ini khusus milk tea yeah

4. **displayTabelSemuaData()**.
   Fungsinya buat nampilin semua objek dari kopi sama teh jadi satu tabel dinamis nyeaaa

5. **main**.
   Nambah 5 objek dummy pas awal ke dalam masing masing kelas. Menampilkan menu 1.show/2.add boba/3.add kopi yang akan loop sampe ada input 'malas'.

## .✦ ݁˖ Alur Kode
1. Inisialisasi Program & Alokasi Data Awal
   yang awal banget tentu manggil library sama kelas kelas yang tadi udah dibuat. Lalu kita inisialisasi data dummy yang 5

2. Menu Interaktif & Pembacaan Input
   - Tampilin teks awal(header) dulu, habistu masuk infinite loop. Loop cuma berenti kalo ada input 'malas'
   - Print menuuu show, add boba, add kopi, atau malas (keluar)

3. Eksekusi Berdasarkan Pilihan User
   - Opsi Show
     Program manggil fungsi display untuk show semua objek yang ada di dalem tabel dinamis hoyeah. Data objeknya ni diambil dari KopiLatte dan BobaMilktea pake getter dari kelas king, atributnya tuh diambil dari atas banget tuh dari grandparentnya jadi satu. Diitung maksimal panjang masing masing isi atributnya, cetak header cetak garis tabelnya, lalu isinya.
   - Opsi Add Latte/Milk Tea
     Manggil fungsi AddLatte/AddBoba. Setelah ada input untuk kode, dicocokin dulu tuh ada kembar apa ngganya. Setelah itu user diminta lengkapin atribut lainnya. Harga bentuknya harus integer ya, atau ga dapat pesan cinta. Udah begitu, data yang baru bisa dipush ke array latte/boba yang adaaaa.
   - Opsi Malas
     Ada keluar pesan "oke dadah". Menghentikan while loop yang ada, dan dadaaahh programnya selesai

<p align="center">
  <✦•┈๑⋅⋯ ⋯⋅๑┈•✦>
</p>
