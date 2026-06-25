// class Solution{
//     public:
//     int longestSubstring(string s, int k){
//         int n = s.size();
//         if(n==0 || n<k) return 0;
//         if(k<=1) return n;
//         unordered_map<char,int> freq;
//         for(char c:s) freq[c]++;
//         bool valid = true;
//         for(auto it:freq){
//             if(it.second<k){
//                 valid = false;
//                 break;
//             }
//         }
//         if(valid) return n;
//         int maxLen = 0;
//         int start = 0;
//         for(int i=0;i<n;i++){
//             if(freq[s[i]]<k){
//                 maxLen = max(maxLen,longestSubstring(s.substr(start,i-start),k));
//                 start = i+1;
//             }
//         }
//         maxLen = max(maxLen,longestSubstring(s.substr(start,n-start),k));
//         return maxLen;
//     }
// };

class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() < k) return 0;
        vector<int> cnt(26);
        for (char c : s) cnt[c - 'a']++;
        for (int i = 0; i < s.size(); i++) {
            if (cnt[s[i] - 'a'] < k) {
                int j = i + 1;
                while (j < s.size() && cnt[s[j] - 'a'] < k) j++;
                return max(longestSubstring(s.substr(0, i), k),
                           longestSubstring(s.substr(j), k));
            }
        }
        return s.size();
    }
};