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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*>r;

        r.push(p);
        r.push(q);

        while(!r.empty()){
            TreeNode*r1=r.front();
            r.pop();

            TreeNode*r2=r.front();
            r.pop();

            if(r1==nullptr &&r2==nullptr) continue;
            if(r1==nullptr ||r2==nullptr)return false;

            if(r1->val!=r2->val)return false;
             r.push(r1->left);
                r.push(r2->left);
                r.push(r1->right);
                r.push(r2->right);
            

        }
        return true;
        
    }
};