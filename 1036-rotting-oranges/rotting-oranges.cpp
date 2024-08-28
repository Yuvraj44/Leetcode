class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector <vector<int>> vis(grid.size(), vector <int>(grid[0].size(), 0));
        queue <vector<int>> q;

        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j,0});
                    vis[i][j]=1;
                }
            }
        }
        int dx[]={0,1,-1,0};
        int dy[]={1,0,0,-1};
        int ans=0;
        while(!q.empty())
        {
            vector <int> temp=q.front();
            int r=temp[0];
            int c=temp[1];
            int t=temp[2];
            ans=max(t, ans);

            q.pop();

            for(int i=0; i<4; i++)
            {
                int nr=r+dx[i];
                int nc=c+dy[i];

                if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc]==1 && vis[nr][nc]==0)
                {
                    q.push({nr,nc,t+1});
                    vis[nr][nc]=1;
                }
            }
        }

        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                {
                    ans=-1;
                }
            }
        }
        
        return ans;
    }
};