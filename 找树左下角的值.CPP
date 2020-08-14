/***广度优先
层次遍历
***/

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        int res=root->val;
        while(!qu.empty())
        {
            int l=qu.size();
            for(int i=0;i<l;i++)
            {
                TreeNode* curr=qu.front();
                qu.pop();
                if(i==0) res=curr->val;
                if(curr->left) qu.push(curr->left);
                if(curr->right) qu.push(curr->right);
            }
        }
        return res;
    }
};
