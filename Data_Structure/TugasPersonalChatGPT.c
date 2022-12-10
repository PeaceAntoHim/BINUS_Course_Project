#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisikan struktur data untuk menyimpan data karyawan
typedef struct Employee
{
   int id;
   char nama[30];
   char tempat_lahir[30];
   char tanggal_lahir[15];
   char jabatan[50];
   struct Employee *next;
} Employee;

// Fungsi untuk menambahkan data karyawan
void push_data(Employee **head, Employee **tail)
{
   // Alokasikan memori untuk data karyawan baru
   Employee *new_employee = (Employee *)malloc(sizeof(Employee));

   // Validasi jumlah data karyawan, maksimal 5 data
   if (count_data(*head) >= 5)
   {
      printf("Data karyawan sudah mencapai batas maksimal (5 data)\n");
      return;
   }

   // Input data karyawan
   printf("Employee ID (maksimal 5 angka): ");
   scanf("%d", &new_employee->id);

   printf("Nama Lengkap (maksimal 30 karakter): ");
   scanf("%s", new_employee->nama);

   printf("Tempat Lahir (maksimal 30 karakter): ");
   scanf("%s", new_employee->tempat_lahir);

   printf("Tanggal Lahir (format: dd/mm/yyyy): ");
   scanf("%s", new_employee->tanggal_lahir);

   printf("Jabatan (maksimal 50 karakter): ");
   scanf("%s", new_employee->jabatan);

   // Tambahkan data karyawan baru ke linked list
   if (*head == NULL)
   {
      // Jika linked list masih kosong, tambahkan data karyawan sebagai elemen pertama
      *head = new_employee;
      *tail = new_employee;
   }
   else
   {
      // Jika linked list sudah ada elemen, tambahkan data karyawan sebagai elemen terakhir
      (*tail)->next = new_employee;
      *tail = new_employee;
   }

   // Set next pointer dari elemen terakhir menjadi NULL
   (*tail)->next = NULL;

   printf("Data karyawan berhasil ditambahkan\n");
}

// Fungsi untuk menghitung jumlah data karyawan
int count_data(Employee *head)
{
   int count = 0;
   Employee *curr = head;

   // Lakukan iterasi selama curr tidak NULL
   while (curr != NULL)
   {
      count++;
      curr = curr->next;
   }

   return count;
}

// Fungsi untuk menampilkan data karyawan
void display_data(Employee *head)
{
   // Jika linked list kosong, tampilkan pesan
   if (head == NULL)
   {
      printf("Data karyawan tidak ditemukan\n");
      return;
   }

   // Tampilkan header tabel
   printf("Employee ID\tNama Lengkap\tTempat Lahir\tTanggal Lahir\tJabatan\n");

   // Lakukan iterasi selama head tidak NULL
   while (head != NULL)
   {
      // Tampilkan data karyawan
      printf("%d\t%s\t%s\t%s\t%s\n", head->id, head->nama, head->tempat_lahir, head->tanggal_lahir, head->jabatan);

      // Pindahkan head ke elemen selanjutnya
      head = head->next;
   }
}

// // Fungsi untuk menghapus data karyawan berdasarkan Employee ID
// void delete_data(struct DataKaryawan **head, struct DataKaryawan **tail, int id) {
//   // Jika linked list kosong, tidak ada data yang dapat dihapus
//   if(*head == NULL) {
//     return;
//   }

//   // Cari elemen dengan Employee ID sesuai input
//   struct DataKaryawan *curr = *head;
//   while(curr != NULL && curr->id != id) {
//     curr = curr->next;
//   }

//   // Jika elemen tidak ditemukan, tampilkan pesan error
//   if(curr == NULL) {
//     printf("Data karyawan dengan Employee ID %d tidak ditemukan\n", id);
//   }
//   // Jika elemen ditemukan, hapus elemen tersebut dari linked list
//   else {
//     // Jika elemen yang ditemukan merupakan head, hapus head
//     if(curr == *head) {
//       *head = (*head)->next;
//       free(curr);
//     }
//     // Jika elemen yang ditemukan bukan head dan bukan tail, hapus elemen dari tengah linked list
//     else if(*head != curr && *tail != curr) {
//       struct DataKaryawan *temp = *head;
//       while(temp->next != curr) {
//         temp = temp->next;
//       }
//       temp->next = curr->next;
//       free(curr);
//     }
// Jika elemen yang ditemukan merupakan tail, hap

// // Fungsi untuk menghapus data karyawan berdasarkan Employee ID
// void delete_data(struct DataKaryawan **head, struct DataKaryawan **tail, int id) {
//   // Jika linked list kosong, tidak ada data yang dapat dihapus
//   if(*head == NULL) {
//     return;
//   }

//   // Cari elemen dengan Employee ID sesuai input
//   struct DataKaryawan *curr = *head;
//   while(curr != NULL && curr->id != id) {
//     curr = curr->next;
//   }

//   // Jika elemen tidak ditemukan, tampilkan pesan error
//   if(curr == NULL) {
//     printf("Data karyawan dengan Employee ID %d tidak ditemukan\n", id);
//   }
//   // Jika elemen ditemukan, hapus elemen tersebut dari linked list
//   else {
//     // Jika elemen yang ditemukan merupakan head, hapus head
//     if(curr == *head) {
//       *head = (*head)->next;
//       free(curr);
//     }
//     // Jika elemen yang ditemukan bukan head dan bukan tail, hapus elemen dari tengah linked list
//     else if(*head != curr && *tail != curr) {
//       struct DataKaryawan *temp = *head;
//       while(temp->next != curr) {
//         temp = temp->next;
//       }
//       temp->next = curr->next;
//       free(curr);
//     }
//     // Jika elemen yang ditemukan merupakan tail, hapus tail
//     else {
//       *tail = *head;
//       while((*tail)->next != curr) {
//         *tail = (*tail)->next;
//       }
//       (*tail)->next = NULL;
//       free(curr);
//     }
//   }
// }

