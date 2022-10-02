from typing import List


class Solution:
    def helper(self,n):
        if n == 0:
            return [[1]]
        if n == 1:
            return [[1],[1,1]]
        res = self.helper(n-1)
        output = [1]
        for i in range(0,len(res[-1])-1):
            output.append(res[-1][i] + res[-1][i+1])
        output.append(1)
        # print(output)
        res.append(output)
        return res
    def getRow(self, n: int) -> List[int]:
        final = self.helper(n)
        return final[-1]