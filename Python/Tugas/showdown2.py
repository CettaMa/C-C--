from forex_python.converter import CurrencyRates #mengambil kurs rate untuk konversi dollar ke rupiah menggunakan module forex_python
obj_laptop={}
dict_cpu={
    1: {"name" :"Ryzen 6600U", "core" : "6", "base_prices" :229},
    2: {"name" :"Ryzen 6600H", "core" : "6", "base_prices" :299},
    3: {"name" :"Ryzen 6700U", "core" : "8", "base_prices" :329},
    4: {"name" :"Ryzen 6700H", "core" : "8", "base_prices" :399},
    5: {"name" :"Ryzen 6900U", "core" : "12", "base_prices" :429},
    6: {"name" :"Ryzen 6900H", "core" : "12", "base_prices" :549},
    7: {"name" :"Ryzen 6950X", "core" : "16", "base_prices" :699},
    8: {"name" :"Intel Core i5-12500H", "core" : "12", "base_prices" :219},
    9: {"name" :"Intel Core i5-12600H", "core" : "12", "base_prices" :239},
    10: {"name" :"Intel Core i7-12700H", "core" : "20", "base_prices" :359},
    11: {"name" :"Intel Core i7-12800H", "core" : "20","base_prices":449},
    12: {"name" :"Intel Core i9-12900H", "core" : "20","base_prices":529},
}

dict_gpu={
    1: {"name" : "RTX 3050", "base_prices" :249},
    2: {"name" : "RTX 3060", "base_prices" :329},
    3: {"name" : "RTX 3060 Ti", "base_prices" :399},
    4: {"name" : "RTX 3070", "base_prices" :499},
    5: {"name" : "RTX 3070 Ti", "base_prices" : 599},
    6: {"name" : "RTX 3080", "base_prices" :699},
    7: {"name" : "RTX 3080 Ti", "base_prices" :1199},
    8: {"name" : "RTX 3090", "base_prices" :1500},
}

dictlaptop={
    1: {"name" : "Asus TUF","Processor": "Ryzen 6600H", "memory" : 8, "gpu" : "RTX 3050"},
    2: {"name" : "Asus ROG Strix","Processor": "Ryzen 6900H", "memory" : 16, "gpu" : "RTX 3070"},
    3: {"name" : "Lenovo Ideapad Gaming 3","Processor": "Ryzen 6600H", "memory" : 8, "gpu" : "RTX 3060"},
    4: {"name" : "Lenovo Legion 7","Processor": "Intel Core i7-12700H", "memory" : 16, "gpu" : "RTX 3080"},
    5: {"name" : "HP Victus","Processor": "Intel Core i5-12600H", "memory" : 8, "gpu" : "RTX 3050"},
    6: {"name" : "HP Omen","Processor": "Ryzen 6700H", "memory" : 16, "gpu" : "RTX 3070"},
    7: {"name" : "Asus Zenbook","Processor": "Intel Core i7-12800H", "memory" : 32},
    8: {"name" : "MSI Summit","Processor": "Ryzen 6900H", "memory" : 32},
    9: {"name" : "Lenovo Yoga","Processor": "Intel Core i7-12700H", "memory" : 32},
    10: {"name" : "HP Spectre","Processor": "Ryzen 6900U", "memory" : 32},
    11: {"name" : "Asus Vivobook","Processor": "Ryzen 6600U", "memory" : 16},
    12: {"name" : "MSI Prestige","Processor": "Intel Core i5-12600H", "memory" : 16},
    13: {"name" : "MSI Raider","Processor": "Intel Core i9-12900H", "memory" : 64,"gpu" :"RTX 3090"},
}

c=CurrencyRates()
class laptop():
    def __init__(self,name,processor,memory, prices):
        self.name = name
        self.processor = processor
        self.memory = memory
        self.__prices = prices

    def tampilkan(self):
        print("Nama\t\t  :",self.name)
        print("Tipe Laptop\t  : Laptop Offices")
        print("Processor\t  :",self.processor)
        print("Memory\t\t  :",self.memory,"GB")
        print("Harga\t\t  : Rp.",self.__prices,"\n")

class laptop_gaming(laptop):
    def __init__(self,name,processor,memory,gpu,prices):
        self.name = name
        self.processor = processor
        self.memory = memory
        self.gpu = gpu
        self.__prices = prices

    def tampilkan(self):
        print("Nama\t\t  :",self.name)
        print("Tipe Laptop\t  : Laptop Gaming")
        print("Processor\t  :",self.processor)
        print("Memory\t\t  :",self.memory,"GB")
        print("Kartu Grafis\t  :",self.gpu)
        print("Harga\t\t  : Rp.",self.__prices,"\n")

#konsolidasi 
for x,y in dictlaptop.items():
    totalprice=0
    for j,k in dict_cpu.items():
        if y["Processor"]==k["name"]:
            totalprice+=k["base_prices"]
        else :
            pass
    if "gpu" in dictlaptop[x]:
        for j,k in dict_gpu.items():
            if y["gpu"]==k["name"]:
                totalprice+=k["base_prices"]
        else :
            pass
    else:
        pass
    totalprice+=y["memory"]*4
    totalprice=c.convert('USD','IDR',totalprice)
    dictlaptop[x]["prices"]=int(totalprice)

for x,y in dictlaptop.items():
    if "gpu" in dictlaptop[x]:
        obj_laptop[x]=laptop_gaming(y["name"],y["Processor"],y["memory"],y["gpu"],y["prices"])
    else :
        obj_laptop[x]=laptop(y["name"],y["Processor"],y["memory"],y["prices"])

for x in range(1,len(obj_laptop)+1):
    obj_laptop[x].tampilkan()

with open("Python/Tugas/laptop.txt","w") as f:
    for x,y in dictlaptop.items():
        if "gpu" in dictlaptop[x]:
            f.write(str(x)+","+y["name"]+","+y["Processor"]+","+str(y["memory"])+","+str(y["gpu"])+","+str(y["prices"])+"\n")
        else :
            f.write(str(x)+","+y["name"]+","+y["Processor"]+","+str(y["memory"])+","+str(y["prices"])+"\n")

#urut dari harga termurah
print("Diurutkan berdasarkan Harga termurah \t:")
urut=sorted(dictlaptop.items(),key=lambda x:x[1]["prices"])
for x in urut:
    print(x)

#urut dari nama
print("\nDiurutkan berdasarkan Nama \t:")
urut=sorted(dictlaptop.items(),key=lambda x:x[1]["name"])
for x in urut:
    print(x)