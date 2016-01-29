#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL)
            return NULL;
        else
        {
            ListNode *cur = head;
            ListNode *next = head->next;
            while (next != NULL)
            {
                if (cur->val != next->val)
                {
                    cur = cur->next;
                    next = next->next;
                }
                else
                {
                    if (next->next == NULL)
                    {
                        cur->next = NULL;
                        break;
                    }
                    else
                    {
                        cur->next = next->next;
                        next = cur->next;
                    }
                }
            }
            return head;
        }
    }
};

int main()
{
    ListNode L1(1);
    ListNode L2(2);
    ListNode L3(2);
    ListNode L4(3);
    ListNode L5(3);
    L1.next = &L2;
    L2.next = &L3;
    L3.next = &L4;
    L4.next = &L5;
    Solution solution;
    ListNode *head = solution.deleteDuplicates(&L1);
    while (head != NULL)
    {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}
