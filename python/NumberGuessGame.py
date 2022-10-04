choice = input('How many players? (1,2 or 3):')
if choice not in range (1,4):
        print("enter valid number of players")
if choice in ('1'): 
        player1 = str(input("Enter Your Name:"))
        if choice == '1':
           print('welcome', '' ,player1)
        import random
        
        number = random.randint(1,100)

        attempts = 0
        guess = 0
        
             
        while guess != number:
         try:
            guess = eval(str(input('Guess number between 1 to 100:')))
         except NameError: 
                 print('enter only number')
                 continue
         except SyntaxError:
                 print('no special characters allowed')
                 continue
         if guess not in range (1,101):
              print('enter only numbers between 1 to 100')
              continue


         attempts += 1
         
         if guess == number:
                 print ('Correct! You used', attempts, 'attempts!')
                 break
         
         if guess < number:
                  print ('Go higher!')
         if guess > number:
                   print ('Go lower!')
                   
if choice in ('2'):
       player2=str(input('Enter First Player Name:'))
       print('welcome', '' ,player2)
       player3=str(input('Enter Second Player Name:'))
       print('welcome', '' ,player3)
       import random
        
       number = random.randint(1,100)

       attempts1 = 0
       guess = 0
       print(player2,'', 'will play first')
       while guess != number:
         try:
            guess = eval(str(input('Guess number between 1 to 100:')))
         except NameError: 
                 print('enter only number')
                 continue
         except SyntaxError:
                 print('no special characters allowed')
                 continue
         if guess not in range (1,101):
              print('enter only numbers between 1 to 100')
              continue


         attempts1 += 1
         
        
         if guess < number:
                  print ('Go higher!')
         if guess > number:
                   print ('Go lower!')

         if guess == number:
                 print ('Correct! You used', attempts1, 'attempts!')
                
         
         
                 print('now','', player3,'', 'will play')
                 import random
                
                 number = random.randint(1,100)

                 attempts2 = 0
                 guess = 0



                 
                 while guess != number:
                  try:
                    guess = eval(str(input('Guess number between 1 to 100:')))
                  except NameError: 
                         print('enter only number')
                         continue
                  except SyntaxError:
                         print('no special characters allowed')
                         continue
                  if guess not in range (1,101):
                      print('enter only numbers between 1 to 100')
                      continue


                  attempts2 += 1
                 
                  if guess == number:
                         print ('Correct! You used', attempts2, 'attempts!')
                         break

                 
                  if guess < number:
                          print ('Go higher!')
                  if guess > number:
                           print ('Go lower!')
                           
                  



                 print('now it is result time')
                 if attempts1 < attempts2:
                  print(player2, '', "has won and ", player3, "lost")
                 elif attempts1 == attempts2 :
                  print('It is a tie')
                 else:
                  print(player3, '', "has won and ", player,2, "lost")


                   
if choice in ('3'):
       player4=str(input('Enter First Player Name:'))
       print('welcome', '' ,player4)
       player5=str(input('Enter Second Player Name:'))
       print('welcome', '' ,player5)
       player6=str(input('Enter Third Player Name:'))
       print('welcome', '' ,player6)


       import random
        
       number = random.randint(1,100)

       attempts3 = 0
       guess = 0
       print(player4,'', 'will play first')
       while guess != number:
         try:
            guess = eval(str(input('Guess number between 1 to 100:')))
         except NameError: 
                 print('enter only number')
                 continue
         except SyntaxError:
                 print('no special characters allowed')
                 continue
         if guess not in range (1,101):
              print('enter only numbers between 1 to 100')
              continue


         attempts3 += 1
         
        
         if guess < number:
                  print ('Go higher!')
         if guess > number:
                   print ('Go lower!')

         if guess == number:
                 print ('Correct! You used', attempts3, 'attempts!')
                
         
         
                 print('now','', player5,'', 'will play')
                 import random
                
                 number = random.randint(1,100)

                 attempts4 = 0
                 guess = 0



                 
                 while guess != number:
                  try:
                    guess = eval(str(input('Guess number between 1 to 100:')))
                  except NameError: 
                         print('enter only number')
                         continue
                  except SyntaxError:
                         print('no special characters allowed')
                         continue
                  if guess not in range (1,101):
                      print('enter only numbers between 1 to 100')
                      continue


                  attempts4 += 1
                 
                  if guess == number:
                         print ('Correct! You used', attempts4, 'attempts!')
                         break

                 
                  if guess < number:
                          print ('Go higher!')
                  if guess > number:
                           print ('Go lower!')
                           
                  
                 print('now','', player6,'', 'will play')
                 import random
                
                 number = random.randint(1,100)

                 attempts5 = 0
                 guess = 0



                 
                 while guess != number:
                  try:
                    guess = eval(str(input('Guess number between 1 to 100:')))
                  except NameError: 
                         print('enter only number')
                         continue
                  except SyntaxError:
                         print('no special characters allowed')
                         continue
                  if guess not in range (1,101):
                      print('enter only numbers between 1 to 100')
                      continue


                  attempts5 += 1
                 
                  if guess == number:
                         print ('Correct! You used', attempts5, 'attempts!')
                         break

                 
                  if guess < number:
                          print ('Go higher!')
                  if guess > number:
                           print ('Go lower!')
                           


                 print('now it is result time')
                 t = min(attempts3,attempts4,attempts5)
                 if t == attempts3:
                         print(player4, '', "has won and ", player5, " and ", player6, "lost" )
                 if t == attempts4:
                         print(player5, '', "has won and ", player4, " and ", player6, "lost")
                 if t == attempts5:
                         print(player6, '', "has won and ", player4, " and ", player5, "lost")
                 if attempts3 == attempts4:
                         print("It is a tie between ", player4, " and ", player5)
                 if attempts4 == attempts5:
                         print("It is a tie between ", player5, " and ", player6)
                 if attempts3 == attempts5:
                         print("It is a tie between ", player4, " and ", player6)
                 if attempts3 == attempts5 == attempts4:
                         print("It is a tie between ", player4, " , ", player5 , " and ", player6 )
                 
