// class Solution {
// public:
//     bool isNumber(string s) {
//         bool digit = false, dot = false, exp = false, digitExp = true;
//         for (int i = 0; i < s.size(); i++) {
//             if (isdigit(s[i])) {
//                 digit = true;
//                 if (exp) digitExp = true;
//             }
//             else if (s[i] == '+' || s[i] == '-') {
//                 if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
//                     return false;
//             }
//             else if (s[i] == '.') {
//                 if (dot || exp)
//                     return false;
//                 dot = true;
//             }
//             else if (s[i] == 'e' || s[i] == 'E') {
//                 if (exp || !digit)
//                     return false;
//                 exp = true;
//                 digitExp = false;
//             }
//             else
//                 return false;
//         }
//         return digit && digitExp;
//     }
// };

class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        bool isdot = false, nums = false, ise = false;
        for(int i=0; i<n; i++){
            if(isdigit(s[i])) nums = true;
            else if(s[i] == '+' || s[i] == '-'){
                if(i > 0 && (s[i-1] != 'e' && s[i-1] != 'E')) return false;
            }
            else if(s[i] == 'e' || s[i] == 'E'){
                if(ise || !nums) return false;
                ise = true;
                nums = false;
            }
            else if(s[i] == '.'){
                if(isdot || ise) return false;
                isdot = true;
            }
            else return false;
        }
        return nums;
    }
};