import duckdb
import pandas as pd

# Load dataset (pastikan path sesuai dengan file data Anda)
data = pd.read_csv('insurance_with_bmi.csv')

# Jalankan query menggunakan DuckDB
query = """
    SELECT age, sex, bmi, children, smoker, region, charges 
    FROM data 
    ORDER BY charges DESC 
    LIMIT 10
"""
result = duckdb.query(query).df()

# Menampilkan hasil
print(result)

