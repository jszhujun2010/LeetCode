#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        /*base case*/
        if (!root) return;
        TreeNode *tmp = help(root);
    }

    TreeNode* help(TreeNode* root) {
        if (!root) return NULL;

        if (!root->left && !root->right)
            return root;

        TreeNode* bottom = root;
        TreeNode* right = root->right;
        root->right = root->left;

        if (root->left) bottom = help(root->left);

        bottom->right = right;
        bottom = right;

        if (right) TreeNode* tmp = help(right);

        return bottom;
    }
};


int main() {
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);
//    TreeNode* n7 = new TreeNode(7);
//    TreeNode* n8 = new TreeNode(8);

//    n1->left = n2;
//    n1->right = n3;
//    n2->left = n4;
//    n2->right = n7;
//    n4->right = n8;
//    n3->left = n5;
//    n5->right = n6;

    n1->left = n2;
//    n1->right = n5;
//    n2->left = n3;
//    n2->right = n4;
//    n5->right = n6;


    Solution sln = Solution();
    sln.flatten(n1);
    while (n1) {
        cout << n1->val << endl;
        n1 = n1->right;
    }
    return 0;
}
