def factorial(x):

  if x == 1:
    return 1
  else:
    return (x * factorial(x - 1))


n = int(input("Write a number: "))

print("\nThe factorial of %i is %i" % (n, factorial(n)))