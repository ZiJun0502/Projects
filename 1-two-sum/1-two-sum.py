class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dd = {}
        for i, num in enumerate(nums):
            diff = target - num
            if num in dd:
                return [dd[num], i]
            dd[diff]=i