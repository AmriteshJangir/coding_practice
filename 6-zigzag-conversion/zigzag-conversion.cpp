class Solution{
    public:
    string convert(string s, int numberRows){
        if(numberRows == 1) return s;
        vector<string> rows(min(numberRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;
        for(char c: s){
            rows[curRow] += c;
            if(curRow == 0 || curRow == numberRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }
        string ret;
        for(string row: rows) ret += row;
        return ret;
    }
};