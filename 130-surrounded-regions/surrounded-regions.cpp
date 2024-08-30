class Solution {
public:

    void dfs(int r, int c, vector <vector<int>> &vis, vector<vector<char>>& board, int dx[], int dy[])
    {
        vis[r][c]=1;
        for(int ind=0; ind<4; ind++)
        {
            int nr=r+dx[ind];
            int nc=c+dy[ind];

            if(nr>=0 && nc>=0 && nr<board.size() && nc<board[0].size() && vis[nr][nc]==0 && board[nr][nc]=='O')
            {
                dfs(nr, nc, vis, board, dx, dy);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector <vector<int>> vis(n, vector <int>(m,0));

        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};

        for(int i=0; i<m; i++)
        {
            if(board[0][i]=='O' && vis[0][i]==0)
            dfs(0, i, vis, board, dx, dy);
            
            if(board[n-1][i]=='O' && vis[n-1][i]==0)
            dfs(n-1, i, vis, board, dx, dy);
        }

        for(int i=0; i<n; i++)
        {
            if(board[i][0]=='O' && vis[i][0]==0)
            dfs(i, 0, vis, board, dx, dy);
            
            if(board[i][m-1]=='O' && vis[i][m-1]==0)
            dfs(i, m-1, vis, board, dx, dy);
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]=='O' && vis[i][j]==0)
                board[i][j]='X';
            }
        }
        
    }
};