// Fungsi untuk menghapus data karyawan berdasarkan Employee ID
void delete_data(Employee **head, Employee **tail, int id)
{
   Employee *curr = *head;
   Employee *prev = NULL;

   // Lakukan iterasi selama curr tidak NULL
   while (curr != NULL)
   {
      // Jika Employee ID yang dicari ditemukan, hapus elemen
      if (curr->id == id)
      {
         // Jika elemen yang dihapus merupakan elemen pertama, pindahkan head ke elemen selanjutnya
         if (prev == NULL)
         {
            *head = curr->next;
         }
         else
         {
            // Jika elemen yang dihapus bukan elemen pertama, atur pointer next dari elemen sebelumnya menunjuk ke elemen selanjutnya
            prev->next = curr->next;
         }

         // Jika elemen yang dihapus merupakan elemen terakhir, atur tail menunjuk ke elemen sebelumnya
         if (curr->next == NULL)
         {
            *tail = prev;
         }

         // Hapus elemen
         free(curr);

         printf("Data karyawan berhasil dihapus\n");
         return;
      }

      // Pindahkan prev dan curr ke elemen selanjutnya
      prev = curr;
      curr = curr->next;
   }

   printf("Data karyawan tidak ditemukan\n");
}

// Fungsi untuk menghapus semua data karyawan
void clear_data(Employee **head, Employee **tail)
{
   Employee *curr = *head;
   Employee *next = NULL;

   // Lakukan iterasi selama curr tidak NULL
   while (curr != NULL)
   {
      // Simpan pointer ke elemen selanjutnya
      next = curr->next;

      // Hapus elemen
      free(curr);

      // Pindahkan curr ke elemen selanjutnya
      curr = next;
   }

   // Set head dan tail menjadi NULL
   *head = NULL;
   *tail = NULL;

   printf("Semua data karyawan berhasil dihapus\n");
}

// Fungsi untuk mengurutkan data karyawan berdasarkan Employee ID
void sort_data(Employee *head)
{
   // Jika linked list kosong atau hanya terdiri dari 1 elemen, tidak perlu diurutkan
   if (head == NULL || head->next == NULL)
   {
      return;
   }

   // Deklarasikan variabel untuk menyimpan data karyawan selama proses sorting
   Employee *curr;
   Employee *next;

   // Lakukan iterasi selama data belum terurut
   int is_sorted = 0;
   while (!is_sorted)
   {
      // Set is_sorted menjadi 1, jika data sudah terurut maka is_sorted tidak akan berubah
      is_sorted = 1;

      // Set curr dan next ke elemen pertama
      curr = head;
      next = curr->next;

      // Lakukan iterasi selama next tidak NULL
      while (next != NULL)
      {
         // Jika Employee ID dari curr lebih besar dari Employee ID dari next, tukar data karyawan
         if (curr->id > next->id)
         {
            int temp_id = curr->id;
            curr->id = next->id;
            next->id = temp_id;

            char temp_nama[30];
            strcpy(temp_nama, curr->nama);
            strcpy(curr->nama, next->nama);
            strcpy(next->nama, temp_nama);

            char temp_tempat_lahir[30];
            strcpy(temp_tempat_lahir, curr->tempat_lahir);
            strcpy(curr->tempat_lahir, next->tempat_lahir);
            strcpy(next->tempat_lahir, temp_tempat_lahir);

            char temp_tanggal_lahir[15];
            strcpy(temp_tanggal_lahir, curr->tanggal_lahir);
            strcpy(curr->tanggal_lahir, next->tanggal_lahir);
            strcpy(next->tanggal_lahir, temp_tanggal_lahir);

            char temp_jabatan[50];
            strcpy(temp_jabatan, curr->jabatan);
            strcpy(curr->jabatan, next->jabatan);
            strcpy(next->jabatan, temp_jabatan);

            // Set is_sorted menjadi 0 karena data belum terurut
            is_sorted = 0;
         }

         // Pindahkan curr dan next ke elemen selanjutnya
         curr = curr->next;
         next = curr->next;
      }
   }
}

int main()
{
   // Deklarasikan variabel untuk linked list
   Employee *head = NULL;
   Employee *tail = NULL;

   // Deklarasikan variabel untuk input pilihan user
   int pilihan;

   // Tampilkan menu selama user belum memilih keluar dari program
   do
   {
      // Tampilkan menu
      printf("Pilih menu:\n");
      printf("1. Tambah Data Karyawan\n");
      printf("2. Tampilkan Daftar Karyawan\n");
      printf("3. Hapus Data Karyawan\n");
      printf("4. Hapus Semua Data Karyawan\n");
      printf("5. Keluar\n");

      printf("Pilihan: ");
      scanf("%d", &pilihan);

      switch (pilihan)
      {
      case 1: // Tambah data karyawan
         push_data(&head, &tail);
         break;
      case 2: // Tampilkan daftar karyawan
         sort_data(head);
         display_data(head);
         break;
      case 3: // Hapus data karyawan
         printf("Masukkan Employee ID: ");
         int id;
         scanf("%d", &id);
         delete_data(&head, &tail, id);
         break;
      case 4: // Hapus semua data karyawan
         clear_data(&head, &tail);
         break;
      case 5: // Keluar dari program
         break;
      default: // Input tidak valid
         printf("Pilihan tidak valid\n");
         break;
      }
   } while (pilihan != 5);

   return 0;
}
