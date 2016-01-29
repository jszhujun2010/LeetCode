#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;

        ListNode *fast, *slow;
        fast = head;
        slow = head;
        bool first = true;

        while (fast != slow || first) {
            if (first) first = false;

            if (fast && fast->next) {
                fast = fast->next->next;
            }
            else return NULL;

            if (slow) slow = slow->next;
            else return NULL;
        }

        fast = head;

        while (fast != slow || first) {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
};

int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
//    n6->next = n3;

    Solution sln = Solution();
    ListNode *result = sln.detectCycle(n1);

    if (result) cout << "Cicle begins at " << result->val << endl;
    else cout << "No cicle detected!" << endl;
}
