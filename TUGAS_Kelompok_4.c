#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100

struct viewHistory {
	char *namaMinuman;
	char *size;
	char *penyajian;
	int harga;
};

char* chop(char *string)
{
	int i, len;
	len = strlen(string);
	char *newstring;

	newstring = (char *)malloc(len-1);


	for(i = 0; i < strlen(string)-1; i++)
	{
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
	struct viewHistory minuman[max];
	
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
		// This Loop for minuman
			for (i = 0; i < max; i++) {
				minuman[i].namaMinuman = calloc(20, sizeof(char));
				minuman[i].size = calloc(20, sizeof(char));
				minuman[i].penyajian = calloc(20, sizeof(char));
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
					 		puts(namaMinuman[i]); 
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
					 		puts(size[i]); 
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
					 		puts(penyajian[i]); 
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
				for (i = 0; i < max; i++) {
					if(strcmp(minuman[i].namaMinuman, "") == 0) {
						printf("Masukan Nama Minuman : \n");
						fgets(minuman[i].namaMinuman, 20, stdin);
							printf("in di bawah namaMinuman %s",  minuman[i].namaMinuman);
							if(!bandingInputan(minuman[i].namaMinuman, namaMinuman)) break;
						printf("Masukan Size Minuman : \n");
						fgets(minuman[i].size, 20, stdin);
							if(!bandingInputan(minuman[i].size, size)) break;
						printf("Masukan Cara Penyajian : \n");
						fgets(minuman[i].penyajian, 20, stdin);
							if(!bandingInputan(minuman[i].penyajian, penyajian)) break;
						minuman[i].harga = (strlen(minuman[i].size) - 1)* (strlen(minuman[i].namaMinuman) - 1)* (strlen(minuman[i].penyajian) - 1) * 100;
						printf("\nNama Minuman : %s", minuman[i].namaMinuman);
						printf("Size : %s", minuman[i].size);
						printf("Penyajian : %s", minuman[i].penyajian);
						printf("Harga : Rp.%d\n\n", minuman[i].harga);
					// This for confirm data input
					printf("Konfirmasi apakah yang anda pilih benar yes(y)/no(n)? \n");
					choice = getchar();
						if ( choice == 'n' || choice == 'N' ) {
							minuman[i].namaMinuman = "";
							minuman[i].size = "";
							minuman[i].penyajian = "";
							minuman[i].harga = 0;
							printf("\nData tidak berhasil di masukan\n\n");
							break;
						} else if( choice == 'y' || choice == 'Y' ) {
							printf("\nBerhasil memasukan data\n\n");
							break;
						} else {
							minuman[i].namaMinuman = "";
							minuman[i].size = "";
							minuman[i].penyajian = "";
							minuman[i].harga = 0;
							printf("\nAnda salah memasukan data pilihan konfirmasi\n\n");
							break;
						}
					} 
				}
			}
		
		}
	
	return 0;
	
}
