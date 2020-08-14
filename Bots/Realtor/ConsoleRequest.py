import os
import requests
from time import sleep
from bs4 import BeautifulSoup as soup
import random
import shutil
import pickle
import glob

print('\n')
print(" =========================================")
print("| [Process : Data Collecting] [x] Started |")
print(" =========================================")
print('\n')
# OBTAIN THE PATH THE PROGRAM IS IN
fileDir = os.path.dirname(os.path.realpath('__file__'))

# OBTAIN THE PATH TO THE GECKODRIVER
# geckopath = os.path.join(fileDir, 'Drivers/GeckoDriver/geckodriver.exe')
# browser = webdriver.Firefox(executable_path = geckopath)

# SELECt THE FILE FROM DRIVER => SEARCH FOLDER
# LOOK FOR THE TOP 25 TEXT FILE CREATED IN FOLDER "SEARCH"
filename = os.path.join(fileDir, 'Drivers/search/')
print(type(fileDir))
print(type(filename))
print(type(os))

quit()

# OPEN THAT FILE AND OBTAIN THE INFORMATION (CITY,STATE)
with open(filename) as f:
    content = f.readlines()
# REMOVE ALL THE \n
content = [x.strip() for x in content]
f.close()
# print(content)


# CREATE LISTS FOR CITIES AND STATES
state = []
city = []

# PARSE EACH LINE OBTAINED IN THE TOP25.TXT
for x in content:
    word = x.split(",")
    word[0] = word[0].replace(" ", "-")
    city.append(word[0].strip())
    state.append(word[1].strip())

# CREATE DATA FOLDER
    if (os.path.isdir(os.path.join('Data'))):
        # Data/ # for python
        # Data\\ # for windows
        datapath = os.path.join(fileDir, 'Data/')
        shutil.rmtree(datapath)
    else:
        os.mkdir("Data")

# CREATE DIRECTORIES
for x, y in zip(city, state):
    # CREATE FOLDERS IN DATA
    city_state = x.title() + "_" + y.upper()
    # CREATE PATHS FOR DATA
    citystatepath = "/Data/" + x.title() + "_" + y.upper()
    # print(citystatepath)

    # CREATE THE SUBFOLDERS FOR DATA
    os.makedirs(os.path.join('Data', city_state))

# CREATE A LIST FOR THE CUSTOM URLS NEEDED
my_urls = []

