# Author: Luzia Thomas
# Description: This program computes the freefall time, impact velocity, and force of an object dropped from planets of varying characteristics. Additonally, the program allows the user to conduct the experiment as many times as they would like before ending.

import math
gravity_constant = 6.674e-11

#functions
def main():
    distance = float(input("How far will the object be dropped? "))
    planet_radius = float(input("What is the radius of the planet it is being dropped on? "))
    planet_mass = float(input("What is the mass of the planet it is being dropped on? "))
    under_radical = distance / ((1 / 2) * (gravity_constant) * (planet_mass / (planet_radius ** 2)))
    time = math.sqrt(under_radical)
    velocity = ((gravity_constant) * ((planet_mass / (planet_radius ** 2))) * (time))
    print("It will take", time, "seconds for the object to drop", distance, "meters.")
    print("The object will be traveling", velocity, "meters per second at impact.")   
    print()
    
def again():
    ask = input("Would you like to conduct this experiment on another planet? Yes or No? ")
    if ask == "Yes" or ask == "yes":
        main()
        again()
    elif ask == "No" or ask == "no":
        print("Goodbye!")
    else:
        print("Please run this program again, and enter either 'yes' or 'no'")

#runs the main program and allows user to experiment for as long as they would like
print("Welcome!")
go = input("Would you like to run a physics experiment? Yes or No? ")
if go == "Yes" or go == "yes":
    main()
    again()
elif go == "No" or go == "no":
    print("Goodbye!")
else:
    print("Please run this program again, and enter either 'yes' or 'no'.")
  