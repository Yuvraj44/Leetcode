class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> m;
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto temp = q.front(); q.pop();
            TreeNode* node = temp.first;
            int x = temp.second.first, y = temp.second.second;
            m[x][y].insert(node->val);
            if (node->left) q.push({node->left, {x - 1, y + 1}});
            if (node->right) q.push({node->right, {x + 1, y + 1}});
        }

        for (auto& p : m) {
            vector<int> col;
            for (auto& q : p.second)
                col.insert(col.end(), q.second.begin(), q.second.end());
            ans.push_back(col);
        }
        return ans;
    }
};
