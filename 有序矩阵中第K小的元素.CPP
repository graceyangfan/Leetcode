/***
二分查找，矩阵存在一定的顺序
low=matrix[0][0]
high=matrix[n-1][n-1]
mid=low+(high-low)>>1
只需确保矩阵被划分为两侧，一侧不大于mid，一侧不小于mid
数组的划分可以直接采用左右分界线，而矩阵划分需要采用边界线，边界线近似为一条对角线
可以从一角往另外一边查找，结合矩阵的顺序特征，可以找到一条分界线，在分界线和左侧组合的区域内
数组不大于mid，通过统计该区域的数的个数和k的大小作比较来判定下一个mid的取值在左侧还是右侧，
结合high 和low不断缩小区间
在二分过程中采用了不大于和大于 low=mid+1;
***/


class Solution {
public:
    bool check_direction(vector<vector<int>> & matrix ,int mid,int k )
    {
        int n=matrix.size();
        int i=n-1;
        int j=0;
        int num=0;
        while((i>=0)&&(j<n))
        {
            if(matrix[i][j]<=mid)
            {
                num+=i+1;
                j++;
            }
            else
            {
                i--;
            }
        }
        return num>=k;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(check_direction(matrix,mid,k))
            {
                high=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};
