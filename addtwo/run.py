# Definition for singly-linked list.
# https://leetcode.com/problems/add-two-numbers/

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        t = 0
        r = []
        while l1 or l2:
            x, y = 0, 0
            if l1:
                x = l1.val
                l1 = l1.next
            if l2:
                y = l2.val
                l2 = l2.next
            s = x + y + t
            if t == 1:
                t = 0
            if s >= 10:
                t = 1
                s = int(str(s)[-1])
            r.append(s)
        if t == 1:
            r.append(t)
        return self.create_from_list(r)

    def create_from_list(self, l):
        x = l.pop(0)
        x = ListNode(x)
        n = x
        for i in l:
            t = ListNode(i)
            n.next = t
            n = n.next
        return x

    def print_list(self, n):
        while n:
            print n.val
            n = n.next


if __name__ == '__main__':
    a = [2, 4, 2, 1, 2, 3, 9, 4, 7]
    b = [5, 6, 4, 9, 7, 1, 2]
    a = [5]
    b = [5]
    s = Solution()
    x = s.create_from_list(a)
    y = s.create_from_list(b)
    r = s.addTwoNumbers(x, y)
    s.print_list(r)
    
