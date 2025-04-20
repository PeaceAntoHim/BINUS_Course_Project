from Bio import Entrez

Entrez.email = 'learnbiopython@gmail.com'


# espell package
dataTerm = [
    'Bos gaurus', 'Antelope cervicapra', 'Gazella bennettii', 'Boselaphus tragocamelus',
    'Canis lupus', 'Panthera leo', 'Elephas maximus', 'Equus africanus', 'Panthera pardus',
    'Cervus canadensis', 'Pavo cristatus', 'Grus leucogeranus', 'Vulpes vulpes', 'Rhinoceros unicornis',
    'Panthera Tigris', 'Crocodylus palustris', 'Gavialis gangeticus', 'Equus caballus', 'Equus quagga',
    'Babalus bubalis', 'Sus scrofa', 'Camelus dromedaries', 'Giraffa camelopardalis', 'Hemidactylus flaviviridis',
    'Hippopotamus amphibius', 'Macaca mulatta', 'Canis lupus', 'Felis domesticus', 'Acinonyx jubatus',
    'Rattus rattus', 'Mus musculus', 'Oryctolagus cuniculus', 'Bubo virginianus', 'Passer domesticus',
    'Corvus splendens', 'Acridotheres tristis', 'Psittacula eupatria', 'Molpastes cafer', 'Eudynamis scolopaccus',
    'Columba livia', 'Naja naja', 'Ophiophagus hannah', 'Hydrophiinae', 'Python molurus', 'Ptyas mucosa'
]

Entrez.email = 'your_email@example.com'  # Replace with your email address

handle = Entrez.espell(db='pmc', term=''.join(dataTerm))
record = Entrez.read(handle)

print(type(record))
print(record.keys())

for key in record.keys():
    print(key, ':', record[key])

handle.close()
