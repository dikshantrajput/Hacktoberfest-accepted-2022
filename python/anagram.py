def anagram(a, b):
    if(sorted(a)== sorted(b)):
        print("The strings are anagrams.")
    else:
        print("The strings are not anagrams.")
        
a = "debit card"
b = "bad credit"
anagram(a,b)