class Solution {
public:
    bool isPalindrome(const string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> mp;

        for (int i = 0; i < words.size(); i++) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            mp[rev] = i;
        }
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            for (int j = 0; j <= word.size(); j++) {
                string left = word.substr(0, j);
                string right = word.substr(j);
                if (isPalindrome(right, 0, right.size() - 1)) {
                    if (mp.count(left) && mp[left] != i) {
                        res.push_back({i, mp[left]});
                    }
                }
                if (j > 0 && isPalindrome(left, 0, left.size() - 1)) {
                    if (mp.count(right) && mp[right] != i) {
                        res.push_back({mp[right], i});
                    }
                }
            }
        }
        return res;
    }
};