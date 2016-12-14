# https://leetcode.com/problems/longest-palindromic-substring/

class Solution(object):
    def longestPalindrome(self, s):
        ansl, ansr, maxx = 0, 1, 0
        length = len(s)
        for i in range(1, length * 2):
            if i % 2 == 0 :
                left = i / 2
                right = left
            else :
                left = i / 2 - 1
                right = left + 1
            while (left >= 0) and (right < length) and (s[left] == s[right]):
                left -= 1
                right += 1
            left += 1
            right -= 1
            if right - left > maxx:
                maxx = right - left
                ansl = left
                ansr = right
        return s[ansl: ansr + 1]


if __name__ == '__main__':
    s = Solution()
    #st = 'abcbbcba' # abcba
    st = 'abcbaa778bcba'
    st = 'abbb'
    r = s.longestPalindrome(st)
    print r
    st = 'cccd'
    r = s.longestPalindrome(st)
    print r
