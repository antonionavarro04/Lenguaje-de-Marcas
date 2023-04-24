from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from bs4 import BeautifulSoup
import json
import csv

# Variable con la página a buscar
termino = "Videos+de+Terror"
url = "https://www.youtube.com/results?search_query=" + termino

# Creamos el driver
chromedriver_path = "C:/Users/antnavarro/Downloads/chromedriver/chromedriver.exe"

options = webdriver.ChromeOptions()
options.add_argument("--headless")
driver = webdriver.Chrome(executable_path=chromedriver_path, options=options)

# Abrimos la página de Amazon.es
driver.get(url)

# Esperamos a que aparezca el campo de búsqueda
wait = WebDriverWait(driver, 10)
search_box = wait.until(EC.presence_of_element_located((By.ID, "dismissible")))

# Parseamos el HTML de la página
soup = BeautifulSoup(driver.page_source, 'html.parser')

# Buscamos los elementos que contienen el nombre y el enlace de los videos
nombres = [] # List to store the names of the videos
links = [] # List to store the links of the videos
for a in soup.findAll('a', href=True, attrs={'class':'yt-simple-endpoint style-scope ytd-video-renderer'}):
    name = a['title']
    nombres.append(name)
    link = "https://www.youtube.com" + a['href']
    links.append(link)

# Guardamos la información en el archivo youtube.csv
with open(termino + '.csv', 'w', newline='', encoding='utf-8') as file:
    writer = csv.writer(file)
    writer.writerow(['Nombre', 'Link'])
    for i in range(len(nombres)):
        writer.writerow([nombres[i], links[i]])

# Guardamos la información en el archivo termino + .json
with open(termino + '.json', 'w', encoding='utf-8') as file:
    data = []
    for i in range(len(nombres)):
        video = {'Nombre': nombres[i], 'Link': links[i]}
        data.append(video)
    json.dump(data, file, ensure_ascii=False)

# Cerramos el driver
driver.quit()