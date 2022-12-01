import requests
from bs4 import BeautifulSoup
import time

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys

url="https://stockbit.com/#/stream"
driver=webdriver.Chrome(executable_path='./chromedriver')
driver.get(url)

