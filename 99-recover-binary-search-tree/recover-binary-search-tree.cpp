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
    void inorder(TreeNode* root, TreeNode*& first, TreeNode*& mid, TreeNode*& last, TreeNode*& prev) {
        if (root == nullptr)
            return;

        // Traverse the left subtree
        inorder(root->left, first, mid, last, prev);

        // Check if the previous node's value is greater than the current node's value
        if (first == nullptr && prev->val > root->val) {
            first = prev;  // Mark the first node
            mid = root;    // Mark the middle node
        } else if (prev->val > root->val) {
            last = root;   // Mark the last node
        }

        // Update the previous node
        prev = root;

        // Traverse the right subtree
        inorder(root->right, first, mid, last, prev);
    }

    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* mid = nullptr;
        TreeNode* last = nullptr;
        TreeNode* prev = new TreeNode(INT_MIN);  // Initialize previous node to the minimum possible value

        // Perform inorder traversal and identify the swapped nodes
        inorder(root, first, mid, last, prev);

        // If two nodes were swapped
        if (first && last)
            swap(first->val, last->val);
        else if (first && mid)  // If adjacent nodes were swapped
            swap(first->val, mid->val);
    }
};
