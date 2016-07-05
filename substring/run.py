# https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        if not s:
            return 0
        total = len(s)
        r = 1
        st = 0
        et = st + 1
        c = ''
        t = []
        cnt = 1

        while et < total:
            t = s[st:et]

            n = et
            if n >= total:
                break
            c = s[n]

            if c in t:
                st = st + 1
                r = max(cnt, r)
                cnt = 0
            else:
                et = et + 1
                cnt = len(t) + 1

        r = max(cnt, r)
        return r


if __name__ == '__main__':
    st = 'pwwkew'

    pair = [
        ('', 0),
        ('abcabcbb', 3),
        ('bbbbb', 1),
        ('pwwkew', 3),
        ('au', 2),
        ('sjjj88mayue***xxx7788414', 7)
    ]

    s = Solution()
    for st, result in pair:
        r = s.lengthOfLongestSubstring(st)
        assert r == result
