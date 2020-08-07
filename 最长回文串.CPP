/***
hashmap记录出现的奇数和偶数的次数
偶数没有影响直接相加，奇数-1可以直接用，中间使用奇数最多的值填充
***/

class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> count;
        for(int i=0;i<s.size();i++)
        {
            count[s[i]]++;
        }
        int res=0;
        bool single=false;
        for(auto it=count.begin();it!=count.end();it++)
        {
            if(it->second%2==0)
            {
                res+=it->second;
            }
            else 
            {
                res+=it->second-1;
                single=true;
            }
        }
        if(single) res+=1;
        return res;
    }
};

/*** 官方
***/
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        int ans = 0;
        for (char c : s)
            ++count[c];
        for (auto p : count) {
            int v = p.second;
            ans += v / 2 * 2;
            if (v % 2 == 1 and ans % 2 == 0)
                ++ans;
        }
        return ans;
    }
};

