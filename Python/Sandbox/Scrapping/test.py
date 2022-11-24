import requests
from bs4 import BeautifulSoup
import time

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys

pointer="//*[@id=\"content\"]/div/div[1]/div/div[1]/article["

artikel={}

def parser_para():

    for page in range(1,6):
        newest=driver.find_element(By.XPATH, pointer + str(page)+"]/a")
        newest.click()
        req=requests.get(driver.current_url)
        soup= BeautifulSoup(req.content,'html.parser')
        s = soup.find('div',class_='detail_text')
        content = s.find_all('p')
        artikel[page]={"judul": soup.title.text}
        isi=""
        for line in content:
            isi+=line.text
        artikel[page]={"isi": isi}
        
        with open("Python/Sandbox/Scrapping/scrap.txt","a+") as file:
            file.write("\t")
            file.write(soup.title.text)
            file.write("\n")
            for line in content:
                file.write(line.text)
                file.write("\n")
            file.write("\n")

        
        driver.get(main_page_oto)
    
url="https://www.cnnindonesia.com/"

driver=webdriver.Chrome(executable_path='./chromedriver') #menggunakan selenium untuk automasi
driver.get(url)

otomotif=driver.find_element(By.XPATH,'//*[@id="nav_menu"]/li[7]/a')
otomotif.click()

main_page_oto=driver.current_url

parser_para()

for line in artikel.items():
    print(line)