fl=open("berita.txt","w").close()  
# for url in lnews:
#   cari = requests.get(url) #"https://investasi.kontan.co.id") #/communication-cable-systems-ccsi-akan-rights-issue-efek-dilusi-maksimal-1453")
#   bscari = bs(cari.content,'lxml')
#   #soup = bs(berita.content, features="lxml")
#   title = bscari.find("div",attrs={"class":"bag-kiri"})
#   judul = title.find("h1")
#   fl=open("berita.txt","a")
  

#   print(judul.text+"***")  #*** digunakan untuk memisahkan judul dengan isi berita
#   fl.write(judul.text+"***")
  

#   isi = bscari.find("div",attrs={"class":"tmpt-desk-kon"})
#   berita = isi.find_all("p")
#   #print("berita=",berita)
#   #input()

#   # Pengolahan text berita
#   for data in berita:
#     # Ada kalimat diawali "Baca Juga" dan "Cek Berita" untuk info tambahan di berita, yang harus dibuang
#     # kalimat tersebut ada di baris a tersendiri, jadi bisa dibuang hanya jika a mengandung :"Baca Juga".
#     if data.text.find("Baca Juga") >=0 or data.text.find("Cek Berita") >=0: pass
#     else: 
#       print(data.text)
#       fl.write(data.text)
#   fl.write("\n\n")
#   fl.close()