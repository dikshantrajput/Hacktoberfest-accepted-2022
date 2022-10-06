# function which return reverse of a string
 
def isPalindrome(s):
    return s == s[::-1]
 
s = input("Enter Text : ")
ans = isPalindrome(s)
 
if ans:
    print("Yes")
else:
    print("No")