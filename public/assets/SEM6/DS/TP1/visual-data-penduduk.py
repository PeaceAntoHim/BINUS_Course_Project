import matplotlib.pyplot as plt

# Data Negara dan Jumlah Penduduk (dalam juta)
negara = ['Indonesia', 'Brunei Darussalam', 'Malaysia', 'Thailand', 'Vietnam']
jumlah_penduduk = [267, 5.63, 327, 126, 69.4]

# Membuat visualisasi line chart
plt.plot(negara, jumlah_penduduk, marker='o')
plt.title('Jumlah Penduduk di Beberapa Negara ASEAN')
plt.xlabel('Negara')
plt.ylabel('Jumlah Penduduk (dalam juta)')
plt.grid(True)
plt.show()
