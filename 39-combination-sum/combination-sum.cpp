class Solution {
public:

    void func(vector <int> &arr, int ind, int &target, int sum, vector <int> &temp, vector <vector <int>> &ans)
    {
        if(ind==arr.size())
        {
            if(sum==target)
            ans.push_back(temp);

            return;
        }

        if(sum+arr[ind] <= target)
        {
            temp.push_back(arr[ind]);
            func(arr, ind, target, sum+arr[ind], temp, ans);
            temp.pop_back();
        }
        func(arr, ind+1, target, sum, temp, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector <vector <int>> ans;
        vector <int> temp;

        func(arr, 0, target, 0, temp, ans);

        return ans;
    }
};