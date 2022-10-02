# Given an M × N integer matrix, print it in spiral order.

# For example,

# Input:
 
# [  1   2   3   4  5 ]
# [ 16  17  18  19  6 ]
# [ 15  24  25  20  7 ]
# [ 14  23  22  21  8 ]
# [ 13  12  11  10  9 ]
 
# Output: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25

def printSpiral(mat, top, bottom, left, right):
 
    # base case
    if not mat or not len(mat) or left > right:
        return
 
    # print top row
    for i in range(left, right + 1):
        print(mat[top][i], end=' ')
 
    top = top + 1
 
    if top > bottom:
        return
 
    # print right column
    for i in range(top, bottom + 1):
        print(mat[i][right], end=' ')
 
    right = right - 1
 
    if left > right:
        return
 
    # print bottom row
    for i in range(right, left - 1, -1):
        print(mat[bottom][i], end=' ')
 
    bottom = bottom - 1
 
    if top > bottom:
        return
 
    # print left column
    for i in range(bottom, top - 1, -1):
        print(mat[i][left], end=' ')
 
    left = left + 1
 
    printSpiral(mat, top, bottom, left, right)
 
 
if __name__ == '__main__':
 
    mat = [
        [1, 2, 3, 4, 5],
        [16, 17, 18, 19, 6],
        [15, 24, 25, 20, 7],
        [14, 23, 22, 21, 8],
        [13, 12, 11, 10, 9]
    ]
 
    top = 0
    bottom = len(mat) - 1
    left = 0
    right = len(mat[0]) - 1
 
    printSpiral(mat, top, bottom, left, right)
