from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from bs4 import BeautifulSoup
import json
import csv

# Pedimos al usuario lo que quiere mostrar y lo guardamos en la variabe search_query
search_query = input("¿Qué quieres buscar? ")

# Definimos la ruta hacia el ChromeDriver
chromedriver_path = "C:/Users/antnavarro/Downloads/chromedriver/chromedriver.exe"

# Definimos la query de busqueda y la url de Amazon.es
url = "https://www.amazon.es/"

# Establecemos la conexión con el driver de Chrome
options = webdriver.ChromeOptions()
options.add_argument("--headless")
driver = webdriver.Chrome(executable_path=chromedriver_path, options=options)

# Abrimos la página de Amazon.es
driver.get(url)

# Esperamos a que aparezca el campo de búsqueda
wait = WebDriverWait(driver, 10)
search_box = wait.until(EC.presence_of_element_located((By.ID, "twotabsearchtextbox")))

# Introducimos la búsqueda y la enviamos
search_box.send_keys(search_query)
search_box.submit()

# Esperamos a que la página de resultados cargue completamente
wait.until(EC.presence_of_element_located((By.ID, "search")))

# Parseamos el HTML de la página
soup = BeautifulSoup(driver.page_source, "html.parser")

# Guardamos en el array laptops la información de los laptops
laptops = []
for laptop in soup.find_all("div", {"class": "s-result-item"}):
    try:
        name = laptop.find("h2", {"class": "a-size-mini"}).text.strip().replace(",", ".")
        price = laptop.find("span", {"class": "a-price-whole"}).text.strip().replace(",", ".")
        rating = laptop.find("span", {"class": "a-icon-alt"}).text.strip().replace(",", ".")
        link = laptop.find("a", {"class": "a-link-normal"}).get("href")
        laptops.append({"name": name, "price": price, "rating": rating, "link": url[:-1] + link})
    except:
        continue

# Guardamos la información en el archivo amazon.json
with open("outputs/" + search_query + ".json", "w") as file:
    json.dump(laptops, file)

# Guardamos la información en csv también
with open("outputs/" + search_query + ".csv", "w", newline="", encoding="utf-8") as file:
    writer = csv.writer(file)
    writer.writerow(["Name", "Price", "Rating", "Link"])
    for laptop in laptops:
        writer.writerow([laptop["name"], laptop["price"], laptop["rating"], laptop["link"].replace(",", "_")])

# Cerramos la conexión con el driver
driver.close()