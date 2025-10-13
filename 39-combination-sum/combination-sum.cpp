class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector <int> v;
        vector <vector <int>> ans;
        // sort(nums.begin(), nums.end());
        func(0, nums, v, ans, target);
        return ans;
    }

    void func(int ind, vector <int> &nums,vector <int> &v, vector <vector<int>> &ans, int target)
    {
        if(ind==nums.size() || target<0)
        return;

        if(target==0)
        {
            ans.push_back(v);
            return;
        }

       

        if(nums[ind] <= target)
        {
            v.push_back(nums[ind]);
            func(ind, nums, v, ans, target-nums[ind]);
            v.pop_back();
        }
        func(ind+1, nums, v, ans, target);

    }
};