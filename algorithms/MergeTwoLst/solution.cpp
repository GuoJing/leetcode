//
// Created by Guo Jing on 2016/12/14.
//

#include <iostream>
#include "solution.h"

using namespace std;

void Solution::printNodes(ListNode *l) {
    while (l != NULL) {
        cout << l->val << ", ";
        l = l->next;
    }
    cout << endl;
}

ListNode* Solution::mergeTwoLists(ListNode *l1, ListNode *l2) {
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    ListNode *first = l2;
    while(l1!=NULL) {
        ListNode *tmp = new ListNode();
        tmp->val = l1->val;
        first = insertSort(tmp, first);
        l1 = l1->next;
    }
    return first;
}

ListNode* Solution::insertSort(ListNode *n, ListNode *l) {
    int forceBreakerNumber = 0;
    int MAX_BREAKER = 1000;
    ListNode *last = NULL;
    ListNode *first = l;
    bool inserted = false;

    if (n->val <= first->val) {
        n->next = first;
        return n;
    }

    while (l != NULL){
        // if our node value is larger than list node
        if (n->val > l->val) {
            last = l;
            l = l->next;
            continue;
        }

        if (n->val <= l->val) {
            last->next = n;
            n->next = l;
            inserted = true;
            break;
        }

        if (forceBreakerNumber > MAX_BREAKER) {
            break;
        }

        forceBreakerNumber++;
    }

    if (!inserted) {
        last->next = n;
        n->next = NULL;
    }

    return first;
}