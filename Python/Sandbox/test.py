import time
from bs4 import BeautifulSoup as bs
from selenium import webdriver
from selenium.webdriver.edge.options import Options
from requests_html import HTMLSession

# driver=webdriver.Chrome()
s=HTMLSession()
url='https://www.jd.id/'
# driver.get(url)
# time.sleep(3)

html = s.get(url)
html.html.render(sleep=3)
soup = bs(html.html.raw_html,"lxml")
# print(soup)

kategori = soup.find('div',class_ = 'navitems') 
lkategori = []
i = 0
print('Daftar Item :')
for item in kategori.findAll('li')[:4] :
    for link in item.findAll('a') :
        i += 1
        print(f'{i}. {link["title"]}')
        lkategori.append([i,link['title'],'https:'+link['href']])

if soup.findAll('div', class_ = 'w only-app-wrap') != None :
    #deditor = {}
    i = 0
    print('\nPilihan Editor Item :')
    for item in soup.findAll('li', class_ = 'product-recommend-roll') :
        for link in item.findAll('a') :
            i += 1
            print(i,link.find('span', class_ = 'title').text.title(),link.find('div', class_ = 'price-box'),'https:'+link['href'])   