class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb;
        function<void(int,int)> backtrack = [&](int start, int k) {
            if (k == 0) {
                res.push_back(comb);
                return;
            }
            for (int i = start; i <= n - k + 1; i++) {
                comb.push_back(i);
                backtrack(i + 1, k - 1);
                comb.pop_back();
            }
        };
        backtrack(1, k);
        return res;
    }
};