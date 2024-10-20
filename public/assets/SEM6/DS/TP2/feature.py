import numpy as np
from collections import Counter

# Data rumah (Latitude, Longitude)
data_rumah = {
    "A": [11, 26],
    "B": [15, 29],
    "C": [19, 28],
    "D": [18, 30],
    "E": [16, 26],
    "F": [23, 25],
    "G": [25, 22],
    "H": [21, 24],
    "I": [29, 24],
    "J": [29, 24]
}

# Lokasi masing-masing rumah
lokasi_rumah = {
    "A": "Kota",
    "B": "Kota",
    "C": "Kota",
    "D": "Kota",
    "E": "Kota",
    "F": "Kabupaten",
    "G": "Kabupaten",
    "H": "Kabupaten",
    "I": "Kabupaten",
    "J": "Kabupaten"
}

# Fungsi untuk menghitung Euclidean Distance
def euclidean_distance(point1, point2):
    return np.sqrt(np.sum((np.array(point1) - np.array(point2))**2))

# Fungsi K-NN
def k_nearest_neighbors(data, predict, k=3):
    distances = []
    for rumah in data:
        dist = euclidean_distance(data[rumah], predict)
        distances.append((dist, lokasi_rumah[rumah]))
    
    # Sort jarak dan ambil K tetangga terdekat
    distances = sorted(distances)[:k]
    
    # Ambil lokasi mayoritas
    votes = [i[1] for i in distances]
    vote_result = Counter(votes).most_common(1)[0][0]
    
    return vote_result

# Rumah X yang ingin diklasifikasikan (19, 25)
rumah_x = [19, 25]

# Klasifikasi menggunakan k-NN
hasil = k_nearest_neighbors(data_rumah, rumah_x, k=3)
print(f"Rumah X berada di: {hasil}")
