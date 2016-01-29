#include <iostream>
#include <vector>

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

    /*so much effort!!! the core idea is that
    we should keep track of every path.
    It is not sufficient for us to keep one-d
    array to record path, instead, we should use
    two-d array so that every path in it*/
    void iter_draw() {
        vector<TreeNode*> stacks;
        vector<vector<int>> num;
        stacks.push_back(this);
        vector<int> tmp;
        tmp.push_back(this->val);
        num.push_back(tmp);
        while (!stacks.empty()) {
            TreeNode *cur = stacks.back();
            vector<int> path = num.back();
            stacks.pop_back();
            num.pop_back();

            if (!cur->left && !cur->right) {
                for (int i = 0; i < path.size()-1; i++)
                    cout << path[i] << "->";
                cout << path[path.size()-1] << endl;
            }

            if (cur->right) {
                stacks.push_back(cur->right);
                vector<int> temp = path;
                temp.push_back(cur->right->val);
                num.push_back(temp);
            }
            if (cur->left) {
                stacks.push_back(cur->left);
                vector<int> temp = path;
                temp.push_back(cur->left->val);
                num.push_back(temp);
            }
        }
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

//class Solution {
//public:
//    void flatten(TreeNode* root) {
//        /*base case*/
//        if (!root) return;
//        TreeNode *tmp = help(root);
//    }
//
//    TreeNode* help(TreeNode* root) {
//        if (!root) return NULL;
//
//        if (!root->left && !root->right)
//            return root;
//
//        TreeNode* bottom = root;
//        TreeNode* right = root->right;
//        root->right = root->left;
//
//        if (root->left) bottom = help(root->left);
//
//        if (bottom) {
//            bottom->right = right;
//            bottom = right;
//        }
//
//        if (right) TreeNode* tmp = help(right);
//
//        return bottom;
//    }
//};


//class Solution {
//public:
//    void flatten(TreeNode* root) {
//        /*base case*/
//        if (!root) return;
//
//        TreeNode* left = root->left;
//        TreeNode* right = root->right;
//
//        flatten(left);
//        flatten(right);
//
//        root->left = NULL;
//        root->right = left;
//        while (root->right) root = root->right;
//        root->right = right;
//    }
//};


/*non-recursive version*/
//class Solution {
//public:
//    void flatten(TreeNode* root) {
//        TreeNode* left;
//        TreeNode* right;
//        while (root) {
//            left = root->left;
//            right = root->right;
//            if (left) {
//                while (left->right)
//                    left = left->right;
//                left->right = right;
//                root->right = root->left;
//                root->left = NULL;
//            }
//            root = root->right;
//        }
//    }
//};

/*use prev version*/
/*This is so brillaint!!! each time, we keep prev as last time's root.
we start from right child tree, then return top of right child tree.
and    we start flatten right child tree    and again we go down to the
right most child which is next root(as prev), and we link it with
last prev*/
class Solution {
private:
    TreeNode* prev = NULL;
public:
    void flatten(TreeNode* root) {
        if (!root)
            return;
        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        prev = root;
    }
};


int main() {
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n8 = new TreeNode(8);
//
//    n1->left = n2;
//    n1->right = n3;
//    n2->left = n4;
//    n2->right = n7;
//    n4->right = n8;
//    n3->left = n5;
//    n5->right = n6;

    n1->left = n2;
    n1->right = n5;
    n2->left = n3;
    n2->right = n4;
    n5->right = n6;

    //INT_MIN stands for null
//    vector<int> tree = {1, 2, 3, 4, INT_MIN, 6, 7, 8, 9};
//    TreeNode* root = array_to_tree(tree);
//    root->draw();


    n1->iter_draw();
//    Solution sln = Solution();
//    sln.flatten(n1);
//    while (n1) {
//        cout << n1->val << endl;
//        n1 = n1->right;
//    }
    return 0;
}
