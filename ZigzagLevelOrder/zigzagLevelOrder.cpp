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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<TreeNode*> curNodes;
        vector<TreeNode*> nextNodes;
        vector<int> curInts;
        bool odd = false;
        if (!root)
            return res;

        nextNodes.push_back(root);
        curInts.push_back(root->val);

        while (!nextNodes.empty()) {
//            cout << "nextNodes" << endl;
//            for (TreeNode* x: nextNodes)
//                cout << x->val << " ";
//            cout << endl;
//
//            cout << "curNodes" << endl;
//            for (TreeNode* x: curNodes)
//                cout << x->val << " ";
//            cout << endl;

            if (curNodes.empty()) {
                odd = !odd;
                curNodes = nextNodes;
                nextNodes.clear();
                res.push_back(curInts);
                curInts.clear();
            }

//            cout << "nextNodes" << endl;
//            for (TreeNode* x: nextNodes)
//                cout << x->val << " ";
//            cout << endl;
//
//            cout << "curNodes" << endl;
//            for (TreeNode* x: curNodes)
//                cout << x->val << " ";
//            cout << endl;

            while (!curNodes.empty()) {
                TreeNode* cur = curNodes.back();
                curNodes.pop_back();

//                cout << "cur: " << cur->val << endl;

                if (odd) {
                    if (cur->right) {
                        nextNodes.push_back(cur->right);
                        curInts.push_back(cur->right->val);
                    }
                    if (cur->left) {
                        nextNodes.push_back(cur->left);
                        curInts.push_back(cur->left->val);
                    }
                }
                else {
                    if (cur->left) {
                        nextNodes.push_back(cur->left);
                        curInts.push_back(cur->left->val);
                    }
                    if (cur->right) {
                        nextNodes.push_back(cur->right);
                        curInts.push_back(cur->right->val);
                    }
                }
            }
//            cout << "=================loop again================" << endl;
        }

        return res;
    }
};

void printResult(vector<vector<int>> res) {
    int m = res.size();
    if (m < 1) return;
    cout << "======================printing result=======================" << endl;

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << "====================printing result done====================" << endl;
}

int main() {
    vector<int> nums = {3,9,20,2,INT_MIN,15,7};
    TreeNode* root = array_to_tree(nums);
    Solution sln = Solution();
    vector<vector<int>> res = sln.zigzagLevelOrder(root);
    printResult(res);

    return 0;
}
