#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    void draw() {
        vector<int> num;
        help_draw(this, num);
    }

    void help_draw(TreeNode* root, vector<int> num) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            for (int n: num)
                cout << n << "->";
            cout << root->val << endl;
            return;
        }
        num.push_back(root->val);
        help_draw(root->left, num);
        help_draw(root->right, num);
    }
};

TreeNode* array_to_tree(vector<int> nums) {
    int n = nums.size();
    if (n < 1) return NULL;
    int i = 1, j = 0;
    while (i < n)  {
        j += 1;
        i *= 2;
    }
    if (i-1 == n) j++;
    vector<TreeNode*> numTree;
    for (int k = 0; k < n; k++)
        numTree.push_back(new TreeNode(nums[k]));
    for (int k = 0; k < n; k++) {
        if (numTree[k]->val != INT_MIN) {
            if (2*k+1 <= n-1) {
                if (numTree[2*k+1]->val != INT_MIN)
                    numTree[k]->left = numTree[2*k+1];
                else
                    numTree[k]->left = NULL;
            }
            if (2*k+2 <= n-1) {
                if (numTree[2*k+2]->val != INT_MIN)
                    numTree[k]->right = numTree[2*k+2];
                else
                    numTree[k]->right = NULL;
            }
        }
    }

    return numTree[0];
}

void Preorder(TreeNode* root, vector<int>& preorder) {
    if (!root)
        return;

    preorder.push_back(root->val);
    Preorder(root->left, preorder);
    Preorder(root->right, preorder);
}

void Inorder(TreeNode* root, vector<int>& inorder) {
    if (!root)
        return;

    Inorder(root->left, inorder);
    inorder.push_back(root->val);
    Inorder(root->right, inorder);
}

void Postorder(TreeNode* root, vector<int>& postorder) {
    if (!root)
        return;

    Postorder(root->left, postorder);
    Postorder(root->right, postorder);
    postorder.push_back(root->val);
}

void printVector(vector<int> vec) {
    for (int i: vec)
        cout << i << " ";
    cout << endl;
}


/*iterative disgusting!!!*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return create(inorder, preorder, 0, inorder.size()-1, 0, preorder.size()-1);
    }

    TreeNode* create(vector<int>& inorder, vector<int>& preorder,
                     int inLeft, int inRight, int preLeft, int preRight)
    {
        if (preLeft > preRight) return NULL;

        TreeNode* root = new TreeNode(preorder[preLeft]);

        int i = inLeft;
        while (inorder[i] != root->val)
            i++;

        TreeNode* left = create(inorder, preorder, inLeft, i-1, preLeft+1, preLeft+i-inLeft);
        TreeNode* right = create(inorder, preorder, i+1, inRight, preLeft+i-inLeft+1, preRight);

        root->left = left;
        root->right = right;

        return root;
    }
};


int main() {
    vector<int> tree = {6, 2, 8, 0, 4, 7, 9, INT_MIN, INT_MIN, 3, 5};
    TreeNode* root = array_to_tree(tree);
    vector<int> inorder, preorder;
    Inorder(root, inorder);
    Preorder(root, preorder);

    Solution sln = Solution();
    TreeNode* newroot = sln.buildTree(preorder, inorder);
    newroot->draw();
}

