# https://leetcode.com/problems/zigzag-conversion/

class Solution(object):
    def convert(self, s, numRows):
        n = numRows

        if not s:
            return ''

        if n == 1:
            return s

        x, y = 0, 0
        st = []
        ht = {}

        t = len(s)

        i = 0

        while i < t:
            if y < n:
                if not ht.get(y):
                    ht[y] = []
                ht[y].append(s[i])
                y += 1
            else:
                y -= 1
                while y > 1 and i < t:
                    x += 1
                    y -= 1
                    if not ht.get(y):
                        ht[y] = []
                    ht[y].append(s[i])
                    i += 1
                y -= 1
                x += 1
                continue
            i += 1

        r = []

        for k in sorted(ht.keys()):
            r.append(''.join(ht.get(k)))

        return ''.join(r)

if __name__ == '__main__':
    s = Solution()
    st = 'ABCDEFGHIJ'
    st = 'asldjlasd9123981092381asdjlkasd'
    st = 'AB'
    st = 'exhocptracgvczgzwnigfunjwzaegrqmqxaspvlrarmetsephovokkxgja'
    r = s.convert(st, 3)
    print r

