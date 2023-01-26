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
driver.get("https://indopremier.com/#ipot/app/order-book")
time.sleep(8)
username=driver.find_element(By.ID,"input-login-username")
password=driver.find_element(By.ID,"input-login-password")
username.send_keys("BUHR68")
password.send_keys("HL2nBzIq")
login=driver.find_element(By.CSS_SELECTOR,".proces-fn").click()
time.sleep(2)
Lstock=[]
while True:
    print("Masukan kode stock yang ingin discrap (kosongkan jika tidak perlu/selesai menambahkan)")
    tambah=input(" : ")
    if tambah is "":
        break
    else:
        Lstock.append(tambah)


#inisialisasi DICT
#auto log in webdriver
def scrap(loop):
    
    driver.refresh()
    time.sleep(10)
    print(loop)
    mainpage=driver.find_element(By.CSS_SELECTOR,"div.page-content:nth-child(8)")
    mainpage.send_keys(Keys.PAGE_DOWN)
    time.sleep(3)
    mainpage.send_keys(Keys.PAGE_DOWN)
    time.sleep(3)
    mainpage.send_keys(Keys.PAGE_DOWN)
    time.sleep(3)
    mainpage.send_keys(Keys.PAGE_DOWN)
    time.sleep(3)
    mainpage.send_keys(Keys.PAGE_DOWN)
    time.sleep(3)
    mainpage.send_keys(Keys.PAGE_DOWN)
    time.sleep(3)
    html=driver.page_source
    soup=bs(html,'lxml')
    stock=soup.find_all("div",class_="column col-100 medium-50 large-33 xxlarge-25 xxxlarge-20")
    stock_info=[]
    for x in range(0,5):
        stock_info.append([])
    stock_header=[]
    for x in range(0,9):
        stock_header.append([])

    for x in stock:
        if x.find("span",class_="ob-sec margin-right-half pointer") == None: x.clear()
        else:
            n=0
            for i in range(0,5):
                stock_info[i]=[]
            for i in range(0,9):
                stock_header[i]=[]
            stock_code=x.find("span",class_="ob-sec margin-right-half pointer").get_text()
            stock_name=x.find("div",class_="ob-secname text-ellipsis").get_text()
            last=x.find("div",class_="ob-last text-align-right nowrap").get_text()
            for y in x.find("div",class_="row no-gap"):
                for i,j in y.find_all("div",class_="mi"):
                    stock_header[n]=j.text
                    n+=1
            n=0
            bidlot=x.find_all("div",class_="col-35 ob-value padding-right-half-half")
            ob=x.find("div",class_="ob")
            bidoffer=ob.find_all("span")
            bidoffer.pop(-1)
            bidoffer.pop(-1)
            ldata=[]
            lbidlot=[]
            lofflot=[]
            lbid=[]
            loffer=[]

            for x in bidlot:
                ldata.append(x.get_text())
            for x in ldata[0:5]:
                lbidlot.append(x)
            for x in ldata[5:10]:
                lofflot.append(x)
            ldata=[]
            for x in bidoffer:
                if x.text == "" :
                    pass
                else : 
                    ldata.append(x.get_text()) 
            for x in bidoffer[0:11]:
                ldata.append(x.get_text())
            for x in ldata[0:5]:
                lbid.append(x)
            for x in ldata[5:10]:
                loffer.append(x)
            with open("Python/Sandbox/Scrapping/scrap_indo/output"+str(loop)+".txt","a+") as file_sum:
                tulis='{ "saham" : "'+stock_code+'","last":"'+last+'","prev":"'+stock_header[0]+'","chg":"'+stock_header[1]
                tulis=tulis+',"pchg":"'+stock_header[2]+'","open":"'+stock_header[3]+'","high":"'+stock_header[4]+'","low":"'+stock_header[5]
                tulis=tulis+',"vol":"'+stock_header[6]+',"val":"'+stock_header[7]+',"avg":"'+stock_header[8]+',"tbv":"'+ldata[10]
                tulis=tulis+',"tov":"'+ldata[11]
                tulis=tulis+',"bvol0":"'+lbidlot[0]+',"bprice0":"'+lbid[0]+',"bvol1":"'+lbidlot[1]+',"bprice1":"'+lbid[1]
                tulis=tulis+',"bvol2":"'+lbidlot[2]+',"bprice2":"'+lbid[2]+',"bvol3":"'+lbidlot[3]+',"bprice3":"'+lbid[3]
                tulis=tulis+',"bvol4":"'+lbidlot[4]+',"bprice4":"'+lbid[4]
                tulis=tulis+',"ovol0":"'+lofflot[0]+',"oprice0":"'+loffer[0]+',"ovol1":"'+lofflot[1]+',"oprice1":"'+loffer[1]
                tulis=tulis+',"ovol2":"'+lofflot[2]+',"oprice2":"'+loffer[2]+',"ovol3":"'+lofflot[3]+',"oprice3":"'+loffer[3]
                tulis=tulis+',"ovol4":"'+lofflot[4]+',"oprice4":"'+loffer[4]
                tulis=tulis+'","}\n'
                file_sum.write(tulis)
            if stock_code in Lstock:
                pass
            else:
                Lstock.append(stock_code)

def change(lis):
    # stocklist=["SMGR","UNTR","BRPT","GOTO","INDY","ANTM","ICBP","CPIN","BMRI","BBNI","ASII","ARGO","AGII","ADHI","ADRO","GGRM","UNVR","AMRT","ARTO","BFIN","BUKA","EMTK","ERAA","HMSP","INCO","ITMG","MEDC","TOWR","SUNI"]
    #stocklist=["SMGR","UNTR","BRPT","GOTO","INDY","ANTM","ICBP"]
    driver.find_element(By.CSS_SELECTOR,".icon-star-fab").click()
    time.sleep(2)
    for x in range(len(Lstock)-1):
        delete=driver.find_element(By.CSS_SELECTOR,"tr.item:nth-child(1) > td:nth-child(3) > div:nth-child(1) > button:nth-child(2)").click()
        confirm=driver.find_element(By.CSS_SELECTOR,"span.dialog-button:nth-child(2)")
        webdriver.ActionChains(driver).move_to_element(confirm).click().perform()
        time.sleep(0.5)
    for x in (Lstock[:len(Lstock)-1]):
        driver.find_element(By.CSS_SELECTOR,"tr.item:nth-child(1) > td:nth-child(3) > div:nth-child(1) > button:nth-child(1)").click()
        driver.find_element(By.CSS_SELECTOR,".input-search").send_keys(x)
        webdriver.ActionChains(driver).move_to_element(driver.find_element(By.CSS_SELECTOR,"li.padding-vertical-half > div:nth-child(1)")).click().perform()
        time.sleep(0.6)
    webdriver.ActionChains(driver).move_to_element(driver.find_element(By.CSS_SELECTOR,"a.margin-horizontal-half > span:nth-child(1)")).click().perform()

for x in range(0,5):
    scrap(x)
    change(Lstock)
    time.sleep(5)
    Lstock=[]
# looppass=0
# while looppass<10:
#     scrap(looppass)
#     time.sleep(10)
#     looppass+=1
