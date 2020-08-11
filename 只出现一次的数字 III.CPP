/***
二进制取反加1刚好等于取负号
 (~sign) + 1=-sign;
 异或^ 相同取0，不同取1
 & 只有全为1才是1
 | 只要有1就是1 
sign &(~sign)=0 (不可能出现两个1）

***/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans1 = 0, ans2 = 0;
        for (int& num : nums) ans1 ^= num;
        int dif = ans1 & (-ans1);

        for (int& num : nums) if (num & dif) ans2 ^= num;
        return { ans1 ^ ans2 , ans2 };
    }
};只出现一次的数字 III
