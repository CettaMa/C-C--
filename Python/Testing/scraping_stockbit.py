import requests
from bs4 import BeautifulSoup as bs
import time
from requests_html import HTMLSession

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.firefox.options import Options
from selenium.webdriver.firefox.firefox_profile import FirefoxProfile

option=Options()
session= HTMLSession()
option.add_argument("--profile")
option.add_argument(r'C:\\Users\\cetta\\AppData\\Roaming\\Mozilla\\Firefox\\Profiles\\17i4qof6.bot')

driver=webdriver.Firefox(options=option)

driver.get("https://stockbit.com/#/stream")
time.sleep(5)
req= session.get(driver.current_url)
req.html.render()
# soup=bs(req.content,"lxml")
print(req.html.links)
# driver.quit()
# # for x in chat:
# #     print(x.text)
# with open("Python/Testing/scrapstockbit.txt","a+") as file:
#     file.write(str(soup))