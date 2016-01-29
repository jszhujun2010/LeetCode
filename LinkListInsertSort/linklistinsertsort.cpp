#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode * insertionSortList(ListNode * head)
    {
        if(!head) { return NULL; }

        ListNode node = ListNode(INT_MIN);
        ListNode* dummy = &node;
        ListNode* prev = dummy;

        while(head)
        {
            ListNode * p = dummy;

            while(p->val <= head->val)
            {
                prev = p;
                p = p->next;

                if(!p) break;
            }

            if(!p)
            {
                prev->next = head;
                head = head->next;
                prev->next->next = NULL;
            }
            else
            {
                prev->next = head;
                head = head->next;
                prev->next->next = p;
            }
        }

        return dummy->next;
    }
};

int main()
{
    vector<int> listVal = {-2147483647, -2147483648};
    ListNode * dummy = new ListNode(0);
    ListNode * head = dummy;

    for(int i : listVal)
    {
        head->next = new ListNode(i);
        head = head->next;
    }

    head = dummy->next;

    Solution sln = Solution();
    ListNode * res = sln.insertionSortList(head);

    while(res)
    {
        cout << res->val << " ";
        res = res->next;
    }

    cout << endl;
    return 0;
}
