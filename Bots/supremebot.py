# =================================================================================
#   Logan Campbell || loganmcampbell@hotmail.com/ || Computer Science & Engineering
# =================================================================================
# www.github.com/loganmcampbell || www.loganmcampbell.com/
# THURSDAY @ 11 AM EST :: (10 AM CST)
from bs4 import BeautifulSoup as soup
import requests
import pickle
from time import sleep
# import random
curr_url = "https://www.supremenewyork.com/shop/new"
# CREATE A SESSION TO DO HTTP CALLS
sess = requests.Session()
request = sess
headers = {'User-Agent': 'Mozilla/5.0 (Windows; U; Windows NT 6.1; en-US; rv:1.9.2.15) Gecko/20110303 Firefox/3.6.15'}
# sleep(random.randint(4, 8))
request = requests.get(curr_url, headers=headers)
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
print("-------------------------------------------------------------------------")
print("completed : " + curr_url + "\t [x]")
print("-------------------------------------------------------------------------")

list_objects = html.find("ul", {"class": "turbolink_scroller"}).findAll("li")
filter = False
links = []
for object in list_objects:
    sleep(.2)
    # filter sold out items [x]
    if (not (object.find("div", {"class": "sold_out_tag"})) and filter):
        print("https://www.supremenewyork.com" + object.find('a')['href'] + "\t [x] sold-out [x]")
    else:
        print("https://www.supremenewyork.com" + object.find('a')['href'])
    links.append("https://www.supremenewyork.com" + (object.find('a')['href']))

# FILTER : [JACKETS, SHIRTS, TOPS-SWEATERS, T-SHIRTS, SWEATSHIRTS, PANTS, HATS, BAGS, ACCESSORIES]

print("\n end of program")
