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
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return true;
        else
        {
            bool flag = true;
            int depth = 0;
            PreVisit(root, flag);
            return flag;
        }
    }

    int PreVisit(TreeNode *curNode, bool &flag)
    {
        int leftdepth = 0;
        int rightdepth = 0;
        int depth;
        if (curNode->left == NULL && curNode->right == NULL)
            return 0;
        if (curNode->left != NULL)
        {
            depth = PreVisit(curNode->left, flag);
            if (!flag)
                return -1;
            leftdepth = depth + 1;
        }
        if (curNode->right != NULL)
        {
            depth = PreVisit(curNode->right, flag);
            if (!flag)
                return -1;
            rightdepth = depth + 1;
        }
        if (leftdepth - rightdepth > 1 || leftdepth - rightdepth < -1)
        {
            flag = false;
            return -1;
        }
        depth = max(leftdepth, rightdepth);
        return depth;
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
    //Node2.right = &Node5;
    Node4.left = &Node6;
    Solution solution;
    cout << solution.isBalanced(root) << endl;
    return 0;
}
