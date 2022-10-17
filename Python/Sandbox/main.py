barang = {
    1 : {
        "kode" : 100,
        "nama" : "Bayam",
        "jenis": "Sayuran",
        "jumlah1": 15,
        "hargabeli":1500, 
        "sisa" : 0,
        "untung" : 0
    },
    2 : {
        "kode" : 200,
        "nama" : "Kangkung",
        "jenis": "Sayuran",
        "jumlah1": 10,
        "hargabeli":1000, 
        "sisa" : 0,
        "untung" : 0
    },
    3 : {
        "kode" : 300,
        "nama" : "Beras",
        "jenis": "pokok",
        "jumlah1": 25,
        "hargabeli":10000, 
        "sisa" : 0,
        "untung" : 0
    },
    4 : {
        "kode" : 400,
        "nama" : "Kerupuk",
        "jenis": "tambahan",
        "jumlah1": 20,
        "hargabeli":1250, 
        "sisa" : 0,
        "untung" : 0
    },
    5 : {
        "kode" : 500,
        "nama" : "Ubi",
        "jenis": "Pokok",
        "jumlah1": 15,
        "hargabeli":2000, 
        "sisa" : 0,
        "untung" : 0
    },
    6 : {
        "kode" : 600,
        "nama" : "Wortel",
        "jenis": "Sayuran",
        "jumlah1": 20,
        "hargabeli":4000, 
        "sisa" : 0,
        "untung" : 0
    }
        }
print("Data Dagangan")
for x in barang :
  print(barang[x])

jual = {
        1 : {
        "tanggal": 101020,
        "kode" : 200,
        "jumlah1": 1,
        "hargajual":1200, 
        "diskon" : 0.05
    },
        2 : {
        "tanggal": 101020,
        "kode" : 300,
        "jumlah1": 2,
        "hargajual":12000, 
        "diskon" : 0.10
    },  3 : {
        "tanggal": 101020,
        "kode" : 200,
        "jumlah1": 1,
        "hargajual":900, 
        "diskon" : 0
    },  4 : {
        "tanggal": 101020,
        "kode" : 100,
        "jumlah1": 1,
        "hargajual":2500, 
        "diskon" : 0
    },    "5" : {
        "tanggal": 101020,
        "kode" : 600,
        "jumlah1": 2,
        "hargajual":5000, 
        "diskon" : 0.05
    },  6 : {
        "tanggal": 121020,
        "kode" : 400,
        "jumlah1": 2,
        "hargajual":1500, 
        "diskon" : 0
    },  7 : {
        "tanggal": 121020,
        "kode" : 200,
        "jumlah1": 3,
        "hargajual":1500, 
        "diskon" : 0
    },
        8 : {
        "tanggal": 131020,
        "kode" : 100,
        "jumlah1": 1,
        "hargajual":2500, 
        "diskon" : 0.25
    },
        9 : {
        "tanggal": 131020,
        "kode" : 200,
        "jumlah1": 3,
        "hargajual":1500, 
        "diskon" : 0.10
    },
        10 : {
        "tanggal": 131020,
        "kode" : 300,
        "jumlah1": 1,
        "hargajual":15000, 
        "diskon" : 0.10
    },
     
}
print("")
print("Data Transaksi") 
for x in jual :
  print(jual[x])

print("")
print(">>>Menghitung Jumlah Sisa Dan Untung<<<")
for y in barang :
  barang[y]["sisa"] = barang[y]["jumlah1"]
  print("Kelompok Barang : ", barang[y]["kode"],barang[y]["nama"])
  for z in jual:
    if barang[y]["kode"] == jual[z]["kode"]:
      barang[y]["sisa"] = barang[y]["jumlah1"] - jual[z]["jumlah1"]
      barang[y]["jumlah1"] = barang[y]["sisa"]
      barang[y]["untung"] = barang[y]["untung"] + (jual[z]["hargajual"]*(1-jual[z]["diskon"])-barang[y]["hargabeli"])*jual[z]["jumlah1"]
      print("Tanggal", jual[z]["tanggal"],"Harga Asli", jual[z]["hargajual"],"Sisa", barang[y]["sisa"], "Untung", barang[y]["untung"] )    