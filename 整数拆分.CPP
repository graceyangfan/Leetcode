class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        int quotient = n / 3;
        int remainder = n % 3;
        if (remainder == 0) {
            return (int)pow(3, quotient);
        } else if (remainder == 1) {
            return (int)pow(3, quotient - 1) * 4;
        } else {
            return (int)pow(3, quotient) * 2;
        }
    }
};

/***动态规划
从小到大一次求解保存到vector中
***/
class Solution {
public:
    int integerBreak(int n) {
        if (n < 4) {
            return n - 1;
        }
        vector<int> dp(n+1);
        dp[2]=1;
        for(int i=3;i<=n;i++)
        {
            dp[i]=max(max(2*(i-2),2*dp[i-2]),max(3*(i-3),3*dp[i-3]));
        }
        return dp[n];
    }
};
