#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct DataKaryawan
{
   int id;
   char namaLengkap[50];
   char tempatLahir[30];
   char tanggalLahir[15];
   char jabatan[21];
   struct DataKaryawan *next;
} * head, *tail, *curr;

void view()
{
   int i = 0, j = 0;
   printf("        --------------------- LIST EMPLOYEE -------------- \n\n");
   for (j = 0; j < 128; j++)
      printf("=");
   printf("\n");
   printf("| %-3s    |    %-6s    |   %-20s   |   %-15s   |   %-8s    |   %-8s    |\n",
          "No.", "ID", "Nama Lengkap", "Tempat Lahir", "Tanggal Lahir", "Jabatan");
   for (j = 0; j < 128; j++)
      printf("=");
   printf("\n");
   curr = head;
   while (curr)
   {
      i++;
      printf("| %3d.  |    %-12s    |   %-20s   |   %-15s   |   %8d     | %-15s     |\n",
             i, curr->id, curr->namaLengkap, curr->tempatLahir, curr->tanggalLahir, curr->jabatan);
      curr = curr->next;
   }
   for (j = 0; j < 128; j++)
      printf("=");
   printf("\n");
   getchar();
   fflush(stdin);
}

void push(char id[], char namaLengkap[], char tempatLahir[], int tanggalLahir[], char jabatan[])
{
   curr = (struct DataKaryawan *)malloc(sizeof(struct DataKaryawan));
   // strcpy(curr->id, id);
   curr->id = id;
   strcpy(curr->namaLengkap, namaLengkap);
   strcpy(curr->tempatLahir, tempatLahir);
   strcpy(curr->tanggalLahir, tanggalLahir);
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

void pop(char id[])
{
   curr = head;
   while (curr != NULL && strcmp(curr->id, id) != 0)
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

int main()
{
   int choice;
   char id[5];
   char namaLengkap[50];
   char tempatLahir[30];
   int tanggalLahir;
   char jabatan[21];

   do
   {
      clear();
      menu();
      scanf("%d", &choice);
      fflush(stdin);
      switch (choice)
      {
      case 1:
         view();
         break;
      case 2:
         do
         {
            printf(" Masukan id employee. Note: tidak kurang dari 1 angka atau lebih dari 5 angka: ");
            scanf("%d", id);
            fflush(stdin);
         } while (strlen(id) < 1 || strlen(id) > 5);
         printf("\n");
         do
         {
            printf(" Masukan nama lengkap employee. Note: tidak kurang dari 3 kata atau lebih dari 50 kata[3..50]: ");
            scanf("%[^\n]", namaLengkap);
            fflush(stdin);
         } while (strlen(namaLengkap) < 3 || strlen(namaLengkap) > 50);
         printf("\n");
         do
         {
            printf(" Masukan tempat lahir employee. Note: tidak kurang dari 3 kata atau lebih dari 30 kata[3..30]: ");
            scanf("%[^\n]", tempatLahir);
            fflush(stdin);
         } while (strlen(tempatLahir) < 3 || strlen(tempatLahir) > 30);
         printf("\n");
         do
         {
            printf(" Masukan tanggal lahir employee. Note: tidak kurang dari angka 1 atau lebih dari angka 31: ");
            scanf("%d", &tanggalLahir);
            fflush(stdin);
         } while (tanggalLahir < 1 || tanggalLahir > 31);

         do
         {
            printf(" Masukan jabata employee. Note: tidak kurang dari 3 kata atau lebih dari 20 kata[3..20]: ");
            scanf("%[^\n]", jabatan);
            fflush(stdin);
         } while (strlen(jabatan) < 3 || strlen(jabatan) > 20);
         printf("\n");
         push(id, namaLengkap, tempatLahir, tanggalLahir, jabatan);
         printf("\n\n\n ---------- Data Employee baru berhasil di tambahkan ------------ \n");
         getchar();
         fflush(stdin);
         printf("\n");
         break;
      case 3:
         if (head == NULL)
         {
            printf(" List data employee kosong...");
         }
         else
         {
            do
            {
               printf(" Masukan id employee untuk menghapus data employee. Note id employee maksimal 5 angka: ");
               scanf("%[^\n]", id);
               fflush(stdin);
            } while (strlen(id) < 1 || strlen(id) > 5);
            pop(id);
         }
         getchar();
         fflush(stdin);
         break;
      case 4:
         popall();
         break;
      };

   } while (choice != 4);
   return 0;
}
