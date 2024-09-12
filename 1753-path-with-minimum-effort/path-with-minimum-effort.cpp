class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n=heights.size();
        int m=heights[0].size();

        vector <vector <int>> effort(n, vector <int>(m, INT_MAX));
        effort[0][0]=0;

        priority_queue <vector <int>, vector <vector<int>>, greater <vector<int>>> q;
        q.push({0,0,0});

        vector <int> dx={0, 1, 0, -1};
        vector <int> dy={1, 0, -1, 0};

        while(!q.empty())
        {
            auto temp=q.top();

            int e=temp[0];
            int r=temp[1];
            int c=temp[2];

            q.pop();

            if(r==n-1 && c==m-1)
            return effort[n-1][m-1];

            for(int i=0; i<4; i++)
            {
                int nr=r+dx[i];
                int nc=c+dy[i];

                if(nr>=0 && nc>=0 && nr< n && nc<m)
                {
                    int diff= max(effort[r][c], abs(heights[r][c]- heights[nr][nc]));
                    if(diff < effort[nr][nc])
                    {
                        effort[nr][nc]=diff;
                        q.push({diff, nr, nc});
                    } 
                }
            }
        }
        return 0;
    }
};