import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd

# Memuat dataset
data = pd.read_csv('insurance_with_bmi.csv')

# Mengatur gaya plot
sns.set(style="whitegrid")

# Membuat scatter plot untuk menunjukkan hubungan antara usia dan biaya asuransi
plt.figure(figsize=(10, 6))
sns.scatterplot(x='age', y='charges', data=data, hue='smoker', palette='coolwarm', alpha=0.7)

# Menambahkan label dan judul
plt.title('Biaya Asuransi Berdasarkan Usia dengan Status Perokok', fontsize=16)
plt.xlabel('Usia', fontsize=12)
plt.ylabel('Biaya Asuransi', fontsize=12)
plt.legend(title="Status Perokok")

# Menampilkan plot
plt.tight_layout()
plt.show()
