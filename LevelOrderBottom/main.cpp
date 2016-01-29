#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root)
    {
        vector<vector<int> > result;
        vector<int> vec;
        queue<TreeNode*> CurLine;
        if (root == NULL)
            return result;
        else
        {
            TreeNode *CurNode;
            CurLine.push(root);
            int curline = 1;
            int nextline = 0;
            while (!CurLine.empty())
            {
                CurNode = CurLine.front();
                CurLine.pop();
                curline--;
                if (CurNode->left != NULL)
                {
                    CurLine.push(CurNode->left);
                    nextline++;
                }
                if (CurNode->right != NULL)
                {
                    CurLine.push(CurNode->right);
                    nextline++;
                }
                vec.push_back(CurNode->val);
                if (curline == 0)
                {
                    curline = nextline;
                    nextline = 0;
                    result.insert(result.begin(), vec);
                    vec.clear();
                }
            }
            return result;
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
    Node3.left = &Node6;
    Solution solution;
    vector<vector<int> > result = solution.levelOrderBottom(root);
    for (auto i = result.begin(); i != result.end(); i++)
    {
        for (auto j = (*i).begin(); j!= (*i).end(); j++)
        {
            cout << *j << " ";
        }
        cout << endl;
    }
    return 0;
}
