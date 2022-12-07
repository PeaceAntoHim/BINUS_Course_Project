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

void pop(int id)
{
   curr = head;
   while (head != NULL && curr->id, id != 0)
   {
      curr = curr->next;
   }

   if (curr == NULL)
   {
      printf("    Id employee yang anda masukan tidak di temukan \n");
   }
   else if (head == curr)
   {
      head = head->next;
      free(curr);
      printf("    Id employee yang anda masukan telah berhasil di hapus \n");
   }
   else if (head != curr && tail != curr)
   {
      struct DataKaryawan *temp;
      temp = head;
      while (temp->next != curr)
         temp = temp->next;
      temp->next = curr->next;
      free(curr);
      printf("   Id employee yang anda masukan telah berhasil di hapus \n");
   }
   else if (tail == curr)
   {
      printf("    Id employee yang anda masukan tidak bisa di hapus karena employee terkahir\n");
   }
}

void popall()
{
   while (head != NULL)
   {
      curr = head;
      head = head->next;
      free(curr);
   }
}

void menu()
{
   printf("\n COMPUTER ADMINISTRATOR");
   printf("\n +++++++++++++++++++++++");
   printf("\n 1. List Employee");
   printf("\n 2. Add (PUSH) Data Employee Baru");
   printf("\n 3. Hapus (POP) Data Employee Lama");
   printf("\n 4. Keluar Program");
   printf("\n >> Input Pilihan : ");
}

void clear()
{
   int i = 0;
   for (i = 0; i < 25; i++)
      printf("\n");
}