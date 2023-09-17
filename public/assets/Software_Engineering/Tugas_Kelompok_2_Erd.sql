-- Tabel untuk informasi Mahasiswa
CREATE TABLE Mahasiswa (
    MahasiswaID INT PRIMARY KEY,
    Nama VARCHAR(255),
    NIM VARCHAR(20) UNIQUE,
    Email VARCHAR(255),
    Password VARCHAR(255)
);

-- Tabel untuk informasi Mata Kuliah
CREATE TABLE MataKuliah (
    MataKuliahID INT PRIMARY KEY,
    NamaMataKuliah VARCHAR(255),
    Deskripsi TEXT
);

-- Tabel untuk informasi Kelas Mata Kuliah
CREATE TABLE KelasMataKuliah (
    KelasID INT PRIMARY KEY,
    MataKuliahID INT,
    NamaKelas VARCHAR(255),
    Semester INT,
    Tahun INT,
    FOREIGN KEY (MataKuliahID) REFERENCES MataKuliah(MataKuliahID)
);

-- Tabel untuk informasi Tugas
CREATE TABLE Tugas (
    TugasID INT PRIMARY KEY,
    KelasID INT,
    NamaTugas VARCHAR(255),
    Deadline DATE,
    FOREIGN KEY (KelasID) REFERENCES KelasMataKuliah(KelasID)
);

-- Tabel untuk informasi Jawaban Tugas
CREATE TABLE JawabanTugas (
    JawabanID INT PRIMARY KEY,
    TugasID INT,
    MahasiswaID INT,
    IsiJawaban TEXT,
    FOREIGN KEY (TugasID) REFERENCES Tugas(TugasID),
    FOREIGN KEY (MahasiswaID) REFERENCES Mahasiswa(MahasiswaID)
);

-- Tabel untuk informasi Forum Diskusi
CREATE TABLE ForumDiskusi (
    ForumID INT PRIMARY KEY,
    KelasID INT,
    NamaForum VARCHAR(255),
    FOREIGN KEY (KelasID) REFERENCES KelasMataKuliah(KelasID)
);

-- Tabel untuk informasi Pesan dalam Forum Diskusi
CREATE TABLE PesanForum (
    PesanID INT PRIMARY KEY,
    ForumID INT,
    PengirimID INT,
    IsiPesan TEXT,
    TanggalPesan DATETIME,
    FOREIGN KEY (ForumID) REFERENCES ForumDiskusi(ForumID),
    FOREIGN KEY (PengirimID) REFERENCES Mahasiswa(MahasiswaID)
);

-- Tabel untuk informasi Pembayaran Biaya Kuliah
CREATE TABLE Pembayaran (
    PembayaranID INT PRIMARY KEY,
    MahasiswaID INT,
    JumlahBiaya DECIMAL(10, 2),
    TanggalPembayaran DATE,
    FOREIGN KEY (MahasiswaID) REFERENCES Mahasiswa(MahasiswaID)
);

-- Tabel untuk informasi Penilaian
CREATE TABLE Penilaian (
    PenilaianID INT PRIMARY KEY,
    TugasID INT,
    MahasiswaID INT,
    Nilai DECIMAL(5, 2),
    FOREIGN KEY (TugasID) REFERENCES Tugas(TugasID),
    FOREIGN KEY (MahasiswaID) REFERENCES Mahasiswa(MahasiswaID)
);

-- Tabel untuk informasi Administrator
CREATE TABLE Administrator (
    AdminID INT PRIMARY KEY,
    Nama VARCHAR(255),
    Email VARCHAR(255),
    Password VARCHAR(255)
);

-- Tabel untuk informasi Dosen (Lecturer)
CREATE TABLE Dosen (
    DosenID INT PRIMARY KEY,
    Nama VARCHAR(255),
    Email VARCHAR(255),
    Password VARCHAR(255)
);

-- Tabel untuk menghubungkan Dosen dengan Mata Kuliah yang diajar
CREATE TABLE DosenMengajar (
    DosenID INT,
    MataKuliahID INT,
    FOREIGN KEY (DosenID) REFERENCES Dosen(DosenID),
    FOREIGN KEY (MataKuliahID) REFERENCES MataKuliah(MataKuliahID)
);

-- Tabel untuk informasi Webinar
CREATE TABLE Webinar (
    WebinarID INT PRIMARY KEY,
    KelasID INT,
    NamaWebinar VARCHAR(255),
    TanggalWebinar DATETIME,
    FOREIGN KEY (KelasID) REFERENCES KelasMataKuliah(KelasID)
);

-- Tabel untuk informasi Quiz
CREATE TABLE Quiz (
    QuizID INT PRIMARY KEY,
    KelasID INT,
    NamaQuiz VARCHAR(255),
    TanggalQuiz DATE,
    FOREIGN KEY (KelasID) REFERENCES KelasMataKuliah(KelasID)
);

-- Tabel untuk menghubungkan Mahasiswa dengan Kelas Mata Kuliah yang diikuti
CREATE TABLE MahasiswaKelas (
    MahasiswaID INT,
    KelasID INT,
    FOREIGN KEY (MahasiswaID) REFERENCES Mahasiswa(MahasiswaID),
    FOREIGN KEY (KelasID) REFERENCES KelasMataKuliah(KelasID)
);

-- Tabel untuk menghubungkan Administrator dengan Kelas Mata Kuliah yang dielola
CREATE TABLE AdminKelolaKelas (
    AdminID INT,
    KelasID INT,
    FOREIGN KEY (AdminID) REFERENCES Administrator(AdminID),
    FOREIGN KEY (KelasID) REFERENCES KelasMataKuliah(KelasID)
);

-- Tabel untuk menyimpan notifikasi
CREATE TABLE Notifikasi (
    NotifikasiID INT PRIMARY KEY,
    PenerimaID INT,
    IsiNotifikasi TEXT,
    TanggalNotifikasi DATETIME,
    FOREIGN KEY (PenerimaID) REFERENCES Mahasiswa(MahasiswaID)
);
