#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100
#include <conio.h>
#include <ctype.h>

/* 	Tugas Kelompok_5, Tugas ke-4
	Nama: Frans Sebastian Nim: 2502121162
	Nama: Gilang Hansangita Nim: 2502124403
	Nama: Denny Chrisnanda Nim: 2502124914
	compiler yang digunakan adalah compiler dari onlinegdb
*/
struct viewHistory {
	char namaMinuman[20];
	char size[20];
	char penyajian[20];
	int harga;
};

char* chop(char *string) {
	int i, len;
	len = strlen(string);
	char *newstring;

	newstring = (char *)malloc(len-1);

	for(i = 0; i < strlen(string)-1; i++) {
		newstring[i] = string[i]; 
	}
	return newstring;
}

int bandingInputan(char *inputan, char *namaMinuman[]) {
	inputan = chop(inputan);
	int j;
	for(j = 0; j < 10; j++) {
		if(strcmp(inputan, namaMinuman[j]) == 0) {
			printf("inputan benar.\n");
			return 1;
		} else {
			continue;
		}
	}
	printf("inputan salah\n");
	return 0;
}

	
int main () {
	char *dataMinuman = "dataminuman.txt";
//	char *data = calloc(100, sizeof(char));
	char data[250];
	char *namaMinuman[10];
	char *size[10];
	char *penyajian[10];
	int i;
	int inputan;
	int loop = 1;
	char choice;
	static struct viewHistory minuman[max];
	char tempNama[20];
	char tempSize[20];
	char tempPenyajian[20];
	int tempHarga;
	int indexDelete;
	
	FILE *fRead;
	fRead = fopen(dataMinuman, "r");
		// This  loop for nama Minuman
			for (i = 0; i < 10; i++) {
				namaMinuman[i] = calloc(20, sizeof(char));	
			}
		// This loop for size
			for (i = 0; i < 10; i++) {
				size[i] = calloc(20, sizeof(char));	
			}
		// This Loop for penyajian
			for (i = 0; i < 10; i++) {
				penyajian[i] = calloc(20, sizeof(char));	
			}

	if(!fRead) {
		perror("File not found");
		getchar();
		return 1;
	} 
	
	while(!feof(fRead)) {
		fscanf(fRead, "%[^\n]\n", data);
		char *temp;
		temp = strtok(data, ":");
			if(strcmp(temp, "namaMinuman") == 0) {
				char *temp2 ;
				temp2 = strtok(NULL, ",");
				while(temp2 != NULL) {
					for(i = 0; i < 10; i++) {
						if(strcmp(namaMinuman[i], "") != 0) continue;
						else {
							strcpy(namaMinuman[i], temp2);
					 		//puts(namaMinuman[i]); 
					 		temp2 = strtok(NULL, ",");
							i = 10;
						}
					}
				}
			}else if(strcmp(temp, "size") == 0) {
				char *temp2 ;
				temp2 = strtok(NULL, ",");
				while(temp2 != NULL) {
					for(i = 0; i < 10; i++) {
						if(strcmp(size[i], "") != 0) continue;
						else {
							strcpy(size[i], temp2);
					 		//puts(size[i]); 
					 		temp2 = strtok(NULL, ",");
							i = 10;
						}
					}
				}
			} else if(strcmp(temp, "penyajian") == 0) {
				char *temp2 ;
				temp2 = strtok(NULL, ",");
				while(temp2 != NULL) {
					for(i = 0; i < 10; i++) {
						if(strcmp(penyajian[i], "") != 0) continue;
						else {
							strcpy(penyajian[i], temp2);
					 		//puts(penyajian[i]); 
					 		temp2 = strtok(NULL, ",");
							i = 10;
						}
					}
				}
			}continue;
		}
		
		while(loop) {
			printf("Pilih Menu di bawah ini : \n");
			printf("	1. Input data\n");
			printf("	2. View History\n");
			printf("	3. Delete History\n");
			printf("	4. Exit\n");
			scanf("%d", &inputan);
			
			// Step 1 input data
			getchar();
			if(inputan == 1) {
				system("cls");
				//printf("inputan %d\n", inputan);
				for (i = 1; i < max; i++) {
					//printf("%d\n", i);
					if(strcmp(minuman[i].namaMinuman, "") == 0) {
						printf("Masukan Nama Minuman : \n");
						fgets(tempNama, 20, stdin);          
						if(!bandingInputan(tempNama, namaMinuman)) break;
						printf("Masukan Size Minuman : \n");
						fgets(tempSize, 20, stdin);
						if(!bandingInputan(tempSize, size)) break;
						printf("Masukan Cara Penyajian : \n");
						fgets(tempPenyajian, 20, stdin);
						if(!bandingInputan(tempPenyajian, penyajian)) break;
						tempHarga = (strlen(tempNama) - 1)* (strlen(tempSize) - 1)* (strlen(tempPenyajian) - 1) * 100;
						printf("\nNama Minuman : %s", tempNama);
						printf("Size : %s", tempSize);
						printf("Penyajian : %s", tempPenyajian);
						printf("Harga : Rp.%d\n\n", tempHarga);
						
						// This for confirm data input
						printf("Konfirmasi apakah yang anda pilih benar yes(y)/no(n)? \n");
						scanf("%c", &choice);
						fflush(stdin);
						if ( choice =='y' || choice == 'Y'){
							strcpy(minuman[i].namaMinuman, chop(tempNama));
							strcpy(minuman[i].size, chop(tempSize));
							strcpy(minuman[i].penyajian, chop(tempPenyajian));
							minuman[i].harga = tempHarga;
							puts("Data berhasil dimasukkan.");
							break;
						}else if(choice =='n' || choice == 'N'){
							puts("Data tidak berhasil dimasukkan.");
							break;
						}else{
							puts("input konfirmasi salah");
							break;
						}
					}
				} 
			} else if (inputan == 2) {
				system("cls");
				printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
				printf("No.\t nama\t size\t penyajian\t harga\n ");
				for (i = 1; i < max; i++) {
					if(minuman[i].harga != 0) {
						printf("%d\t %s\t %s\t %s\t\tRp.%i\n", i, minuman[i].namaMinuman, minuman[i].size, minuman[i].penyajian, minuman[i].harga);
					}
				}
			} else if (inputan == 3) {
				system("cls");
				printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
				printf("No.\t nama\t size\t penyajian\t harga\n ");
				for (i = 1; i < max; i++) {
					if(minuman[i].harga != 0) {
						printf("%d\t %s\t %s\t %s\t\tRp.%i\n", i, minuman[i].namaMinuman, minuman[i].size, minuman[i].penyajian, minuman[i].harga);
					}
				}
				printf("\nMasukan No index yang mau di hapus: \n\n");
				scanf("%d", &indexDelete);
				strcpy(minuman[indexDelete].namaMinuman, "");
				strcpy(minuman[indexDelete].size, "");
				strcpy(minuman[indexDelete].penyajian, "");
				minuman[indexDelete].harga = 0;
				printf("\nData Successfully delete..\n\n");
			} else if(inputan == 4) {
				system("cls");
				FILE *fWrite;
				
				fWrite = fopen(dataMinuman, "a");
				
				fprintf(fWrite, "Data Minuman\n");
				fprintf(fWrite,"No.\t nama\t size\t penyajian\t harga\n ");
				for (i = 1; i < max; i++) {
					if(minuman[i].harga != 0) {
						fprintf(fWrite, "%d\t %s\t %s\t %s\t\tRp.%i\n", i, minuman[i].namaMinuman, minuman[i].size, minuman[i].penyajian, minuman[i].harga);
					}
				}
				
				fclose(fWrite);
				break;
			}	
		}
		fclose(fRead);
	return 0;
}
