class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) 
    {
        int n=adj.size();
        vector <int> topo;
        vector <int> indegree(n, 0);
        queue <int> q;

        vector<vector<int>> adjRev(n);
        for(int i=0; i<n; i++)
        {
            for(auto it: adj[i])
            {
                adjRev[it].push_back(i);
                indegree[i]++;
            }        
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

            for(auto it: adjRev[node])
            {
                indegree[it]--;

                if(indegree[it]==0)
                q.push(it);
            }
        }
        sort(topo.begin(), topo.end());
        return topo;
    }
};