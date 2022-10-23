# Python3 implementation to check if
# two arrays can be made equal

# Function to check if array B
# can be made equal to array A
def canMadeEqual(A, B, n):

# Sort both the arrays
    A.sort()
    B.sort()

    # Check if both the arrays
    # are equal or not
    for i in range(n):
	    if (A[i] != B[i]):
	        return False
	
    return True

    # Driver Code
    if __name__ == "__main__":

        A = [ 1, 2, 3 ]
        B = [ 1, 3, 2 ]
        n = len(A)

    if (canMadeEqual(A, B, n)):
	    print( "Yes")
    else:
	    print("No")


