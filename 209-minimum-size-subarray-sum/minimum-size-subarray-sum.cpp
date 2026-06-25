// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int n = nums.size();
//         int ans = INT_MAX;
//         int sum = 0, left = 0;
//         for (int right = 0; right < n; right++) {
//             sum += nums[right];
//             while (sum >= target) {
//                 ans = min(ans, right - left + 1);
//                 sum -= nums[left++];
//             }
//         }
//         return ans == INT_MAX ? 0 : ans;
//     }
// };

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int sum = 0;
        int minLen = INT_MAX;
        while (right < n) {
            sum += nums[right++];
            while (sum >= target) {
                minLen = min(minLen, right - left);
                sum -= nums[left++];
            }
        }
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};