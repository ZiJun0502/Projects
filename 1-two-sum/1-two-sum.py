class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dd = {}
        for i, num in enumerate(nums):
            diff = target - num
            if diff in dd.keys():
                return [dd[diff], i]
            dd[num]=i