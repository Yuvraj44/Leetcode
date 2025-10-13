class Solution {
public:
     vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector <int> v;
        vector <vector <int>> ans;
        sort(nums.begin(), nums.end());
        func(0, nums, v,ans);
        return ans;
    }

    void func(int ind, vector <int> &nums, vector <int> &v, vector <vector <int>> &ans)
    {
        ans.push_back(v);

        for (int i=ind; i<nums.size(); i++)
        {
            if(i!=ind && nums[i] == nums[i-1])
            continue;
            v.push_back(nums[i]);
            func(i+1, nums, v, ans);
            v.pop_back();
        }
    }
};