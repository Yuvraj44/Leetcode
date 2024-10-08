class Solution {
public:
    vector <string> m = {"",    "",    "abc",  "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void func(int ind, string digits, string temp, vector <string> &ans)
    {
        if(ind==digits.length())
        {
            if(temp!="")
            ans.push_back(temp);
            return;
        }

        string op=m[(digits[ind]-'0')];

        for(int i=0; i<op.length(); i++)
        {
            temp.push_back(op[i]);
            func(ind+1, digits, temp, ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string temp="";
        vector <string> ans;
        
        func(0, digits, temp, ans);
        return ans;
    }
};