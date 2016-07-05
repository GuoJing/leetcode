# https://leetcode.com/problems/median-of-two-sorted-arrays/

from bisect import bisect_left

class Solution(object):
    def isodd(self, n):
        return n % 2 == 1

    def find_index(self, t):
        if self.isodd(t):
            return (t/2, t/2)
        else:
            return (t/2 - 1, t/2)

    def findMedianSortedArrays(self, nums1, nums2):
        l1= len(nums1)

        for i, n in enumerate(nums2):
            _i = bisect_left(nums1, n)
            nums1.insert(_i, n)
            l1 += 1

        x, y = self.find_index(l1)
        vx = nums1[x]
        vy = nums1[y]

        if x == y:
            return float(vx)
        return float((vx + vy)) / 2

if __name__ == '__main__':
    n1 = [1, 3]
    n2 = [2]
    s = Solution()
    r = s.findMedianSortedArrays(n1, n2) 
    print r
