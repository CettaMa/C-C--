from bs4 import BeautifulSoup as bs
import requests
import re


ipot = requests.get("https://www.indopremier.com/ipotnews/newsPages.php?level4=topnews") 
# ipot = requests.get("https://www.indopremier.com/ipotnews")
#data={'level4':'topnews', 'submit':''}
#ipot = requests.post("https://www.indopremier.com/ipotnews/newsPages.php", data=data) 
#ipot = requests.get("https://www.indopremier.com/ipotnews/nw-saham.php?level4=stocks")
#print(ipot.text)
soup =bs(ipot.content, 'lxml')
content=soup.findAll('dl')

# print(soup)
# for a in link.find_all('a' , href=True):
#     if a['href'].find("newsDetail")>=0: 
#       print("Found the URL:", a['href'],"\n")