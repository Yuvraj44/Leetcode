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
  
    class BSTIterator
    {
        stack <TreeNode*> st;
        bool rev;

        public:
        BSTIterator(TreeNode* root, bool b)
        {
            rev=b;

            if(rev)
            push_rightSubtree(root);
            else
            push_leftSubtree(root);
        }

        void push_rightSubtree(TreeNode* root)
        {
            while(root!=NULL)
            {
                st.push(root);
                root=root->right;
            }
        }

        void push_leftSubtree(TreeNode* root)
        {
            while(root!=NULL)
            {
                st.push(root);
                root=root->left;
            }
        }

        int next()
        {
            auto ans=st.top();
            st.pop();

            if(rev)
            push_rightSubtree(ans->left);
            else
            push_leftSubtree(ans->right);

            return ans->val;
        }
    };



    bool findTarget(TreeNode* root, int k) {

        if(root==NULL)
        return false;

        BSTIterator   b1(root, false);
        BSTIterator   b2(root, true);

        int i=b1.next(), j=b2.next();

        while(i<j)
        {
            if(i+j==k)
            return true;

            if(i+j < k)
            i=b1.next();
            else
            j=b2.next();
        }
        return false;
    }
};