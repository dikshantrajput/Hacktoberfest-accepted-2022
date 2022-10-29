try:
    tc = int(input())
    for i in range(tc):
        a = int(input())
        factorial = 1
        for j in range(1,a+1):
            factorial = factorial*j
        print(factorial)
except:
    pass