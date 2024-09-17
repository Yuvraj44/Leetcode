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

    int height(TreeNode* root)
    {
        if(root==NULL)
        return 0;

        int l=height(root->left);
        int r=height(root->right);

        return 1+max(l,r);
    }

    void diameter(TreeNode* root, int &ans)
    {
        if(root==NULL)
        return;

        int l=height(root->left);
        int r=height(root->right);

        cout<<root->val<<" "<<l<<" "<<r<<" "<<endl;
        ans=max(ans, l+r);

        diameter(root->left, ans);
        diameter(root->right, ans);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        return 0;

        int ans=0;
        diameter(root, ans);

        return ans;
    }
};