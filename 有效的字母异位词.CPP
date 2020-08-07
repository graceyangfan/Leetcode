/***
使用两个hash表，比较两个hashmap是否完全一致
***/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int> l;
        unordered_map<char,int> r;
        for(int i=0;i<s.size();i++)
        {
            l[s[i]]++;
        }
        for(int j=0;j<t.size();j++)
        {
            r[t[j]]++;
        }
        int sizeofst=0;
        for(auto it=l.begin();it!=l.end();it++)
        {
            if((r[it->first])&&(r[it->first]==it->second))
            {
                sizeofst++;
            }
        }
        if(sizeofst==l.size())
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};

/***
使用1个Hashmap,一个增加统计，一个减少统计
***/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int> count;
        for(int i=0;i<s.size();i++)
        {
            count[s[i]]++;
            count[t[i]]--;
        }
        bool res=true;
        for(auto it=count.begin();it!=count.end();it++)
        {
            if(it->second!=0) res=false;
        }
        return res;
        
    }
};
