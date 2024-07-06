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
     int findMaxPath(TreeNode* root,int &maxi){
        if(root==nullptr)return 0;

        int maxLeftPathSum= max(0,findMaxPath(root->left,maxi));
          int maxRightPathSum= max(0,findMaxPath(root->right,maxi));

          maxi=max(maxi,maxLeftPathSum + maxRightPathSum + root->val);

          return (root->val) +max(maxLeftPathSum ,maxRightPathSum);


     }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        findMaxPath(root,maxi);
        return maxi;
        
    }
};