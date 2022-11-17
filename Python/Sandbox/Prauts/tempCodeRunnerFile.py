import json

mahasiswa= {
    1 : {"nama": "Budi Banjaran", "nim": 110401, "ipk": 0, "SKSLulus": 0},
    2 : {"nama": "Cici Cianjur", "nim": 110402, "ipk": 0, "SKSLulus": 0},
    3 : {"nama": "Bandung Bondowoso", "nim": 110403, "ipk": 0, "SKSLulus": 0},
    4 : {"nama": "Edi Dermayu", "nim": 110404, "ipk": 0, "SKSLulus": 0},
    5 : {"nama": "Dudi Durudi", "nim": 110405, "ipk": 0, "SKSLulus": 0},
}

nil = {
    1 : {"nim" : 110401, "namamk" : "fisika", "sks" : 3, "uts" : 80, "uas" : 85, "indeks" : "x"},
    2 : {"nim" : 110402, "namamk" : "fisika", "sks" : 3, "uts" : 70, "uas" : 60, "indeks" : "x"},
    3 : {"nim" : 110403, "namamk" : "fisika", "sks" : 3, "uts" : 40, "uas" : 35, "indeks" : "x"},
    4 : {"nim" : 110403, "namamk" : "kalkulus", "sks" : 4, "uts" : 30, "uas" : 30, "indeks" : "x"},
    5 : {"nim" : 110404, "namamk" : "kalkulus", "sks" : 4, "uts" : 60, "uas" : 65, "indeks" : "x"},
    6 : {"nim" : 110405, "namamk" : "kalkulus", "sks" : 4, "uts" : 90, "uas" : 70, "indeks" : "x"},
    7 : {"nim" : 110401, "namamk" : "agama", "sks" : 2, "uts" : 90, "uas" : 80, "indeks" : "x"},
    8 : {"nim" : 110402, "namamk" : "agama", "sks" : 2, "uts" : 75, "uas" : 60, "indeks" : "x"},
    9 : {"nim" : 110401, "namamk" : "binggris", "sks" : 3, "uts" : 80, "uas" : 85, "indeks" : "x"},
    10 : {"nim" : 110402, "namamk" : "binggris", "sks" : 3, "uts" : 70, "uas" : 70, "indeks" : "x"},
    11 : {"nim" : 110403, "namamk" : "binggris", "sks" : 3, "uts" : 90, "uas" : 80, "indeks" : "x"},
    12 : {"nim" : 110404, "namamk" : "binggris", "sks" : 3, "uts" : 30, "uas" : 40, "indeks" : "x"},
    13 : {"nim" : 110405, "namamk" : "binggris", "sks" : 3, "uts" : 60, "uas" : 50, "indeks" : "x"},
}

def simpandict(mode):
    if mode==1:
        with open("Python/Sandbox/Prauts/datamhs.json","w") as filemhs:
            json.dump(mahasiswa,filemhs)
    else :
        with open("Python/Sandbox/Prauts/datanilai.json","w") as filenilai:
            json.dump(nil,filenilai)

def loaddict(mode):
    if mode==1:
        with open("Python/Sandbox/Prauts/datamhs.json","r") as filemhs:
            mahasiswa=json.load(filemhs)
            dict(mahasiswa)
    else :
        with open("Python/Sandbox/Prauts/datanilai.json","r") as filenilai:
            nil=json.load(filenilai)
            dict(nil)

def buatindeks():
    loaddict(2)
    print("\nMenghitung Indeks\t:")
    for x in nil:
        nilaiakhir=float((nil[x]["uts"]*4/10)+(nil[x]["uas"]*6/10))
        if nilaiakhir>=80:
            nil[x]["indeks"]="A"
        elif nilaiakhir>=70 and nilaiakhir<80:
            nil[x]["indeks"]="B"
        elif nilaiakhir>=55 and nilaiakhir<70:
            nil[x]["indeks"]="C"
        elif nilaiakhir>=40 and nilaiakhir<55:
            nil[x]["indeks"]="D"
        elif nilaiakhir<40:
            nil[x]["indeks"]="E"
    tampilkan(2)
    simpandict(2)

