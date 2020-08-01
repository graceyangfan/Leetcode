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
