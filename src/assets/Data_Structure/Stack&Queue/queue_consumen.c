#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_SIZE 100

/* Struktur data untuk menyimpan informasi consumen. */
typedef struct
{
   char nama[100];
   char nomor_telepon[100];
   char alamat[100];
} Consumen;

/* Fungsi untuk mengembalikan elemen terdepan dari queue tanpa menghapusnya. */
Consumen peek(Consumen *queue, int *front, int *rear)
{
   return queue[*front];
}

/* Fungsi untuk menghapus elemen terdepan dari queue. */
Consumen dequeue(Consumen *queue, int *front, int *rear)
{
   Consumen elem = queue[*front];
   (*front)++;
   return elem;
}

/* Fungsi untuk menambahkan elemen baru ke queue. */
void enqueue(Consumen *queue, int *front, int *rear, Consumen elem)
{
   (*rear)++;
   queue[*rear] = elem;
}

/* Prosedur untuk menambahkan consumen baru ke antrian. */
void tambah_consumen(Consumen *queue, int *front, int *rear)
{
   Consumen consumen;
   fflush(stdin);
   printf("Masukkan nama consumen: ");
   scanf("%[^\n]", consumen.nama);
   fflush(stdin);
   printf("Masukkan nomor telepon consumen: ");
   scanf("%[^\n]", consumen.nomor_telepon);
   fflush(stdin);
   printf("Masukkan alamat consumen: ");
   scanf("%[^\n]", consumen.alamat);
   fflush(stdin);
   enqueue(queue, front, rear, consumen);
}

/* Prosedur untuk mengeluarkan consumen dari antrian. */
void keluarkan_consumen(Consumen *queue, int *front, int *rear)
{
   if (*front > *rear)
   {
      printf("Antrian kosong!\n");
   }
   else
   {
      Consumen consumen = dequeue(queue, front, rear);
      printf("consumen yang keluar: %s\n", consumen.nama);
   }
}

/* Fungsi untuk mencetak informasi consumen. */
void cetak_consumen(Consumen consumen)
{
   printf("Nama: %s\n", consumen.nama);
   printf("Nomor telepon: %s\n", consumen.nomor_telepon);
   printf("Alamat: %s\n", consumen.alamat);
}

void menu()
{
   printf("\nMenu:\n");
   printf("1. Tambah konsumen\n");
   printf("2. Keluarkan konsumen\n");
   printf("3. Cetak konsumen terdepan\n");
   printf("4. Keluar\n");
   printf("-->Masukkan pilihan: ");
}

void clear()
{
   int i = 0;
   for (i = 0; i < 20; i++)
      printf("\n");
}

int main()
{
   int front = 0, rear = -1, choice;
   Consumen queue[QUEUE_SIZE];
   /* Loop utama program yang menangani input dari pengguna. */
   do
   {
      menu();
      fflush(stdin);
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
         tambah_consumen(queue, &front, &rear);
         clear();
         break;
      case 2:
         keluarkan_consumen(queue, &front, &rear);
         break;
      case 3:
         if (front > rear)
         {
            printf("Antrian kosong!\n");
         }
         else
         {
            Consumen consumen = peek(queue, &front, &rear);
            printf("Informasi consumen terdepan:\n");
            cetak_consumen(consumen);
         }
         break;
      case 4:
         printf("Goodbye!\n");
         break;
      default:
         printf("Pilihan tidak valid!\n");
      }
   } while (choice != 4);

   return 0;
}
