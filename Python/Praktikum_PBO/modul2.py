#menghitung jumlah list
print("===LIST===")
list_menu = ["Ayam Geprek","Ayam Bakar","Ikan Asam Manis","Udang Sambal"]
jumlah_menu= len(list_menu)
print("Total Menu :",jumlah_menu)

#Mengurutkan tuple
print("===TUPLE===")
tuple_angka=(9,7,3,5,1,17,11)
print("Urutkan angka berikut :",tuple_angka)
tuple_angka=sorted(tuple_angka)
print("Angka :",tuple_angka)

#konversi tipe data
print("===Koversi Tipe Data===")
list_hape=["Samsung","Apple","Xiaomi","Realme","Huawei"]
set_hape= set(list_hape)
print("SET : ",set_hape)
list_hape= list(set_hape)
print("LIST :",list_hape)