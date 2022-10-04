class Solution:
    def mySqrt(self, x: int) -> int:
        if (x < 0): return -1
        if (x <= 1): return x
        
        lb = 1
        ub = x // 2
        
        sqrt = -1
        
        while lb <= ub:
            mid = lb + ((ub - lb) // 2)
            
            if (mid * mid == x): return mid
            elif (mid * mid > x): ub = mid - 1
            else:
                sqrt = mid
                lb = mid + 1
        
        return sqrt