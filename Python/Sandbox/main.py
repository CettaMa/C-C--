import json
print ("Dibuat Oleh :")
print ("Nama : Muhammad Musyaffakul Harisna")
print ("NIM : 1103213131")
print ("Kelas : TK-45-04")

Isikcg = {
    100 : {
        "Nama": "Manis",
        "Jenis": "Kampung",
        "Mutu": int(1),
        "NilTotal": 0,
        "Harga": 0
    },
    200 : {
        "Nama": "Wolfgang",
        "Jenis": "Persia",
        "Mutu": int(2),
        "NilTotal": 0,
        "Harga": 0
    },
    300 : {
        "Nama": "Alexander",
        "Jenis": "Angora",
        "Mutu": int(2),
        "NilTotal": 0,
        "Harga": 0
    },
    400 : {
        "Nama": "Borneo",
        "Jenis": "Angora",
        "Mutu": int(1),
        "NilTotal": 0,
        "Harga": 0
    },
    500 : {
        "Nama": "Pussycat",
        "Jenis": "Angora",
        "Mutu": int(1),
        "NilTotal": 0,
        "Harga": 0
    }
}
dfilekcg=json.dumps(Isikcg)
with open("kucing.json","w") as wfilekcg:
    wfilekcg.write(dfilekcg)


Isinilai= {
    1: {
        "Nama": "Manis",
        "Aspek": "Bulu",
        "Kualitas": int(1),
        "Nilai": int(70),
        "Index": ""
    },
    2: {
        "Nama": "Wolfgang",
        "Aspek": "Bulu",
        "Kualitas": int(3),
        "Nilai": int(70),
        "Index": ""
    },
    3: {
        "Nama": "Alexander",
        "Aspek": "Bulu",
        "Kualitas": int(2),
        "Nilai": int(100),
        "Index": ""
    },
    4: {
        "Nama": "Borneo",
        "Aspek": "Bulu",
        "Kualitas": int(3),
        "Nilai": int(30),
        "Index": ""
    },
    5: {
        "Nama": "Pussycat",
        "Aspek": "Bulu",
        "Kualitas": int(2),
        "Nilai": int(60),
        "Index": ""
    },
    6: {
        "Nama": "Manis",
        "Aspek": "Badan",
        "Kualitas": int(1),
        "Nilai": int(80),
        "Index": ""
    },
    7: {
        "Nama": "Wolfgang",
        "Aspek": "Badan",
        "Kualitas": int(2),
        "Nilai": int(90),
        "Index": ""
    },
    8: {
        "Nama": "Alexanders",
        "Aspek": "Badan",
        "Kualitas": int(2),
        "Nilai": int(100),
        "Index": ""
    },
    9: {
        "Nama": "Manis",
        "Aspek": "Sehat",
        "Kualitas": int(1),
        "Nilai": int(75),
        "Index": ""
    },
    10: {
        "Nama": "Wolfgang",
        "Aspek": "Sehat",
        "Kualitas": int(3),
        "Nilai": int(70),
        "Index": ""
    },
    11: {
        "Nama": "Alexander",
        "Aspek": "Sehat",
        "Kualitas": int(2),
        "Nilai": int(100),
        "Index": ""
    },
    12: {
        "Nama": "Borneo",
        "Aspek": "Sehat",
        "Kualitas": int(3),
        "Nilai": int(30),
        "Index": ""
    },
}
dfilenilai=json.dumps(Isinilai)
with open("nilai.json","w") as wfilenilai:
    wfilenilai.write(dfilenilai)

def Tampil():
    print ("Membaca dan Menampilkan File Kucing")
    with open ("kucing.json","r") as rfilekcg:
        bcfilekcg=rfilekcg.read()
        lfilekcg=json.loads(bcfilekcg)
    for p,q in lfilekcg.items():
        print(q)
    print ("\nMembaca dan Menampilkan File Nilai")
    with open ("nilai.json","r") as rfilenilai:
        bcfilenilai=rfilenilai.read()
        lfilenilai=json.loads(bcfilenilai)
    for p,q in lfilenilai.items():
        print(q)
