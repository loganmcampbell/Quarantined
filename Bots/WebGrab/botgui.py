# =================================================================================
#   Logan Campbell || loganmcampbell@hotmail.com/ || Computer Science & Engineering
# =================================================================================
# www.github.com/loganmcampbell || www.loganmcampbell.com/
import time
import tkinter as tk
from tkinter import ttk
from bs4 import BeautifulSoup as soup
import requests
import pickle
from sprint import sprint
# INITALIZE WINDOW
window = tk.Tk()
# INTERFACE
window.title("CPU BOT")
window.geometry("500x500")
window.resizable(False, False)
screen_width = window.winfo_screenwidth()
screen_height = window.winfo_screenheight()
window_height = 500
window_width = 500
x_cordinate = int((screen_width / 2) - (window_width / 2))
y_cordinate = int((screen_height / 2) - (window_height / 2))
window.geometry("{}x{}+{}+{}".format(window_width, window_height, x_cordinate, y_cordinate))

ttk.Label(window, text="[COMPUTER :: BOT :: STIMULATOR]").grid(row=1, column=1)
ttk.Label(window, text="enter site here \t").grid(row=2, column=1)

website_entry = tk.Entry(window)
website_entry.grid(row=2, column=2)


def get_site():
    web_info = website_entry.get()
    print("Captured :: [" + web_info + "]")
    ttk.Label(window, text="connecting").grid(row=3, column=1)
    time.sleep(2)
    ttk.Label(window, text=". .").grid(row=3, column=2)
    ttk.Label(window, text="[ x ]").grid(row=3, column=4)
    curr_url = "http://www." + web_info
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
    save_file = open("saved_info.txt", "w")
    words = html.text
    sprint(words)
    save_file.write(words)
    print("[[Information Saved :: File Generated]]")
    # CLOSE SESSION FOR THE CURRENT URL #
    sess.close()
    request.close()
    ttk.Label(window, text="File Generated :: [ complete ]").grid(row=4, column=1)
    ttk.Button(window, text="[ParseTags]", width=20, command=get_tags).grid(row=5, column=3)
    return(web_info)


def get_tags():
    f = open("saved_info.txt", "r")
    print(f.read())

    return


ttk.Button(window, text="[Inspect Site]", width=20, command=get_site).grid(row=3, column=3)

# Start the GUI event loop
window.mainloop()

print("\n end of program")
