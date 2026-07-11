
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         int pi= p->val;
//         int qi= q->val;
//         int curr = root->val;
//      if(root==nullptr){
//         return root;
//      }   
//         if(curr<pi && curr<qi){
//             return lowestCommonAncestor(root->right,p,q);
//         }
//         if(curr>pi && curr>qi){
//             return lowestCommonAncestor(root->left,p,q);
//         }
//             return root;

//     }
// };



class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == NULL) return NULL;
        if (q == p) return NULL;

        while (root != NULL){

            if (q->val > root->val && p->val > root-> val) root = root->right;
            else if (q->val < root-> val && p->val < root->val) root = root->left;
            else return root;

        }
        return NULL;

        
    }
};