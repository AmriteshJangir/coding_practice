class Solution {
public:
    vector<bool> pathExistenceQueries(long n, vector<int>& nums, long long maxDiff, vector<vector<int>>& queries) {
        vector<bool> res;
        vector<int> parent(n);
        for(int i=0;i<n;i++) parent[i]=i;
        function<int(int)> find=[&](int x){
            if(parent[x]==x) return x;
            return parent[x]=find(parent[x]);
        };
        for(int i=0;i<n-1;i++){
            if(nums[i+1]-nums[i]<=maxDiff)
                parent[find(i)]=find(i+1);
        }
        for(auto &q:queries)
            res.push_back(find(q[0])==find(q[1]));
        return res;
    }
};