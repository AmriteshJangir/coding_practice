
// class Solution{
//     public:
//     string minWindow(string s, string t) {
//         int n = s.size();
//         int m = t.size();
//         if (n < m) return "";
//         unordered_map<char, int> charCount;
//         for (char c : t) {
//             charCount[c]++;
//         }
//         int required = charCount.size();
//         int l = 0, r = 0;
//         int formed = 0;
//         unordered_map<char, int> windowCounts;
//         int minLen = INT_MAX, minLeft = 0;
//         while (r < n) {
//             char c = s[r];
//             windowCounts[c]++;
//             if (charCount.count(c) && windowCounts[c] == charCount[c]) {
//                 formed++;
//             }
//             while (l <= r && formed == required) {
//                 c = s[l];
//                 if (r - l + 1 < minLen) {
//                     minLen = r - l + 1;
//                     minLeft = l;
//                 }
//                 windowCounts[c]--;
//                 if (charCount.count(c) && windowCounts[c] < charCount[c]) {
//                     formed--;
//                 }
//                 l++;
//             }
//             r++;
//         }
//         return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
//     }
// };

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for (char c : t) {
            map[c]++;
        }
        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        while (end < s.size()){
            if (map[s[end++]]-- > 0) {
                counter--;
            }
            while (counter == 0) {
                if (end - begin < d) {
                    head = begin;
                    d = end - head;
                }
                if (map[s[begin++]]++ == 0) {
                    counter++;
                }
            }  
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};