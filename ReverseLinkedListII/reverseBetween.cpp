#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int cnt = 0;
        ListNode* start = head;
        ListNode* ends;
        ListNode* zero = head;
        ListNode* prev;
        ListNode* cur;
        ListNode* first = head;

        while (head != NULL) {
            cnt++;

            if (cnt < m-1) {
                head = head->next;
            }
            else if (cnt == m-1) {
                zero = head;
                head = head->next;
                start = head;
            }
            else if (cnt == m) {
                prev = head;
                head = head->next;
            }
            else if (cnt < n) {
                cur = head;
                head = head->next;
                cur->next = prev;
                prev = cur;
            }
            else if (cnt == n)
            {
                if (m == 1)
                    first = head;
                ends = head;
                head = head->next;
                zero->next = ends;
                ends->next = prev;
                start->next = head;
            }
            else if (cnt > n) {
                head = head->next;
            }
        }

        return first;
    }
};

int main() {
    ListNode* head;
    ListNode* prev;
    ListNode* root;
    prev = new ListNode(1);
    root = prev;
    for (int i = 2; i <= 6; i++) {
        head = new ListNode(i);
        prev->next = head;
        prev = head;
    }

    Solution sln = Solution();
    ListNode* h = sln.reverseBetween(root, 1, 2);

    while (h) {
        cout << h->val << " ";
        h = h->next;
    }

    return 0;
}
