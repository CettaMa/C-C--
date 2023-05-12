text=input("Masukan text : ")
dicari=input("Masukan input yang dicari : ")
indeks=0
ditemukan=False
for x in text:
    if x==dicari:
        print(indeks)
        ditemukan=True
        break
    elif x==" ":
        pass
    elif x!=dicari:
        indeks+=1

if ditemukan==False:
    print("Karakter tidak ditemukan")
