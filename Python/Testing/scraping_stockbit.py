import requests
from bs4 import BeautifulSoup as bs
import time

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.firefox.options import Options
from selenium.webdriver.firefox.firefox_profile import FirefoxProfile

option=Options()
option.add_argument("--profile")
option.add_argument(r'C:\\Users\\cetta\\AppData\\Roaming\\Mozilla\\Firefox\\Profiles\\17i4qof6.bot')

driver=webdriver.Firefox(options=option)

driver.get("https://stockbit.com/#/stream")
time.sleep(5)
req= requests.get(driver.current_url)
soup=bs(req.content,"lxml")
driver.quit()
chat=soup.find("div",id="app-react")
print(chat)
# for x in chat:
#     print(x.text)
# with open("Python/Testing/scrapstockbit.txt","a+") as file:
#     file.write(str(soup))