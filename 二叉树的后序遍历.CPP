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
## 出压栈和把结果输入到res中,如果不考虑把结果输入到res中那么代码为：
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
            if(## in stack condition )
            {
                ## in stack 
                stk.push(p);
                if(p->right) stk.push(p->right);
                if(p->left)  stk.push(p->left);
            }
            else( ## out stack condition)
            {
                ## out stack 
            }
        }
        return res;
    }
};

##现在考察什么情况下需要把结果输入到res中？？？
##当然是当左右子树都被访问完了,此时的节点是需要输入到res中,但是二叉树并没有原生方法告诉我们限制左右子树已经访问完成
##因此我们需要自己加入标签来说明，这里用一个nullptr 来说明即可
                stk.push(p);
                stk.push(nullptr);
                if(p->right) stk.push(p->right);
                if(p->left)  stk.push(p->left);
##在入栈时就添加标签,一但左右子树访问完成(出栈必然和入栈反序），此时触发标签,进入out stack condition.
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

