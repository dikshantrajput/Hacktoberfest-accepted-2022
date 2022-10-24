import random

highest = 100
answer = random.randint(1, highest)
guess = int(input("Guess number between 1 and {}: ".format(highest)))
c=0
while True :
    if guess < 1 or guess > highest :
        if guess == 0 and c > 0:
            print("Game over")
            break
        guess = int(input("Please guess number between 1 and {}: ".format(highest)))
    if guess == 0 and c > 0 :
        print("Game over")
        break
    if guess == answer:
        print("Well done, you guessed it ")
        break
    else:
        if guess < answer:
            print("Please guess higher ")
        else:   # guess must be greater than answer
            print("Please guess lower ")
    c += 1
    if guess != 0 :
        guess = int(input("If you don't want to continue please type 0, else continue guessing "))




