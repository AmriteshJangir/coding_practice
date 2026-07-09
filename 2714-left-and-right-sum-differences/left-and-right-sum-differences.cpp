class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int total=0,left=0;
        for(int x:nums) total+=x;
        for(int i=0;i<nums.size();i++){
            total-=nums[i];
            int cur=nums[i];
            nums[i]=abs(left-total);
            left+=cur;
        }
        return nums;
    }
};