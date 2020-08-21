/*** 动态规划，背包问题

分配 n+1,target +1
为了求解一个问题从小到大所有问题都被求解一次。

d[i][j]表示长度为i（nums[0:i])的序列中抽取一些数使得其和为j
(1)
 for(int i=0;i<n;i++)
 {
     dp[i][0]=true;
 }
 使得和为0，任意长度都满足，只有抽选0个数就好了
 (2) 状态转移
 for(int i=1;i<n+1;i++)
 {
    ## 考察dp[i][j]和dp[i-1][?]
    if(nums[i-1]>j)
    {
      ## 长度为i的数组的最后一个数不影响dp[i][j]，
      dp[i][j]=dp[i-1][j]
    else
    {
      ## 长度为i的数组的最后一个数影响dp[i][j]，
      a.最后那个数属于被选取的数之一，从dp[i-1][j-nums[i-1]]转移到dp[i][j]
      b.不属于被选数，对dp[i][j]没有什么影响
      dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]]
 }
***/


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto num:nums)
        {
            sum+=num;
        }
        if(sum%2==1)
        {
            return false;
        }
        int target=sum/2;
        //找到一些数之和为target
        int n = nums.size();
        //dp[i][j]表示从数组的 [0, i] 这个子区间内挑选一些正整数，每个数只能用一次，使得这些数的和恰好等于 j 
        vector<vector<bool>> dp(n+1,vector<bool>(target+1,false) );
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<=target;j++)
            {
                if(j - nums[i-1] < 0)//背包容量放不下第i个数 
                    dp[i][j] = dp[i-1][j];//不将第i个数放入背包
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];//逻辑与 前面表示第i个数不放入背包，后面表示放入背包
            }
        }
        return dp[n][target];
    }
};
