#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//The problem could be integer overflow

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if (root == NULL)
            return 0;
        vector<int> num;
        vector<TreeNode *> node;
        vector<int> final_collection;
        int digit = root->val;
        num.push_back(digit);
        node.push_back(root);
        while (!num.empty())
        {
            digit = num.back();
            num.pop_back();
            TreeNode *x = node.back();
            node.pop_back();
            if (x->left == NULL && x->right == NULL)
                final_collection.push_back(digit);
            if (x->left != NULL)
            {
                TreeNode *L = x->left;
                node.push_back(L);
                num.push_back(10*digit+(L->val));
            }
            if (x->right != NULL)
            {
                TreeNode *R = x->right;
                node.push_back(R);
                num.push_back(10*digit+(R->val));
            }
        }
        int result = 0;
        for (auto it = final_collection.begin(); it != final_collection.end(); it++)
            result += *it;
        return result;
    }
};

int main()
{
    TreeNode Node1(1);
    TreeNode Node2(2);
    TreeNode Node3(3);
    TreeNode Node4(4);
    TreeNode Node5(5);
    TreeNode Node6(6);
    TreeNode *root = &Node1;
    root->left = &Node2;
    root->right = &Node3;
    Node2.left = &Node4;
    Node2.right = &Node5;
    Node4.right = &Node6;
    Solution solution;
    cout << solution.sumNumbers(root) << endl;
    cout << "Hello world!" << endl;
    return 0;
}
