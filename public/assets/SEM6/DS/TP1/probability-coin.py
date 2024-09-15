import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import bernoulli

# Langkah 1: Simulasikan 2000 kali lemparan koin
n_trials = 2000
p = 0.55  # Peluang munculnya angka (1)
x = bernoulli.rvs(p, size=n_trials)  # Simulasi Bernoulli

# Langkah 2: Hitung rata-rata kumulatif setelah setiap lemparan
cumulative_mean_1 = np.cumsum(x) / np.arange(1, n_trials + 1)  # Rata-rata kumulatif 1
cumulative_mean_0 = 1 - cumulative_mean_1  # Rata-rata kumulatif 0

# Langkah 3: Gambarkan diagram garis
plt.figure(figsize=(10, 6))
plt.plot(cumulative_mean_1, label='Rata-rata kumulatif angka (1)', color='blue')
plt.plot(cumulative_mean_0, label='Rata-rata kumulatif gambar (0)', color='red')
plt.axhline(y=p, color='blue', linestyle='--', label=f'Teori angka (p = {p})')
plt.axhline(y=1-p, color='red', linestyle='--', label=f'Teori gambar (1-p = {1-p})')
plt.title('Perubahan Nilai Rata-rata Kumulatif setelah n Lemparan Koin')
plt.xlabel('Jumlah Lemparan')
plt.ylabel('Nilai Rata-rata Kumulatif')
plt.legend()
plt.grid(True)
plt.show()
