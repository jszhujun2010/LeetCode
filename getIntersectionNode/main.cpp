#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        ListNode *a = headA;
        ListNode *b = headB;
        int length_a = 0;
        int length_b = 0;
        while (a != NULL)
        {
            length_a++;
            a = a->next;
        }
        while (b != NULL)
        {
            length_b++;
            b = b->next;
        }
        a = headA;
        b = headB;
        if (length_a > length_b)
        {
            int diff1 = length_a - length_b;
            int count1 = 0;
            while (count1++ < diff1)
                a = a->next;
        }
        else if (length_b > length_a)
        {
            int diff2 = length_b - length_a;
            int count2 = 0;
            while (count2++ < diff2)
                b = b->next;
        }
        while (a != NULL && b != NULL)
        {
            if (a->val == b->val)
                break;
            else
            {
                a = a->next;
                b = b->next;
            }
        }
        return a;
    }
};

int main()
{
    ListNode A1(1);
    ListNode A2(2);
    ListNode A3(3);
    ListNode A4(4);
    ListNode A5(5);
    A1.next = &A2;
    A2.next = &A3;
    A3.next = &A4;
    A4.next = &A5;
    ListNode B1(-2);
    ListNode B2(-1);
    ListNode B3(0);
    ListNode B4(6);
    ListNode B5(7);
    ListNode B6(8);
    ListNode B7(9);
    ListNode B8(1);
    B1.next = &B2;
    B2.next = &B3;
    B3.next = &B4;
    B4.next = &B5;
    B5.next = &B6;
    B6.next = &B7;
    B7.next = &B8;
    Solution solution;
    ListNode *result = solution.getIntersectionNode(&A1, &B1);
    if (result == NULL)
        cout << "NULL" << endl;
    else
        cout << result->val << endl;
    return 0;
}
