class Solution {
public:

    void func(int ind, vector <int> v, vector <int> nums, vector <vector <int>> &ans, int n)
    {
        if(ind==n)
        {
            ans.push_back(v);
            v.clear();
            return;
        }

        v.push_back(nums[ind]);
        func(ind+1, v, nums, ans, n);
        v.pop_back();
        func(ind+1, v, nums, ans, n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <int> v;
        vector <vector <int>> ans;
        func(0, v, nums, ans, nums.size());
        return ans;
    }
};