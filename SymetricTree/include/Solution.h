#ifndef SOLUTION_H
#define SOLUTION_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    public:
        //Solution();
        //virtual ~Solution();
        bool isSymmetric(TreeNode *root);
        bool RecursiveJudge(TreeNode *lc, TreeNode *rc);
};

#endif // SOLUTION_H
