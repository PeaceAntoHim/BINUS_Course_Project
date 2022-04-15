#include <stdio.h>
#include <string.h>

struct individu{
	char nama[50];
	char bulan[15];
	int tanggal;
	char *zodiak;
}

main(){
	struct individu saya;
	
	puts("masukkan nama: ");
	gets(saya.nama);
	puts("masukkan bulan: ");
	gets(saya.bulan);
	puts("masukkan tanggal: ");
	scanf("%d", &saya.tanggal);

	
	if((saya.tanggal >= 21 && strcmp(saya.bulan, "maret")== 0) || (saya.tanggal <= 19 && strcmp(saya.bulan, "april")==0)){
		saya.zodiak = "aries";
	}else if((saya.tanggal >= 20 && strcmp(saya.bulan, "april")== 0) || (saya.tanggal <= 20 && strcmp(saya.bulan, "mei")==0)){
		saya.zodiak = "taurus";
	}else if((saya.tanggal >= 21 && strcmp(saya.bulan, "mei")== 0) || (saya.tanggal <= 20 && strcmp(saya.bulan, "juni")==0)){
		saya.zodiak = "gemini";
	}else if((saya.tanggal >= 21 && strcmp(saya.bulan, "juni")== 0) || (saya.tanggal <= 22 && strcmp(saya.bulan, "juli")==0)){
		saya.zodiak = "cancer";
	}else if((saya.tanggal >= 23 && strcmp(saya.bulan, "juli")== 0) || (saya.tanggal <= 22 && strcmp(saya.bulan, "agustus")==0)){
		saya.zodiak = "leo";
	}else if((saya.tanggal >= 23 && strcmp(saya.bulan, "agustus")== 0) || (saya.tanggal <= 22 && strcmp(saya.bulan, "september")==0)){
		saya.zodiak = "virgo";
	}else if((saya.tanggal >= 23 && strcmp(saya.bulan, "september")== 0) || (saya.tanggal <= 22 && strcmp(saya.bulan, "oktober")==0)){
		saya.zodiak = "libra";
	}else if((saya.tanggal >= 23 && strcmp(saya.bulan, "oktober")== 0) || (saya.tanggal <= 21 && strcmp(saya.bulan, "november")==0)){
		saya.zodiak = "scorpio";
	}else if((saya.tanggal >= 22 && strcmp(saya.bulan, "november")== 0) || (saya.tanggal <= 21 && strcmp(saya.bulan, "desember")==0)){
		saya.zodiak = "sagitarius";
	}else if((saya.tanggal >= 22 && strcmp(saya.bulan, "desember")== 0) || (saya.tanggal <= 19 && strcmp(saya.bulan, "januari")==0)){
		saya.zodiak = "capricorn";
	}else if((saya.tanggal >= 20 && strcmp(saya.bulan, "januari")== 0) || (saya.tanggal <= 18 && strcmp(saya.bulan, "februari")==0)){
		saya.zodiak = "aquarius";
	}else if((saya.tanggal >= 19 && strcmp(saya.bulan, "februari")== 0) || (saya.tanggal <= 20 && strcmp(saya.bulan, "maret")==0)){
		saya.zodiak = "pisces";
	}else printf("salah masukkan tanggal atau bulan\n");
	
	printf("nama: %s\n", saya.nama);
	printf("bintang: %s\n", saya.zodiak);
	printf("tanggal lahir: %d %s\n", saya.tanggal, saya.bulan);
}