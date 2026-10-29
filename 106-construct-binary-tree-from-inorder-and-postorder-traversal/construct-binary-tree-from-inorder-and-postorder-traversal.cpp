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
    int search(vector<int>& inorder, int left, int right, int val){
        for(int i=left;i<=right;i++){
            if(inorder[i] == val){
                return i;
            }
        }
        return -1;
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int left, int right, int& postidx){
        if(left > right){
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postidx]);

        int inidx = search(inorder, left, right, postorder[postidx]);
        postidx--;

        root->right = build(inorder,postorder, inidx+1, right, postidx);
        root->left = build(inorder,postorder, left, inidx-1, postidx);
       

        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postidx = postorder.size()-1;
        return build(inorder, postorder, 0, postorder.size()-1, postidx);
    }
};