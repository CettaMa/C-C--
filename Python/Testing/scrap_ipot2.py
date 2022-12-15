import requests
from bs4 import BeautifulSoup as bs
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time

url="https://www.ipotnews.com/ipotnews/newsPages.php?level4=topnews"
driver=webdriver.Chrome(executable_path='./chromedriver')
driver.get(url)

req=requests.get(driver.current_url())
