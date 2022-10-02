def staircase(n,stair):
	"""
	A function to print staircase in the console.

	Parameters
	----------
	n : size of the staircase (int)
	stair : symbol for the stairs (string)
  """
	space = " "
  text = n*space
  for i in range(1,n+1,1):
    text = text[:n-i] + i*stair
    print(text)
    
    
if __name__ == '__main__':
  n = int(input().strip())

  staircase(n)
