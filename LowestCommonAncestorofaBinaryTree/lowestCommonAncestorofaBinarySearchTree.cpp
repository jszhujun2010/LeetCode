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


//class Solution {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        bool cond1 = (root->val <= max(p->val, q->val));
//        bool cond2 = (root->val >= min(p->val, q->val));
//        if (!root || (cond1 && cond2))
//            return root;
//
//        if (root->val > max(p->val, q->val))
//            return lowestCommonAncestor(root->left, p, q);
//        else
//            return lowestCommonAncestor(root->right, p, q);
//    }
//};

/*iterative, very simple*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while ((root->val - p->val)*(root->val - q->val) > 0)
            root = (root->val > p->val) ? root->left: root->right;
        return root;
    }
};

int main() {
    vector<int> tree = {6, 2, 8, 0, 4, 7, 9, INT_MIN, INT_MIN, 3, 5};
    TreeNode* root = array_to_tree(tree);
//    root->draw();

    Solution sln = Solution();
    TreeNode* p = root->left->left;
    TreeNode* q = root->left->right->left;


    TreeNode* an = sln.lowestCommonAncestor(root, p, q);
    cout << an->val << endl;

    return 0;
}
