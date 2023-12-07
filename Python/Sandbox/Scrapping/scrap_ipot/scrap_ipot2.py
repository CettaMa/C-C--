import requests
from bs4 import BeautifulSoup
from requests_html import HTMLSession
import nltk
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize
import matplotlib.pyplot as plt

import time
lnews=[]
r=HTMLSession()
req=r.get("https://www.ipotnews.com/ipotnews/newsPages.php?level4=topnews#1")
req.html.render(sleep=5)
soup=BeautifulSoup(req.html.raw_html,"html.parser")
container=soup.find("div",id="divMoreNewsPages")
daftarlink=container.find_all('a')
haram_words=["'","-",".","Ipotnews","(",")",",","``","''","%",":","&"]
negatif_word=["penurunan", "melemah","turun","menyusut","lemah","melemahnya","negatif","merosot","kejatuhan","mengecewakan","memburuk","penurunan","anjlok","terjerembab","tergelincir","terendah","melorot","merugi","menderita"]
positif_word=["menguat","kenaikan","bagus","peningkatan","positif","menembus","tertingginya","tinggi","Penguatan","kuat","stabil","tertinggi","melonjak","pertumbuhan","meningkat"]
for x in daftarlink:
    if "newsDetail" in x.get('href'):
        lnews.append("https://www.ipotnews.com/ipotnews/"+x.get('href'))

def write():
    file.write("\t")
    file.write(soup.title.text)
    file.write(article)
    for x in dist_word.most_common(5):
        file.write(str(x))
    file.write("\n\n")

for x in lnews[:25]:
    positif=0
    negatif=0
    xaxis=[]
    yaxis=[]
    print(x,"\n")
    req=requests.get(x)
    soup= BeautifulSoup(req.content,'lxml')
    paragraft=soup.find('article')
    article=""
    for x in paragraft:
        if "Sumber : admin" in x:
            pass
        else :
            article=article+x.text
    article.replace("Ipotnews","")
    token=word_tokenize(article)
    stop_word=set(stopwords.words('indonesian')) 
    token_no_stopwords=[w for w in token if not w in stop_word]
    token_filter=[w for w in token_no_stopwords if not w in haram_words]
    for w in token_filter:
        if w in negatif_word:
            negatif+=1
        elif w in positif_word:
            positif+=1
    dist_word=nltk.FreqDist(token_filter)
    for x in dist_word.most_common(15):
        xaxis.append(x[0])
        yaxis.append(x[1])
    
    if positif>negatif :
        with open("../scrap_positif.txt","a+") as file:
            write()
    elif positif<negatif:
        with open("../scrap_negatif.txt","+a") as file:
            write()
    else :
        with open("../scrap_undecided.txt","+a") as file:
                  write()   
    # plt.plot(xaxis, yaxis)
    # plt.xticks( ha='right')
    # plt.xlabel("Kata")
    # plt.ylabel("Jumlah")
    # plt.show()
    # choice=input("Done? (y/n)")
    # if choice=="y" or choice=="Y":
    #     break 
    # else: 
    #     pass

print(len(lnews))