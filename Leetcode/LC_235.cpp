#include<stdio.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;
        if (root == p || root == q)
            return root;
        TreeNode* lChild = lowestCommonAncestor(root->left, p, q);
        TreeNode* rChild = lowestCommonAncestor(root->right, p, q);
        if (lChild && rChild)
            return root;
        if (lChild && !rChild)
            return lChild;
        if (rChild && !lChild)
            return rChild;
        return NULL;
    }
};