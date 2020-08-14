/***
一层一层的访问，先进去先出来，queue
对一层先记录长度，用指针++来访问即可

queue常用方法
    bool empty() const  
    {   // test if queue is empty  
        return (c.empty());  
    }  
  
    size_type size() const  
    {   // return length of queue  
        return (c.size());  
    }  
    reference front()  
    {   // return first element of mutable queue  
        return (c.front());  
    }  
  
    reference back()  
    {   // return last element of mutable queue  
        return (c.back());  
    }  
    void pop()  
    {   // erase element at end  
        c.pop_front();  
    }  
  
***/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<vector<int>> res;
        if(root==NULL) return res;
        qu.push(root);
        while(!qu.empty())
        {
            vector<int> resint;
            int l=qu.size();
            for(int i=0;i<l;i++)
            {
                TreeNode* curr=qu.front();
                qu.pop();
                resint.push_back(curr->val);
                if(curr->left) qu.push(curr->left);
                if(curr->right) qu.push(curr->right);
            }
            res.push_back(resint);
        }
        return res;
    }
};
