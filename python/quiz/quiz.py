#importing required libraries
import json
from random import *

#function to display basic information
def display_information():
  print('WELCOME TO QUIZ.py')
  print('----------------')
  print('THIS IS AN QUIZ APPLICATION WHERE YOU CAN GIVE QUIZ ON CPP,JAVA,PYTHON')
  print('----------------------------------------------------------------------')
  print('INSTRUCTIONS-')
  print('------------')
  print('1.CHOOSE THE QUIZ OF YOUR CHOICE')
  print('2.ENTER YOUR NAME')
  print('3.TYPE THE EXACT SAME ANSWER AS GIVEN IN OPTIONS')
  print('----------------------------')

#function to choose the topic and to get the name of the user
def second_phase():
  required_data=[]
  sc=''
  print('SELECT A TOPIC')
  print('--------------')
  print('PRESS 1 FOR CPP')
  print('PRESS 2 FOR JAVA')
  print('PRESS 3 FOR PYTHON')
  print('------------------')
  try:
    selected_topic = int(input())
  except ValueError as ve:
    print('wrong selection')
    return second_phase()
  if selected_topic == 1:
    sc = 'CPP'
  elif selected_topic == 2:
    sc = 'JAVA'
  elif selected_topic == 3:
    sc = 'PYTHON'
  else:
    print('WRONG SELECTION')
    return second_phase()
  print('ENTER YOUR NAME')
  print('--------------')
  name = input().strip().upper()
  print(f'WELLCOME {name}, GET READY FOR YOUR {sc} QUIZ, ALL THE BEST!!')
  print('---------------------------------------------------------------')
  required_data.append(sc)
  required_data.append(name)
  return required_data


#function to display shuffled questions with shuffled options
def show_que(t,name):
  with open(f"./{t}.json", 'r') as openfile:
    json_object = json.load(openfile)
  index = ['1','2','3','4','5','6','7','8','9','10']
  shuffle(index)
  s=0
  for i in index:
    print(json_object[i]['que'])
    l = json_object[i]['options']
    shuffle(l)
    for j in l:
      print(j)
    print('---------------')
    ua = input().strip()
    print('---------------')
    if ua == json_object[i]['ans']:
      s += 1
      print('CORRECT ANSWER!!')
      print('-----------------')
    else:
      print(f"OOPS WRONG ANSWER CORRECT ANSWER WAS {json_object[i]['ans']}")
      print('--------------------------------------------------------')
  openfile.close()
  print('------------------------------')
  print(f'{name} your score is {s} out of 10, great job!!')
  return re_qu()

#function to quit or reattemt the quiz
def re_qu():
  print('-----------------------')
  print("PRESS 'R' TO REATTEMPT")
  print("PRESS 'Q' TO QUIT")
  print('------------------')
  ui = input().strip().upper()
  if ui == 'R':
    print('QUIZ WILL BEGIN AGAIN!!')
    print('-----------------------')
    return show_que(t,name)
  elif ui =='Q':
    return 'THANKYOU'
  else:
    print("WRONG SELECTION")
    return re_qu()

#main code
display_information()
data = second_phase()
t = data[0]
name = data[1]
show_que(t,name)