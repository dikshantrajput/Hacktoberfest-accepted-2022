n = int(input("Enter number of terms? "))


x, y = 0, 1
count = 0


if n <= 0:
   print("Please enter a positive integer")

elif n == 1:
   print("Fibonacci sequence upto",n,":")
   print(x)

else:
   print("Fibonacci sequence:")
   while count < n:
       print(x)
       nth = x + y
     
       x = y
       y = nth
       count += 1
