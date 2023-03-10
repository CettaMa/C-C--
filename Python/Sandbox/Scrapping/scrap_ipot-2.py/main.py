from bs4 import BeautifulSoup as bs
import time
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import requests
import nltk
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize

haram_words=["'","-",".","Ipotnews","(",")",",","``","''"]
stop=set(stopwords.words('indonesian'))

# page=input("Halaman? : ")
page=1
driver=webdriver.Edge()
driver.get("https://www.ipotnews.com/ipotnews/newsSmartSearch.php?code=ADRO")
driver.execute_script("smartSearchSwitchPage('ADRO',"+str(page)+");")
time.sleep(3)
html=driver.page_source
soup=bs(html,"lxml")
soup=soup.find('div',class_="listMoreLeft smartSearch")
listlink=[]
for x in soup.find_all('a'):
    listlink.append("https://www.ipotnews.com/ipotnews/"+x.get('href').replace(" ","%20"))

for x in listlink[:1]:
    req=requests.get(x)
    req=bs(req.content,"lxml")
    req=req.find("article")
    artikel=req.text.replace("Ipotnews","").replace("Sumber : Admin","")
    artikel=word_tokenize(artikel)
    artikel_nostop=[w for w in artikel if not w in stop]
    artikel_filter=[w for w in artikel_nostop if not w in haram_words]
    print(artikel_filter)