#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;
        else
        {
            ListNode *head, *p;
            ListNode *h1 = l1;
            ListNode *h2 = l2;
            if (h1->val <= h2->val)
            {
                ListNode *Node = new ListNode(h1->val);
                head = Node;
                h1 = h1->next;
            }
            else
            {
                ListNode *Node = new ListNode(h2->val);
                head = Node;
                h2 = h2->next;
            }
            p = head;
            while (h1 != NULL && h2 != NULL)
            {
                if (h1->val <= h2->val)
                {
                    ListNode *Node = new ListNode(h1->val);
                    p->next = Node;
                    //p = p->next;
                    h1 = h1->next;
                }
                else
                {
                    ListNode *Node = new ListNode(h2->val);
                    p->next = Node;
                    //p = p->next;
                    h2 = h2->next;
                }
                p = p->next;
            }
            if (h2 != NULL)
            {
                while (h2 != NULL)
                {
                    ListNode *Node = new ListNode(h2->val);
                    p->next = Node;
                    p = p->next;
                    h2 = h2->next;
                }
            }
            else if (h1 != NULL)
            {
                while (h1 != NULL)
                {
                    ListNode *Node = new ListNode(h1->val);
                    p->next = Node;
                    p = p->next;
                    h1 = h1->next;
                }
            }
            return head;
        }
    }
};

int main()
{
    ListNode A1(1);
    ListNode A2(2);
    ListNode A3(3);
    ListNode A4(5);
    ListNode A5(7);
    A1.next = &A2;
    A2.next = &A3;
    A3.next = &A4;
    A4.next = &A5;
    ListNode B1(2);
    ListNode B2(4);
    ListNode B3(6);
    ListNode B4(8);
    ListNode B5(10);
//    ListNode B6(8);
//    ListNode B7(9);
//    ListNode B8(1);
    B1.next = &B2;
    B2.next = &B3;
    B3.next = &B4;
    B4.next = &B5;
//    B5.next = &B6;
//    B6.next = &B7;
//    B7.next = &B8;
    Solution solution;
    ListNode *x = solution.mergeTwoLists(&A1, &B1);
    //int i = 0;
    while (x != NULL)
    {
        //cout << i++ << endl;
        cout << x->val << endl;
        x = x->next;
    }
    return 0;
}
