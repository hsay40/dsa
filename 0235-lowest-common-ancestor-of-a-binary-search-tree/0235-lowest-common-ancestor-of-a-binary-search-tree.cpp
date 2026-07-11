/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pi= p->val;
        int qi= q->val;
        int curr = root->val;
     if(root==nullptr){
        return root;
     }   
        if(curr<pi && curr<qi){
            return lowestCommonAncestor(root->right,p,q);
        }
        if(curr>pi && curr>qi){
            return lowestCommonAncestor(root->left,p,q);
        }
            return root;

    }
};