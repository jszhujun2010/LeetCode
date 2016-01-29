#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//public:
//    vector<int> rightSideView(TreeNode* root) {
//        vector<int> result;
//        vector<TreeNode*>  layer;
//        if (!root)
//            return result;
//        layer.push_back(root);
//        result.push_back(root->val);
//        while (!layer.empty()) {
//            vector<TreeNode*>  cur_layer;
//            for (int i = 0; i < layer.size(); i++) {
//                if (layer[i]->left)
//                    cur_layer.push_back(layer[i]->left);
//                if (layer[i]->right)
//                    cur_layer.push_back(layer[i]->right);
//            }
//            if (!cur_layer.empty())
//                result.push_back(cur_layer.back()->val);
//            layer = cur_layer;
//        }
//        return result;
//    }
//};

//class Solution {
//public:
//    vector<int> rightSideView(TreeNode* root) {
//        vector<int> result;
//        dfs(1, result, root);
//
//        return result;
//    }
//
//    void dfs(int layer, vector<int> &result, TreeNode* root) {
//        if (!root) return;
//        if (layer > result.size()) result.push_back(root->val);
//
//        dfs(layer+1, result, root->right);
//        dfs(layer+1, result, root->left);
//    }
//};

/*The basic idea is to calc the number of left generation(direct only)
and the number of right generation(direct only), if left greater than
right, just use part of left*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        result.push_back(root->val);

        vector<int> left = rightSideView(root->left);
        vector<int> right = rightSideView(root->right);
        left.insert(left.begin(), result.begin(), result.end());
        right.insert(right.begin(), result.begin(), result.end());


        if (left.size() <= right.size()) {
            return right;
        }
        else {
            right.insert(right.end(), left.begin()+right.size(), left.end());
            return right;
        }
    }
};

int main() {
    TreeNode *root = new TreeNode(0);
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n6 = new TreeNode(6);
    TreeNode *n7 = new TreeNode(7);

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n2->left = n4;
    n2->right = n7;
    n3->right = n5;
    n5->left = n6;

    Solution sln = Solution();
    vector<int> result = sln.rightSideView(root);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}
