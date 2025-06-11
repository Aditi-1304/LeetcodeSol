class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m= INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            int t = nums[i];
            if(t > m)m=t;
            for(int j=i+1;j<nums.size();j++)
            {
                t *= nums[j];
                if(t > m)m=t;
            }
            if(t > m)m=t;
        }
        return m;
    }
};
