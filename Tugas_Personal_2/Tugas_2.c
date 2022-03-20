#include <stdio.h>
#include <string.h>

//Struktur data inputan biodata mahasiswa
struct mhs {
   char  nim[11];
   char  nama[50];
   char jurusan[50];
   float gpa;
};

//Struktur data inputan nilai mahasiswa
struct nilai {
	int nilaiHadir;
	int nilaiTugas;
	int nilaiQuiz;
	int nilaiForum;
	int nilaiUas;
};


int main () {
   struct mhs info; 
   struct nilai data;
   char Menu1, Menu2, Menu3, Menu4;
   float wgpa;
   
   
	printf("Plih menu di bawah ini \n Menu 1\n Menu 2\n"); scanf("[^\n]", Menu1);
   if (Menu1 = '1') {
      printf("Masukan Nim anda = "); scanf("%[^\n]", &info.nim);
      fflush(stdin);
      printf("Masukan Nama anda = "); scanf("%[^\n]", &info.nama);
      printf("Masukan GPA anda = "); scanf("%f", &wgpa);
	  info.gpa = wgpa;
	  fflush(stdin);  
      printf("Masukan jurusan anda = "); scanf("%[^\n]", &info.jurusan);
   }  
   
   	printf("Tampilkan Nim = %s\n", info.nim);
    printf("Tampilkan Nama = %s\n", info.nama);
    printf("Tampilkan GPA =  %.2f\n", info.gpa);
    printf("Tampilkan jurusan = %s\n", info.jurusan);
   
   return 0;
}
