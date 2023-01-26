# Import semua modul yang dibutuhkan
from bs4 import BeautifulSoup as bs
import time
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.firefox.options import Options
from selenium.webdriver.firefox.firefox_profile import FirefoxProfile
from tabulate import tabulate
from cleantext import clean

#Melakukan persiapan untuk menginisialisasi webdriver
option=Options()
option.add_argument("--profile")
option.add_argument(r'C:\\Users\\cetta\\AppData\\Roaming\\Mozilla\\Firefox\\Profiles\\17i4qof6.bot')
driver=webdriver.Firefox(options=option)
driver.get("https://indopremier.com/#ipot/app/broker-summary")
time.sleep(8)
username=driver.find_element(By.ID,"input-login-username")
password=driver.find_element(By.ID,"input-login-password")
username.send_keys("BUHR68")
password.send_keys("HL2nBzIq")
login=driver.find_element(By.CSS_SELECTOR,".proces-fn").click()
time.sleep(5)
Lstock=[]
mainpage=driver.find_element(By.CSS_SELECTOR,"div.page-content:nth-child(8)")
for x in range(0,6):
    mainpage.send_keys(Keys.PAGE_DOWN)
    time.sleep(2)
for x in range(0,6):
    mainpage.send_keys(Keys.PAGE_UP)

# for x in range(1,31):
#     space=driver.find_element(By.CSS_SELECTOR,"div.column:nth-child("+str(x)+") > div:nth-child(2) > div:nth-child(3)").send_keys(Keys.PAGE_DOWN)
#     time.sleep(0.3)
#     button=driver.find_element(By.CSS_SELECTOR,"div.column:nth-child("+str(x)+") > div:nth-child(2) > div:nth-child(3) > table:nth-child(2) > tfoot:nth-child(3) > tr:nth-child(1) > td:nth-child(1) > a:nth-child(1)")
#     driver.execute_script("arguments[0].click();", button)
section=driver.find_element(By.CSS_SELECTOR,"section.row").get_attribute('innerHTML')
soup=bs(section,'lxml')
lstock=soup.find_all('div',class_="column col-100 medium-50 large-33 xlarge-25")
print(len(lstock))
lstock.pop(-1)
lstock.pop(-1)
for x in lstock:
    buy=[]
    sell=[]
    stock_code=x.find('span',class_="ob-sec margin-right-half pointer").text
    last=x.find('div',class_="ob-last").text
    value=x.find_all('div',class_="value-brokersummary")
    tval=value[0].text
    fnval=value[1].text
    tlot=value[2].text
    avg=value[3].text
    print("\n",stock_code,last,"\n")
    print("T.VAL :",tval,"F.NVAL :",fnval,"T.LOT :",tlot,"AVG :",avg)
    table=x.find_all('tbody')
    for x in table[0].find_all("tr"):
        data=[]
        for y in x:
            data.append(y.text)
        buy.append(data)
    print("BUY Data : ")
    for y in buy:
        print(y)
    for x in table[2].find_all("tr"):
        data=[]
        for y in x:
            data.append(y.text)
        sell.append(data)
    print("SELL Data : ")
    for y in buy:
        print(y)
    with open("scrape.txt","a+") as file:   
        file.write(stock_code+"\t"+last+"\n")
        file.write("T.VAL : "+tval+" F.NVAL : "+fnval+" T.LOT : "+tlot+" AVG : "+avg+"\n")
        file.write("data buy : "+"\n")
        file.write(str(buy)+"\n")
        file.write("data sell : "+"\n")
        file.write(str(sell)+"\n\n")
