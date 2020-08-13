/***除了考虑出入stack的顺序外，还要考虑res的值
入stack和出stack顺序相反，
int: top->left-right
get-vaule top->right-left 
true :left->right->top 
***/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> res;
        if(root==NULL) return res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* curr=st.top();
            st.pop();
            if(curr!=NULL)
            {
                res.push_back(curr->val);
            }
            else
            {
                continue;
            }
            st.push(curr->left);
            st.push(curr->right);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
