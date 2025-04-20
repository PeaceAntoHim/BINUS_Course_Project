<?php
include 'koneksi.php';

// Mendapatkan data dari form
$nik = $_POST['nik'];
$nama = $_POST['nama'];
$alamat = $_POST['alamat'];
$tanggal_lahir = $_POST['tanggal_lahir'];
$email = $_POST['email'];

// Validasi NIK harus 16 digit
if (!preg_match("/^[0-9]{16}$/", $nik)) {
    die("NIK harus 16 digit.");
}

// Validasi nama hanya boleh huruf dan spasi
if (!preg_match("/^[a-zA-Z ]+$/", $nama)) {
    die("Nama hanya boleh berisi huruf dan spasi.");
}

// Validasi email dengan filter bawaan PHP
if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
    die("Format email tidak valid.");
}

// Menyimpan data ke database
$sql = "INSERT INTO mahasiswa (nik, nama, alamat, tanggal_lahir, email) VALUES ('$nik', '$nama', '$alamat', '$tanggal_lahir', '$email')";
if ($conn->query($sql) === TRUE) {
    echo "Pendaftaran berhasil!";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>
