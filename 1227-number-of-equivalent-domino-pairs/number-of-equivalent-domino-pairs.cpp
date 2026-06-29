class Solution{
    public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes){
        unordered_map<string, int> mp;
        int count = 0;
        for(auto& d: dominoes){
            string s = to_string(min(d[0], d[1])) + to_string(max(d[0], d[1]));
            count += mp[s];
            mp[s]++;
        }
        return count;
    }
};