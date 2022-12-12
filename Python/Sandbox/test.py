from datetime import date, timedelta

DtBan = {
    1:{"Merk":"Dunlop", "Fungsi":"Street", "Kualitas":"B", "Ukuran":19, "Harga":1000000},
    2:{"Merk":"Bridgestone", "Fungsi":"Offroad", "Kualitas":"A", "Ukuran":15, "Harga":1500000},
    3:{"Merk":"GT Radial", "Fungsi":"Street", "Kualitas":"A", "Ukuran":17, "Harga":1250000},
    4:{"Merk":"Accelera", "Fungsi":"Racing", "Kualitas":"C", "Ukuran":18, "Harga":800000},
    5:{"Merk":"Yokohama", "Fungsi":"Racing", "Kualitas":"A", "Ukuran":18, "Harga":2000000}
}

class ban():
    def __init__(self,brand,quality,size,price,fungsi):
        self.fungsi= fungsi
        self.brand = brand
        self.quality = quality
        self.size = size
        self.price = price
    
    def tampil(self):
        x = ' '
        print("=== Data Jual Ban ===")
        print(f'\nMerk{x*8}: {self.brand}\nFungsi{x*4}: {self.quality}\nKualitas{x*5}: {self.size}\nUkuran Terbit : {self.price}')
    
class jual(ban):
    def __init__(self,code,dbuy,dsell):
        self.code = code
        self.dbuy = dbuy
        self.dsell = dsell

    def tampil(self, ban):
        x = ' '
        print(f'\nMerk{x*16}: {ban.brand}\nFungsi{x*12}: {ban.quality}\nKualitas{x*13}: {ban.size}\nUkuran Terbit{x*9}: {ban.price}')
        print(f'Tanggal Pembelian   : {self.dbuy}\nTanggal Penjualan: {self.dsell}')

    # def hitung(self):
    #     self.deadline = self.dbuy + timedelta(30)
    #     if self.dsell > self.deadline:
    #         ngaret = (self.dsell - self.dbuy).days
    #         self.denda = ngaret * 2000
    #         print("Kamu terlambat mengembalikan buku selama {} hari".format(ngaret))
    #     else:
    #         print("Kamu telah mengembalikan buku tepat waktu. Terimakasih!")
list_ban={}
for x,y in DtBan.items():
    list_ban[x]=ban(y["Merk"],y["Kualitas"],y["Ukuran"],y["Harga"],y["Fungsi"])
for x in range(1,len(list_ban)+1):
    list_ban[x].tampil()
