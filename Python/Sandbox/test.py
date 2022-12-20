# Import library yang dibutuhkan
from bs4 import BeautifulSoup
import requests

# Tentukan URL website yang akan Anda scrape
url = 'https://www.zalora.co.id/'

# Ambil data HTML dari website
response = requests.get(url)
soup = BeautifulSoup(response.text, 'html.parser')

# Cari elemen HTML yang ingin Anda ambil
products = soup.find_all('div', class_='product-card')

# Iterasi setiap elemen untuk mengekstrak data yang diinginkan
for product in products:
    product_title = product.find('h3', class_='product-card__name').text
    product_price = product.find('span', class_='product-card__price').text
    product_link = product.find('a', class_='product-card__link')['href']

    print(f'{product_title}: {product_price} ({product_link})')