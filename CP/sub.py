from cgitb import html
import json
from operator import index
import pdfkit
import os
from PyPDF2 import PdfFileMerger
import requests

def merge():
    dir = os.getcwd()
    merger = PdfFileMerger()
    for item in os.listdir(dir):
        if(item.endswith('pdf')):
            merger.append(item)
    merger.write('Rander_Complete.pdf');
    merger.close();

merge()
