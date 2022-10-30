#Dict Barang
DataBrg={}
DataBrg[100]={'nama': 'Bayam','jenis':'sayuran','jumlaha':15,'hargabeli':1500,'sisa':0,'untung':0}
DataBrg[200]={'nama': 'kangkung','jenis':'sayuran','jumlaha':10,'hargabeli':1000,'sisa':0,'untung':0}
DataBrg[300]={'nama': 'Beras','jenis':'pokok','jumlaha':25,'hargabeli':10000,'sisa':0,'untung':0}
DataBrg[400]={'nama': 'Kerupuk','jenis':'tambahan','jumlaha':20,'hargabeli':1250,'sisa':0,'untung':0}
DataBrg[500]={'nama': 'Ubi','jenis':'pokok','jumlaha':15,'hargabeli':2000,'sisa':0,'untung':0}
DataBrg[600]={'kode':600,'nama': 'Wortel','jenis':'sayuran','jumlaha':20,'hargabeli':4000,'sisa':0,'untung':0}

#Dict Jual
DataJual={}
DataJual[1]={'tanggal': '10-10-20','kode':200,'jumlahb': 1,'harga':1200,'diskon':5}
DataJual[2]={'tanggal': '10-10-20','kode':300,'jumlahb': 2,'harga':12000,'diskon':10}
DataJual[3]={'tanggal': '10-10-20','kode':200,'jumlahb': 1,'harga':900,'diskon':0}
DataJual[4]={'tanggal': '10-10-20','kode':100,'jumlahb': 1,'harga':2500,'diskon':0}
DataJual[5]={'tanggal': '10-10-20','kode':600,'jumlahb': 2,'harga':5000,'diskon':5}
DataJual[6]={'tanggal': '12-10-20','kode':400,'jumlahb': 2,'harga':1500,'diskon':0}
DataJual[7]={'tanggal': '12-10-20','kode':200,'jumlahb': 3,'harga':1500,'diskon':0}
DataJual[8]={'tanggal': '13-10-20','kode':100,'jumlahb': 1,'harga':2500,'diskon':25}
DataJual[9]={'tanggal': '13-10-20','kode':200,'jumlahb': 3,'harga':1500,'diskon':10}
DataJual[10]={'tanggal': '13-10-20','kode':300,'jumlahb': 2,'harga':15000,'diskon':10}

print("\n\t\t\t === Data Dagangan ===\n")
print(f'{"kode":<8}{"Nama":<10}{"Jenis":<10}{"Jumlah":<10}{"Harga Beli":<15}{"Sisa":<10}{"Untung"}')
for x,y in DataBrg.items() :
    print(f"{x:<8}{y['nama']:<10}{y['jenis']:<10}{y['jumlaha']:<10}{y['hargabeli']:<15}{y['sisa']:<10}{y['untung']}")
print("\n\t  === Data Transaksi ===\n")
print(f'{"Tanggal":<10}{"Kode":<10}{"Jumlah":<10}{"Harga Jual":<15}{"Diskon":}')
for x,y in DataJual.items() :
    print(f"{y['tanggal']:<10}{y['kode']:<10}{y['jumlahb']:<10}{y['harga']:<15}{y['diskon']}")

print("\nMenghitung data sisa dan untung\n")
totaluntung=0
untung=0
for x,y in DataBrg.items():
    print("Kelompok Barang: ",x,y['nama'])
    for a,b in DataJual.items():
        if x == b['kode']:
            y['sisa']=y['jumlaha']-b['jumlahb']
            y['jumlaha']=y['sisa']
            totaluntung=y['untung']
            y['untung'] = float(b['harga']*((100-b['diskon'])/100)-b['jumlahb'])
            totaluntung+=y['untung']
            print("Tanggal",b['tanggal'],"Harga Jual",b['harga'],"sisa",y['sisa'],"Untung",y['untung'])

print("\n\t\t\t === Data Dagangan ===\n")
print(f'{"kode":<8}{"Nama":<10}{"Jenis":<10}{"Jumlah":<10}{"Harga Beli":<15}{"Sisa":<10}{"Untung"}')
for x,y in DataBrg.items() :
    print(f"{x:<8}{y['nama']:<10}{y['jenis']:<10}{y['jumlaha']:<10}{y['hargabeli']:<15}{y['sisa']:<10}{y['untung']}")
urutdatabrg=(sorted(DataBrg.items(),key=lambda t:t[1]['jenis']))
DataBrg=dict(urutdatabrg)
print("\nMengurutkan data Isibarang berdasarkan Jenis")
print("\n\t\t\t === Data Dagangan ===\n")
print(f'{"kode":<8}{"Nama":<10}{"Jenis":<10}{"Jumlah":<10}{"Harga Beli":<15}{"Sisa":<10}{"Untung"}')
for x,y in DataBrg.items() :
    print(f"{x:<8}{y['nama']:<10}{y['jenis']:<10}{y['jumlaha']:<10}{y['hargabeli']:<15}{y['sisa']:<10}{y['untung']}")