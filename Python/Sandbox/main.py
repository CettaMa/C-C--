# #Tugas 1
# '''
# nama = input("Masukan Nama :")
# umur = input("Masukan Umur :")
# umur =int (umur) + 10
# print("Umur ",nama," Sepuluh tahun lagi ",umur)'''

# #Tugas 2
# '''
# print("Nama\t: Cetta Maulana Andhika\nNIM\t: 1103213119\nKelas\t: TK-45-04\n")
# nomor = input("Masukan dua nomor terakhir nim anda :")
# nomor = (float(nomor)*float(nomor))*3.14
# print("Hasil =",nomor,)'''

# #Tugas 3
# '''
# nim = input("Masukan NIM Anda :")
# nama = input("Masukan Nama Anda :")
# Alamat = input("Masukan alamat anda :")

# uts = float(input("Masukan Nilai UTS :"))
# uas = float(input("Masukan Nilai UAS :"))

# rata=float((uts+uas)/2)
# if(rata>60) :
#     print("Nama\t: ",nama,"\nNIM\t: ",nim,"\nAlamat\t: ",Alamat,"\nLulus dengan nilai rata rata ",rata)
# else : 
#     print("Nama\t: ",nama,"\nNIM\t: ",nim,"\nAlamat\t: ",Alamat,"\ntidak Lulus dengan nilai rata rata ",rata)'''

# #Tugas 4

# jam = (int(input("Jam\t:")))

# if jam < 3 :
#     harga=2000
# else :
#     harga=((jam-2)*2500)+6000
# print("biaya parkir\t:",harga)

# #tugas mgg 2 1

# umur=(int(input("Usia\t:")))

# if umur <5 :
#     print("Balita")
# elif umur >5 and umur <=12 :
#     print("Anak-Anak")
# elif umur >12 and umur <18 :
#     print("Remaja")
# else :
#     print("Dewasa")

# #tugas 1

# bil= int(input("Masukan angka\t:"))
# jumlah=bil
# for i in range(1,bil) :
#     jumlah=jumlah*(bil-i)

# print(jumlah,"\n")
# #tugas 2

# namelist = ["Andi","Udin","Ujang","Alam","asep"]

# for i in namelist :
#     if i[0]=='a' or i[0]=='A' :
#         print(i)

# #tugas 3

# i=100
# print("\n")
# while i > 0 :
    
#     if i % 2 == 0 :
#         i-=1
#         print("percobaan Ke-",i)
#     else :
#         i-=20
#         if i<0 : break
#         print("percobaan Ke-",i)

list1 = ["apel", "pisang", "ceri", "jeruk", "kiwi", "melon", "mangga"]
list2=[]
for i in range(len(list1)):
  list2.append([i,list1[i]])
print(list2)