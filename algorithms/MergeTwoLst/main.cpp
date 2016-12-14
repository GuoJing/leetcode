#include <iostream>
#include "solution.h"

using namespace std;

ListNode* genFirstNodes() {
    ListNode *l1 = new ListNode();
    ListNode *l2 = new ListNode();
    ListNode *l3 = new ListNode();
    ListNode *l4 = new ListNode();

    l1->val = 1;
    l2->val = 2;
    l3->val = 6;
    l4->val = 8;

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;

    return l1;
}

ListNode* genSecondNodes() {
    ListNode *l1 = new ListNode();
    ListNode *l2 = new ListNode();
    ListNode *l3 = new ListNode();
    ListNode *l4 = new ListNode();

    l1->val = 3;
    l2->val = 5;
    l3->val = 10;
    l4->val = 11;

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;

    return l1;
}

int main() {
    Solution* s = new Solution();
    ListNode* l1 = genFirstNodes();
    ListNode* l2 = genSecondNodes();
    s->printNodes(l1);
    s->printNodes(l2);
    cout << "---" << endl;
    ListNode* f = s->mergeTwoLists(l1, l2);

    s->printNodes(f);

    return 0;
}