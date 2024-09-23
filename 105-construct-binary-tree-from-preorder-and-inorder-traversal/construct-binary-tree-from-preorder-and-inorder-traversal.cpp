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

    TreeNode* func(vector<int>& preorder, int ps, int pe,
                    vector<int>& inorder, int is, int ie,
                    map<int, int> &m)
                    {
                        if(ps>pe || is>ie)
                        return NULL;

                        TreeNode* root = new TreeNode(preorder[ps]);

                        int rootInd=m[root->val];

                        int left_size= rootInd - is;

                        root->left=func(preorder, ps+1, ps+left_size,
                                        inorder, is, rootInd-1,
                                        m);

                        root->right=func(preorder, ps+left_size+1, pe,
                                         inorder, rootInd+1, ie,
                                         m);

                        return root;
                    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> m;

        for(int i=0; i<inorder.size(); i++)
        {
            m[inorder[i]]=i;
        }

        auto ans=func(preorder, 0, preorder.size()-1,
             inorder, 0, inorder.size()-1,
             m);

        return ans;
    }
};