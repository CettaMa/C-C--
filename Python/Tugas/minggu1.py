nama =input("Masukan Nama buah :")
kualitas = int(input("Masukan tingkat kualitas buah :"))
uang = int(input("Masukan Jumlah uang :"))

if nama == "jeruk":
    harga=1000
    if kualitas == 1:
        harga=harga*1.5
    elif kualitas == 3:
        harga=harga*(75/100)
elif nama == "mangga":
    harga=2000
    if  kualitas == 1:
        harga*2
else :
    harga=3000

sisa = int(uang%harga)
jumlah = int(uang/harga)

print("anda membeli",nama,",kualitas",kualitas," dengan harga",harga,", dan mendapatkan",jumlah,"buah dengan sisa uang",sisa,)