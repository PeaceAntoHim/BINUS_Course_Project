#include <stdio.h>
#include <string.h>
#include <stdlib.h>

	struct viewHistory {
		char namaMinuman[10];
		char size[10];
		char penyajian[10];
		int harga;
	};

	
int main () {
	char *dataMinuman = "dataminuman.txt";
//	char *data = calloc(100, sizeof(char));
	char data[250];
	char *namaMinuman[10];
	char *size[10];
	char *penyajian[10];
	int i;
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
		puts(temp);
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
			}
			continue;
	
	
			puts(data);
		}
		
		
	
	return 0;
	
}
