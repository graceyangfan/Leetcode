/***
采用快排的思想，先使用rand()再swap相当于随机选择中轴值，可以避免划分的两部分极度不平衡
为了避免l++和r--带来的l>r使用了双重的while,比较时采用严格的比较，改变内容分布后，两个指针要向中间移动，扩展两侧长度
快速排序的特点为：
平均时间 nlogn
最坏为n**2
排序不稳定,可能导致数组顺序发生变化
***/
class Solution {
public:
    int quickSelect(vector<int> & a,int l,int r,int index)
    {
        int q=randomPartition(a,l,r);
        if(q==index)
        {
            return a[q];
        }
        else
        {
            return q<index?quickSelect(a,q+1,r,index):quickSelect(a,l,q-1,index);
        }
    }

    int randomPartition(vector<int> & a,int l,int r)
    {
        // random select 
        int i =rand()%(r-l+1)+l;
        swap(a[i],a[l]);
        int partition=a[l];
        while(l<r)
        {
            while(l<r)
            {
                if(partition<a[r])
                {
                    r--;
                }       
                else
                {
                    a[l++]=a[r];
                    break;
                }        
            }
            while(l<r)
            {
                if(a[l]<partition)
                {
                    l++;
                }
                else
                {
                    a[r--]=a[l];
                    break;
                }
            }
        }// assert l==r 
        a[l]=partition;
        return l;
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};
