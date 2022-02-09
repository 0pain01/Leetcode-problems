class Solution:
    def rob(self, nums: List[int]) -> int:
        
        if(len(nums)<=1):
            return max(nums)
        
        arr = [] * len(nums)
        arr.append(nums[0])
        arr.append(max(nums[0],nums[1]))
        
        for i in range(2,len(nums)):
            arr.append(max(arr[i-1],nums[i]+arr[i-2]))
            
        return arr[-1]
        