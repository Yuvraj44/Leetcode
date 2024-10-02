class Solution {
public:

    void func(int ind, int n, int target, vector <int> &temp, vector <vector <int>> &ans)
    {
        if(temp.size()==n && target==0)
        {
            ans.push_back(temp);
            return;
        }

        for(int i=ind; i<=9; i++)
        {
            if(target  < 0)
            break;

            temp.push_back(i);
            func(i+1, n, target-i, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector <int> temp;
        vector <vector <int>> ans;

        func(1, k, n, temp, ans);
        return ans;
    }
};