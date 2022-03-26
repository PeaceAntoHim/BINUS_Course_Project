#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
	int hJam = 2000;
	float jamMain;
	float diskon = 0.2;
	
	printf("Masukan jam bermain = "); scanf("%f", &jamMain);
	
	//Logic		
	if(jamMain > 5) {
	//Lebih dari 5 jam
		printf("diskon 20\% \n");			
		printf("Jumlah pembayaran = Rp. %.2f", round(jamMain * hJam * (1 - 0.2)));
	} else {
		printf("Jumlah pembayaran = Rp. %.2f", jamMain * hJam);
	}		
}
