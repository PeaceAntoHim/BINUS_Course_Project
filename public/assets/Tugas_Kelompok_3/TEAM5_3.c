#include <stdio.h>
#include <string.h>
struct alamat{
	char nama_jalan[100];
	char nomor_rumah[5];
	char kota[20];
	char provinsi[20];
};

struct TanggalLahir{
	char tanggal[5];
	char bulan[15];
	char tahun[5];
};

struct data_dosen{
	char no_dosen[20];
	char NIDN[20];
	char nama[40];
	struct alamat alamat_d;
	char tempat_lahir[20];
	struct TanggalLahir TL_dosen;
};

void print_data_dosen(struct data_dosen list_dosen){
		printf(" nomor dosen : %s\n", list_dosen.no_dosen);
		printf(" NIDN dosen : %s\n", list_dosen.NIDN);
		printf(" nama dosen : %s\n", list_dosen.nama);
		printf(" nama jalan dosen : %s\n", list_dosen.alamat_d.nama_jalan);
		printf(" nomor rumah dosen : %s\n", list_dosen.alamat_d.nomor_rumah);
		printf(" kota dosen : %s\n", list_dosen.alamat_d.kota);
		printf(" provinsi dosen : %s\n", list_dosen.alamat_d.provinsi);
		printf(" tempat lahir dosen : %s\n", list_dosen.tempat_lahir);
		printf(" tanggal lahir dosen (tanggal saja): ", list_dosen.TL_dosen.tanggal);
		printf(" bulan lahir dosen : %s\n", list_dosen.TL_dosen.bulan);
		printf(" tahun lahir dosen : %s\n", list_dosen.TL_dosen.tahun);
		printf("--------------\n\n");	
};

struct data_dosen list_dosen[5];

main(){
	
	for(int i = 0; i<5; i++){
		printf("masukkan nomor dosen %d: ", i+1);gets(list_dosen[i].no_dosen);
		printf("masukkan NIDN dosen %d: ", i+1);gets(list_dosen[i].NIDN);
		printf("masukkan nama dosen %d: ", i+1);gets(list_dosen[i].nama);
		printf("masukkan nama jalan dosen %d: ", i+1);gets(list_dosen[i].alamat_d.nama_jalan);
		printf("masukkan nomor rumah dosen %d: ", i+1);gets(list_dosen[i].alamat_d.nomor_rumah);
		printf("masukkan kota dosen %d: ", i+1);gets(list_dosen[i].alamat_d.kota);
		printf("masukkan provinsi dosen %d: ", i+1);gets(list_dosen[i].alamat_d.provinsi);
		printf("masukkan tempat lahir dosen %d: ", i+1);gets(list_dosen[i].tempat_lahir);
		printf("masukkan tanggal lahir dosen %d(tanggal saja): ", i+1);gets(list_dosen[i].TL_dosen.tanggal);
		printf("masukkan bulan lahir dosen %d: ", i+1);gets(list_dosen[i].TL_dosen.bulan);
		printf("masukkan tahun lahir dosen %d: ", i+1);gets(list_dosen[i].TL_dosen.tahun);
		printf("*******************\n\n");
	}
	print_data_dosen(list_dosen[0]);

}