#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*There can be three situations:
1. the root is the largest on the left subtree of whole tree
2. the root has no right subtree(maybe leaf or not, if leaf, judge case 1)
3. the root has right subtree*/

/*The problem has a bug, when we initialize the class with the root of the tree, we do
can only find those elements bigger than the root, then the left subtree makes no sense!*/

/*The real intention for this problem is just for non-recursive way of middle order visit of a BST*/

//class BSTIterator {
//private:
//    queue<int> record;
//public:
//    BSTIterator(TreeNode *root) {
//        if (root != NULL)
//        {
////            record.push(root->val);
////            TreeNode *current = root;
////            if (current->right != NULL)
////            {
////                PreVisit(current->right);
////            }
//            PreVisit(root);
//        }
//    }
//
//    void PreVisit(TreeNode *root)
//    {
//        if (root->left != NULL)
//            PreVisit(root->left);
//        record.push(root->val);
//        if (root->right != NULL)
//            PreVisit(root->right);
//    }
//
//    /** @return whether we have a next smallest number */
//    bool hasNext() {
//        if (record.empty())
//            return false;
//        else
//            return true;
//    }
//
//    /** @return the next smallest number */
//    int next() {
//        int x = record.front();
//        record.pop();
//        return x;
//    }
//};

class BSTIterator {
private:
    vector<TreeNode *> record;
public:
    BSTIterator(TreeNode *root) {
        if (root != NULL)
        {
            getElem(root);  //find all left elements
        }
    }

    void getElem(TreeNode *root)
    {
        TreeNode *current = root;
        while(current != NULL)
        {
            record.push_back(current);
            current = current->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (record.empty())
            return false;
        else
            return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *x = record.back();
        record.pop_back();
        getElem(x->right);  //get all right-left elements
        return x->val;
    }
};

int main()
{
    TreeNode Node1(9);
    TreeNode Node2(6);
    TreeNode Node3(12);
    TreeNode Node4(5);
    TreeNode Node5(8);
    TreeNode Node6(10);
    TreeNode Node7(15);
    TreeNode Node8(4);
    TreeNode Node9(7);
    TreeNode Node10(11);
    TreeNode Node11(14);
    //TreeNode Node12(6);
    TreeNode *root = &Node1;
    root->left = &Node2;
    root->right = &Node3;
    Node2.left = &Node4;
    Node2.right = &Node5;
    Node3.left = &Node6;
    Node3.right = &Node7;
    Node4.left = &Node8;
    Node5.left = &Node9;
    Node6.right = &Node10;
    Node7.left = &Node11;
    BSTIterator i = BSTIterator(root);
    while (i.hasNext())
        cout << i.next() << endl;
    //cout << "Hello world!" << endl;
    return 0;
}
