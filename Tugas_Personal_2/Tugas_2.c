#include <stdio.h>
#include <string.h>

//Struktur data inputan biodata mahasiswa
struct mhs {
   char  nim[11];
   char  nama[50];
   float gpa;
   char mataKuliah[50];
};

//Struktur data inputan nilai mahasiswa
struct nilai {
	int nilaiHadir;
	int nilaiTugas;
	int nilaiQuiz;
	int nilaiForum;
	int nilaiUas;
};

struct menu {
	char Menu1;
	char Menu2;
	char Menu3;
	char Menu4;
};

int main () {
   struct mhs info; 
   struct nilai data;
   struct menu option;
   float wgpa;
   
   
	printf("Plih menu di bawah ini \n Menu 1\n Menu 2\n"); scanf("[^\n]", &option.Menu1);
   if (&option.Menu1 == 1) {
      printf("Masukan Nim anda = "); scanf("%s", &info.nim);
      fflush(stdin);
      printf("Masukan Nama anda = "); scanf("[^\n]", &info.nama);
      printf("Masukan GPA anda = "); scanf("%f", &wgpa);
      info.gpa = wgpa;
      printf("Masukan Mata Kuliah anda = "); scanf("[^\n]", &info.mataKuliah);
   } else if() {
   	
   } else if(&option.Menu3 == 3) {
   	  printf("Tampilkan Nim = %s\n", info.nim);
      printf("Tampilkan Nama = %s\n", info.nama);
      printf("Tampilkan GPA =  %.2f\n", info.gpa);
      printf("Tampilkan mata kuliah = %s\n", info.mataKuliah);
   }   
   
   return 0;
}
