/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
        return "";

        string ans="";

        queue <TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();

            if(temp==NULL)
            ans+="#,";
            else
            ans=ans+to_string(temp->val)+",";

            if(temp!=NULL)
            {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="")
        return NULL;

        stringstream ss (data);

        string temp;
        getline(ss, temp, ',');

        queue <TreeNode*> q;
        TreeNode* root=new TreeNode(stoi(temp));
        q.push(root);

        while(!q.empty())
        {
            auto node=q.front();

            q.pop();

            getline(ss, temp, ',');

            if(temp=="#")
            {
                node->left=NULL;
            }
            else
            {
                TreeNode* l = new TreeNode(stoi(temp));
                node->left=l;
                q.push(l);
            }

            getline(ss, temp,',');

            if(temp=="#")
            {
                node->right=NULL;
            }
            else
            {
                TreeNode* r = new TreeNode(stoi(temp));
                node->right=r;
                q.push(r);
            }

        }

        return root;

        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));