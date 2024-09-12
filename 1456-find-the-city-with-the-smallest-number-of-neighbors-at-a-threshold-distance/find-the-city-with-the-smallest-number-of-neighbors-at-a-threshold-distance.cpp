class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector <vector<int>> adj(n, vector <int>(n, INT_MAX));
        
        for(auto it: edges)
        {
            adj[it[0]][it[1]]=it[2];
            adj[it[1]][it[0]]=it[2];
        }
        
        for(int i=0; i<n; i++)
        adj[i][i]=0;

        for(int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(adj[i][k]==INT_MAX || adj[k][j]==INT_MAX)
                    continue;

                    adj[i][j]=min(adj[i][j], adj[i][k]+ adj[k][j]);
                }
            }
        }

        int ans=-1;
        int cnt=INT_MAX;
        for(int i=0; i<n; i++)
        {
            int c=0;
            for(int j=0; j<n; j++)
            {
                if(adj[i][j] <= distanceThreshold)
                c++;
            }
            if(c <= cnt)
            {
                cnt=c;
                ans=i;
            }
        }
        
        return ans;
    }
};