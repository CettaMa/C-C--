class car:
    def __init__(self,name,year,transmission,color):
        self.name = name
        self.year = year
        self.transmission = transmission
        self.color=color

again=True

name=input("Masukan nama mobil anda\t:")
year=input("Masukan tahun mobil anda\t:")
transmission=input("Masukan jenis transmisi mobil anda\t:")
color=input("Masukan warna mobil anda\t:")
car1= car(name,year,transmission,color)

print(car1.name,car1.year,car1.transmission,car1.color)
