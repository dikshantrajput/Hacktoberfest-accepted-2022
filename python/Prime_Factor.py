n = int(input('Enter the number to get prime factors: '))
for i in range(2, n+1):
    if n % i == 0:
        while n % i == 0:
            print(i, end=" ")
            n = n/i
print()
