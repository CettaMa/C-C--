# algoritma genetika    

# import library yang digunakan
import numpy
import matplotlib as mpl    
import matplotlib.pyplot as plt
from tabulate import tabulate

#ini fungsi buat nampilin populasi
def tampil_list(some_list):
    for x in range(len(some_list)):
        print(x,". ",some_list[x])
    print()

#ini fungsi buat nampilin populasi sama fitnessnya
def tampil_list_fitt(some_list,some_fit):
    print(tabulate(zip(some_list,some_fit),headers=["Kromosom","Fitness"],tablefmt="orgtbl"))
    print()

#nested sum, buat nyari total dari sebuah list yaa
def nested_sum(L):
    total = 0 
    for i in L:
        if isinstance(i, list):  
            total += nested_sum(i)
        else:
            total += i
    return total

# inisialisasi populasi dari algoritma genetika
def inisialisasi_populasi(populasi):
    for x in range(jumlah_k):
        populasi.append([])
        kro = [] #
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
            if x < 0 : # kalo ada gen yang kurang dari 0, fitnessnya langsung 0
                sum_fitness = [0]
                break
            else : 
                sum_fitness.append((x*y)) # ini buat kalkulasi fitnessnya, gen dikali sama beratnya
        fitness[i].append(sum(sum_fitness)) # trus dimasukin ke dalem list fitness
        i += 1
    return fitness

# seleksi dan menghitung fitness kumulatif
def seleksi(fitness,populasi):
    
    
    realtive_fitness = []
    #ini buat ngitung realtive fitness dari tiap kromosom
    for x in (range(len(fitness))):
        realtive_fitness.append([])
        realtive_fitness[x].append(fitness[x][0]/nested_sum(fitness)) # ini rumusnya, fitness / total fitness
    print(f"\nRelative Fitness :")
    tampil_list(realtive_fitness)
    cumu_fit = [] #ini buat fitness kumulatif
    rules_selec = [] #ini buat rules dari tiap kromosom
    i=1
    for x in range(0,len(realtive_fitness)):
        cumu_fit.append([])
        cumu_fit[x] = numpy.cumsum(realtive_fitness[:i]).tolist() # ini buat bikin list kumulatif fitnessnya, indeks sekarang ditambah sama indeks sebelumnya
        i+=1
    cumu_fit = cumu_fit[len(cumu_fit)-1:]
    rules_selec.append([round(numpy.random.uniform(0,1),2) for _ in range(jumlah_k)]) # ini buat roullete wheel nya dari setiap ruless
    print(f"Fitnes Kumulatif\t:\n{cumu_fit}\n\nRules\t\t\t:\n{rules_selec}\n")
    i=0
    yang_dituker = []
    yang_ketuker = []
    for x in range(len(realtive_fitness)):
        if cumu_fit[0][x] < rules_selec[0][x]: #kalo misal rules nya lebih besar dari kumulatif fitnessnya, masukin indeksnya ke list yang_dituker
            yang_dituker.append(x)

    for x in yang_dituker: # ini buat nyari harus dituker sama kromosom yang mana, tergantung dari cumulative fitnessnya
        for y in range(jumlah_k-1):
            if y == 0:
                if rules_selec[0][x] < cumu_fit[0][0]:
                    yang_ketuker.append(0)
            else :
                if rules_selec[0][x] < cumu_fit[0][y+1] and rules_selec[0][x] > cumu_fit[0][y]:
                    yang_ketuker.append(y+1)
    print(tabulate(zip(yang_dituker,yang_ketuker),headers=["Yang Ditukar","Yang Ketukar"],tablefmt="pretty"))
    print(f"Sebelum Diseleksi :")
    tampil_list(populasi)
    for x,y in zip(yang_dituker,yang_ketuker): #ini buat nukernya yang dituker sama yang ketuker
        populasi[x],populasi[y] = populasi[y].copy(),populasi[x].copy()
    print(f"Setelah Diseleksi :")
    tampil_list(populasi)
    pol_fitness = kalkulasi_fitness(population,berat_gaming) # ini itung ulang fitness populasi yang udah dituker

