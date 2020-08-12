class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> count;
        for(int i=0;i<nums.size();i++)
        {
            count[nums[i]]++;
        }
        int n=nums.size();
        int maxcount=count.begin()->second;
        int res=count.begin()->first;
        for(auto it=count.begin();it!=count.end();it++)
        {
            if(it->second>n/2&& it->second>maxcount)
            {
                res=it->first;
            }
        }
        return res;
    }
};
