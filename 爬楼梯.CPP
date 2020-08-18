class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1)
        {
            return 1;
        }
        int f=1;
        int g=1;
        while(n>1)
        {
            f=f+g;
            g=f-g;
            n--;
        }
        return f;

    }
};
