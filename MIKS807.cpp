class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int count=0;
        int r = grid.size(),c=grid[0].size();

        // finding max elemnt in each col and storing in vector
        vector<int> col(c);
        for(int i=0;i<c;i++)
        {
            int m = grid[0][i];
            for(int j=1;j<r;j++)
            {
                if(grid[j][i] > m)
                {
                    m = grid[j][i];
                }
            }
            col[i] = m;
        }

        for(int i=0;i<r;i++)
        {
            int m1 = *max_element(grid[i].begin(),grid[i].end());
            
            for(int j=0;j<c;j++)
            {
                int m2 = col[j];
                int x = m1>m2 ? m2 : m1;
                if(x > grid[i][j])
                {
                    count += (x-grid[i][j]);
                }
            }
        }
        return count;
    }
};
