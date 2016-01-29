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
    int maxDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
        int maxdepth = 0;
        int depth = 1;
        PreVisit(root, depth, maxdepth);
        return maxdepth;
    }

    void PreVisit(TreeNode *CurNode, int depth, int &maxdepth)
    {
        if (CurNode->left == NULL && CurNode->right == NULL)
        {
            if (depth > maxdepth)
                maxdepth = depth;
            return;
        }
        if (CurNode->left != NULL)
        {
            PreVisit(CurNode->left, depth+1, maxdepth);
        }
        if (CurNode->right != NULL)
        {
            PreVisit(CurNode->right, depth+1, maxdepth);
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
    TreeNode *root = &Node1;
//    root->left = &Node2;
//    root->right = &Node3;
//    Node2.left = &Node4;
//    Node2.right = &Node5;
//    Node3.left = &Node6;
    Solution solution;
    cout << solution.maxDepth(root) << endl;
    return 0;
}
