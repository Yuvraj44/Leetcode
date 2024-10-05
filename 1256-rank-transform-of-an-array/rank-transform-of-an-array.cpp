class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector <int> ans=arr;
        sort(arr.begin(), arr.end());
        map <int, int> m;

        int rank=1;
        for(auto it:arr)
        {
            if(m.find(it) != m.end())
            rank--;
            m[it]=rank++;
        }   
        for(int i=0; i<arr.size(); i++)
        {
            ans[i]=m[ans[i]];
        }

        return ans;
    }
};