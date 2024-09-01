class Solution {
public:

    bool check(vector <vector <int>> graph, int src, vector <int> &col)
    {
        col[src]=0;

        queue<int> q;
        q.push(src);

        while(!q.empty())
        {
            int node=q.front();

            q.pop();

            for(auto it: graph[node])
            {
                if(col[it]==-1)
                {
                    col[it]=!col[node];
                    q.push(it);
                }
                else
                {
                    if(col[it]==col[node])
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector <int> col(graph.size(), -1);
        bool ans;
        for(int i=0; i<graph.size(); i++)
        {
            if(col[i]==-1)
            {
                ans=check(graph, i, col);
                if(ans==false)
                return false;
            }
        }
        return true;
    }
};