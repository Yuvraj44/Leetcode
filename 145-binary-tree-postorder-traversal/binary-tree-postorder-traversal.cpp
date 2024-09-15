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

 //LRN
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack <TreeNode*> st;
        vector <int> ans;
        TreeNode* cur=root;
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

                if(temp->right != NULL)
                cur=temp->right;
                else
                {
                    st.pop();

                    ans.push_back(temp->val);

                    while (!st.empty() && temp == st.top()->right) //to go back in the tree
                    {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }

                
            }
        }
        return ans;
    }
};