/*** 二叉搜索树天然满足中序遍历
***/ 

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()&&nums.size()<k)
        {
            TreeNode* curr=st.top();
            if(curr!=NULL)
            {
                st.pop();
                if(curr->right) st.push(curr->right);
                st.push(curr);
                st.push(NULL);
                if(curr->left) st.push(curr->left);
            }
            else
            {
                st.pop();
                nums.push_back(st.top()->val);
                st.pop();
            }
        }
        return nums[nums.size()-1];
    }
};
