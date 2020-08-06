//https://leetcode-cn.com/problems/different-ways-to-add-parentheses/submissions/

/***
语法注意：string取一个为char，用''而不是“”
char 可以直接==比较
substr(i,j)i开始到j，j取不到，不写全默认start=0，end=size()-1
string数字转化为int，采用差值，string-'0'
直接用int会转化assic
分治注意：
result添加只针对只有数字的string，所以只要result的size为0，意味着序列没有+-*（默认子序列返回的result的大小一定大于0）
因此对只有数字的序列 计算
***/
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {

        vector<int> result;
        for(int i=input.size()-1;i>=0;i--)
        {
            char s=input[i];
            if ((s=='+')||(s=='-')||(s=='*'))
            {
                string left=input.substr(0,i);
                string right=input.substr(i+1);
                vector<int> lr=diffWaysToCompute(left);
                vector<int> rr=diffWaysToCompute(right);
                for(int a=0;a<lr.size();a++)
                {
                    for(int b=0;b<rr.size();b++)
                    {
                        if(s=='+')  
                        {
                            result.push_back(lr[a]+rr[b]);
                        }
                        else if(s=='-')
                        {
                            result.push_back(lr[a]-rr[b]);
                        }
                        else
                        {
                            result.push_back(lr[a]*rr[b]);
                        }
                        
                    }
                }
            }
        }
        if(result.size()<1)
        {
            int number=0;
            for(int i=0;j<input.size();j++)
            {
                int a=input[j]-'0';
                number=number*10+a;
            }
            result.push_back(number);
        }
        return result;

    }
};

