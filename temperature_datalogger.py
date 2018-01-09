import os
import datetime
import glob
import time
import sys
import gspread

os.system('modprobe w1-gpio')
os.system('modprobe w1-therm')
lst=[]
temp_log='/mnt/temp.csv'
lst.append('/sys/bus/w1/devices/28-000003500339/w1_slave')
date_log=str(datetime.datetime.now())


googleSheetsUsername = 'loggertemperature@gmail.com'
googleSheetsPassword = 't3mp3r4tur3'
googleSheetsWorksheet = 'Temperature Log'


def get_temp(device):
	f=open(device,'r')
        data=f.readlines()
        f.close()
        deg_f=''
        if data[0].strip()[-3:]=='YES':
                temp=data[1][data[1].find('t=')+2:]
                try:
                        if float(temp)==0:
                                deg_f=32

			else:
                                deg_f=float(temp)/1000
				
                except:
                        print "Error with t=",temp
                        pass
        return deg_f

while 1:
	for device in lst:
		device_name=device.split('/')[5]
		with open(temp_log,'a') as f:
                	s=device_name+','
                	s+=date_log+','
			s+=str(get_temp(device))
               		temp_value=str(get_temp(device))
                	print(s+'degree celcuis'+'\r\n')
			googleConnection = gspread.login(googleSheetsUsername, googleSheetsPassword)
			googleWorksheet = googleConnection.open(googleSheetsWorksheet).sheet1
			firstColumnValues = googleWorksheet.col_values(1)
			newRow = len(firstColumnValues) + 1
			googleWorksheet.insert_row([date_log[:10],date_log[11:18],temp_value,device_name], newRow);
			f.write(s)

	time.sleep(1)



