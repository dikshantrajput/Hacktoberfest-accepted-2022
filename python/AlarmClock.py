""" Alarm Clock
-------------------------------------
"""

#Importing all the necessary libraries to form the alarm clock

from time import time
from tkinter import *
import datetime
import time
import winsound

def alarm(set_alarm_timer):
    while True:
        time.sleep(1)
        current_time = datetime.datetime.now()
        now = current_time.strftime("%H:%M:%S")
        date = current_time.strftime("%d/%m/%Y")
        print("The Set Date is :",date)
        print(now)
        if now == set_alarm_timer:
            print("Time to wake up")

winsound.PlaySound("sound.wav",winsound.SND_ASYNC)
#

def actual_time():
    set_actual_timer = f"{hour.get()}:{min.get()}:{sec.get()}"
    alarm(set_alarm_timer)