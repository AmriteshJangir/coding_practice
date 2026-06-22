class Solution {
public:
    bool canSplit(vector<int>& weights, int capacity, int days) {
        int currentLoad = 0;
        int requiredDays = 1;
        for (int weight : weights) {
            if (currentLoad + weight > capacity) {
                requiredDays++;
                currentLoad = weight;
                if (requiredDays > days)
                    return false;
            }
            else {
                currentLoad += weight;
            }
        }
        return true;
    }
    int splitArray(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canSplit(weights, mid, days))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};