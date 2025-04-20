<?php
$servername = "localhost";
$username = "root"; // ganti dengan username database
$password = "@Password123"; // ganti dengan password database
$dbname = "binus-wp"; // nama database

// Membuat koneksi
$conn = new mysqli($servername, $username, $password, $dbname);

// Memeriksa koneksi
if ($conn->connect_error) {
  die("Koneksi gagal: " . $conn->connect_error);
}
