class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> parts;
        vector<vector<string>> ans;
        func(0, s, parts, ans);
        return ans;
    }
    bool isPalin(string s, int l, int h) {
        while (l <= h) {
            if (s[l++] != s[h--])
                return false;
        }
        return true;
    }
    void func(int ind, string s, vector<string> parts,
              vector<vector<string>> &ans) {
        if (ind == s.length()) {
            ans.push_back(parts);
            return;
        }

        for (int i = ind; i < s.length(); i++) {
            if (isPalin(s, ind, i)) {
                parts.push_back(s.substr(ind, i - ind + 1));
                func(i + 1, s, parts, ans);
                parts.pop_back();
            }
        }
    }
};