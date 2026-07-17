class Solution{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights){
        if(heights.empty()||heights[0].empty()) return {};
        int m=heights.size(),n=heights[0].size();

        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));
        function<void(int,int,vector<vector<bool>>&)> dfs=[&](int i,int j,
        vector<vector<bool>>& ocean){
            int dirs[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
            for(auto &dir:dirs){
                int x=i+dir[0],y=j+dir[1];

                if(x>=0&&x<m&&y>=0&&y<n&&!ocean[x][y]&&heights[x][y]>=heights[i][j]){
                    ocean[x][y]=true;
                    dfs(x,y,ocean);
                }
            }
        };

        for(int i=0;i<m;i++){
            pacific[i][0]=true;
            dfs(i,0,pacific);
            atlantic[i][n-1]=true;
            dfs(i,n-1,atlantic);
        }

        for(int j=0;j<n;j++){
            pacific[0][j]=true;
            dfs(0,j,pacific);
            atlantic[m-1][j]=true;
            dfs(m-1,j,atlantic);
        }
        
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j]&&atlantic[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};