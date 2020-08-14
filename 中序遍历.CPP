/***
压入顺序：右->中->左
每次压入都要到达最低的左子树
只要没有触碰到子树的左叶子节点，node==NULL就不会被触发，因为每次都会压入一个左子树节点
因此第一次触发node==NULL比然是到达子树的最左节点，因为此时可以开始进入中序遍历了，因此进入了node==NULL
触碰NULL自动回溯到局部子树的父亲，由于父亲之上push的node是右局部子树，因此进入右局部子树的访问
***/
/***
十分有趣的是利用NULL来调节压入和写出的顺序
如果没有NULL，会在最左边的叶子节点处反复出入stack，因此必须用NULL进入另外一个循环
整个过程为：
(1)压左子树
(2)读取左子树
(3)访问中值
(4)压右子树
(5)读右子树
***/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if(node!=NULL)
            {
                st.pop();
                if(node->right) st.push(node->right);
                st.push(node);
                st.push(NULL);
                if(node->left) st.push(node->left);
            }
            else
            {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val); 
            }
        }
        return result;
    }
};
