class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n > m) return findMedianSortedArrays(nums2, nums1);
        int low = 0, high = n;
        while(low <= high){
            int i = low + (high - low) / 2;
            int j = (n + m + 1) / 2 - i;
            int maxLeftX = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRightX = (i == n) ? INT_MAX : nums1[i];
            int maxLeftY = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRightY = (j == m) ? INT_MAX : nums2[j];
            if(maxLeftX <= minRightY && maxLeftY <= minRightX){
                if((n + m) % 2 == 0){
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                }
                return max(maxLeftX, maxLeftY);
            }
            else if(maxLeftX > minRightY){
                high = i - 1;
            }
            else{
                low = i + 1;
            }
        }
        return 0.0;
    }
};