def hitungip():
    print("\nMenghitung IPK\t:")
    loaddict(1)
    loaddict(2)

    for keys1,isi1 in mahasiswa.items():
        jmlbobot=0
        jmlsks=0
        skslulus=0
        for keys2,isi2 in nil.items():
            if isi1["nim"]==isi2["nim"]:
                jmlsks+=isi2["sks"]
                if isi2["indeks"]=="A":
                    jmlbobot+=4*isi2["sks"]
                    skslulus+=1
                elif isi2["indeks"]=="B":
                    jmlbobot+=3*isi2["sks"]
                    skslulus+=1
                elif isi2["indeks"]=="C":
                    jmlbobot+=2*isi2["sks"]
                    skslulus+=1
                elif isi2["indeks"]=="D":
                    jmlbobot+=2*isi2["sks"]
                elif isi2["indeks"]=="E":
                    jmlbobot+=isi2["sks"]
            else :
                continue
        ipk=jmlbobot/jmlsks
        mahasiswa[keys1]["ipk"]=ipk
        mahasiswa[keys1]["SKSLulus"]=skslulus
    tampilkan(1)
    simpandict(1)

def urut(mode):
    if mode==1:
        file= open("Python/Sandbox/Prauts/datanilai.json","r")
        filenilai=json.load(file)
        lap=(sorted(filenilai.items(),key=lambda item: item[1]["nim"]))
        nil=dict(lap)
        print("\nMengurutkan Berdasarkan NIM (Acending)")
        for x,y in nil.items():
            print(y["nim"],"\t",y["namamk"],"    \t",y["sks"],"\t",y["uts"],y["uas"],y["indeks"])

        with open("Python/Sandbox/Prauts/datanilai.json","w") as filenil: 
            json.dump(nil,filenil)  

    elif mode==2:
        file= open("Python/Sandbox/Prauts/datanilai.json","r")
        filenilai=json.load(file)
        lap=(sorted(filenilai.items(),reverse=True, key=lambda item: item[1]["nim"]))
        nil=dict(lap)
        print("\nMengurutkan Berdasarkan NIM (Decending)")
        for x,y in nil.items():
            print(y["nim"],"\t",y["namamk"],"    \t",y["sks"],"\t",y["uts"],y["uas"],y["indeks"])

        with open("Python/Sandbox/Prauts/datanilai.json","w") as filenil: 
            json.dump(nil,filenil)  

    elif mode==3:
        with open("Python/Sandbox/Prauts/datamhs.json","r") as filemhs:
            mahasiswa=json.load(filemhs)
            lap=(sorted(mahasiswa.items(),reverse=True, key=lambda x: x[1]['ipk']))
            mahasiswa=dict(lap)
            print("\nMengurutkan Berdasarkan IPK")
            for x,y in mahasiswa.items():
                print(y["nim"],"\t",y["nama"],"    \t","%.2f" %y["ipk"],"\t",y["SKSLulus"])
        with open("Python/Sandbox/Prauts/datamhs.json","w") as filemhs: 
            json.dump(mahasiswa,filemhs)  
        

    elif mode==4:
        file= open("Python/Sandbox/Prauts/datamhs.json","r")
        filemhs=json.load(file)
        lap=(sorted(filemhs.items(), key=lambda item:item[1]["SKSLulus"]))
        mahasiswa=dict(lap)
        print("\nMengurutkan Berdasarkan SKS Lulus")
        for x,y in mahasiswa.items():
            print(y["nim"],"\t",y["nama"],"    \t","%.2f" %y["ipk"],"\t",y["SKSLulus"])
        
        with open("Python/Sandbox/Prauts/datamhs.json","w") as filemhs: 
            json.dump(mahasiswa,filemhs)  

def peringkat():
    urut(3)
    file= open("Python/Sandbox/Prauts/datamhs.json","r")
    mahasiswa=json.load(file)
    print("Peringkat Mahasiswa\t:")
    i=1
    for x,y in mahasiswa.items():
        print(x,"\t",y["nim"],"\t",y["nama"],"    \t","%.2f" %y["ipk"])
        i+=1
        if i>3:
            break

def tampilkan(mode):
    if mode == 1:
        loaddict(1)
        for x,y in mahasiswa.items():
            print(y["nim"],"\t",y["nama"],"   \t","%.2f"%y["ipk"],"\t",y["SKSLulus"])
    elif mode == 2:
        loaddict(2)
        for x,y in nil.items():
            print(y["nim"],"\t",y["namamk"],"   \t",y["sks"],"\t",y["uts"],"\t",y["uas"],"\t",y["indeks"])

buatindeks()
hitungip()
peringkat()
