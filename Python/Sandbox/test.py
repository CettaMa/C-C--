from bs4 import BeautifulSoup
import requests
from requests_html import HTMLSession

session = HTMLSession()
r = session.get("https://www.uniqlo.com/id/id/men/tops/t-shirt")
r.html.render()