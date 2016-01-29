#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
            return NULL;
        int mid = (nums.size()-1)/2;
        TreeNode* root = new TreeNode(nums[mid]);

        vector<int> left_part;
        vector<int> right_part;

        if (nums.size() <= 2) {
            if (nums.size() == 2) {
                right_part.push_back(nums[1]);
            }
        }
        else {
            left_part.assign(nums.begin(), nums.begin()+mid);
            right_part.assign(nums.begin()+mid+1, nums.end());
        }
        root->left = sortedArrayToBST(left_part);
        root->right = sortedArrayToBST(right_part);
        return root;
    }
};

int main() {
    vector<int> nums = {0, 1};
    Solution LTB = Solution();
    TreeNode* x = LTB.sortedArrayToBST(nums);
    cout << x->val << endl;
    if (x->left)
        cout << x->left->val << endl;
    if (x->right)
        cout << x->right->val << endl;
    return 0;
}
