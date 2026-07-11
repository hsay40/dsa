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
    bool isValidBST(TreeNode* root) {
         auto curr = root;
        stack<TreeNode*> st;
        long long prev = LLONG_MIN; //given range in question
        bool check = true;
        while(curr!=nullptr || !st.empty()){
            while(curr!=nullptr){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();

            if(curr->val<=prev){
                check = false;
                break;
            }
            prev = curr->val;


            curr = curr->right;
                // if(!is_sorted(v.begin(), v.end())){  vector approach will take o(n^2))
                //     check = false;
                //     break;
                // }

        }
        return check;
    }
};