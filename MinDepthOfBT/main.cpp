#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        else
        {
            vector<int> Depth;
            PreVisit(root, Depth, 1);
            return *min_element(Depth.begin(),Depth.end());
        }
    }

    void PreVisit(TreeNode *Node, vector<int> &Depth, int depth)
    {
        if (Node->left == NULL && Node->right == NULL)
        {
            Depth.push_back(depth);
            return;
        }
        if(Node->left != NULL)                 //Be careful of "if" and "else if"
            PreVisit(Node->left, Depth, depth+1);
        if(Node->right != NULL)
            PreVisit(Node->right, Depth, depth+1);
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
    //root->right = &Node3;
    Node2.left = &Node4;
    Node2.right = &Node5;
    Node4.right = &Node6;
    Solution solution;
    cout << solution.minDepth(root) << endl;
    return 0;
}
