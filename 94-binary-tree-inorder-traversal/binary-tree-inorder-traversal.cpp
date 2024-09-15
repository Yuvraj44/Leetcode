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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* cur=root;
        vector <int> ans;
        stack <TreeNode*> st;

        while(true)
        {
            if(cur!=NULL)
            {
                st.push(cur);
                cur=cur->left;
            }

            else
            {
                if(st.empty())
                break;

                auto temp=st.top();
                st.pop();

                ans.push_back(temp->val);

                cur=temp->right;
            }
        }
        return ans;
    }
};