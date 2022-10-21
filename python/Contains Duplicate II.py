class Solution:
    def containsNearbyDuplicate(self, nums: list[int], k: int) -> bool:

        d = defaultdict(int)                               
        for i, num in enumerate(nums):                   
     
            if num in d and i - d[num] <= k: 
            return True   
            d[num] = i                                      
        return False
