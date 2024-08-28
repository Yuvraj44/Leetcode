class Solution {
public:

    void dfs(vector<vector<int>>& image, int r, int c, int init, vector<vector<int>> &vis, int dx[], int dy[], int color)
    {
        vis[r][c]=color;
        for(int ind=0; ind<4; ind++)
        {
            int nr=r+dx[ind];
            int nc=c+dy[ind];

            if(nr>=0 && nc>=0 &&  nr<image.size() && nc<image[0].size() && image[nr][nc]==init && vis[nr][nc]!=color)
            {
                vis[nr][nc]=color;
                dfs(image, nr, nc, init, vis, dx, dy, color);
            }
            
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int init=image[sr][sc];
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        vector <vector<int>> vis=image;
        
                dfs(image, sr, sc, init, vis, dx, dy, color);
            
        return vis;
    }
};
