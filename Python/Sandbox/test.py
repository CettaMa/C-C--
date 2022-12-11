import json

myrokok = { 
    1 : {"name" : "LA", "Jumlah" : 16, "Jenis" : "Filter", "Hrgsatuan" : 17500},
    2 : {"name" : "Sukun", "Jumlah" : 12, "Jenis" : "Kretek", "Hrgsatuan" : 13500},
    3 : {"name" : "Cuhiba", "Jumlah" : 10, "Jenis" : "Cerutu", "Hrgsatuan" : 350000},
}

class Rokok ():
    def __init__(self,name,jumlah,hrgsatuan,jenis):
        self.name = name
        self.jumlah = jumlah
        self.hrgsatuan = hrgsatuan
        self.jenis = jenis
        

    def macam(self):
        if self.jenis=="Kretek":
            macam="Kesukaan Orang dengan Umur lebih dari 50 tahun";
        if self.jenis=="Cerutu":
            macam="Kesukaan Orang dengan Umur 40 Sampai 49 tahun";
        else : 
            macam="Kesukaan Orang dengan Umur 18 Sampai 39 tahun";
        return macam

    def namerokok(self):
        print("Rokok " + self.name)

    def harga(self):
        return (self.hrgsatuan*self.jumlah)

class kel(Rokok):
    def __init__(self):
    #     for a,b in myrokok.items():
    #         self.name = b["name"]
    #         self.jumlah = b["Jumlah"]
    #         self.hrgsatuan = b["Hrgsatuan"]
        super.__init__(self)
    def dampak(self):
        print(self.name, "Tidak baik untuk kesehatan")

def jberdasar(jberdasar):
  print("Berjenis :",jberdasar)

for x,y in myrokok.items():
    p1=kel(y["name"],y["Jumlah"],y["Hrgsatuan"],y["Jenis"])