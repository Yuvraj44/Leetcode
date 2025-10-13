class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
       vector <int> v;
       vector <vector <int>> ans;
       sort(nums.begin(), nums.end());
       func(0, nums, v, ans, target);
       return ans; 
    }

    void func(int ind, vector <int> &nums, vector <int> &v, vector <vector <int>> &ans, int target)
    {
        if(target==0)
        {
            ans.push_back(v);
            return;
        }

        for(int i=ind; i<nums.size(); i++)
        {
            if(i!=ind && nums[i]== nums[i-1])\
            continue;

            if(target >= nums[i])
            {
                v.push_back(nums[i]);
                func(i+1, nums, v, ans, target-nums[i]);
                v.pop_back();
            }
        }
    }
};