# CYCLE THROUGH NEXT URL (MANUALLY)
cycle = True
# CREATE THE URLS AND PLACE INTO URL LIST
for x, y in zip(city, state):
    if (cycle is False):
        break
    # CREATE URL FOR CITY & STATE
    curr_url = 'https://www.realtor.com/soldhomeprices/' + x.upper() + "_" + y.upper()
    # ADD TO LIST OF PLACES TO LOOK AT
    my_urls.append(curr_url)

    # CREATE A SESSION TO DO HTTP CALLS
    sess = requests.Session()
    request = sess
    headers = {'User-Agent': 'Mozilla/5.0 (Windows; U; Windows NT 6.1; en-US; rv:1.9.2.15) Gecko/20110303 Firefox/3.6.15'}
    proxies = {"http": "http://10.10.1.10:3128"}
    # post = requests.post(curr_url)
    # SLEEP BEFORE PROCESSING GET INFOMATION
    sleep(random.randint(4, 8))
    request = requests.get(curr_url, headers=headers, proxies=proxies)
    # DISPLAY REQUEST INFORMATION
    if (request.status_code == 200):
        # print("*")
        # print(request.status_code)
        # print(request.cookies)
        with open('cookiesjar', 'wb') as f:
            pickle.dump(sess.cookies, f)
        # print(request.headers)
        # print("*")
    else:
        # DISPLAY PROBLEMATIC OR REDIRECTIONS
        print(request.status_code)
        # print(request.cookies)
        # print(request.headers)

    result = request
    # CONVERT OBTAIN URL TEXT INFORMATION
    data = result.text
    # CONVERT TEXT TO HTML
    html = soup(data, 'html.parser')

    # print(html)
    # CLOSE SESSION FOR THE CURRENT URL #
    sess.close()
    request.close()
    # CONTINUE TO PARSE NOW #############
    # GENERATE THE ATTEMPT OF GETTING INFORMATION INDICATOR
    print("completed : " + curr_url + "\t [x]")

    # GENERATE BOUNDS FOR HOW MANY PAGES TO SEARCH THROUGH
    pages = html.findAll("span", {"class": "page"})
    firstpage = int(pages[0].text)
    lastpage = int(pages[3].text)
    print("[contains : {" + str(lastpage) + " pages }")
    datafilenumber = 0
    # CREATE A LIST TO OBTAIN INFO OF OBJECT/ITEM/THING
    house = []
    # FIND ALL CONTAINERS WITHIN OUR HTML FILE THAT HAS BEEN OBTAINED
    containers = html.findAll("li", {"class": "component_property-card js-component_property-card"})
    # DISPLAY HOW MANY HTML OBJECTS TO PARSE THROUGH :
    print("number of boxes in page: " + str(len(containers)))
    if(len(containers) <= 0):
        break
    print(os.path)
    datafoldername = x.title() + "_" + y.upper()
    datafilepath = os.path.join(fileDir, "Data/" + x.title() + "_" + y.upper() + "/")
    # CREATE FILE TO CONTAIN DATA OF THE CURRENT PAGE[N]
    print(datafilepath)
    print(datafilepath + x.title() + "~" + y.title() + str(datafilenumber) + ".txt")
    filedataname = datafilepath + x.title() + "~" + y.title() + str(datafilenumber) + ".txt"
    print('--------------------------------------------------------------------------------')
    print("|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|")
    print('--------------------------------------------------------------------------------')
    print("STRUCTURE : [PropertyType, Price, Beds, Baths, Sqft, StAddress, Lotsize, LAddress, Postal, Region, Lat, Long ]")
    filedata = open(filedataname, "w")
    # print("created file data:\t" + str(filedata))
    # START FILTERING
    filtering = True
    for x in containers:
        # cyclecondition = input("Keeping going? [y or n] : ")
        # if (cyclecondition == "y"):
        #     cycle = False
        # else:
        #     break
        # IF FILTERING IS FALSE THEN BREAK OUT OF CONTAINERS LOOP
        if (filtering is False):
            break
        else:
            try:
                solddate = x.find(
                    "span", {"data-label": "property-label-sold"}).text
                solddate = " ".join(solddate.split())
                if solddate.find('november'.title()) >= 0:
                    filtering = True
                elif solddate.find('september'.title()) >= 0:
                    filtering = True
                elif solddate.find('october'.title()) >= 0:
                    filtering = True
                elif solddate.find('august'.title()) >= 0:
                    filtering = True
                else:
                    filtering = False
                    continue
            except:
                solddate = "-"
            house.append(solddate + "*")
            try:
                property_type = x.find("div", {"class": "property-type"}).text
            except:
                property_type = "-"
            house.append(property_type + "*")

            try:
                price = x.find("div", {"class": "price"}).text.strip()
            except:
                price = "-"
            house.append(price + "*")

            try:
                beds = x.find("span", {"class": "data-value meta-beds"}).text
            except:
                beds = "-"
            house.append(beds + "*")

            try:
                baths = x.find("li", {"data-label": "property-meta-baths"}).text
            except:
                baths = ""
            house.append(baths + "*")

            try:
                sqft = x.find("li", {"data-label": "property-meta-sqft"}).text
            except:
                sqft = "-"
            house.append(sqft + "*")

            try:
                street = x.find("span", {"itemprop": "streetAddress"}).text
            except:
                street = "-"
            house.append(street + "*")

            try:
                lotsize = x.find("li", {"data-label": "property-meta-lotsize"}).text
            except:
                lotsize = "-"
            house.append(lotsize + "*")
            try:
                city = x.find("span", {"itemprop": "addressLocality"}).text
            except:
                city = "-"
            house.append(city + "*")

            try:
                postal = x.find("span", {"itemprop": "postalCode"}).text
            except:
                postal = "-"
            house.append(postal + "*")

            try:
                state = x.find("span", {"itemprop": "addressRegion"}).text
            except:
                state = "-"
            house.append(state + "*")

            try:
                longitude = x.find(itemprop="latitude").get("content")
            except:
                longitude = "-"
            house.append(longitude + "*")

            try:
                latitude = x.find(itemprop="longitude").get("content")
            except:
                latitude = "-"
            house.append(latitude + "*")
            informationstring = ''.join(house)
            print(informationstring)
            sleep(.1)
            filedata.write(informationstring + '\n')
            house.clear()
    print("file : " + filedataname + " closed [x]")
    print(datafoldername + " is processed and closed [x]")
    sleep(random.randint(15, 20))
    # CLOSE FILE AFTER WRITING EACH CONTAINERS INFO
    filedata.close()

# CONCENTATE ALL TXT INTO ONE FILE FOR EASIER ACCESS AND IMPLEMENTATION
print("...collecting data & compressing data...")
datafolderpath = os.path.join(fileDir, 'Data/')
with open('result.txt', 'w') as result:
    for root, dirs, files in os.walk(datafolderpath):
        for f in files:
            txtfilepath = os.path.join(root, f)
            if os.path.splitext(txtfilepath)[1] == '.txt':
                for line in open(txtfilepath, 'r'):
                    result.write(line + '\n')

# END OF PROGRAM
clearthings = input("Test clear? yes or no : ")
if clearthings == "yes":
    datapath = os.path.join(fileDir, 'Data')
    shutil.rmtree(datapath)
else:
    print("keep it")

print("completed processes...")
quit()
