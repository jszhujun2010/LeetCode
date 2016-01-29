#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        int last = INT_MIN;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* cur = head;
        ListNode* prev = dummy;
        ListNode* keep;
        while (cur) {
            if (cur->val != last) {
                keep = prev;
                last = cur->val;
                prev = cur;
                cur = cur->next;
            }
            else {
                while (cur && cur->val == last) {
                    cur = cur->next;
                }
                if (cur) {
                    keep->next = cur;
                    last = cur->val;
                    prev = cur;
                    cur = cur->next;
                }
                else
                {
                    keep->next = NULL;
                    break;
                }
            }
        }
        return dummy->next;
    }
};

int main() {
    vector<int> nums = {3, 3, 3, 3, 5,  4, 4};
    ListNode* head = new ListNode(nums[0]);
    ListNode* prev = head;
    for (int i = 1; i < nums.size(); i++) {
        ListNode* node = new ListNode(nums[i]);
        prev->next = node;
        prev = node;
    }

    Solution sln = Solution();
    ListNode* res = sln.deleteDuplicates(head);

    while (res) {
        cout << res->val << endl;
        res = res->next;
    }


    return 0;
}
