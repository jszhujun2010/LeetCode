#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    void draw() {
        vector<int> num;
        help_draw(this, num);
    }

    void help_draw(TreeNode* root, vector<int> num) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            for (int n: num)
                cout << n << "->";
            cout << root->val << endl;
            return;
        }
        num.push_back(root->val);
        help_draw(root->left, num);
        help_draw(root->right, num);
    }
};

TreeNode* array_to_tree(vector<int> nums) {
    int n = nums.size();
    if (n < 1) return NULL;
    int i = 1, j = 0;
    while (i < n)  {
        j += 1;
        i *= 2;
    }
    if (i-1 == n) j++;
    vector<TreeNode*> numTree;
    for (int k = 0; k < n; k++)
        numTree.push_back(new TreeNode(nums[k]));
    for (int k = 0; k < n; k++) {
        if (numTree[k]->val != INT_MIN) {
            if (2*k+1 <= n-1) {
                if (numTree[2*k+1]->val != INT_MIN)
                    numTree[k]->left = numTree[2*k+1];
                else
                    numTree[k]->left = NULL;
            }
            if (2*k+2 <= n-1) {
                if (numTree[2*k+2]->val != INT_MIN)
                    numTree[k]->right = numTree[2*k+2];
                else
                    numTree[k]->right = NULL;
            }
        }
    }

    return numTree[0];
}


class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> cur;

        help(root, sum, res, cur);
        return res;
    }

    void help(TreeNode* root, int sum, vector<vector<int>>& res, vector<int> cur) {
        if (!root)
            return;

        if (sum == root->val && (!root->left && !root->right)) {
            cur.push_back(root->val  );
            res.push_back(cur);
            return;
        }

        cur.push_back(root->val);

        help(root->left, sum-(root->val), res, cur);
        help(root->right, sum-(root->val), res, cur);
    }
};


int main() {
//    vector<int> nums = {5,4,8,11,INT_MIN,13,4,7,2,INT_MIN,INT_MIN,INT_MIN,INT_MIN,5,1};
    vector<int> nums = {1};
    TreeNode* root = array_to_tree(nums);

    Solution sln = Solution();
    vector<vector<int>> res = sln.pathSum(root, 22);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
