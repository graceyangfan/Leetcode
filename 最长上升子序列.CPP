/***
动态规划，从小到大
***/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()<=1)
        {
            return nums.size();
        }
        int n=nums.size();
        vector<int> dp(n,0);
        for(int i=0;i<n;i++)
        {
            dp[i]=1;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        sort(dp.begin(),dp.end());
        return dp[n-1];
    }
};


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> minnums;
        for(int v : nums)
        {
            if(!minnums.size() || v > minnums.back()) 
                minnums.push_back(v);
            else
                *lower_bound(minnums.begin(), minnums.end(), v) = v;
        }
        return minnums.size();
    }
};
