/***
牛顿法：
2*x_i(x-x_i)+xi**2-C=0
=>
x=0.5*(x_i+C/x_i)

***/
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        double C = x, x0 = x;
        while (true) {
            double xi = 0.5 * (x0 + C / x0);
            if (fabs(x0 - xi) < 1e-7) {
                break;
            }
            x0 = xi;
        }
        return int(x0);
    }
};

二分法

class Solution {
public:
    int mySqrt(int x) {
        long l = 1;
        long h = x;
        if (x == 0) return 0;
        if (x == 1) return 1;
        while(l<h)
        {
            int mid=(l+h)/2;
            if(x/mid==mid)
            {
                return mid;
            }
            else if(x/mid>mid)
            {
                l=mid+1;
            }
            else
            {
                h=mid;
            }
        }
        return l-1;
    }
};
