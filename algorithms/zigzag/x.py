class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        r = 0
        if x == 0:
            return 0
        if x > 0:
            r = str(x)[::-1]
        if x < 0:
            r = '-' + str(abs(x))[::-1]

        r = int(r)

        if r > 1000000003:
            r = 0
        if r < -1000000003:
            r = 0

        return int(r)

if __name__ == '__main__':
    s = Solution()
    print s.reverse(-123)
