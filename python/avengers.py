import random
def avenger():

    avengers = random.choice(["ironman","thor","hulk","captainamerica","blackpanther","drstrange","spiderman","blackwidow","antman","wasp","captainmarvel","falcon","hawkeye","msmarvel"])
    validLetters = 'abcdefghijklmnopqrstuvwxyz'
    turns = 10
    guessmade = ''

    while len(avengers) > 0:
        main = ""
        missed = 0

        for letter in avengers:
            if letter in guessmade:
                main = main + letter
            else:
                main = main + "_" + " "
        if main == avengers:
            print(main)
            print("You win!")
            break

        print("Guess the avenger:" , main)
        guess = input()

        if guess in validLetters:
            guessmade = guessmade + guess
        else:
            print("Enter a valid character")
            guess = input()

        if guess not in avengers:
            turns = turns - 1
            if turns==9:
                    print("9 tries left")
                    print("---------------------")
                    print("\   /")
                    print(" \ /")
                    print("  |  ")
            if turns==8:
                    print("8 tries left")
                    print("---------------------")
                    print("\   / _____")
                    print(" \ /  |   |")
                    print("  |   |___|")
            if turns==7:
                    print("7 tries left")
                    print("---------------------")
                    print("\   / _____  ")
                    print(" \ /  |   |  |   |")
                    print("  |   |___|  |___|")
            if turns==6:
                    print("6 tries left")
                    print("---------------------")
                    print("\   / _____  ")
                    print(" \ /  |   |  |   |    _____")
                    print("  |   |___|  |___|         ")
            if turns==5:
                    print("5 tries left")
                    print("---------------------")
                    print("\   / _____                   |")
                    print(" \ /  |   |  |   |    _____   |")
                    print("  |   |___|  |___|            |_____")
            if turns==4:
                    print("4 tries left")
                    print("---------------------")
                    print("\   / _____                   |       ____  ")
                    print(" \ /  |   |  |   |    _____   |      |    |")
                    print("  |   |___|  |___|            |_____ |____|")
            if turns==3:
                    print("3 tries left")
                    print("---------------------")
                    print("\   / _____                   |       ____  ")
                    print(" \ /  |   |  |   |    _____   |      |    |")
                    print("  |   |___|  |___|            |_____ |____|")
            if turns==2:
                    print("2 tries left")
                    print("---------------------")
                    print("\   / _____                   |       ____  _____")
                    print(" \ /  |   |  |   |    _____   |      |    | |____ ")
                    print("  |   |___|  |___|            |_____ |____| _____|" )
            if turns==1:
                    print("1 try left")
                    print("---------------------")
                    print("\   / _____                   |       ____  _____   |" )
                    print(" \ /  |   |  |   |    _____   |      |    | |____ --|--")
                    print("  |   |___|  |___|            |_____ |____| _____|  |" )
            if turns==0:
                    print("0 try left")
                    print("---------------------")
                    print("\   / _____                   |       ____  _____   |    | " )
                    print(" \ /  |   |  |   |    _____   |      |    | |____ --|--  |  ")
                    print("  |   |___|  |___|            |_____ |____| _____|  |    o  ")
                    break


name = input("Enter your name: ")
print("Welcome" , name, "Lets see your avengers knowledge" )
print("-------------------")
print("try to guess the avenger in less than 10 attempts")
avenger()
print()