tampil:Tampil()
print("\n")

def BuatIndex():
    dfilenilai=json.dumps(Isinilai)
    with open("nilai.json","w") as wfilenilai:
        for p,q in Isinilai.items():
            if (q["Kualitas"])==1:
                NI=100 * (q["Nilai"])/100
                if NI >= 80:
                    q["Index"]="A"
                elif 70 <= NI < 80:
                    q["Index"]="B"
                elif 55 <= NI < 70:
                    q["Index"]="C"
                elif 40 <= NI < 55:
                    q["Index"]="D"
                elif NI < 40:
                    q["Index"]="E"
            elif (q["Kualitas"])==2:
                NI=80 * (q["Nilai"])/100
                if NI >= 80:
                    q["Index"]="A"
                elif 70 <= NI < 80:
                    q["Index"]="B"
                elif 55 <= NI < 70:
                    q["Index"]="C"
                elif 40 <= NI < 55:
                    q["Index"]="D"
                elif NI < 40:
                    q["Index"]="E"
            elif (q["Kualitas"])==3:
                NI=100 * (q["Nilai"])/100
                if NI >= 80:
                    q["Index"]="A"
                elif 70 <= NI < 80:
                    q["Index"]="B"
                elif 55 <= NI < 70:
                    q["Index"]="C"
                elif 40 <= NI < 55:
                    q["Index"]="D"
                elif NI < 40:
                    q["Index"]="E"
        json.dump(Isinilai,wfilenilai)
    with open ("nilai.json","r") as rfilenilai:
        bcfilenilai=rfilenilai.read()
        lfilenilai=json.loads(bcfilenilai)
    for p,q in lfilenilai.items():
        print(q)
index:BuatIndex()

def HitungNT():
    dfilekcg=json.dumps(Isikcg)
    with open("kucing.json","w") as wfilekcg:
        for a,b in Isikcg.items():
            for p,q in Isinilai.items():
                if (q["Nama"])=="Manis":
                    if (q["Index"])=="A":
                        if (q["Aspek"])=="Bulu":
                            aspek=3
                            NilAs=4*3
                        elif (q["Aspek"])=="Badan":
                            aspek=4
                            NilAs=4*4
                        elif (q["Aspek"])=="Sehat":
                            aspek=5
                            NilAs=4*5
                    elif (q["Index"])=="B":
                        if (q["Aspek"])=="Bulu":
                            aspek=3
                            NilAs=3*3
                        elif (q["Aspek"])=="Badan":
                            aspek=4
                            NilAs=3*4
                        elif (q["Aspek"])=="Sehat":
                            aspek=5
                            NilAs=3*5
                    elif (q["Index"])=="C":
                        if (q["Aspek"])=="Bulu":
                            aspek=3
                            NilAs=2*3
                        elif (q["Aspek"])=="Badan":
                            aspek=4
                            NilAs=2*4
                        elif (q["Aspek"])=="Sehat":
                            NilAs=2*5
                    elif (q["Index"])=="D":
                        if (q["Aspek"])=="Bulu":
                            aspek=3
                            NilAs=1*3
                        elif (q["Aspek"])=="Badan":
                            aspek=4
                            NilAs=1*4
                        elif (q["Aspek"])=="Sehat":
                            aspek=5
                            NilAs=1*5
                    elif (q["Index"])=="E":
                        if (q["Aspek"])=="Bulu":
                            aspek=3
                            NilAs=0*3
                        elif (q["Aspek"])=="Badan":
                            aspek=4
                            NilAs=0*4
                        elif (q["Aspek"])=="Sehat":
                            aspek=5
                            NilAs=0*5
                    for p,q in Isinilai.items():
                        NilaiAkhir = NilAs/aspek
                    
HitungNT()

if aspek==bulu:
    aspek=3
elif aspek==badan:
    aspek=4
elif aspek==sehat:
    aspek=5

if indeks==A:
    aspek=aspek*4
elif indeks==B:
    aspek=aspek*3
elif indeks==c:
    aspek=aspek*2
elif indeks==d:
    aspek=aspek*1
elif indeks==e:
    pass
