class Solution {
public:

    bool check(int src, vector <int> adj[], vector <int> &vis, vector <int> &pathvis)
    {
        vis[src]=1;
        pathvis[src]=1;

        for(auto it : adj[src])
        {
            if(vis[it]==0)
            {
                if(check(it, adj, vis, pathvis)==true)
                return true;
            }
            else if(pathvis[it]==1)
            return true;
        }
        pathvis[src]=0;
        return false;
    }

    bool isCycle(vector <int> adj[], int n)
    {
        vector <int> vis(n, 0);
        vector <int> pathvis(n, 0);

        for(int i=0; i<n; i++)
        {
            if(vis[i]==0)
            {
                if(check(i, adj, vis, pathvis)==true)
                return true;
            }
        }
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        
        for(int i = 0; i < prerequisites.size(); i++) 
        {
            int v = prerequisites[i][0], u = prerequisites[i][1];
            adj[u].push_back(v);
        }
        
        return !(isCycle(adj, numCourses));

    }
};