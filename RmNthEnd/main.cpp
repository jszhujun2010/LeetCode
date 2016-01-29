#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL)
            return NULL;
        ListNode *p = head->next;
        int cnt = 1;
        while (p != NULL)
        {
            p = p->next;
            cnt++;
        }
        p = head;
        if (p->next == NULL)
            return NULL;
        if (cnt == n)
        {
            head = p->next;
            p = NULL;
            return head;
        }
        for (int i = 1; i < cnt-n; i++)
            p = p->next;
        ListNode *temp = p->next;
        if (temp->next == NULL)
        {
            p->next = NULL;
            return head;
        }
        p->next = temp->next;
        temp = NULL;
        return head;
    }
};

int main()
{
    ListNode L1(1);
    ListNode L2(2);
    ListNode L3(3);
    ListNode L4(4);
    ListNode L5(5);
    L1.next = &L2;
    L2.next = &L3;
    L3.next = &L4;
    L4.next = &L5;
    Solution solution;
    ListNode *head = solution.removeNthFromEnd(&L1, 2);
    while (head != NULL)
    {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}
