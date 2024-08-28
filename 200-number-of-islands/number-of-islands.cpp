class Solution {
public:
    
    
    void bfs(int i, int j, vector <vector <int>> &vis, vector<vector<char>>& grid)
    {
        vis[i][j]=1;
        queue<pair<int, int>> q;
        q.push({i, j});
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int idx=-1; idx<=1; idx++)
            {
                for(int jdx=-1; jdx<=1; jdx++)
                {
                    int nrow=row+idx;
                    int ncol=col+jdx;
                     
                    if((idx==-1&&jdx==-1) || (idx==-1&&jdx==1) || (idx==1&&jdx==-1) || (idx==1&&jdx==1)){
                        continue;
                    }
                    if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol]=='1' && vis[nrow][ncol]==0)
                    {
                        vis[nrow][ncol]=1;
                        q.push({nrow, ncol});
                    }
                }
            }

            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        vector <vector <int>> vis(grid.size(), vector<int>(grid[0].size(),0));

        for(int i=0; i< grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(vis[i][j]==0 && grid[i][j] == '1')
                {
                    bfs(i, j, vis, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};