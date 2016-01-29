#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL)
            return true;
        else if ((p == NULL || q == NULL) || p->val != q->val)
            return false;
        else
        {
            //bool flag = false;
            if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
                return true;
            else
                return false;
        }
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
    TreeNode Node7(1);
    TreeNode Node8(2);
    TreeNode Node9(3);
    TreeNode Node10(4);
    TreeNode Node11(5);
    TreeNode Node12(6);
    TreeNode *root1 = &Node1;
    root1->left = &Node2;
    root1->right = &Node3;
    Node2.left = &Node4;
    Node2.right = &Node5;
    Node3.right = &Node6;
    TreeNode *root2 = &Node7;
    root2->left = &Node9;
    root2->right = &Node8;
    Node9.left = &Node12;
    Node8.left = &Node11;
    Node8.right = &Node10;
    Solution solution;
    cout << solution.isSameTree(root1, root2) << endl;
    return 0;
}
