class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int total = nums1.size()+nums2.size();
        int half = total/2;

        const int n = nums1.size();
        const int m = nums2.size();
        const int leftCount = (n + m + 1) / 2;
        int lo = 0, hi = n; 

        while (lo <= hi) {
            int cut1 = (lo + hi) / 2;
            int cut2 = leftCount - cut1;
            int L1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int R1 = cut1 == n ? INT_MAX : nums1[cut1];
            int L2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            int R2 = cut2 == m ? INT_MAX : nums2[cut2];

            if (L1 <= R2 && L2 <= R1) 
            {
                int maxLeft = max(L1, L2);
                int minRight = min(R1, R2);
                return ((n + m) % 2 == 1) ? maxLeft : (maxLeft + minRight) / 2.0;
            }
            if (L1 > R2) hi = cut1 - 1; 
            else lo = cut1 + 1; 
        }
        return 0.0;
    }
};
