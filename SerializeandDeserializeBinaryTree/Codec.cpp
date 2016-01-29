#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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

/*memory limit!!!*/
//class Codec {
//public:
//
//    // Encodes a tree to a single string.
//    string serialize(TreeNode* root) {
//        int depth = max_depth(root, 0);
//        int all = 1;
//        int d = depth;
//        while (d > 0) {
//            all *= 2;
//            d--;
//        }
//        all--;
//
//        vector<int> nums(all);
//        string s = "";
//
//        vector<TreeNode*> last;
//        vector<TreeNode*> cur;
//        last.push_back(root);
//
//        for (int i = 1; i < depth; i++) {
//            for (TreeNode* x: last) {
//                if (!x) {
//                    cur.push_back(NULL);
//                    cur.push_back(NULL);
//                    s += "NULL,";
//                }
//                else {
//                    cur.push_back(x->left);
//                    cur.push_back(x->right);
//                    s += to_string(x->val)+",";
//                }
//            }
//            last = cur;
//            cur.clear();
//        }
//        while (!last.empty() && !last.back())
//            last.pop_back();
//
//        if (!last.empty()) {
//            for (int i = 0; i < last.size()-1; i++) {
//                TreeNode* x = last[i];
//                if (!x) s+= "NULL,";
//                else s += to_string(x->val)+",";
//            }
//            TreeNode* x = last[last.size()-1];
//            s += to_string(x->val);
//        }
//
//        return s;
//    }
//
//    int max_depth(TreeNode *root, int depth) {
//        if (!root)
//            return depth;
//
//        return max(max_depth(root->left, depth+1), max_depth(root->right, depth+1));
//    }
//
//    // Decodes your encoded data to tree.
//    TreeNode* deserialize(string data) {
//        vector<int> nums;
//        std::stringstream ss(data);
//        string item;
//        while (getline(ss, item, ',')) {
//            if (item == "NULL")
//                nums.push_back(INT_MIN);
//            else
//                nums.push_back(stoi(item));
//        }
//
//        int n = nums.size();
//        if (n < 1) return NULL;
//        int i = 1, j = 0;
//        while (i < n)  {
//            j += 1;
//            i *= 2;
//        }
//        if (i-1 == n) j++;
//        vector<TreeNode*> numTree;
//        for (int k = 0; k < n; k++)
//            numTree.push_back(new TreeNode(nums[k]));
//        for (int k = 0; k < n; k++) {
//            if (numTree[k]->val != INT_MIN) {
//                if (2*k+1 <= n-1) {
//                    if (numTree[2*k+1]->val != INT_MIN)
//                        numTree[k]->left = numTree[2*k+1];
//                    else
//                        numTree[k]->left = NULL;
//                }
//                if (2*k+2 <= n-1) {
//                    if (numTree[2*k+2]->val != INT_MIN)
//                        numTree[k]->right = numTree[2*k+2];
//                    else
//                        numTree[k]->right = NULL;
//                }
//            }
//        }
//
//        return numTree[0];
//    }
//};

/*pre-order traverse solution*/
class Codec {
public:

    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);

        string s = out.str();
        return s;
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        TreeNode* root = deserialize(in);

        return root;
    }

private:

    void serialize(TreeNode* root, ostringstream& out) {
        if (!root)
            out << "# ";
        else {
            out << root->val << " ";
            serialize(root->left, out);
            serialize(root->right, out);
        }
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;

        if (val == "#")
            return NULL;
        else {
            TreeNode* root = new TreeNode(stoi(val));
            root->left = deserialize(in);
            root->right = deserialize(in);
            return root;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


int main() {
//    vector<int> tree = {6, 2, 8, 0, 4, 7, 9, INT_MIN, INT_MIN, 3, 5};
    vector<int> tree;
    for (int i = 1; i < 1000; i++) {
        tree.push_back(i);
        tree.push_back(INT_MIN);
    }
    tree.push_back(1000);

    TreeNode* root = array_to_tree(tree);

    root->draw();
    Codec codec;
    string s = codec.serialize(root);
    cout << s << endl;
    TreeNode* newroot = codec.deserialize(s);
    newroot->draw();
}
