#Game With Computer 

from random import randint
from time import sleep
li = ['Stone','Papper','Secior']
comp_choice = ' '
user_choice = 0
while (1): 
    comp = randint(0,2)
    comp_choice = li[comp]
    print('\n\t\t*** Stone-Papper-Secior Game***')
    print('Choose The below Options -> ')
    print('\t0:Stone')
    print('\t1:Papper')
    print('\t2:Secior')
    print('-------------------------------------------------------------------')
    try:
        user_input = int(input('Enter Your choice from Above : '))
        user_input = li[user_input]
    except Exception as IndexError:
        print('-------------------------------------------------------------------')
        print('\t\tWrong input')
        sleep(3)
        print('\t\tEXIT')
        print('-------------------------------------------------------------------')
        break
    
    if user_input == 'Stone' and comp_choice == 'Secior':
        print(f'\t\tComputer has {comp_choice} but you have {user_input}')
        sleep(3)
        print('\t\tUser Win')
        print('-------------------------------------------------------------------')
        sleep(2)
    elif user_input == 'Papper' and  comp_choice == 'Stone':
        print(f'\t\tComputer has {comp_choice} but you have {user_input}')
        sleep(3)
        print('\t\tUser Win')
        print('-------------------------------------------------------------------')
        sleep(2)
    elif user_input == 'Secior' and  comp_choice == 'Papper':
        print(f'\t\tComputer has {comp_choice} but you have {user_input}')
        sleep(3)
        print('\t\tUser Win') 
        print('-------------------------------------------------------------------')
        sleep(2)
    elif user_input == comp_choice:
        print(f'\t\tBoth Having same : {user_input}')
        sleep(3)
        print('\t\tDRAW')
        print('-------------------------------------------------------------------')
        sleep(2)
    else:
        print(f'\t\tComputer has {comp_choice} and you have {user_input}')
        sleep(3)
        print('\t\tOoops, User Loose')
        print('-------------------------------------------------------------------')
        sleep(2)

    

    