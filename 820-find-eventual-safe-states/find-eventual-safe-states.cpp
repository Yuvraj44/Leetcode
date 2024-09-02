class Solution {
public:

    bool check(int src, vector<vector<int>>& graph, vector <int> &vis, vector <int> &pathvis, vector <int> &safe)
    {
        vis[src]=1;
        pathvis[src]=1;
        safe[src]=0;

        for(auto it: graph[src])
        {
            if(vis[it] == 0)
            {
                if(check(it, graph, vis, pathvis, safe)==true)
                return true;
            }
            else if(pathvis[it]==1)
            return true;
        }

        safe[src]=1;
        pathvis[src]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector <int> vis(graph.size(), 0);
        vector <int> pathvis(graph.size(), 0);
        vector <int> safe(graph.size(), 0);
        vector <int> ans;
        for(int i=0; i<graph.size(); i++)
        {
            if(vis[i]==0)
            {
                check(i, graph, vis, pathvis, safe);
            }
        }

        for(int i=0; i<graph.size(); i++)
        {
            if(safe[i]==1)
            ans.push_back(i);
        }
        return ans;
    }
};