class Solution {
public:
    int trap(vector<int>& height) {
        int t=0;
        vector<int> pmax(height.size());
        pmax[0] = height[0];
        for(int j=1;j<height.size();j++)
        {
            pmax[j] = max(height[j], pmax[j-1]);
        }

        vector<int> smax(height.size());
        smax[height.size()-1] = height[height.size()-1];
        for(int j=height.size()-2;j>=0;j--)
        {
            smax[j] = max(height[j], smax[j+1]);
        }

        for(int i=0;i<height.size();i++)
        {
            int hleft = pmax[i], hright = smax[i];
            if(height[i] < hleft && height[i] < hright)
            {
                t += min(hleft,hright) - height[i];
            }
        }
        return t;
    }
};
