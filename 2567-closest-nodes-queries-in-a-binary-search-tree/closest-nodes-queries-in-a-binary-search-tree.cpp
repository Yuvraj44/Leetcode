/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>in;
    void fun(TreeNode *root)
    {
        if(!root) return ;
        fun(root->left);
        in.push_back(root->val);
        fun(root->right);
    }
    void low(int &x,int k)
    {
        int l=0;
        int h=in.size()-1;
        while(h>=l)
        {
            int m=l+(h-l)/2;
            if(in[m]>k) h=m-1;
            else 
            {
                x=in[m];
                l=m+1;
            }
        }
    }
     void upp(int &x,int k)
    {
        int l=0;
        int h=in.size()-1;
        while(h>=l)
        {
            int m=l+(h-l)/2;
            if(in[m]<k) l=m+1;
            else 
            {
                x=in[m];
                h=m-1;
            }
        }
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        
        fun(root);
        vector<vector<int>> v;
        for(auto q:queries)
        {
            int x=-1;
            int y=-1;
            low(x,q);
            upp(y,q);
            v.push_back({x,y});
            
        }
        return v;
    }
};