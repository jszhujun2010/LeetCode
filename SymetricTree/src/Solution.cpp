#include <stddef.h>
#include "Solution.h"

/*struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};*/


bool Solution::isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    else if((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL))
        return false;
    TreeNode *lc = root->left;
    TreeNode *rc = root->right;
    if (RecursiveJudge(lc,rc))
        return true;
    else
        return false;
}

bool Solution::RecursiveJudge(TreeNode *lc, TreeNode *rc)
{
    if (lc->val == rc->val)
    {
        if (lc->left != NULL && rc->right != NULL)
        {
            if (RecursiveJudge(lc->left, rc->right))
                if (lc->right != NULL && rc->left != NULL)
                    if (RecursiveJudge(lc->right, rc->left))
                        return true;
                    else
                        return false;
                else if (lc->right == NULL && rc->left == NULL)
                    return true;
                else
                    return false;
            else
                return false;
        }
        else if (lc->left == NULL && rc->right == NULL)
        {
            if (lc->right != NULL && rc->left != NULL)
                if (RecursiveJudge(lc->right, rc->left))
                    return true;
                else
                    return false;
            else if (lc->right == NULL && rc->left == NULL)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}
