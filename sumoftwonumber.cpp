/***
直接采用hashmap的查找，因为直接查找为O(1),不存在会返回false
***/
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mymap;
        vector<int> result;
        for(int i=0;i<nums.size();i++)
        {
            mymap[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            if((mymap[target-nums[i]])&&(mymap[target-nums[i]]!=i))
            {
                result.push_back(i);
                result.push_back(mymap[target-nums[i]]);
                return result;
            }
        }
        return result;
	}
};
