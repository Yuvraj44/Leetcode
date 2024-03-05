class Solution {
public:

    int fo(vector <int> nums, int target)
    {
        int l=0, h=nums.size()-1;
        int first=-1;

        while(l<=h)
        {
            int mid=l+(h-l)/2;

            if(nums[mid]== target)
            {
                first=mid;
                h=mid-1;
            }

            else if(nums[mid] < target)
            l=mid+1;
            else
            h=mid-1;
        } 
        return first;
    }

    int lo(vector <int> nums, int target)
    {
        int l=0, h=nums.size()-1;
        int last=-1;

        while(l<=h)
        {
            int mid=l+(h-l)/2;

            if(nums[mid]== target)
            {
                last=mid;
                l=mid+1;
            }

            else if(nums[mid] < target)
            l=mid+1;
            else
            h=mid-1;
        } 
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> ans;
        ans.push_back(fo(nums, target));
        ans.push_back(lo(nums, target));
        return ans;
    }
};