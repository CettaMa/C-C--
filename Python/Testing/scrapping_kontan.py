from bs4 import BeautifulSoup as bs
import requests

tanggal=input("Masukan tanggal : (Format : ##) :") #input berita tanggal berapa yang ingin discraping e.g 01
bulan=input("Masukan bulan : (Format : ##) :") #e.g 12
tahun=input("Masukan tahun : (Format : ####) :") #e.g 2022
page=0

#mencari jumlah page di dalam website
nav=requests.get("https://www.kontan.co.id/search/indeks?kanal=investasi&tanggal="+str(tanggal)+"&bulan="+str(bulan)+"&tahun="+str(tahun)+"&pos=indeks&per_page="+str(page))
isi_nav=bs(nav.content,"lxml")
list=isi_nav.find('ul', class_="cd-pagination").text
hal=int(list[-7]) #ini jumlah page didalam tanggal tersebut
lnews=[]

for n in range(hal):
    url="https://www.kontan.co.id/search/indeks?kanal=investasi&tanggal="+str(tanggal)+"&bulan="+str(bulan)+"&tahun="+str(tahun)+"&pos=indeks&per_page="+str(page)
    req=requests.get(url)
    content=bs(req.content,'lxml')
    list_berita=content.find('div', class_="list-berita")
    for x in list_berita.find_all('a'):
        if x.get('href')=="//investasi.kontan.co.id":
            pass
        else :
            if "https:"+x.get('href') not in lnews:
                lnews.append("https:"+x.get('href'))
            else:
                pass
        
    page+=20 #saat melihat url dari website, terlihat bahwa website menggunakan interval 20 pada setiap page nya, kenaikan ini digunkan website untuk berpindah page


fl=open("berita.txt","w").close()  
for url in lnews:
  cari = requests.get(url) #"https://investasi.kontan.co.id") #/communication-cable-systems-ccsi-akan-rights-issue-efek-dilusi-maksimal-1453")
  bscari = bs(cari.content,'lxml')
  #soup = bs(berita.content, features="lxml")
  title = bscari.find("div",attrs={"class":"bag-kiri"})
  judul = title.find("h1")
  fl=open("berita.txt","a")
  

  print(judul.text+"***")  #*** digunakan untuk memisahkan judul dengan isi berita
  fl.write(judul.text+"***")
  

  isi = bscari.find("div",attrs={"class":"tmpt-desk-kon"})
  berita = isi.find_all("p")
  #print("berita=",berita)
  #input()

  # Pengolahan text berita
  for data in berita:
    # Ada kalimat diawali "Baca Juga" dan "Cek Berita" untuk info tambahan di berita, yang harus dibuang
    # kalimat tersebut ada di baris a tersendiri, jadi bisa dibuang hanya jika a mengandung :"Baca Juga".
    if data.text.find("Baca Juga") >=0 or data.text.find("Cek Berita") >=0: pass
    else: 
      print(data.text)
      fl.write(data.text)
  fl.write("\n\n")
  fl.close()