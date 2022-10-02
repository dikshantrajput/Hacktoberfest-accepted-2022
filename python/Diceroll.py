import random
min = 1
max = 6

roll = "y"

while roll == "y":
    a = random.randint(min, max)
    b = random.randint(min, max)
    print ("Your first dice rolled " + str(a))
    print ("Your second dice rolled " + str(b))
    print ("Total score " = str(a + b)
    roll = raw_input("Type y to roll again")
