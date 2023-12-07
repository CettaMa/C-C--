class mobil():
    def __init__(self,nama,tahun,bahanBakar):
        self.nama=nama
        self.tahun=tahun
        self.bahanBakar=bahanBakar
        self._jRoda=4

    def tampilInfo(self):
        print("\nNama mobil :{}\nTahun :{}\nBahan Bakar :{}\n".format(self.nama,self.tahun,self.bahanBakar))

mbim=mobil("corolla",2019,"Bensin")
mbim.tampilInfo()

class mobilBekas(mobil):
    def __init__(self,nama,tahun,bahanBakar):
        super().__init__(nama,tahun,bahanBakar)
        self.__grade="\t"

    @property
    def grade(self):
        pass
    
    @grade.setter
    def grade(self, grade):
        self.__grade=grade
    
    @grade.getter
    def grade(self):
        return self.__grade

Mobil=mobilBekas("lexus",2003,"bensin")
Mobil.grade= "tabrak"
Mobil.tampilInfo()
print("Grade : {}".format(Mobil.grade))


print(Mobil._jRoda)
