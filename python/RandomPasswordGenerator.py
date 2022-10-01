/*Based on the length of the password given by user, computer generates a random password*/



import random
import string 

#string is library in python like random whuch conatains all the string handling operations just like string.h in c/c++

if __name__=="__main__":
#search on net how main works 

    s1=string.ascii_lowercase
#ascii_lowercase imports all the lower alphabet from string library 

    s2=string.ascii_uppercase
#imports all upper alphabet from string library 

    s3=string.punctuation
 #A string contains letters, whitespace, numbers. And it has punctuation: these characters include commas and periods and semicolons.

    s4=string.digits
#impports digits 

    length=int(input("length of your password "))
    s=[]
#this is an empty list that adds whatver we want into it 
#now since s is a alist and we can change items in it but we can only add elements of type list to it and so we need to convert all our strings into lists 

    s.extend(list(s1))
    s.extend(list(s2))
    s.extend(list(s3))
    s.extend(list(s4))
#.extend is a function operating on lists that will add a list in the form of elements search on net how extend works 

    random.shuffle(s)
#shuffle is a function in random library that just shuffles a list in any order 

    print("".join(s[0:length]))
#slicing lists list_name[start:stop]
