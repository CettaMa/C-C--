import requests
from bs4 import BeautifulSoup

url="https://www.cnnindonesia.com/otomotif/20221117090847-579-874904/ktt-g20-ditutup-ratusan-mobil-listrik-bakal-dikembalikan"
#membuat request
req = requests.get(url)
parsed_html= BeautifulSoup(req.content,'html.parser')
print(parsed_html.prettify())
print(parsed_html.title.text)