import json

dict1 = {
    1 : {"kode" : 100 ,"nama" : "bayam","jenis" : "sayuran","jumlah" : 15,"Hargabeli" : 1500,"sisa" : 0,"untung" :0},
    2 : {"kode" : 200 ,"nama" : "kangkung","jenis" : "sayuran","jumlah" : 10,"Hargabeli" : 1000,"sisa" : 0,"untung" : 0},
    3 : {"kode" : 300 ,"nama" : "beras","jenis" : "pokok","jumlah" : 25,"Hargabeli" : 10000,"sisa" : 0,"untung" : 0},
    4 : {"kode" : 400 ,"nama" : "kerupuk","jenis" : "tambahan","jumlah" : 20,"Hargabeli" : 1250,"sisa" : 0,"untung" : 0},
    5 : {"kode" : 500 ,"nama" : "ubi","jenis" : "pokok","jumlah" : 15,"Hargabeli" : 2000,"sisa" : 0,"untung" : 0},
    6 : {"kode" : 600 ,"nama" : "wortel","jenis" : "sayuran","jumlah" : 20,"Hargabeli" : 4000,"sisa" : 0,"untung" : 0}
}

#isibarang 
with open("Python/Sandbox/File/barang.json","w") as file1:
    json.dump(dict1,file1,indent=4)

dict2 = {
    "barang1" : {"tanggal" : 101020,"kode" : 200,"jumlah" : 1,"harga" : 1200,"diskon" : 5},
    "barang2" : {"tanggal" : 101020,"kode" : 300,"jumlah" : 2,"harga" : 12000,"diskon" : 10},
    "barang3" : {"tanggal" : 101020,"kode" : 200,"jumlah" : 1,"harga" : 900,"diskon" : 0},
    "barang4" : {"tanggal" : 101020,"kode" : 100,"jumlah" : 1,"harga" : 2500,"diskon" : 0},
    "barang5" : {"tanggal" : 101020,"kode" : 600,"jumlah" : 2,"harga" : 5000,"diskon" : 5},
    "barang6" : {"tanggal" : 121020,"kode" : 400,"jumlah" : 2,"harga" : 1500,"diskon" : 0},
    "barang7" : {"tanggal" : 121020,"kode" : 200,"jumlah" : 3,"harga" : 1500,"diskon" : 0},
    "barang8" : {"tanggal" : 131020,"kode" : 100,"jumlah" : 1,"harga" : 2500,"diskon" : 25},
    "barang9" : {"tanggal" : 131020,"kode" : 200,"jumlah" : 3,"harga" : 1500,"diskon" : 10},
    "barang10" : {"tanggal" : 131020,"kode" : 300,"jumlah" : 1,"harga" : 15000,"diskon" : 10}
}

#isijual
with open("Python/Sandbox/File/jual.json","w") as file2:
    json.dump(dict2,file2,indent=4)

#urut
with open("Python/Sandbox/File/jual.json","r") as file2:
    filejual=json.load(file2)

dict(filejual)

lap=(sorted(filejual.items(), key=lambda item: item[1]["kode"]))
filejual=dict(lap)

with open("Python/Sandbox/File/jual.json","w") as file2:
    json.dump(filejual,file2,indent=4)

#nomor.D
for barang1,keys1 in dict1.items():
    dict1[barang1]["sisa"]= dict1[barang1]["jumlah"]
    untung=0
    for barang2,keys2 in filejual.items():
        if keys1["kode"]==keys2["kode"] :
            # print("ketemu!!",keys1["kode"])
            sisa=keys1["sisa"]-keys2["jumlah"]
            dict1[barang1]["sisa"]=sisa
            # print(dict1[barang1]["sisa"])

            if keys2["diskon"]==0 :
                untung +=keys2["harga"]-keys1["Hargabeli"]
            else :
                untung +=(keys2["harga"]*(1-(keys2["diskon"]/100)))-keys1["Hargabeli"]
        else :
            continue
    dict1[barang1]["untung"]=untung

with open("Python/Sandbox/File/barang.json","w") as file1:
    json.dump(dict1,file1,indent=4)

#Menampilkan data dari file dan mengurutkan berdasarkan jenis
with open("Python/Sandbox/File/barang.json","r") as file1:
    dict1=json.load(file1)

print("Data Dagangan")
for keys,item in dict1.items() :
    print(item["kode"],item["nama"],"\t",item["jenis"],"    \t",item["jumlah"],"\t",item["Hargabeli"],"\t",item["sisa"],"\t",item["untung"])
lap=(sorted(dict1.items(), key=lambda item: item[1]["jenis"]))
dict1=dict(lap)
print("\nSetelah diurutkan Berdasarkan Jenis :")
for keys,item in dict1.items() :
    print(item["kode"],item["nama"],"\t",item["jenis"],"    \t",item["jumlah"],"\t",item["Hargabeli"],"\t",item["sisa"],"\t",item["untung"])

with open("Python/Sandbox/File/barang.json","w") as file1:
    json.dump(dict1,file1,indent=4)

#menampilkan total untung tiap jenis
with open("Python/Sandbox/File/barang.json","r") as file1:
    dict1=json.load(file1)

untungpokok=0
untungsayuran=0
untungtambahan=0

for keys,item in dict1.items():
    if item["jenis"]=="pokok":
        untungpokok+=item["untung"]
    if item["jenis"]=="sayuran":
        untungsayuran+=item["untung"]
    if item["jenis"]=="tambahan":
        untungtambahan+=item["untung"]

print("\nlaporan Keuntungan dari tiap jenis\t:")
print("1\tPokok\t",untungpokok)
print("2\tSayuran\t",untungsayuran)
print("3\tPokok\t",untungtambahan)