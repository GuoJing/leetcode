# https://leetcode.com/problems/3sum/

class Solution(object):
    def threeSum(self, nums):
        nums = sorted(nums)
        rt = []

        i = 0
        total = len(nums)
        ht = {}

        for i in range(total):
            j = i + 1
            k = total - 1
            while j < k:
                x, y, z = nums[i], nums[j], nums[k]
                if x + y + z == 0:
                    t = [x, y, z]
                    key = '%s:%s:%s' % (x, y, z)
                    ht[key] = t
                    j = j + 1
                    k = k - 1
                elif (nums[i] +nums[j] + nums[k]) < 0:
                    j = j + 1
                else:
                    k = k - 1

        return ht.values()

    def check(self, nums, target):
        ht = {}
        rt = []
        for i, v in enumerate(nums):
            t = target - v
            _i = ht.get(t)
            if _i is not None:
                x, y = [_i[0], i]
                x, y = nums[x], nums[y]
                rt.append((x, y))
            ht[v] = (i, t)
        return rt

if __name__ == '__main__':
    nums = [0,-6,0,-14,2,0,-9,5,-9,-8,-7,12,-4,14,-6,6,0,5,-2,6,-7,1,10,-10,-5,3,-2,-3,-13,-6,1,-6,3,9,-5,12,-6,-7,2,0,1,11,-11,4,2,-2,-5,-13,11,0,9,11,-13,-4,-13,-11,14,-8,1,8,1,9,-13,-11,3,-11,9,12,-2,-4,-11,6,14,-7,-5,1,-1,-3,-4,-5,12,12,13,6,-7,-15,10,14,14,-12,8,0,13,2,-3,1,-1,-9,-9,12,-6,-5,-5,-6,4,5,2,10,-13,13,12,6]
    s = Solution()
    r = s.threeSum(nums)
    for i in r:
        assert sum(i) == 0
    print len(r)
    print r
