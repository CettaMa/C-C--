def hitungan():
    for x,y in dictcat.items():
        jumlahbobot=0
        jumlahaspek=0
        nilaiakhir=0
        for a,b in dictnilai.items():
            if x == b["Nama"]:
                if b["Aspek"] == "Bulu":
                    pengali=5
                    jumlahaspek=pengali
                elif b["Aspek"] == "Badan":
                    pengali=4
                    jumlahaspek=pengali
                elif b["Aspek"] == "Sehat":
                    pengali=3
                    jumlahaspek=pengali

                if b["Index"]=='A':
                    jumlahbobot+=pengali*4
                elif b["Index"]=='B':
                    jumlahbobot+=pengali*3
                elif b["Index"]=='C':
                    jumlahbobot+=pengali*2
                elif b["Index"]=='D':
                    jumlahbobot+=pengali*1
                elif b["Index"]=='E':
                    jumlahbobot+=pengali*0
        nilaiakhir=jumlahbobot/jumlahaspek
        y["nilakhir"]=nilaiakhir
        print(y["nilakhir"])
        isikucing()