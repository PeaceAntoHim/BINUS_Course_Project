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
   char Menu[50];
   int menu = 0;
   char szKey1[] = "Menu 1";
   char szInput1[80];
   float wgpa;
   int nilaiHadir, nilaiTugas, nilaiForum, nilaiQuiz, nilaiUas;
   
	printf("Plih menu di bawah ini \n\n Menu 1 untuk menginput biodata\n Menu 2 untuk menginput nilai\n Menu 3 untuk melihat nilai mahasiswa dan status\n Menu 4 untuk keluar dari program\n\n"); 
	scanf("%[^\n]", &Menu);

		switch(menu) {
		    case '1' :
		    {
		    fflush(stdin);	
		    printf("Masukan Nim Anda = "); scanf("%[^\n]", &info.nim);
		    fflush(stdin);
		    printf("Masukan Nama Anda = "); scanf("%[^\n]", &info.nama);
		    printf("Masukan GPA Anda = "); scanf("%f", &wgpa);
			info.gpa = wgpa;
			fflush(stdin);  
		    printf("Masukan Jurusan Anda = "); scanf("%[^\n]", &info.jurusan);
		    }
		    case '2' :
		    {
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
		    }
		    case '3':
		    {
		    fflush(stdin);
			printf("Masukan NIM anda untuk melihat kalkulasi nilai = "); scanf("%[^\n]", &info.nim);
    			if(info.nim == info.nim) {
    				printf("Hasil kalkulasi = ");
    				printf("%d", (nilaiHadir + nilaiTugas + nilaiForum + nilaiQuiz + nilaiUas));
    			}    
		    }
		    case '4':
		    {
		  printf("Anda sudah keluar dari program. Terima Kasih sudah menggunakan program saya, Semoga membantu");
			return 0;	 
		    }
	}

   
}
