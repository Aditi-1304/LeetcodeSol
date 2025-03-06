class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> a;
        // int x=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] < pivot)
            {
                a.push_back(nums[i]);
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == pivot)
            {
                a.push_back(nums[i]);
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] > pivot)
            {
                a.push_back(nums[i]);
            }
        }
        return a;
    }
};
