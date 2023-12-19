# algoritma genetika    

# import library yang digunakan
import numpy
import matplotlib as mpl
import matplotlib.pyplot as plt
from numerize import numerize as nz
from tabulate import tabulate

#inisialisasi plot object
plotting = plt.subplot()

def tampil_list(some_list):
    for x in range(len(some_list)):
        print(x,".",some_list[x],"Total = ",sum(some_list[x]))
    print()

def tampil_list_fitt(some_list,some_fit):
    print(tabulate(zip(some_list,some_fit),headers=["Kromosom","Fitness"]))
    print()

#nested sum
def nested_sum(L):
    total = 0 
    for i in L:
        if isinstance(i, list):  
            total += nested_sum(i)
        else:
            total += i
    return total

def alokasi_budget(populasi,fitness):
    i = 0
    for x in (populasi):
        total = 0
        for aspek in x:
            total += aspek*1000000
        i+=1
    print()
    print(tabulate(populasi,headers=["Desain","Prosesor","Ram","Storage","Layar","Batterai","kartu Grafis"]))
    print()

# inisialisasi populasi
def inisialisasi_populasi(populasi):
    for x in range(8):
        populasi.append([])
        kro = []
        for _ in range(7):
            kro.append(numpy.random.randint(2,15))
        for _ in kro:
            populasi[x].append(round((_/sum(kro)*1.5)*10,2))
    print(f"Populasi Awal :")
    for x in populasi:
        print(x,"\ttotal = ",round(sum(x)))
    print()

#mengkalkulasikan fitness dari setiap populasi
def kalkulasi_fitness(populasi,berat,):
    i = 0
    fitness = []
    for individual in populasi:
        fitness.append([])
        sum_fitness=[]
        #dengan berat
        for x,y in zip(individual,berat):
            sum_fitness.append((x*y))
        fitness[i].append(sum(sum_fitness))
        i += 1
    plotting.plot(*range(8),fitness,'o')
    plotting.set_xlabel('population')
    plotting.set_ylabel('fitness')

    return fitness

#seleksi dan menghitung fitness kumulatif
def seleksi(fitness,populasi):
    realtive_fitness = []
    for x in (range(len(fitness))):
        realtive_fitness.append([])
        realtive_fitness[x].append(fitness[x][0]/nested_sum(fitness))
    cumu_fit = []
    rules_selec = []
    i=1
    for x in range(0,len(realtive_fitness)):
        cumu_fit.append([])
        cumu_fit[x] = numpy.cumsum(realtive_fitness[:i]).tolist()
        i+=1
    cumu_fit = cumu_fit[len(cumu_fit)-1:]
    rules_selec.append([round(numpy.random.uniform(0,1),2) for _ in range(8)])

    i=0
    print("Fitness Cummulative : ")
    print(cumu_fit)
    print()
    print("Rules Select : ")
    print(rules_selec)
    yang_dituker = []
    yang_ketuker = []
    for x in range(len(realtive_fitness)):
        if cumu_fit[0][x] < rules_selec[0][x]:
            print("yang dituker",x)
            yang_dituker.append(x)
    
    for x in yang_dituker:
        if rules_selec[0][x] < cumu_fit[0][0]:
            yang_ketuker.append(0)
        elif rules_selec[0][x] < cumu_fit[0][1] and rules_selec[0][x] > cumu_fit[0][0] :
            yang_ketuker.append(1)
        elif rules_selec[0][x] < cumu_fit[0][2] and rules_selec[0][x] > cumu_fit[0][1] :
            yang_ketuker.append(2)
        elif rules_selec[0][x] < cumu_fit[0][3] and rules_selec[0][x] > cumu_fit[0][2] :
            yang_ketuker.append(3)
        elif rules_selec[0][x] < cumu_fit[0][4] and rules_selec[0][x] > cumu_fit[0][3] :
            yang_ketuker.append(4)
        elif rules_selec[0][x] < cumu_fit[0][5] and rules_selec[0][x] > cumu_fit[0][4] :
            yang_ketuker.append(5)
        elif rules_selec[0][x] < cumu_fit[0][6] and rules_selec[0][x] > cumu_fit[0][5] :
            yang_ketuker.append(6)
        elif rules_selec[0][x] < cumu_fit[0][7] and rules_selec[0][x] > cumu_fit[0][6] :
            yang_ketuker.append(7)
        else :
            print("no")

    print(yang_dituker)
    print(yang_ketuker)
    print("\nPopulasi lama :")
    tampil_list(populasi)
    for x,y in zip(yang_dituker,yang_ketuker):
        populasi[x],populasi[y] = populasi[y].copy(),populasi[x].copy()
    print("\nPopulasi baru : ")
    pol_fitness = kalkulasi_fitness(population,berat_gaming)
    tampil_list_fitt(populasi,pol_fitness)

def crossover(populasi):
    prob_cross = numpy.random.uniform(0,1)
    print(prob_cross)
    pasangan = []
    i=0
    for x in range(0,len(populasi),2):
        pasangan.append([])
        pasangan[i].append([x,x+1])
        i+=1
    for x in pasangan:
        if numpy.random.uniform(0,1) < prob_cross:
            titik_potong = numpy.random.randint(1,len(populasi[0]))
            print("titik potong : ",titik_potong)
            offspring1 = populasi[x[0][0]][:titik_potong]+populasi[x[0][1]][titik_potong:]
            offspring2 = populasi[x[0][0]][titik_potong:]+populasi[x[0][1]][:titik_potong]

            #perbaikan nilai
            delta_offsprint1 = abs(sum(offspring1)-15)
            delta_offsprint2 = abs(sum(offspring2)-15)
            if sum(offspring1)>15:
                for y in range(len(offspring1)):
                    offspring1[y] = round(offspring1[y] - round((delta_offsprint1/len(offspring1)),3),3)
                for y in range(len(offspring2)):
                    offspring2[y] = round(offspring2[y] + round((delta_offsprint2/len(offspring2)),3),3)
            else : 
                for y in range(len(offspring1)):
                    offspring1[y] = round(offspring1[y] + round((delta_offsprint1/len(offspring1)),3),3)
                for y in range(len(offspring2)):
                    offspring2[y] = round(offspring2[y] - round((delta_offsprint2/len(offspring2)),3),3)
            populasi[x[0][0]] = offspring1
            populasi[x[0][1]] = offspring2
        else : 
            pass 

#buat list kosong untuk komponen yang diperlukan
population = []
pol_fitness = []
rel_pol_fitness = []

# buat berat dari setiap kromosom [Desain,Prosesor,Ram,Storage,Layar,Batterai,kartu Grafis]
berat_gaming = [10,70,50,30,40,15,80]

#inisialisasi populasi
if __name__ == "__main__":
    inisialisasi_populasi(population)
    ittera = 0
    while ittera < 10:
        print(ittera)
        tampil_list(population)
        pol_fitness = kalkulasi_fitness(population,berat_gaming)
        list(rel_pol_fitness)
        list(pol_fitness)
        print("Fitness Populasi :")
        tampil_list(pol_fitness)
        seleksi(pol_fitness,population)
        crossover(population)
        pol_fitness=kalkulasi_fitness(population,berat_gaming)
        tampil_list(population)
        tampil_list_fitt(population,pol_fitness)
        ittera += 1