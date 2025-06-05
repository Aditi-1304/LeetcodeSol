class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int i=0,j=0;
        int m=0;
        while(i<r-2)
        {
            for(j=0;j<c-2;j++)
            {
                int s=0;
                s+=grid[i][j]+grid[i][j+1]+grid[i][j+2];
                s+= grid[i+1][j+1];
                s+= grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
                if(s>m)m=s;
            }
            i++;
        }
        return m;
        
    }
};
