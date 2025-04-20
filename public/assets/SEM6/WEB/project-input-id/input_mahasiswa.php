<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <title>Form Input Mahasiswa Baru</title>
</head>

<body>
  <h2>Form Pendaftaran Mahasiswa Baru</h2>
  <form action="proses_input.php" method="post">
    NIK: <input type="text" name="nik" required maxlength="16"><br><br>
    Nama: <input type="text" name="nama" required><br><br>
    Alamat: <textarea name="alamat" required></textarea><br><br>
    Tanggal Lahir: <input type="date" name="tanggal_lahir" required><br><br>
    Email: <input type="email" name="email" required><br><br>
    <input type="submit" value="Daftar">
  </form>
</body>

</html>