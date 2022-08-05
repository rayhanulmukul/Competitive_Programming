from cgitb import html
import json
from operator import index
import pdfkit
import os
from PyPDF2 import PdfFileMerger
import requests

def html_to_pdf(html_page, save_name):
    pdfkit.from_url(html_page, save_name)

def merge():
    dir = os.getcwd()
    merger = PdfFileMerger()
    for item in os.listdir(dir):
        if(item.endswith('pdf')):
            merger.append(item)
    merger.write('Rander_Complete.pdf');
    merger.close();


url = "https://codeforces.com/api/user.status?handle=adnan_toky"

payload={}
headers = {}

response = requests.request("GET", url, headers=headers, data=payload)

data = json.loads(response.text)

tset = set({});

for item in data['result']:
    tset.add(str(item['contestId']) + " " + str(item['problem']['index']))

for item in tset:
    print(item)