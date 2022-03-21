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
   char Menu1[10];
   char szKey1[] = "Menu 1";
   char szInput1[80];
   float wgpa;
   int nilaiHadir, nilaiTugas, nilaiForum, nilaiQuiz, nilaiUas;
   
	printf("Plih menu di bawah ini \n\n Menu 1 untuk menginput biodata\n Menu 2 untuk menginput nilai\n Menu 3 untuk melihat nilai mahasiswa dan status\n Menu 4 untuk keluar dari program\n\n"); 
	scanf("%[^\n]", &Menu1);
	
   if ( strcmp(Menu1, "Menu 1") == 0) {
   		fflush(stdin);	
	    printf("Masukan Nim Anda = "); scanf("%[^\n]", &info.nim);
	    fflush(stdin);
	    printf("Masukan Nama Anda = "); scanf("%[^\n]", &info.nama);
	    printf("Masukan GPA Anda = "); scanf("%f", &wgpa);
		info.gpa = wgpa;
		fflush(stdin);  
	    printf("Masukan Jurusan Anda = "); scanf("%[^\n]", &info.jurusan);
    } else if( strcmp(Menu1, "Menu 2") == 0 ) {
		printf("Masukan Hilai Hadir Anda = "); scanf("%d", &data.nilaiHadir);
		nilaiHadir = (data.nilaiHadir * 0.1);
		printf("Masukan Nilai Tugas Anda = "); scanf("%d", &data.nilaiTugas);
		nilaiTugas = (data.nilaiTugas * 0.2);
		printf("Masukan Nilai Quiz Anda = "); scanf("%d", &data.nilaiQuiz);
		nilaiQuiz = (data.nilaiQuiz * 0.1);
		printf("Masukan Nilai Keaktifan Forum Anda = "); scanf("%d", &data.nilaiForum); 	
		nilaiForum = (data.nilaiForum * 0.1);
		printf("Masukan Nilai Uas Anda = "); scanf("%d", &data.nilaiUas);
		nilaiUas = (data.nilaiUas * 0.5);
	} else if( strcmp(Menu1, "Menu 3") == 0)  {
		fflush(stdin);
		printf("Masukan NIM anda untuk melihat kalkulasi nilai = "); scanf("%[^\n]", &info.nim);
		if(info.nim == info.nim) {
			printf("Hasil kalkulasi = \n\n");
			printf("%d", (nilaiHadir + nilaiTugas + nilaiForum + nilaiQuiz + nilaiUas));
		}
	} else if( strcmp(Menu1, "Menu 4") == 0 ) {
		printf("Anda sudah keluar dari program. Terima Kasih sudah menggunakan program saya, Semoga membantu");
		return 0;	
	} else {
		printf("Mohon masukan menu dengan benar hanya terdiri dari (Menu 1, Menu 2, Menu 3 dan Menu 4).");
	}
   
   return 0;
}
