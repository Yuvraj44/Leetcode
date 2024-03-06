class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0, h=nums.size()-1;
    vector <int> ans;
        while(l<h)
        {
            if(nums[l]+nums[h]==target)
            {
                ans.push_back(l+1);
                ans.push_back(h+1);
                return ans;
            }
            if(nums[l]+nums[h]>target)
            h--;
            else
            l++;
        }
        return ans;
    }
};