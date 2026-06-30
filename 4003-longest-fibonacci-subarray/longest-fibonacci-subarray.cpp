// class Solution {
// public:
//     int longestSubarray(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return 0;
//         int maxLen = 1;
//         int currLen = 1;
//         for (int i = 1; i < n; i++) {
//             if (nums[i] > nums[i - 1]) {
//                 currLen++;
//             } else {
//                 maxLen = max(maxLen, currLen);
//                 currLen = 1;
//             }
//         }
//         maxLen = max(maxLen, currLen);
//         return maxLen;
//     }
// };
class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int ans=2,curr=2;
        int n=a.size();
        for(int i=2;i<n;i++){
            if(a[i]==a[i-1] + a[i-2]) curr++;
            else curr=2;
            ans  =max(ans,curr);
        }
        return ans;
    }
};
