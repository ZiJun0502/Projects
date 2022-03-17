class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dd = {}
        for i, num in enumerate(nums):
            diffs = target - num
            if diffs in dd.keys():
                return [dd[diffs], i]
            dd[num]=i