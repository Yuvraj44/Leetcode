class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> ans; 
        map <int, int> m;
        for (int i=0;i<nums.size();i++)
        {
            int d=(target-nums[i]);
            if(m.find(d)!=m.end())
            {
                ans.push_back(i);
                ans.push_back(m[d]);
                return ans;
            }
            
            m[nums[i]]=i;
            
            
        } 
        return ans;
    }
};   