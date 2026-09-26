# ⡞⠳⣄⣀⣠⠞⢷ ֹ۪
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
