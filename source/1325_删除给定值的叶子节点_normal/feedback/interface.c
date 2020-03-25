#include "../interface.h"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* removeLeafNodes(struct TreeNode* root, int target)
{
    struct TreeNode *flag;
    if (root == NULL) {
        return NULL;
    }
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);
    if (root->val == target) {
        if (root->right == NULL && root->left == NULL) {
            return NULL;
        }
    }
    return root;
}