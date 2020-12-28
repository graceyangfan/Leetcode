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



## 分两种状态
## (1)NULL 压栈只要不是叶子节点就处于压栈状态
## 且永远先压左子树
##注意！NULL的代码，其反序就是出栈顺序，左数访问完毕，右数访问完毕
##此时就可以访问母节点
##用nullptr作为地雷安放，压栈过程中不会触及
##只要遇到叶子节点，压栈暂停，开始访问
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        stack<TreeNode *> stk;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode* p=stk.top();
            stk.pop();
            if(p!=nullptr)
            {
                stk.push(p);
                stk.push(nullptr);
                if(p->right) stk.push(p->right);
                if(p->left)  stk.push(p->left);
            }
            else
            {
                p=stk.top();
                stk.pop();
                res.push_back(p->val);
            }
        }
        return res;
    }
};
