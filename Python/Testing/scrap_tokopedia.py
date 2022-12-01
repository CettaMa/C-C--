import requests
from bs4 import BeautifulSoup
import time

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys

url="https://www.tokopedia.com/search?navsource=&sc=4008&srp_component_id=02.01.00.00&srp_page_id=&srp_page_title=&st=product&q=rtx%203060"

driver=webdriver.Chrome(executable_path='./chromedriver')
driver.get(url)
req=requests.get(driver.current_url)
soup=BeautifulSoup(req.content,'html.parser')
s=soup.find_all('a')


