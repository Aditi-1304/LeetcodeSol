class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int mx = 0;
        int j = n-1;
        int i=0;
        for(;i<j;)
        {
            int val = (min(height[i] , height[j])) * (j-i);
            if(mx < val)
            {
                mx = val;
            }
            if(height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return mx;
    }
};
