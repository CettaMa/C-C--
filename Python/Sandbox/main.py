from bs4 import BeautifulSoup as bs4
import requests

hotel = []

link = 'https://www.tiket.com/hotel/indonesia/city/bandung-108001534490276290'

headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/108.0.0.0 Safari/537.36'
}
req = requests.get(link,headers=headers)
soup = bs4(req.text,'lxml')
items = soup.findAll('div' , 'hotel-card seo-card')
for i in items:
    if i.find('div','after-price') == None :
        pass
    else : 
        nama = i.find('h3','title ellipsis').text
        alamat = i.find('div','location ellipsis').text
        rate = i.find('div','tiket-rating').text
        harga = i.find('div','after-price').text

    hotel.append ([nama,alamat,rate,harga])

for page in range(2,11):
    links = 'https://www.tiket.com/hotel/indonesia/city/bandung-108001534490276290/page-'+str(page)
    req = requests.get(links,headers=headers)
    req = requests.get(link,headers=headers)
    soup = bs4(req.text,'lxml')
    items = soup.findAll('div' , 'hotel-card seo-card')
    for i in items:
        if i.find('div','after-price') == None :
            pass
        else : 
            nama = i.find('h3','title ellipsis').text
            alamat = i.find('div','location ellipsis').text
            rate = i.find('div','tiket-rating').text
            harga = i.find('div','after-price').text

        hotel.append ([nama,alamat,rate,harga])
        print(page)
# print(len(hotel))
for x in hotel:
    print(x)