#include <iostream>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        bool flag = false;
        if (root == NULL)
            return false;
       PreVisit(root, 0, sum, flag);
       return flag;
    }

    void VisitNode(TreeNode *CurNode, int &cur_sum)
    {
        cur_sum += CurNode->val;
        return;
    }

    void PreVisit (TreeNode *CurNode, int cur_sum, int sum, bool &flag)
    {
        VisitNode(CurNode, cur_sum);
        if (CurNode->left == NULL && CurNode->right == NULL)
        {
            if (cur_sum == sum)
                flag = true;
            else
                flag = false;
            return;
        }
        if (CurNode->left != NULL)
        {
           PreVisit(CurNode->left, cur_sum, sum, flag);
           if (flag)
                return;
        }
        if (CurNode->right != NULL)
        {
            PreVisit(CurNode->right, cur_sum, sum, flag);
            if (flag)
                return;
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
    root->left = &Node2;
    root->right = &Node3;
    Node2.left = &Node4;
    Node2.right = &Node5;
    Node3.right = &Node6;
    Solution solution;
    cout << solution.hasPathSum(root,10) << endl;
    return 0;
}
