/***
使用Hashmap记忆各个元素出现次数,map iter->first,iter->second 分别访问key和values
priority_queue<type,based_Container,function> function可以使用greater<type> 或者less<type> 分别表示大顶堆和小顶堆
优先队每次插入会自动排序，如果时pair，会先按照第一个排序，再按照第二个排序
算法复杂度为O(nlogk)
***/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        //find max and min 
        map<int,int> count;
        for(int i=0;i<nums.size();i++)
        {
            count[nums[i]]++;
        }
        priority_queue<pair<int, int> > a;

        for(auto iter=count.begin();iter!=count.end();iter++)
        {
            a.push(make_pair(iter->second,iter->first));
        }

        vector<int> res(k,0);
        for(int i=0;i<k;i++)
        {
            res[i]=a.top().second;
            a.pop();
        }
        return res;
    }
};
