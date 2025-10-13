class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <int> v;
        vector <vector <int>> ans;
        func(0, nums, v, ans);
        return ans;
    }

    void func(int ind, vector <int> &nums,   vector <int> &v ,vector <vector <int>> &ans)
    {
        if(ind==nums.size())
        {
            ans.push_back(v);
            return;
        }

        v.push_back(nums[ind]);
        func(ind+1, nums, v, ans);
        v.pop_back();
        func(ind+1, nums, v, ans);
    }
};