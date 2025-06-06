class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int t=1;
        while(i<nums.size() && nums[i] <= 0)i++;
        for(;i<nums.size();i++)
        {
            if(i != 0 && nums[i] == nums[i-1])
            {
                continue;
            }
            if(nums[i] != t)return t;
            t++;
        }
        return t;
    }
};
