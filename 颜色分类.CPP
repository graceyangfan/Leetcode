/***
借助快排的思想，引入三个指针,p0代表0的右边界，p2代表2的左边界
,借助curr在0和2之间选择，
结束与curr=p2，通过交换不断扩展边界
为什么与左侧交换后可直接curr++而右侧不行，因为curr是从左边向右侧扫描的，确保了交换后curr是1，因此可以直接++
而右边交换过来的数大小不确定，因此需要扫描
***/
class Solution {
  public:
  /*
  荷兰三色旗问题解
  */
  void sortColors(vector<int>& nums) {
    // 对于所有 idx < p0 : nums[idx < p0] = 0
    // curr 是当前考虑元素的下标
    int p0 = 0, curr = 0;
    // 对于所有 idx > p2 : nums[idx > p2] = 2
    int p2 = nums.size() - 1;
    while(curr<=p2)
    {
        if(nums[curr]==0)
        {
            swap(nums[curr++],nums[p0++]);
        }
        else if(nums[curr]==2)
        {
            swap(nums[curr],nums[p2--]);
        }
        else
        curr++;
    }
  }
};
