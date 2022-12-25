# Import semua modul yang dibutuhkan
import requests
from bs4 import BeautifulSoup as bs
import time
from requests_html import HTMLSession
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.firefox.options import Options
from selenium.webdriver.firefox.firefox_profile import FirefoxProfile
from tabulate import tabulate
from cleantext import clean


#Melakukan persiapan untuk menginisialisasi webdriver
option=Options()
session= HTMLSession()
option.add_argument("--profile")
option.add_argument(r'C:\\Users\\cetta\\AppData\\Roaming\\Mozilla\\Firefox\\Profiles\\17i4qof6.bot')

#inisialisasi webdriver
driver=webdriver.Firefox(options=option)
driver.get("https://stockbit.com/#/stream")

#menuggu web untuk loading
time.sleep(5)

# #scrolling
# last_height = driver.execute_script("return document.body.scrollHeight")

# while True:
#     # Scroll down to bottom
#     driver.execute_script("window.scrollTo(0, document.body.scrollHeight);")

#     # Wait to load page
#     time.sleep(0.5)

#     # Calculate new scroll height and compare with last scroll height
#     new_height = driver.execute_script("return document.body.scrollHeight")
#     if new_height == last_height:
#         break
#     last_height = new_height

driver.execute_script("window.scrollTo(0, 108000)")
time.sleep(10)

#inisialisasi list untuk menyimpan konten scrap kedalam list
stockbit=[]
stockbit.append(["usernames", "date", "Content"])

#scrapping
req=driver.page_source
content=bs(req,"lxml")
timeline=content.find("div", id="stimeline")
stream_box=timeline.find_all("div", class_="streamwithreply")
for x in stream_box:
    stocklist=[]
    username=clean(x.find("div", "stream-username").text, no_emoji= True)
    date=clean(x.find("div", class_="stream-date").text, no_emoji= True)
    isi=clean(x.find("div", class_="stream-text").text, no_emoji= True)
    
    stockbit.append([username,date,isi])
    stocklist.append(x.find_all("a",class_="stock-indicator"))
    reply=x.find("div", class_="stream-reply")
    if reply == None :
        print("pass")
        pass
    else :  
        reply_username=reply.find("div", class_="stream-username").text
        reply_date=reply.find("div", class_="stream-date").text
        reply_isi=reply.find("div", class_="stream-text").text

        # print("Reply :::")
        # print(reply_username,"\n",date,"\n",reply_isi,"\n")

with open("Python/Sandbox/bitbit.txt", "w") as file:
    file.write(str(tabulate(stockbit,headers="firstrow")))
driver.quit()