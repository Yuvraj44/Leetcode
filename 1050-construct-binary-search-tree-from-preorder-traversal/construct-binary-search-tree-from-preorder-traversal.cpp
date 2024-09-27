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

    TreeNode* func(vector<int>& preorder, int &ind, int bound)
    {
        if(ind==preorder.size())
        return NULL;

        if(preorder[ind] > bound)
        return NULL;

        TreeNode* node= new TreeNode(preorder[ind++]);

        node->left= func(preorder, ind, node->val);
        node->right= func(preorder, ind, bound);

        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return func(preorder, i, INT_MAX);
    }
};