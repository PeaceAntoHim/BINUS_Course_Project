import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Data provided
data = {
    'JENIS KELAMIN': ['LAKI - LAKI', 'LAKI - LAKI', 'PEREMPUAN', 'PEREMPUAN', 'LAKI - LAKI', 'LAKI - LAKI', 'PEREMPUAN', 'PEREMPUAN', 'LAKI - LAKI', 'PEREMPUAN', 'PEREMPUAN', 'PEREMPUAN', 'LAKI - LAKI', 'LAKI - LAKI', 'LAKI - LAKI'],
    'STATUS MAHASISWA': ['MAHASISWA', 'BEKERJA', 'MAHASISWA', 'MAHASISWA', 'BEKERJA', 'BEKERJA', 'BEKERJA', 'BEKERJA', 'BEKERJA', 'MAHASISWA', 'MAHASISWA', 'MAHASISWA', 'BEKERJA', 'MAHASISWA', 'MAHASISWA'],
    'STATUS PERNIKAHAN': ['BELUM', 'BELUM', 'BELUM', 'MENIKAH', 'MENIKAH', 'MENIKAH', 'MENIKAH', 'BELUM', 'BELUM', 'MENIKAH', 'BELUM', 'BELUM', 'MENIKAH', 'MENIKAH', 'BELUM'],
    'IPK SEMESTER 1-6': [3.17, 3.30, 3.01, 3.25, 3.20, 2.50, 3.00, 2.70, 2.40, 2.50, 2.50, 3.50, 3.30, 3.25, 2.30],
    'STATUS KELULUSAN': ['TEPAT', 'TEPAT', 'TEPAT', 'TEPAT', 'TEPAT', 'TERLAMBAT', 'TERLAMBAT', 'TERLAMBAT', 'TERLAMBAT', 'TERLAMBAT', 'TERLAMBAT', 'TEPAT', 'TEPAT', 'TEPAT', 'TERLAMBAT']
}

# Create a DataFrame
df = pd.DataFrame(data)

# Visualization (a): Relationship between gender and graduation status
plt.figure(figsize=(8, 6))
sns.countplot(data=df, x='JENIS KELAMIN', hue='STATUS KELULUSAN', palette='coolwarm')
plt.title('Relationship between Gender and Graduation Status')
plt.xlabel('Gender')
plt.ylabel('Count')
plt.legend(title='Graduation Status')
plt.show()

# Visualization (b): Relationship between student status and GPA
plt.figure(figsize=(8, 6))
sns.boxplot(data=df, x='STATUS MAHASISWA', y='IPK SEMESTER 1-6', palette='viridis')
plt.title('Relationship between Student Status and GPA')
plt.xlabel('Student Status')
plt.ylabel('GPA (Semester 1-6)')
plt.show()

# Visualization (c): Trends in on-time graduation by student status
plt.figure(figsize=(8, 6))
sns.countplot(data=df, x='STATUS MAHASISWA', hue='STATUS KELULUSAN', palette='Set2')
plt.title('On-time Graduation Trends by Student Status')
plt.xlabel('Student Status')
plt.ylabel('Count')
plt.legend(title='Graduation Status')
plt.show()
