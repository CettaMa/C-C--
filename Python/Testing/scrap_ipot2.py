import requests
from bs4 import BeautifulSoup
from requests_html import HTMLSession

import time
lnews=[]
r=HTMLSession()
req=r.get("https://www.ipotnews.com/ipotnews/newsPages.php?level4=topnews")
req.html.render(sleep=5)
soup=BeautifulSoup(req.html.raw_html,"html.parser")
container=soup.find("div",id="divMoreNewsPages")
daftarlink=container.find_all('a')
for x in daftarlink:
    if "newsDetail" in x.get('href'):
        lnews.append("https://www.ipotnews.com/ipotnews/"+x.get('href'))

for x in lnews:
    print(x,"\n")
    req=requests.get(x)
    soup= BeautifulSoup(req.content,'lxml')
    paragraft=soup.find('article')
    with open("Python/Testing/scrap.txt","a+") as file:
        file.write("\t")
        file.write(soup.title.text)
        file.write(paragraft.text)
        file.write("\n")

print(len(lnews))