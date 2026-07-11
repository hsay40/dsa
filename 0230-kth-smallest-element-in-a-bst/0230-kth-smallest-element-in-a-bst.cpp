//inroot traversal for kth smallest 

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        auto curr = root;
        stack<TreeNode*> st;
        while(curr!=nullptr || !st.empty()){
            while(curr!=nullptr){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            k--;
            if(k==0){ return curr->val;}
            curr = curr->right;
        }
return -1;

    }
};
