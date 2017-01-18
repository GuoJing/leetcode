class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def __repr__(self):
        return '<ListNode x=%s>' % self.val


class Solution(object):
    def mergeKLists(self, lists):
        self.heap = [[i, lists[i].val]
                     for i in range(len(lists))
                     if lists[i] is not None]
        self.hsize = len(self.heap)
        for i in range(self.hsize - 1, -1, -1):
            self.adjustdown(i)
        nHead = ListNode(0)
        head = nHead

        while self.hsize > 0:
            ind, val = self.heap[0][0], self.heap[0][1]
            head.next = lists[ind]
            head = head.next
            lists[ind] = lists[ind].next
            if lists[ind] is None:
                self.heap[0] = self.heap[self.hsize-1]
                self.hsize = self.hsize - 1
            else:
                self.heap[0] = [ind, lists[ind].val]
            self.adjustdown(0)
        return nHead.next

    def adjustdown(self, p):
        lc = lambda x: (x + 1) * 2 - 1
        rc = lambda x: (x + 1) * 2
        while True:
            np, pv = p, self.heap[p][1]
            if lc(p) < self.hsize and self.heap[lc(p)][1] < pv:
                np, pv = lc(p), self.heap[lc(p)][1]
            if rc(p) < self.hsize and self.heap[rc(p)][1] < pv:
                np = rc(p)
            if np == p:
                break
            else:
                self.heap[np], self.heap[p] = self.heap[p], self.heap[np]
                p = np

def build_list_node_from_list(l):
    if not l:
        return
    root = ListNode(l.pop(0))
    ln = root
    for i in l:
        t = ListNode(i)
        ln.next = t
        ln = t
    return root


def print_list_node(ln):
    while ln:
        print(ln.val)
        ln = ln.next


if __name__ == '__main__':
    a = [1, 2, 3]
    b = [99, 100, 102]
    ln = build_list_node_from_list(a)
    ln1 = build_list_node_from_list(b)
    ret = Solution().mergeKLists([ln, ln1])
    print_list_node(ret)
