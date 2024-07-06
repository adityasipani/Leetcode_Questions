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
    TreeNode* invertTree(TreeNode* root) {
        //bas ecae
        if(root==nullptr) return 0;

        invertTree(root->left); //postorder
        invertTree(root->right);

        //swapping
     TreeNode *temp=root->left;
        root->left=root->right;
        root->right=temp;

        return root;

        
    }
};