class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                int curr=0;
                stack<int> sti;
                stack<int> stj;
                if(grid[i][j]==1)
                {
                    sti.push(i);
                    stj.push(j);
                    while(!sti.empty())
                    {
                        int cur_i=sti.top();
                        int cur_j=stj.top();
                        sti.pop();
                        stj.pop();
                        if(cur_i<0||cur_j<0||cur_i>=grid.size()||cur_j>=grid[0].size()||grid[cur_i][cur_j]==0) continue;
                        curr++;
                        grid[cur_i][cur_j]=0;
                        sti.push(cur_i+1);stj.push(cur_j);
                        sti.push(cur_i-1);stj.push(cur_j);
                        sti.push(cur_i);stj.push(cur_j+1);
                        sti.push(cur_i);stj.push(cur_j-1);
                    }
                }
                res=max(res,curr);
            }
        }
    return res;
    }
};
