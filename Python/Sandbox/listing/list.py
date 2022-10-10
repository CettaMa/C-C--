#No.1
ltemansma=["naufal","nanda","almei","bayu","ardi"]

#No.2
ltemansma.sort()
print(ltemansma)
print()

#No.3
print(ltemansma[:3])
print(ltemansma[-1])

#no.4
ltemansma[1]="sugito"
print(ltemansma)

#no.5
# if "Amir" in ltemansma :
#     print("Amir ada didalam list")
# else :
#     print("Amir tidak ada")

#no.6
ltemansma2=[]
for x in range(len(ltemansma)) :
    ltemansma2.append([x,ltemansma[x]])
    # print("Absen ke-",x,"Dengan Nama",ltemansma[x])
    # uts=int(input("Masukan Nilai Uts\t:"))
    uts=32
    ltemansma2[x].append(uts)
    # umur=int(input("Masukan Umur\t:"))
    umur=32
    ltemansma2[x].append(umur)
print(ltemansma2)

#no.7
n=0
for [absen,nama,nilai,umur] in ltemansma2 :
    if nama[0]=='A' or nama[0]=='A' or umur>20 :
        print(nama,nilai,umur)