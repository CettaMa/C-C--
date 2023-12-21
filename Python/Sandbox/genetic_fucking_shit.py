# algoritma genetika    

# import library yang digunakan
import numpy
import matplotlib as mpl
import matplotlib.pyplot as plt
from numerize import numerize as nz
from tabulate import tabulate

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

# inisialisasi populasi
def inisialisasi_populasi(populasi):
    for x in range(8):
        populasi.append([])
        kro = []
        for _ in range(7):
            kro.append(numpy.random.randint(2,budget))
        for _ in kro:
            populasi[x].append(round((_/sum(kro)*budget),2))
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
            if x < 0 : 
                sum_fitness = [0]
                break
            else : 
                sum_fitness.append((x*y))
        fitness[i].append(sum(sum_fitness))
        i += 1
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
    yang_dituker = []
    yang_ketuker = []
    for x in range(len(realtive_fitness)):
        if cumu_fit[0][x] < rules_selec[0][x]:

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
            pass
    for x,y in zip(yang_dituker,yang_ketuker):
        populasi[x],populasi[y] = populasi[y].copy(),populasi[x].copy()
    pol_fitness = kalkulasi_fitness(population,berat_gaming)

def crossover(populasi):
    prob_cross = numpy.random.uniform(0,1)
    pasangan = []
    i=0
    for x in range(0,len(populasi),2):
        pasangan.append([])
        pasangan[i].append([x,x+1])
        i+=1

    for x in pasangan:
        if numpy.random.uniform(0,1) < prob_cross:
            titik_potong = numpy.random.randint(1,len(populasi[0]))
            offspring1 = populasi[x[0][0]][:titik_potong]+populasi[x[0][1]][titik_potong:]
            offspring2 = populasi[x[0][0]][titik_potong:]+populasi[x[0][1]][:titik_potong]

            #perbaikan nilai
            cumu = 0
            if sum(offspring1)>budget:
                delta_offsprint = abs(sum(offspring1)-budget)
                offspring1 = [x - (delta_offsprint/len(offspring1)) for x in offspring1]
                offspring2 = [x + (delta_offsprint/len(offspring2)) for x in offspring2]
            else : 
                delta_offsprint = abs(sum(offspring1)-budget)
                offspring1 = [x + (delta_offsprint/len(offspring1)) for x in offspring1]
                offspring2 = [x - (delta_offsprint/len(offspring2)) for x in offspring2]
            populasi[x[0][0]] = offspring1
            populasi[x[0][1]] = offspring2
        else : 
            pass 

def mutasi(populasi):
    for x in range(len(populasi)):
        if numpy.random.uniform(0,1) < prob_mutation:
            number = numpy.random.choice(len(populasi)-1,2) 
            populasi[x][number[0]],populasi[x][number[1]] = populasi[x][number[1]],populasi[x][number[0]]
        else : 
            pass

def elitism(populasi,max_fit):
    fitness = kalkulasi_fitness(populasi,berat_gaming)
    populasi[fitness.index(min(fitness))] = max_fit
    fitness = kalkulasi_fitness(populasi,berat_gaming)
    pass
#buat list kosong untuk komponen yang diperlukan
population = []
pol_fitness = []
rel_pol_fitness = []

# buat berat dari setiap kromosom [Desain,Prosesor,Ram,Storage,Layar,Batterai,kartu Grafis]
berat_gaming = [10,70,50,30,40,15,80]

#inisialisasi populasi
if __name__ == "__main__":
    budget = int(input("Masukan Budget Anda :"))
    prob_cross = float(input("Masukan Probability Crossover :"))
    prob_mutation = float(input("Masukan Probability Mutation :"))
    generation = int(input("Masukan Berapa Banyak Generasi yang ingin dijalankan :"))
    inisialisasi_populasi(population)
    ittera = 0
    initial_fitness = []
    while ittera < generation:
        pol_fitness = kalkulasi_fitness(population,berat_gaming)
        k_fitness = population[pol_fitness.index(max(pol_fitness))]
        list(rel_pol_fitness)
        list(pol_fitness)
        seleksi(pol_fitness,population)
        crossover(population)
        pol_fitness=kalkulasi_fitness(population,berat_gaming)
        mutasi(population)
        elitism(population,k_fitness)
        pol_fitness = kalkulasi_fitness(population,berat_gaming)
        if ittera == 0:
            tampil_list_fitt(population,pol_fitness)
            initial_fitness = pol_fitness
        ittera += 1
    tampil_list_fitt(population,pol_fitness)
    plotting = plt.subplot(1,2,1)
    plotting.plot(range(len(initial_fitness)),initial_fitness)
    plotting = plt.subplot(1,2,2)
    plotting.plot(range(len(pol_fitness)),pol_fitness)
    plt.xlabel("Population")
    plt.ylabel("Fitness")
    plt.title("Fitness Population")
    plt.show()