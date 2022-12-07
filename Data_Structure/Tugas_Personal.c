#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct DataKaryawan
{
   int id;
   char namaLengkap[51];
   char tempatLahir[30];
   int tanggalLahir;
   char jabatan[21];
   struct DataKaryawan *next;
} * head, *tail, *curr;

void view()
{
   int i = 0, j = 0;
   printf("        --------------------- LIST KARYAWAN -------------- \n\n");
   for (j = 0; j < 64; j++)
      printf("=");
   printf("\n");
   printf("| %-3s    |    %-6s    |   %-20s   |   %-15s   |   %-8s    |   %-8s    |\n",
          "No.", "ID", "Nama Lengkap", "Tempat Lahir", "Tanggal Lahir", "Jabatan");
   for (j = 0; j < 64; j++)
      printf("=");
   printf("\n");
   curr = head;
   while (curr)
   {
      i++;
      printf("| %3d.  |    %6d    |   %-20s   |   %-15s   |   %8d     | Rp%8d     |\n",
             i, curr->id, curr->namaLengkap, curr->tempatLahir, curr->tanggalLahir, curr->jabatan);
      curr = curr->next;
   }
   for (j = 0; j < 64; j++)
      printf("=");
   printf("\n");
   getchar();
   fflush(stdin);
}

void push(int id, char namaLengkap[], char tempatLahir[], int tanggalLahir[], char jabatan[])
{
   curr = (struct DataKaryawan *)malloc(sizeof(struct DataKaryawan));
   curr->id = id;
   strcpy(curr->namaLengkap, namaLengkap);
   strcpy(curr->tempatLahir, tempatLahir);
   curr->tanggalLahir = tanggalLahir;
   strcpy(curr->jabatan, jabatan);

   if (head == NULL)
   {
      head = tail = curr;
   }
   else
   {
      tail->next = curr;
      tail = curr;
   }
   tail->next = NULL;
}