# https://leetcode.com/problems/palindrome-number/

class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        b = 0
        c = x
        while c > 0:
            i = c % 10
            c = c / 10
            b = b * 10 + i
        max_int = (1 << 31) - 1
        if b > max_int:
            return False
        if b < max_int * -1:
            return False
        return b == x
