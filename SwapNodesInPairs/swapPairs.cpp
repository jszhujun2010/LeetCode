#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* nullhead = new ListNode(-1);
        nullhead->next = head;

        ListNode *p = head;
        ListNode *q;
        ListNode *r;
        ListNode *prev = nullhead;

        while (p) {
            if ((q = p->next)) {
                r = q->next;
                p->next = r;
                q ->next = p;
                prev->next = q;
                prev = p;
                p = r;
            }
            else
                break;
        }
        return nullhead->next;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    ListNode* root = head;
    for (int i = 2; i <= 9; i++) {
        head->next = new ListNode(i);
        head = head->next;
    }

    Solution sln = Solution();
    root = sln.swapPairs(root);

    while(root != NULL) {
        cout << root->val << endl;
        root = root->next;
    }
    return 0;
}
