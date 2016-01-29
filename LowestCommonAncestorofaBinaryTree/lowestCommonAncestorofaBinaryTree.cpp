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

/*Time exceed...*/
//class Solution {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if (!root) return NULL;
//
//        vector<bool> sign(false, 2); //sign[0] stands for p, sign[1] is q
//
//        return searchAncestor(root, p, q, sign);
//    }
//
//    TreeNode* searchAncestor(TreeNode* root, TreeNode* p, TreeNode* q, vector<bool>& sign) {
//        if (root == p) {
//            sign[0] = true;
//            return p;
//        }
//        if (root == q) {
//            sign[1] = true;
//            return q;
//        }
//
//        if (root->left) {
//            search_help(root->left, p, q, sign);
////            cout << "root = " << root->val << endl;
////            cout << "sign[0] = " << sign[0] << ", sign[0] = " << sign[1] << endl;
//
//            if (sign[0] && sign[1]) {
//                sign[0] = false;
//                sign[1] = false;
//                return searchAncestor(root->left, p, q, sign);
//            }
//            else if(!sign[0] && !sign[1]) {
//                if (root->right)
//                    return searchAncestor(root->right, p, q, sign);
//                else
//                    return NULL;
//            }
//            else {
//                return root;
//            }
//        }
//        else if (root->right) {
//            return searchAncestor(root->right, p, q, sign);
//        }
//        else
//            return NULL;
//    }
//
//    void search_help(TreeNode* root, TreeNode* p, TreeNode* q, vector<bool>& sign) {
//        if (root == p)
//            sign[0] = true;
//        if (root == q)
//            sign[1] = true;
//
//        if (sign[0] && sign[1])
//            return;
//
//        if (root->left)
//            search_help(root->left, p, q, sign);
//        if (root->right)
//            search_help(root->right, p, q, sign);
//
//        return;
//    }
//};

/*cheated*/
//class Solution {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if (!root || root == p || root == q) return root;
//        TreeNode* left = lowestCommonAncestor(root->left, p, q);
//        TreeNode* right = lowestCommonAncestor(root->right, p, q);
//
//        if (left && right) return root;
//        return left ? left: right;
//    }
//};


/*path way*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path;
        bool flag = false;
        vector<TreeNode*> tp = find_path(root, p, path, flag);

        path.clear();
        flag = false;
        vector<TreeNode*> tq = find_path(root, q, path, flag);

        TreeNode* last = NULL;
        int n = min(tp.size(), tq.size());
        for (int i = 0; i < n; i++) {
            if (tp[i] == tq[i]) {
                last = tp[i];
            }
            else
                break;
        }
        return last;
    }

    vector<TreeNode*> find_path(TreeNode* root, TreeNode* t, vector<TreeNode*> path, bool &flag) {
        if (!root)
            return path;
        if (!root->left && !root->right && root != t)
            return path;

        path.push_back(root);
        if (root == t) {
            flag = true;
            return path;
        }

        vector<TreeNode*> left = find_path(root->left, t, path, flag);
        if (flag)
            return path;
        else
            return find_path(root->right, t, path, flag);

    }
};

int main() {
    vector<int> tree = {3, 5, 1, 6, 2, 0, 8, INT_MIN, INT_MIN, 7, 4};
    TreeNode* root = array_to_tree(tree);
//    root->draw();

    Solution sln = Solution();
    TreeNode* p = root->right->left;
    TreeNode* q = root->right->right;

//    vector<TreeNode*> path;
//    bool flag = false;
//    path = sln.find_path(root, p, path, flag);
//
//    for (TreeNode* t: path)
//        cout << t->val << " " << endl;
//    cout << endl;

    TreeNode* an = sln.lowestCommonAncestor(root, p, q);
    cout << an->val << endl;

    return 0;
}
