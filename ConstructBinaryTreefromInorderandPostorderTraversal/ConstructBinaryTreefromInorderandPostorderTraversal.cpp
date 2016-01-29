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

/*Time Limit Exceeded*/
/*I should change it to pass index format*/
//class Solution {
//public:
//    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//        if (postorder.size() < 1) return NULL;
//
//        int rootVal = postorder[postorder.size()-1];
//        TreeNode* root = new TreeNode(rootVal);
//        vector<int> inLeft, inRight, postLeft, postRight;
//
//        /*split inorder*/
//        int i = 0;
//        while (inorder[i] != rootVal)
//            inLeft.push_back(inorder[i++]);
//        i++;
//        while (i <= inorder.size()-1)
//            inRight.push_back(inorder[i++]);
//
//        /*split postorder*/
//        set<int> inLeftSet (inLeft.begin(), inLeft.end());
//        i = 0;
//        while (inLeftSet.find(postorder[i]) != inLeftSet.end()) {
//            postLeft.push_back(postorder[i++]);
//        }
//        while (i < postorder.size()-1)
//            postRight.push_back(postorder[i++]);
//
////        printVector(inLeft);
////        printVector(inRight);
////        printVector(postLeft);
////        printVector(postRight);
//
//        TreeNode* left = buildTree(inLeft, postLeft);
//        TreeNode* right = buildTree(inRight, postRight);
//
//        root->left = left;
//        root->right = right;
//
//        return root;
//    }
//};

/*iterative disgusting!!!*/
//class Solution {
//public:
//    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//        return create(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
//    }
//
//    TreeNode* create(vector<int>& inorder, vector<int>& postorder,
//                     int inLeft, int inRight, int postLeft, int postRight)
//    {
//        if (postLeft > postRight) return NULL;
//
//        TreeNode* root = new TreeNode(postorder[postRight]);
//
//        int i = inLeft;
//        while (inorder[i] != root->val)
//            i++;
//
//        TreeNode* left = create(inorder, postorder, inLeft, i-1, postLeft, postLeft+i-inLeft-1);
//        TreeNode* right = create(inorder, postorder, i+1, inRight, postLeft+i-inLeft, postRight-1);
//
//        root->left = left;
//        root->right = right;
//
//        return root;
//    }
//};

/*disgusting iterative fashion*/
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() == 0)return NULL;
        TreeNode *p;
        TreeNode *root;
        stack<TreeNode *> stn;

        root = new TreeNode(postorder.back());
        stn.push(root);
        postorder.pop_back();

        while(true)
        {
            if(inorder.back() == stn.top()->val)
            {
                p = stn.top();
                stn.pop();
                inorder.pop_back();
                if(inorder.size() == 0) break;
                if(stn.size() && inorder.back() == stn.top()->val)
                    continue;
                p->left = new TreeNode(postorder.back());
                postorder.pop_back();
                stn.push(p->left);
            }
            else
            {
                p = new TreeNode(postorder.back());
                postorder.pop_back();
                stn.top()->right = p;
                stn.push(p);
            }
        }
        return root;
    }
};

int main() {
    vector<int> tree = {6, 2, 8, 0, 4, 7, 9, INT_MIN, INT_MIN, 3, 5};
    TreeNode* root = array_to_tree(tree);
    vector<int> inorder, postorder;
    Inorder(root, inorder);
    Postorder(root, postorder);

    Solution sln = Solution();
    TreeNode* newroot = sln.buildTree(inorder, postorder);
    newroot->draw();
}
