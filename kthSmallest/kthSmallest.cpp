#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
            return 0;

        vector<TreeNode*> container;
        TreeNode* node = root;
        TreeNode* temp;
        int i = 0;
        int result;

        while(!container.empty() || node) {
            if (node) {
                container.push_back(node);
                node = node->left;
            }
            else {
                temp = container.back();
                result = temp->val;
                container.pop_back();
                i++;
                if (i == k)
                    break;
                node = temp->right;
            }
        }

        return result;
    }
};


int main() {
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(9);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(30);
    root->right->left->left = new TreeNode(11);

    Solution sln = Solution();
    cout << sln.kthSmallest(root, 1) << endl;
    cout << sln.kthSmallest(root, 2) << endl;
    cout << sln.kthSmallest(root, 3) << endl;
    cout << sln.kthSmallest(root, 4) << endl;
    cout << sln.kthSmallest(root, 5) << endl;
    cout << sln.kthSmallest(root, 6) << endl;
    cout << sln.kthSmallest(root, 7) << endl;
    cout << sln.kthSmallest(root, 8) << endl;
}
