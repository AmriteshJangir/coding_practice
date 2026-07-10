class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b){ return nums[a] < nums[b]; });
        vector<int> pos(n);
        for(int i = 0; i < n; i++) pos[order[i]] = i;
        vector<int> val(n);
        for(int i = 0; i < n; i++) val[i] = nums[order[i]];
        vector<int> reach(n);
        for(int i = 0, j = 0; i < n; i++){
            if(j < i) j = i;
            while(j + 1 < n && val[j+1] - val[i] <= maxDiff) j++;
            reach[i] = j;
        }
        vector<int> comp(n);
        for(int i = 1; i < n; i++){
            comp[i] = comp[i-1] + (val[i] - val[i-1] > maxDiff ? 1 : 0);
        }
        int LOG = 1;
        while((1 << LOG) < n) LOG++;
        vector<vector<int>> jump(LOG, vector<int>(n));
        jump[0] = reach;
        for(int k = 1; k < LOG; k++){
            for(int i = 0; i < n; i++){
                jump[k][i] = jump[k-1][jump[k-1][i]];
            }
        }
        int q = queries.size();
        vector<int> ans(q);
        for(int qi = 0; qi < q; qi++){
            int u = queries[qi][0], v = queries[qi][1];
            int pu = pos[u], pv = pos[v];
            if(comp[pu] != comp[pv]){ ans[qi] = -1; continue; }
            if(pu == pv){ ans[qi] = 0; continue; }
            if(pu > pv) swap(pu, pv);
            int dist = 0;
            int cur = pu;
            for(int k = LOG - 1; k >= 0; k--){
                if(jump[k][cur] < pv){
                    cur = jump[k][cur];
                    dist += (1 << k);
                }
            }
            if(cur < pv) dist++;
            ans[qi] = dist;
        }
        return ans;
    }
};