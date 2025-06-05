class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size());
        int left=0,right=0;
        for(int i=0;i<l.size();i++)
        {
            left = l[i];
            right = r[i];
            vector<int> x;
            for(int j = left;j<=right;j++)
            {
                x.push_back(nums[j]);
            }
            sort(x.begin(),x.end());
            int m = x[1] - x[0];
            int f=0;
            for(int j=1;j<x.size();j++)
            {
                if(m != (x[j]-x[j-1]))
                {
                    f = 1;
                }
            }
            if(f == 1)
            {
                ans[i] = false;
            }
            else
            {
                ans[i] = true;
            }
        }
        return ans;
        
    }
};
