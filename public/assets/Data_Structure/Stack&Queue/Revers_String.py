# mendefinisikan stack
stack = []

# meminta input string dari user
string = input("Masukkan string yang akan dibalik: ")

# memasukkan setiap karakter dari string ke dalam stack
for char in string:
  stack.append(char)

# membuat variabel baru untuk menampung string yang sudah dibalik
reverse_string = ""

# mengambil setiap karakter dari stack dan menambahkannya ke variabel
# reverse_string sampai stack kosong
while stack:
  reverse_string += stack.pop()

# menampilkan string yang sudah dibalik
print(reverse_string)
