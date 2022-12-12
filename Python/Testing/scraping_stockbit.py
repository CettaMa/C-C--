import requests
from bs4 import BeautifulSoup
import time

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys

# url="https://www.ipotnews.com/ipotnews/newsDetail.php?jdl=BEI__Volume_Transaksi_Harian_Selama_Sepekan_Anjlok_22_47__Jadi_24_43_Miliar_Saham&news_id=157972&group_news=IPOTNEWS&news_date=2022-12-11&taging_subtype=INDEKS+INDONESIA&name=&search=y_general&q=IHSG%2CIndeks+Harga+saham+Gabungan%2CJakarta+Composite+Index%2CJCI%2Csaham%2Cemiten%2C&halaman=1"
# driver=webdriver.Chrome(executable_path='./chromedriver')
# driver.get(url)

req=requests.get("https://www.ipotnews.com/ipotnews/newsDetail.php?jdl=BEI__Volume_Transaksi_Harian_Selama_Sepekan_Anjlok_22_47__Jadi_24_43_Miliar_Saham&news_id=157972&group_news=IPOTNEWS&news_date=2022-12-11&taging_subtype=INDEKS+INDONESIA&name=&search=y_general&q=IHSG%2CIndeks+Harga+saham+Gabungan%2CJakarta+Composite+Index%2CJCI%2Csaham%2Cemiten%2C&halaman=1")
soup=BeautifulSoup(req.content,'lxml')
paragraft=soup.find('article')


