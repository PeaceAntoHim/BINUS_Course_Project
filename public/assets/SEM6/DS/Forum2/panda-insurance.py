import pandas as pd

# Memuat file CSV ke dalam DataFrame pandas
file_path = './insurance_with_bmi.csv'
df = pd.read_csv(file_path)

# Menampilkan beberapa baris pertama dari DataFrame
print(df.head())

# Menambahkan kolom baru untuk mengkategorikan risiko individu
df['kategori_risiko'] = df.apply(
    lambda row: 'berisiko tinggi' if row['smoker'] == 'yes' or row['bmi_type'] == 'obese' else 'berisiko rendah', axis=1
)

# Menampilkan beberapa baris pertama setelah transformasi
print(df[['age', 'sex', 'bmi', 'smoker', 'bmi_type', 'kategori_risiko']].head())
