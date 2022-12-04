import mysql.connector

database=mysql.connector.connect(
    host="localhost",
    user="root",
    password="",
    database="alpha"
)
cursor=database.cursor()
sql="INSERT INTO car (nama,mesin) VALUES (%s,%s)"
isi=[
    ("supra","2jz"),
    ("corvette","ls"),
    ("skyline","rb26")
]

for x in isi:
    cursor.execute(sql,x)
    database.commit()

print("berhasil menambahkan",len(isi),"data")
print(isi)
update="UPDATE car SET nama=%s, mesin=%s WHERE id=%s"
isi_update=("rx8","renesis","2")
print("meng-update data dengan variabel",isi_update)

cursor.execute(update,isi_update)
database.commit()

