#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*This is an iterative way, three stacks are used.*/

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
            return NULL;

        int max_index = nums.size()-1;
        vector<int> leftIndex = {0};
        vector<int> rightIndex = {max_index};
        vector<TreeNode*> nodeCon;
        TreeNode *firstNode = new TreeNode(0);
        nodeCon.push_back(firstNode);

        while (!nodeCon.empty()) {
            TreeNode *curNode = nodeCon.back();
            nodeCon.pop_back();

            int left = leftIndex.back();
            leftIndex.pop_back();
            int right = rightIndex.back();
            rightIndex.pop_back();
            int mid = left + (right - left)/2;
            curNode->val = nums[mid];

            if (left <= mid - 1) {
                curNode->left = new TreeNode(0);
                nodeCon.push_back(curNode->left);
                leftIndex.push_back(left);
                rightIndex.push_back(mid-1);
            }
            if (right >= mid + 1) {
                curNode->right = new TreeNode(0);
                nodeCon.push_back(curNode->right);
                leftIndex.push_back(mid+1);
                rightIndex.push_back(right);
            }
        }
        return firstNode;
    }
};

int main() {
    vector<int> nums = {3, 5, 8};
    Solution LTB = Solution();
    TreeNode* x = LTB.sortedArrayToBST(nums);
    cout << x->val << endl;
    if (x->left) {
        cout << x->left->val << endl;
    }
    if (x->right)
        cout << x->right->val << endl;
    return 0;
}
