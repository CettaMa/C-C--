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
req=r.get("https://www.ipotnews.com/ipotnews/newsPages.php?level4=topnews#2")
req.html.render(sleep=5)
soup=BeautifulSoup(req.html.raw_html,"html.parser")
container=soup.find("div",id="divMoreNewsPages")
daftarlink=container.find_all('a')
haram_words=["'","-",".","Ipotnews","(",")",",","``","''","%"]
for x in daftarlink:
    if "newsDetail" in x.get('href'):
        lnews.append("https://www.ipotnews.com/ipotnews/"+x.get('href'))

for x in lnews:
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
    dist_word=nltk.FreqDist(token_filter)
    

    with open("Python/Testing/scrap.txt","a+") as file:
        file.write("\t")
        file.write(soup.title.text)
        file.write(article)
        for x in dist_word.most_common(5):
            file.write(str(x))
        file.write("\n\n")

print(len(lnews))