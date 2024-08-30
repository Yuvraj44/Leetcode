class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector <vector <int>> vis(m, vector <int>(n,0));
        vector <vector <int>> ans(m, vector <int>(n,0));
        queue <vector <int>> q;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j,0});
                    vis[i][j]=1;
                }
            }
        }

        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        while(!q.empty())
        {
            cout<<q.size()<<endl;
            vector <int> temp=q.front();
            int r=temp[0];
            int c=temp[1];
            int d=temp[2];

            q.pop();

            ans[r][c]=d;

            for(int ind=0; ind<4; ind++)
            {
                int nr=r + dx[ind];
                int nc=c+dy[ind];

                if(nr>=0 && nc>=0 && nr<m && nc<n && vis[nr][nc]==0 && mat[nr][nc]==1)
                {
                    q.push({nr,nc,d+1});
                    vis[nr][nc]=1;
                }
            }
        }
        return ans;
    }
};