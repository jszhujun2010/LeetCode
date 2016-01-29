#include <iostream>
#include <vector>
#include "Solution.h"

using namespace std;

//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};


int main()
{
    int tree[3] = {1,2,2};
    vector<TreeNode> NodeSet;
    for (int i = 0; i < 3; i++)
    {
        TreeNode CurNode(tree[i]);
        //CurNode->TreeNode(tree[i]);
        NodeSet.push_back(CurNode);
    }
    TreeNode* root = &NodeSet[0];
    for (int j = 0; j < 1; j++)
    {
        if (tree[2*j+1] < 0)
            NodeSet[j].left = NULL;
        else
            NodeSet[j].left = &NodeSet[2*j+1];
        if (tree[2*j+2] < 0)
            NodeSet[j].right = NULL;
        else
            NodeSet[j].right = &NodeSet[2*j+2];
    }

    //cout << root->right->val << endl;
    Solution solution;
    if (solution.isSymmetric(root))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}
