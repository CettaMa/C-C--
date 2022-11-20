class spbu():
    def __init__(self,nama_pembeli):
        self.nama=nama_pembeli

    def bensin(self,pertamax,pertalite,pertamaxturbo):
        self.__plite=pertalite
        self.__pmax=pertamax
        self.__pmaxturbo=pertamaxturbo

    def hitung(self,jkendaraan,volumepertalite,volumepertamax,volumepertamaxturbo):
        self.__kendaraan=jkendaraan
        self.__vpertalite=volumepertalite
        self.__vpertamax=volumepertamax
        self.__vpertamaxt=volumepertamaxturbo

    def __harga(self):
        totalharga=(self.__plite*self.__vpertalite)+(self.__pmax*self.__vpertamax)+(self.__pmaxturbo*self.__vpertamaxt)
        return totalharga

    def cek(self):
        tharga=self.__harga()
        print("Kendaraan : \t",self.__kendaraan)
        print("Pertalite : \t",self.__vpertalite)
        print("Pertamax : \t",self.__vpertamax)
        print("Pertamax Turbo :",self.__vpertamaxt)
        print("Total Harga : \t",tharga)

cetta=spbu('cetta')
cetta.hitung(10,25,40,38)
cetta.bensin(12700,7650,17900)
cetta.cek()