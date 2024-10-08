class Solution {
public:

vector <int> isCyclebfs(vector <int> adj[], int n)
    {
        vector <int> topo;
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

            topo.push_back(node);

            for(auto it: adj[node])
            {
                indegree[it]--;

                if(indegree[it]==0)
                q.push(it);
            }
        }
        vector <int> ans;
        if(topo.size()!=n)
        return ans;
        else
        return topo;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> adj[numCourses];

        for(int i=0; i<prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            
        }
        vector <int> ans;
        ans=isCyclebfs(adj, numCourses);
        return ans;
    }
};