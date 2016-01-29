#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
Two important thinking:
1. divide and conqure, in a recursive manner
2. two pointers(slow and fast) in the list
*/

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL)
            return NULL;

        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev = slow;
            slow  = slow->next;
        }

    /*be careful of the heap allocation*/
    /*stack allocation will lead to undefined behavior*/
    TreeNode* root = new TreeNode(slow->val);

        if (prev != NULL)
            prev->next = NULL;
        else
            head = NULL;

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};

int main() {
    ListNode head = ListNode(0);
    ListNode* prev = &head;
    ListNode head1 = ListNode(1);
    prev->next = &head1;
    ListNode head2 = ListNode(2);
    head1.next = &head2;
    Solution LTB = Solution();
    TreeNode* x = LTB.sortedListToBST(prev);
    cout << x->val << endl;
    if (x->left)
        cout << x->left->val << endl;
    if (x->right)
        cout << x->right->val << endl;
    return 0;
}
