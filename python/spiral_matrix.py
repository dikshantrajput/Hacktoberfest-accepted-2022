# Given an m x n matrix, return all elements of the matrix in spiral order.

def spiralOrder(self, matrix: list) ->list:
       result=[]
       top=0
       left=0
       right=len(matrix[0])-1
       bottom=len(matrix)-1
       dir=0
       while (top<=bottom and left<=right):
        # going from top left to top right
           if dir == 0:
               for i in range(left,right+1):
                   result.append(matrix[top][i])
               dir=1
               top+=1
            # moving from top +1 right to bottom 
           elif dir ==1:
               for i in range(top,bottom+1):
                   result.append(matrix[i][right])
               dir =2
               right-=1
            # moving from bottom right-1 to left
           elif dir ==2:
               for i in range(right,left-1,-1):
                   result.append(matrix[bottom][i])
               dir =3
               bottom-=1
            # moving from bottom left to top -1 
           elif dir == 3:
               for i in range(bottom,top-1,-1):
                   result.append(matrix[i][left])
               left+=1
               dir=0
       return result