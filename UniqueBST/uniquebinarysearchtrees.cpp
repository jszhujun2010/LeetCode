#include <iostream>
#include <vector>

using namespace std;

//cheated

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> root;
        if (n == 0)
            return root;
        return help(1, n);
    }

    vector<TreeNode*> help(int start, int ends) {
        vector<TreeNode*> res;
        if (start > ends) {
            res.push_back(NULL);
            return res;
        }

        for (int i = start; i <= ends; i++) {
            vector<TreeNode*> left = help(start, i-1);
            vector<TreeNode*> right = help(i+1, ends);

            for (int k = 0; k < left.size(); k++) {
                for (int j = 0; j < right.size(); j++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[k];
                    root->right = right[j];
                    res.push_back(root);
                }
            }
        }

        return res;
    }
};

//no test here, too complicated!!!

int main() {
    Solution sln = Solution();
    cout << sln.generateTrees(0).size() << endl;
    return 0;
}
