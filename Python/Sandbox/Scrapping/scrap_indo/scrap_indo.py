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

#auto log in webdriver
driver=webdriver.Firefox(options=option)
driver.get("https://indopremier.com/#ipot/app/order-book")
time.sleep(8)
username=driver.find_element(By.ID,"input-login-username")
password=driver.find_element(By.ID,"input-login-password")
username.send_keys("BUHR68")
password.send_keys("HL2nBzIq")
login=driver.find_element(By.CSS_SELECTOR,".proces-fn").click()
time.sleep(7)
html=driver.page_source
soup=bs(html,'lxml')
stock=soup.find_all("div",class_="column col-100 medium-50 large-33 xxlarge-25 xxxlarge-20")
stock_info=[]
for x in range(0,5):
    stock_info.append([])

for x in stock:
    if x.find("span",class_="ob-sec margin-right-half pointer") == None: x.clear()
    else:
        n=0
        for i in range(0,5):
            stock_info[i]=[]
        stock_code=x.find("span",class_="ob-sec margin-right-half pointer").get_text()
        stock_name=x.find("div",class_="ob-secname text-ellipsis").get_text()
        print("\n",stock_code,stock_name)
        for y in x.find("div",class_="row no-gap"):
            for i,j in y.find_all("div",class_="mi"):
                print(i.text,"\t",j.text)
        bidlot=x.find_all("div",class_="col-35 ob-value padding-right-half-half")
        ob=x.find("div",class_="ob")
        bidoffer=ob.find_all("span")
        bidoffer.pop(-1)
        bidoffer.pop(-1)
        ldata=[]
        
        for x in bidlot:
            ldata.append(x.get_text())
        for x in ldata[0:5]:
            stock_info[n].append(x)
            n+=1
        n=0
        for x in ldata[5:10]:
            stock_info[n].append(x)
            n+=1
        ldata=[]
        for x in bidoffer:
            if x.text == "" :
                pass
            else : 
                ldata.append(x.get_text()) 
        for x in bidoffer[0:11]:
            ldata.append(x.get_text())
        n=0
        for x in ldata[0:5]:
            stock_info[n].append(x)
            n+=1
        n=0
        for x in ldata[5:10]:
            stock_info[n].append(x)
            n+=1   
        print("\n")
        print(tabulate(stock_info,headers=["BIDLOT","OFFLOT","BID","OFFER"]))
        print(ldata[10],"\t\t\t",ldata[11],"\n")

driver.quit()