def crossover(populasi):
    print(f"\nProbabilitas Crossover ♾️  : {prob_cross}\n")
    pasangan = []
    i=0
    for x in range(3): #Ini buat bikin pasangan pasangannya, bikin 3 pasangan
        pasangan.append([])
        pasangan[i].append(numpy.random.choice(jumlah_k,2,replace=False))
        i+=1

    for x in pasangan:
        if numpy.random.uniform(0,1) < prob_cross: # kalo rules nya lebih kecil daripada propability Crossover, pasanngan bakal di kawinin, yeyyy kawinnnn
            print(f"Kawin Antara {x[0][0]} dan {x[0][1]} !!\n")
            titik_potong = numpy.random.randint(1,len(populasi[0])-1) #bangkitin bilangan random buat titik potong gen
            offspring1 = populasi[x[0][0]][:titik_potong]+populasi[x[0][1]][titik_potong:] #ngambil anak anak 1
            offspring2 = populasi[x[0][0]][titik_potong:]+populasi[x[0][1]][:titik_potong] #ngambil buat anak 2
            #perbaikan nilai
            #kalo nilainya lebih atau kurang dari budget yang ditentuin, kita perbaiki dengan cara nambahin yang kurang ato ngurangin yang lebih 
            print("Sebelum Diperbaiki :")
            print(f"{offspring1} Total = {sum(offspring1)}")
            print(f"{offspring2} Total = {sum(offspring2)}")
            print()
            cumu = 0
            if sum(offspring1)>budget:
                delta_offsprint = abs(sum(offspring1)-budget)
                offspring1 = [x - (delta_offsprint/len(offspring1)) for x in offspring1]
                offspring2 = [x + (delta_offsprint/len(offspring2)) for x in offspring2]
            else : 
                delta_offsprint = abs(sum(offspring1)-budget)
                offspring1 = [x + (delta_offsprint/len(offspring1)) for x in offspring1]
                offspring2 = [x - (delta_offsprint/len(offspring2)) for x in offspring2]
            print("Setelah diperbaiki :")
            print(f"{offspring1} Total = {sum(offspring1)}")
            print(f"{offspring2} Total = {sum(offspring2)}")
            print()
            populasi[x[0][0]] = offspring1 #anak nya masukin ke populasinya
            populasi[x[0][1]] = offspring2 #masukin juga anak ke 2 nya

        else : 
            pass 
    print(F"Hasil Crossover :")
    tampil_list(populasi)

def mutasi(populasi):
    print("Proses Mutasi 🐜  :\n\nSebelum Mutasi :")
    tampil_list(populasi)
    for x in range(jumlah_k):
        if numpy.random.uniform(0,1) < prob_mutation:
            number = numpy.random.choice(7-1,2,replace=False) #ini buat nyari pasangan gen yang mau dituker
            print(f"Kromosom {x} mengalami mutasi di gen {number[0]} dan  {number[1]}")
            populasi[x][number[0]],populasi[x][number[1]] = populasi[x][number[1]],populasi[x][number[0]] #gen yang tertukar
        else : 
            pass
    print("\nHasil Mutasi :")
    tampil_list(populasi)

def elitism(populasi,max_fit):
    print(f"Proses Elitism 🥇  :\n\nkromosom yang dipilih untuk elitisme : \n{max_fit} \nSebelum Elitisme :\n")
    fitness = kalkulasi_fitness(populasi,berat_gaming) #kalkulasi fitness
    tampil_list_fitt(populasi,fitness)
    populasi[fitness.index(min(fitness))] = max_fit #tuker kromosom yang paling bagus sama kromosom yang paling jelek.
    fitness = kalkulasi_fitness(populasi,berat_gaming) #kalkulasi lagi fitnessnya
    print("Setelah Elitisme : ")
    tampil_list_fitt(populasi,fitness)
    pass

#buat list kosong untuk komponen yang diperlukan
population = []
pol_fitness = []
rel_pol_fitness = []

# buat berat dari setiap kromosom [Desain,Prosesor,Ram,Storage,Layar,Batterai,kartu Grafis]
berat_gaming = [10,70,50,30,40,15,80]

#inisialisasi populasi
if __name__ == "__main__":
    budget = 15#int(input("Masukan Budget Anda :   Juta \x1B[8D"))
    jumlah_k = 7#int(input("Masukan Jumlah kromosom :"))
    generation = 2#int(input("Masukan Berapa Banyak Generasi yang ingin dijalankan :"))
    prob_cross = 0.4#float(input("Masukan Probability Crossover :"))
    prob_mutation = 0.1#float(input("Masukan Probability Mutation :"))
    print()
    inisialisasi_populasi(population)
    ittera = 0
    initial_fitness = []
    while ittera < generation:
        print(f"Generasi ke-{ittera}" )
        print()
        print(f"Kalkulasi Fitness👍 :")
        
        pol_fitness = kalkulasi_fitness(population,berat_gaming)
        tampil_list_fitt(population,pol_fitness)
        k_fitness = population[pol_fitness.index(max(pol_fitness))]
        print(f"Kromosom yang dipilih untuk Elitism adalah : {k_fitness} dengan Index : {pol_fitness.index(max(pol_fitness))}")
        list(rel_pol_fitness) #konvert jadi list
        list(pol_fitness) #ini juga sama ya
        print(f"\nProses Seleksi 📗 :")

        seleksi(pol_fitness,population)
        print(f"\nProses Crossover 🔄 :")
        crossover(population)
        pol_fitness=kalkulasi_fitness(population,berat_gaming)
        mutasi(population)
        elitism(population,k_fitness)
        pol_fitness = kalkulasi_fitness(population,berat_gaming)
        if ittera == 0:
            initial_fitness = pol_fitness
        ittera += 1
    print(f"Kromosom yang dipilih sebagai solusi adalah :\n{population[pol_fitness.index(max(pol_fitness))]}\ndengan fitness :\n{max(pol_fitness)}")
    # tampil_list_fitt(population,pol_fitness)
    # plotting = plt.subplot(1,2,1)
    # plotting.plot(range(len(initial_fitness)),initial_fitness)
    # plotting = plt.subplot(1,2,2)
    # plotting.plot(range(len(pol_fitness)),pol_fitness)
    # plt.xlabel("Population")
    # plt.ylabel("Fitness")
    # plt.title("Fitness Population")
    # plt.show()