class Solution{
    public:
        void backtrack(vector<string>& ans, string& current, int open, int close, int max){
        if(current.length() == max * 2){
            ans.push_back(current);
            return;
        }
        if(open < max){
            current.push_back('(');
            backtrack(ans, current, open + 1, close, max);
            current.pop_back();
        }
        if(close < open){
            current.push_back(')');
            backtrack(ans, current, open, close + 1, max);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n){
        vector<string> ans;
        string current;
        backtrack(ans, current, 0, 0, n);
        return ans;
    }
    
};