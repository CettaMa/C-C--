from bs4 import BeautifulSoup as bs
import requests
import re


ipot = requests.get("https://www.jobstreet.co.id/id/job/finance-administration-internship-4148781?jobId=jobstreet-id-job-4148781&sectionRank=1&token=0~b9628264-1456-480c-80ae-bf9326fb78a3&fr=SRP%20View%20In%20New%20Tab") 
# ipot = requests.get("https://www.indopremier.com/ipotnews")
#data={'level4':'topnews', 'submit':''}
#ipot = requests.post("https://www.indopremier.com/ipotnews/newsPages.php", data=data) 
#ipot = requests.get("https://www.indopremier.com/ipotnews/nw-saham.php?level4=stocks")
#print(ipot.text)
soup =bs(ipot.content, 'lxml')
requirement=soup.findAll('li')
desc=soup.findAll('span')
print ("dekripsi pekerjaan : ")
for x in requirement:
    print(x.text)
for x in desc:
    print(x.text)

# print(soup)
# for a in link.find_all('a' , href=True):
#     if a['href'].find("newsDetail")>=0: 
#       print("Found the URL:", a['href'],"\n")