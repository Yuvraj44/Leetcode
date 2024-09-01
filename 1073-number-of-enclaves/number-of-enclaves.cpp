class Solution {
public:
void dfs(int r, int c, vector <vector<int>> &vis, vector<vector<int>>& board, int dx[], int dy[])
    {
        vis[r][c]=1;
        for(int ind=0; ind<4; ind++)
        {
            int nr=r+dx[ind];
            int nc=c+dy[ind];

            if(nr>=0 && nc>=0 && nr<board.size() && nc<board[0].size() && vis[nr][nc]==0 && board[nr][nc]==1)
            {
                dfs(nr, nc, vis, board, dx, dy);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& board) {
         int n=board.size();
        int m=board[0].size();
        int res=0;
        vector <vector<int>> vis(n, vector <int>(m,0));

        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};

        for(int i=0; i<m; i++)
        {
            if(board[0][i]==1 && vis[0][i]==0)
            dfs(0, i, vis, board, dx, dy);
            
            if(board[n-1][i]==1 && vis[n-1][i]==0)
            dfs(n-1, i, vis, board, dx, dy);
        }

        for(int i=0; i<n; i++)
        {
            if(board[i][0]==1 && vis[i][0]==0)
            dfs(i, 0, vis, board, dx, dy);
            
            if(board[i][m-1]==1 && vis[i][m-1]==0)
            dfs(i, m-1, vis, board, dx, dy);
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]==1 && vis[i][j]==0)
                res++;
            }
        }
        return res;
    }
};


    