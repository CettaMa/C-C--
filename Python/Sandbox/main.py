import json

dictcat = {
    "Manis" : {
        "jenis" : "Kampung",
        "mutu" : 1,
        "nilakhir" : 0,
        "harga" : 0
    },
    "Wolfgang" : {
        "jenis" : "Persia",
        "mutu" : 2,
        "nilakhir" : 0,
        "harga" : 0
    },
    "Alexander" : {
        "jenis" : "Angora",
        "mutu" : 2,
        "nilakhir" : 0,
        "harga" : 0
    },
    "Borneo" : {    
        "jenis" : "Angora",
        "mutu" : 1,
        "nilakhir" : 0,
        "harga" : 0
    },
    "Pussycat" : {    
        "jenis" : "Persia",
        "mutu" : 1,
        "nilakhir" : 0,
        "harga" : 0
    }
}

dictnilai = {
    0:{"Nama":"Manis","Aspek":"Bulu","Kualitas":1,"Nilai":70,"Index":0},
    1:{"Nama":"Wolfgang","Aspek":"Bulu","Kualitas":3,"Nilai":70,"Index":0},
    2:{"Nama":"Alexander","Aspek":"Bulu","Kualitas":2,"Nilai":100,"Index":0},
    3:{"Nama":"Borneo","Aspek":"Bulu","Kualitas":3,"Nilai":30,"Index":0},
    4:{"Nama":"Pussycat","Aspek":"Bulu","Kualitas":2,"Nilai":60,"Index":0},
    5:{"Nama":"Manis","Aspek":"Badan","Kualitas":1,"Nilai":80,"Index":0},
    6:{"Nama":"Wolfgang","Aspek":"Badan","Kualitas":2,"Nilai":90,"Index":0},
    7:{"Nama":"Alexander","Aspek":"Badan","Kualitas":2,"Nilai":100,"Index":0},
    8:{"Nama":"Manis","Aspek":"Sehat","Kualitas":1,"Nilai":75,"Index":0},
    9:{"Nama":"Wolfgang","Aspek":"Sehat","Kualitas":3,"Nilai":70,"Index":0},
    10:{"Nama":"Alexander","Aspek":"Sehat","Kualitas":2,"Nilai":100,"Index":0}, 
    11:{"Nama":"Borneo","Aspek":"Sehat","Kualitas":3,"Nilai":30,"Index":0}
}

def isikucing():
    with open("datakucing.json","w") as f:
        json.dump(dictcat,f,indent=4)

def isinilai():
    with open("datanilai.json","w") as f:
        json.dump(dictnilai,f,indent=4)


def tampil(mode):
    if mode==1:
        with open("datakucing.json","r") as f:
            filekucing=json.load(f)
            print(type(filekucing))
            for x in filekucing.items():
                print(x)
    elif mode==2:
        with open("datanilai.json","r") as f:
            filenilai=json.load(f)
            print(type(filenilai))
            for x in filenilai.items():
                print(x)

    elif mode==3:
        for x in dictcat.items():
            print(x)

    elif mode==4:
        for x in dictnilai.items():
            print(x)

    elif mode==5:
        print("Nama : Muhammad Afif Fadhlurrahman")
        print("NIM : 1103210161")
        print("Kelas : TK-45-04")
        print("Data Kucing")

def buatindex():
    for x,y in dictnilai.items():
        nilaiindeks=0
        if y["Kualitas"]==1:
            nilaiindeks=y["Nilai"]
        elif y["Kualitas"]==2:
            nilaiindeks=0.8*y["Nilai"]
        elif y["Kualitas"]==3:
            nilaiindeks=0.7*y["Nilai"]

        if nilaiindeks>=80:
            y["Index"]='A'
        elif nilaiindeks<80 and nilaiindeks>=70:
            y["Index"]='B'
        elif nilaiindeks<70 and nilaiindeks>=55:
            y["Index"]='C'
        elif nilaiindeks<55 and nilaiindeks>=40:
            y["Index"]='D'
        elif nilaiindeks<40:
            y["Index"]='E'

        isinilai()

def hitungna():
    for x,y in dictcat.items():
        jumlahbobot=0
        jumlahaspek=0
        nilaiakhir=0
        for a,b in dictnilai.items():
            if x == b["Nama"]:
                if b["Aspek"]=="Bulu":
                    pengali=5
                    jumlahaspek+=pengali
                elif b["Aspek"]=="Badan":
                    pengali=4
                    jumlahaspek+=pengali
                elif b["Aspek"]=="Sehat":
                    pengali=3
                    jumlahaspek+=pengali

                if b["Index"]=="A":
                    jumlahbobot+=pengali*4
                elif b["Index"]=="B":
                    jumlahbobot+=pengali*3
                elif b["Index"]=="C":
                    jumlahbobot+=pengali*2
                elif b["Index"]=="D":
                    jumlahbobot+=pengali*1
                elif b["Index"]=="E":
                    jumlahbobot+=pengali*0
        nilaiakhir=jumlahbobot/jumlahaspek
        y["nilakhir"]=nilaiakhir
        isikucing()

def isiharga():
    f=open("datakucing.json","r")
    filekucing=json.load(f)
    for x,y in filekucing.items():
        if y["jenis"]=="Persia":
            y["harga"]=y["nilakhir"]*600000
        elif y["jenis"]=="Angora":
            y["harga"]=y["nilakhir"]*500000
        else:
            y["harga"]=y["nilakhir"]*250000
        print(y["harga"])
    with open("datakucing.json","w") as f:
        json.dump(filekucing,f,indent=4)
    tampil(1)



# for x,y in dictcat.items():
#     print(x,y)

# d = json.dumps(dictnilai)
# with open("C:\\Users\Apip\Documents\c\codenlock\PBO\datanilai.txt","w") as f:
#     f.write(s)

# print("\nData Nilai")
# for x,y in dictnilai.items():
#     print(x,y)

# def tampil(pilihan):
#     if pilihan=='a':
#         sFile=open("datakucing.datakucing.txt","r")
#         Isifile=sFile.read()
#         Isifile.replace("'",'"')
#         Lbaris=Isifile.split('\n')
#         for baris in Lbaris:
#             data = json.loads(baris)
#         print(data)
#         sFile.close()
#     elif pilihan=='b':
#         sFile=open("datanilai.txt","r")
#         Isifile=sFile.read()
#         Isifile.replace("'",'"')
#         Lbaris=Isifile.split('\n')
#         for baris in Lbaris:
#             datanilai = json.loads(baris)
#         print(datanilai)
#         sFile.close()
#     elif pilihan=='c':
#         for x,y in dictcat.items():
#             print(x,y)
#     elif pilihan=='d':
#         for x,y in dictnilai.items():
#             print(x,y)
#     elif pilihan=='e':
#         print("Nama : Muhammad Afif Fadhlurrahman")
#         print("NIM : 1103210161")
#         print("Kelas : TK-45-04")
#         print("Data Kucing")

# tampil('a')