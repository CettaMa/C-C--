import requests
from bs4 import BeautifulSoup as bs
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time

pointer="//*[@id=\"divMoreNewsPages\"]/div[1]/dl["

url="https://www.ipotnews.com/ipotnews/newsPages.php?level4=topnews#1"
time.sleep(1)
driver=webdriver.Chrome(executable_path='./chromedriver')
driver.get(url)

def parser_hala():
    i=1
    for page in range(1,26):
        listnews=driver.find_element(By.XPATH,pointer+str(page)+"]/dt/a")
        listnews.click()
        time.sleep(2)
        
        req=requests.get(driver.current_url)
        soup= bs(req.content,'lxml')
        paragraft=soup.find('article')
        print(i)
        with open("Python/Testing/scrap.txt","a+") as file:
            file.write("\t")
            file.write(soup.title.text)
            file.write(paragraft.text)
            file.write("\n")

        driver.get(url)
        time.sleep(2)
        i+=1

parser_hala()