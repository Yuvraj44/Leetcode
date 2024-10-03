class Solution {
public:

    void func(int n, int open, int closed, string s, vector <string> &ans)
    {
        if(open==closed && open==n)
        {
            ans.push_back(s);
            return;
        }

        if(open<n)
            func(n, open+1, closed, s+'(', ans);
           
   
        if(closed < open)
            func(n, open, closed+1, s+')', ans);
           
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        vector <string> ans;
        func(n, 0, 0, s, ans);
        return ans;
    }
};