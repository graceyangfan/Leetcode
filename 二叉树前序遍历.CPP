/***
二叉树深度优先遍历
前序遍历： 0144.二叉树的前序遍历
后序遍历： 0145.二叉树的后序遍历
中序遍历： 0094.二叉树的中序遍历
二叉树广度优先遍历
层序遍历：0102.二叉树的层序遍历

作者：carlsun-2
链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal/solution/dai-ma-sui-xiang-lu-chi-tou-qian-zhong-hou-xu-de-d/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
这个老哥总结得好
***/
/***递归方式***/
class Solution {
public:
    vector<int> visit(TreeNode* root,vector<int>& res)
    {
        if(root==NULL)
        {
            return res;
        }
        else
        {
            res.push_back(root->val);
            visit(root->left,res);
            visit(root->right,res);
        }
        return res;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        return visit(root,res);
    }
};

/***迭代（这种基本都是使用stack或者queue）***/
/***stack最后进的最先处理，故left在right后入stack***/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        stack<TreeNode*> wait;
        wait.push(root);
        while(!wait.empty())
        {   
            TreeNode* now=wait.top();
            wait.pop();
            if(now!=NULL)
            {
                res.push_back(now->val);
            }
            else
            {
                continue;
            }
            wait.push(now->right);
            wait.push(now->left);
        }
        return res;
    }
};
