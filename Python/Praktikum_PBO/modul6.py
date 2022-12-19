import requests
from bs4 import BeautifulSoup

req = requests.get("https://scrape.jeyy.xyz/")
soup= BeautifulSoup(req.content,"lxml")

header = soup.find("h2")
print(header.text)