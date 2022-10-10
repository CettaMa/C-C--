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
if "Amir" in ltemansma :
    print("Amir ada didalam list")
else :
    print("Amir tidak ada")

#no.6
ltemansma2=[]
for x in range(len(ltemansma)) :
    ltemansma2.append([x,ltemansma[x]])
    print("Absen ke-",x,"Dengan Nama",ltemansma[x])
    uts=int(input("Masukan Nilai Uts\t:"))
    ltemansma2[x].append(uts)
    umur=int(input("Masukan Umur\t:"))
    ltemansma2[x].append(umur)
print(ltemansma2)

#no.7
n=0
for [absen,nama,nilai,umur] in ltemansma2 :
    if nama[0]=='A' or nama[0]=='a' or umur>20 :
        print(nama,nilai,umur)

#no.08
namaibu="neni"
ltemansma2.append(namaibu)
print(ltemansma2)

#no.09
ltemansma2.pop(-1)
ltemansma2.pop(-1)
print(ltemansma2)

#no.10
ltemansma3=[]
for [absen,nama,nilai,umur] in ltemansma2 :
    print(absen,"dengan nama ",nama)
    uas=int(input("Masukan nilai UAS\t:"))
    ltemansma3.append([absen,nama,uas,umur])
print(ltemansma3)

#no.11
lnilai=[]
for [absen,nama,nilai,umur]in ltemansma3:
    for [absen2,nama2,nilai2,umur2] in ltemansma2:
        if nama==nama2:
            ratarata=(nilai+nilai2)/2
            if ratarata>60 :
                keterangan="Lulus"
                lnilai.append([absen,nama,ratarata,keterangan])
            else :
                keterangan="Tidak Lulus"
                lnilai.append([absen,nama,ratarata,keterangan])
        else :
            continue
print(lnilai)

#no.12
def sortingkey(var) :
    return(var[2])

lnilai.sort(key=sortingkey, reverse=True)
print(lnilai)

#no.13
print("\nRangking\t:")
print(lnilai[:2])