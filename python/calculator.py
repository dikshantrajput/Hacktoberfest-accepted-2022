# -*- coding: utf-8 -*-
"""
Created on Sat Oct 15 01:48:45 2022

@author: Souvik Bhattacharya
"""

from tkinter import *

root = Tk()

def click(event):
    global screen_value
    item = event.widget.cget("text")
    if item == '=':
        try:
            value = eval(screen_value.get())
        except Exception as e:
            value = 'Error'
        screen_value.set(value)
    elif item == 'C':
        try:
            screen_value.set("")
        except Exception as e:
            pass
    elif item == 'Del':
        try:
            value = screen_value.get()
            value = value[:-1]
            screen_value.set(value)
        except Exception as e:
            pass
    else:
        screen_value.set(screen_value.get() + item)

width = 300
height = 400

root.geometry(f'{width}x{height}')
root.minsize(width,height)
root.maxsize(width,height)
root.title('Calculator')
root.config(bg = '#343638')

screen_value = StringVar()
screen_value.set('')
screen = Entry(textvariable = screen_value,font = 'consolas 20',bg = 'lightgrey')
screen.pack(fill = 'both',padx = 5,pady = 15,ipadx = 10,ipady = 10)

f = Frame(root,bg = '#343638')

b = Button(f,text = '7',padx = 20,pady = 10,bg = '#dffad7',font = 'consolas 15')
b.pack(side = 'left',padx = 3,pady = 1)
b.bind("<Button-1>",click)

b = Button(f,text = '8',padx = 20,pady = 10,bg = '#dffad7',font = 'consolas 15')
b.pack(side = 'left',padx = 3,pady = 1)
b.bind("<Button-1>",click)

b = Button(f,text = '9',padx = 20,pady = 10,bg = '#dffad7',font = 'consolas 15')
b.pack(side = 'left',padx = 3,pady = 1)
b.bind("<Button-1>",click)

b = Button(f,text = 'Del',padx = 20,pady = 10,bg = '#ff2d8e',font = 'consolas 15')
b.pack(side = 'left',padx = 4,pady = 1)
b.bind("<Button-1>",click)

f.pack(fill = 'both',padx = 5,pady = 1)

f = Frame(root,bg = '#343638')

b = Button(f,text = '4',padx = 20,pady = 10,bg = '#dffad7',font = 'consolas 15')
b.pack(side = 'left',padx = 3,pady = 1)
b.bind("<Button-1>",click)

b = Button(f,text = '5',padx = 20,pady = 10,bg = '#dffad7',font = 'consolas 15')
b.pack(side = 'left',padx = 3,pady = 1)
b.bind("<Button-1>",click)

b = Button(f,text = '6',padx = 20,pady = 10,bg = '#dffad7',font = 'consolas 15')
b.pack(side = 'left',padx = 3,pady = 1)
b.bind("<Button-1>",click)

b = Button(f,text = '+',padx = 20,pady = 10,bg = '#fdbc00',font = 'consolas 15')
b.pack(side = 'left',padx = 3,pady = 1)
b.bind("<Button-1>",click)

f.pack(fill = 'both',padx = 5,pady = 1)

f = Frame(root,bg = '#343638')

b = Button(f,text = '1',padx = 20,pady = 10,bg = '#dffad7',font = 'consolas 15')
b.pack(side = 'left',padx = 3,pady = 1)
b.bind("<Button-1>",click)

b = Button(f,text = '2',padx = 20,pady = 10,bg = '#dffad7',font = 'consolas 15')
b.pack(side = 'left',padx = 3,pady = 1)
b.bind("<Button-1>",click)

b = Button(f,text = '3',padx = 20,pady = 10,bg = '#dffad7',font = 'consolas 15')
b.pack(side = 'left',padx = 3,pady = 1)
b.bind("<Button-1>",click)

b = Button(f,text = '-',padx = 20,pady = 10,bg = '#fdbc00',font = 'consolas 15')
b.pack(side = 'left',padx = 3,pady = 1)
b.bind("<Button-1>",click)

f.pack(fill = 'both',padx = 5,pady = 1)

f = Frame(root,bg = '#343638')

b = Button(f,text = '0',padx = 20,pady = 10,bg = '#dffad7',font = 'consolas 15')
b.pack(side = 'left',padx = 3,pady = 1)
b.bind("<Button-1>",click)

b = Button(f,text = '%',padx = 20,pady = 10,bg = '#dffad7',font = 'consolas 15')
b.pack(side = 'left',padx = 3,pady = 1)
b.bind("<Button-1>",click)

b = Button(f,text = '/',padx = 20,pady = 10,bg = '#dffad7',font = 'consolas 15')
b.pack(side = 'left',padx = 3,pady = 1)
b.bind("<Button-1>",click)

b = Button(f,text = '*',padx = 20,pady = 10,bg = '#fdbc00',font = 'consolas 15')
b.pack(side = 'left',padx = 3,pady = 1)
b.bind("<Button-1>",click)

f.pack(fill = 'both',padx = 5,pady = 1)

f = Frame(root,bg = '#343638')

b = Button(f,text = 'C',padx = 20,pady = 10,bg = '#e80851',font = 'consolas 15')
b.pack(side = 'left',padx = 3,pady = 1)
b.bind("<Button-1>",click)

b = Button(f,text = '.',padx = 20,pady = 10,bg = '#fdbc00',font = 'consolas 15')
b.pack(side = 'left',padx = 3,pady = 1)
b.bind("<Button-1>",click)

b = Button(f,text = '=',padx = 70,pady = 10,bg = '#47e2f8',font = 'consolas 15')
b.pack(side = 'left',padx = 3,pady = 1)
b.bind("<Button-1>",click)

f.pack(fill = 'both',padx = 5,pady = 1)

root.mainloop()