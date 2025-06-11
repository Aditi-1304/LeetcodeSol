class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)return 0;

        int sum_max = nums[0];
        int sum_curr = nums[0];
        for(int n=1;n < nums.size();n++)
        {
            sum_curr = max(sum_curr+nums[n], nums[n]);
            sum_max = max(sum_max,sum_curr);
        }
        return sum_max;
    }
};
