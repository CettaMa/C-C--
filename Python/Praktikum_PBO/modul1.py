number = int(input("Masukan 2 angka terakhir dari nim anda\t:"))

x=1
jumlah=0

for x in range (100):
    if x%number==0 :
        jumlah=jumlah+1

#0 nya kebawa
print("Jumlah Kelipatan\t:",jumlah-1)