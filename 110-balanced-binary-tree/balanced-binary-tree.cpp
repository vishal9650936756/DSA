/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root){
        if(root == 0){
        return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);

        return (max(lh, rh)+1);
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        int p = height(root->left);
        int q = height(root->right);

        if (abs(p - q) <= 1 && isBalanced(root->left) && isBalanced(root->right)){
            return true;
        }

        return false;
    }
};