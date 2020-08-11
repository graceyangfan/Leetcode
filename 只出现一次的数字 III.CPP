/***
二进制取反加1刚好等于取负号
 (~sign) + 1=-sign;
 异或^ 相同取0，不同取1
 & 只有全为1才是1
 | 只要有1就是1 
sign &(~sign)=0 (不可能出现两个1）

int dif = ans1 & (-ans1);找到从左往右第一位不相同的位置
该位置必然属于出现奇数次的两个数之一

此后对数组分类，分为三类，重复出现偶数次的数字，以及出现奇数次的a,b
判断if(num&dif) ,出现偶数次的数字必然偶数次进入该循环（包括0次）
只要采用^运算就能消除这些数字的影响
另外两个出现奇数次的a,b必然有且只有一个能进入该循环
故只需要ans2 ^= num;，ans2初始值为0,0^num=num
获得an2后对ans1(a^b)再做a^b^b=a即可

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
