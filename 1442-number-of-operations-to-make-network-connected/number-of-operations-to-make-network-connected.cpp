class Solution {
public:
    class DisjointSet {
        vector<int> rank;
        vector<int> par;

    public:
        DisjointSet(int n) {
            rank.resize(n + 1, 0);
            par.resize(n + 1);
            for (int i = 0; i <= n; i++) {
                par[i] = i;
            }
        }

        int UltParent(int node) {
            if (par[node] == node)
                return node;
            return par[node] = UltParent(par[node]);
        }

        void insertEdges(int u, int v) {
            int pu = UltParent(u);
            int pv = UltParent(v);

            if (pu == pv)
                return;

            if (rank[pu] > rank[pv])
                par[pv] = pu;
            else if (rank[pu] < rank[pv])
                par[pu] = pv;
            else {
                par[pu] = pv;
                rank[pv]++;
            }
        }
    };

public:
    int makeConnected(int n, vector<vector<int>>& edges) {
        if (edges.size() < n - 1) {
            return -1; // Not enough edges to connect all nodes
        }

        DisjointSet ds(n);
        int extra = 0; // Extra edges that connect already connected components
        int components = n; // Initially, each node is its own component

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (ds.UltParent(u) != ds.UltParent(v)) {
                ds.insertEdges(u, v);
                components--; // Successfully merged two components
            } else {
                extra++; // This edge is extra
            }
        }

        // We need (components - 1) edges to connect all components
        return (extra >= components - 1) ? components - 1 : -1;
    }
};
