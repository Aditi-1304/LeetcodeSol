class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> ia;
        vector<int> ja;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(matrix[i][j] == 0)
                {
                    ia.push_back(i);
                    ja.push_back(j);
                }
            }
        }
        for(int i : ia)
        {
            for(int j=0;j<c;j++)
            {
                matrix[i][j] = 0;
            }
        }
        for(int j : ja)
        {
            for(int i=0;i<r;i++)
            {
                matrix[i][j] = 0;
            }
        }
    }
};
