# https://leetcode.com/problems/two-sum/

class Solution(object):
    def twoSum(self, nums, target):
        ht = {}
        for i, v in enumerate(nums):
            t = target - v
            _i = ht.get(t)
            if _i:
                return [_i[0], i]
            ht[v] = (i, t)


if __name__ == '__main__':
    s = Solution()
    nums = [-1,-2,-3,-4,-5]
    target = -8
    r = s.twoSum(nums, target)
    print r
