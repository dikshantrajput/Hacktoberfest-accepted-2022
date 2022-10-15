# program to find all prime numbers between 2 to n
import math

def isPrime(x) :
    if x == 2 :
        return True
    if x%2 == 0 :
        return False
    for i in range(2, int(math.sqrt(x))+1) :
        if x%i == 0 :
            return False
    return True

n = int(input())
for i in range(2, n+1) :
    if isPrime(i) :
        print(i, end = " ")