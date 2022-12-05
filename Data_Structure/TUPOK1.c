#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stokBarang
{
   char namaBarang[51];
   char jenisBarang[21];
   int jumlahBarang;
   int hargaBarang;
   struct stokBarang *next;
} * head, *tail, *curr;

void view()
{
   int i = 0, j = 0;
   printf("        --------------------- LIST BARANG -------------- \n\n");
   for (j = 0; j < 100; j++)
      printf("=");
   printf("\n");
   printf("| %-3s    |   %-20s   |   %-15s   |   %-8s    |   %-8s    |\n",
          "No.", "namaBarang", "jenisBarang", "jumlahBarang", "hargaBarang");
   for (j = 0; j < 100; j++)
      printf("=");
   printf("\n");
   curr = head;
   while (curr)
   {
      i++;
      printf("| %3d.  |   %-20s   |   %-15s   |   %8d     | Rp%8d     |\n",
             i, curr->namaBarang, curr->jenisBarang, curr->jumlahBarang, curr->hargaBarang);
      curr = curr->next;
   }
   for (j = 0; j < 100; j++)
      printf("=");
   printf("\n");
   getchar();
   fflush(stdin);
}

void push(char namaBarang[], char jenisBarang[], int jumlahBarang, int hargaBarang)
{
   curr = (struct data *)malloc(sizeof(struct stokBarang));
   strcpy(curr->namaBarang, namaBarang);
   strcpy(curr->jenisBarang, jenisBarang);
   curr->jumlahBarang = jumlahBarang;
   curr->hargaBarang = hargaBarang;

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

void pop(char namaBarang[])
{
   curr = head;
   while (curr != NULL && strcmp(curr->namaBarang, namaBarang != 0))
   {
      curr = curr->next;
   }

   if (curr == NULL)
   {
      printf("    Nama barang yang anda masukan tidak di temukan \n");
   }
   else if (head == curr)
   {
      head = head->next;
      free(curr);
      printf("    Nama barang yang anda masukan telah berhasil di hapus \n");
   }
   else if (head != curr && tail != curr)
   {
      struct stokBarang *temp;
      temp = head;
      while (temp->next != curr)
         temp = temp->next;
      temp->next = curr->next;
      free(curr);
      printf("    Nama barang yang anda masukan telah berhasil di hapus \n");
   }
   else if (tail == curr)
   {
      printf("    Nama barang yang anda masukan tidak bisa di hapus karena barang terkahir \n");
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
   printf("\n 1. List Barang");
   printf("\n 2. Add (PUSH) barang baru");
   printf("\n 3. Hapus (POP) barang lama");
   printf("\n 4. Keluar");
   printf("\n >> Input pilihan : ");
}

void clear()
{
   for (int i = 0; i < 25; i++)
      printf("\n");
}

int main()
{
   int choice;
   char namaBarang[51];
   char jenisBarang[21];
   int jumlahBarang;
   int hargaBarang;

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
            printf(" Masukan nama barang baru [3..20]: ");
            scanf("%[^\n]", namaBarang);
            fflush(stdin);
         } while (strlen(namaBarang) < 3 || strlen(namaBarang) > 20);
         printf("%[^\n]", jenisBarang);
         do
         {
            printf(" Masukan jenis barang baru [gula/beras/telur]: ");
            scanf("^\n", jenisBarang);
            fflush(stdin);
         } while (strcmp(jenisBarang, "gula") != 0 && strcmp(jenisBarang, "beras") != 0 && strcmp(jenisBarang, "telur") != 0);
         printf("\n");
         do
         {
            printf(" Masukan jumlah barang [1..20]: ");
            scanf("%d", &jumlahBarang);
            fflush(stdin);
         } while (jumlahBarang < 1 || jumlahBarang >= 20);
         printf("\n");
         do
         {
            printf(" Masukan harga barang {Rp1000..Rp100000}: Rp.");
            scanf("%d", &hargaBarang);
            fflush(stdin);
         } while (hargaBarang < 1000 || hargaBarang > 100000);
         push(namaBarang, jenisBarang, jumlahBarang, hargaBarang);
         printf("\n\n\n ---------- Barang baru berhasil di tambahkan ------------ \n");
         getchar();
         fflush(stdin);
         break;
      case 3:
         if (head == NULL)
         {
            printf("List barang kosong.. ");
         }
         else
         {
            do
            {
               printf(" Masukan nama barang [3..20]: ");
               scanf("%[^\n]", namaBarang);
               fflush(stdin);
            } while (strlen(namaBarang) < 3 || strlen(namaBarang) > 20);
            pop(namaBarang);
         }
         getchar();
         fflush(stdin);
         break;
      }
      popall();
   } while (choice != 4);

   return 0;
}
