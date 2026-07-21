class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ones = 0;
        for (char c : s)
            if (c == '1')
                ones++;
        string t = "1" + s + "1";
        int ans = ones;
        int m = t.size();
        for (int i = 1; i < m - 1;) {
            if (t[i] != '0') {
                i++;
                continue;
            }
            int leftZero = 0;
            while (i < m - 1 && t[i] == '0') {
                leftZero++;
                i++;
            }
            int oneBlock = 0;
            while (i < m - 1 && t[i] == '1') {
                oneBlock++;
                i++;
            }
            if (oneBlock == 0) continue;
            int rightZero = 0;
            int j = i;
            while (j < m - 1 && t[j] == '0') {
                rightZero++;
                j++;
            }
            if (leftZero > 0 && rightZero > 0)
                ans = max(ans, ones + leftZero + rightZero);
        }
        return min(ans, n);
    }
};