#Importing the Google Sheet(gspread) library
import gspread #pip install gspread
from oauth2client.service_account import ServiceAccountCredentials #pip install oauth2client

#importing the Data and Time library
import datetime

#URL library t retrieve the PUBLIC IP Address
from urllib.request import urlopen

#Authenticating the Google spread sheet
scope = ['https://spreadsheets.google.com/feeds']
credentials = ServiceAccountCredentials.from_json_keyfile_name('secret.json',scope)
client = gspread.authorize(credentials)

#Calculating the Date and Present Time
now = datetime.datetime.now()

#Calculating the Public IP for the device connected
my_ip = urlopen('http://ip.42.pl/raw').read()

#Appending the Date,Time & Public IP address of the device
data = [str(now),str(my_ip)]

#Opening the Google SPread Sheet
sheet = client.open('PCLoginData').sheet1

#Calculating the Last ROW
all = sheet.get_all_values()
end_row = len(all) + 1

#Inserting the Data at the LAST ROW
sheet.insert_row(data,end_row)

#Printing the Extracted Data
data = sheet.get_all_records()
print(data)