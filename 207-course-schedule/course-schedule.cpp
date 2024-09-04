class Solution {
public:

    bool dfs(int src, vector <int> adj[], vector <int> &vis, vector <int> &pathvis)
    {
        vis[src]=1;
        pathvis[src]=1;

        for(auto it: adj[src])
        {
            if(vis[it]==0)
            {
                if(dfs(it, adj, vis, pathvis)==true)
                return true;
            }
            else
            {
                if(pathvis[it]==1)
                return true;
            }
        }
        pathvis[src]=0;
        return false;
    }

    bool isCycledfs(vector <int> adj[], int n)
    {
        vector <int> vis (n, 0);
        vector <int> pathvis (n, 0);

        for(int i=0; i<n; i++)
        {
            if(vis[i]==0)
            {
               if(dfs(i, adj, vis, pathvis)==true)
               return true;
            }
        }
        return false;
    }

    bool isCyclebfs(vector <int> adj[], int n)
    {
        int c=0;
        vector <int> indegree(n, 0);
        queue <int> q;

        for(int i=0; i<n; i++)
        {
            for(auto it: adj[i])
            indegree[it]++;
        }

        for(int i=0; i<n; i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }


        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            c++;

            for(auto it: adj[node])
            {
                indegree[it]--;

                if(indegree[it]==0)
                q.push(it);
            }
        }

        if(c!=n)
        return true;
        else
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> adj[numCourses];

        for(int i=0; i<prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            
        }
        bool ans;
        // ans=!(isCycledfs(adj, numCourses));
        ans=!(isCyclebfs(adj, numCourses));
        return ans;
    }
};