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
    TreeNode* recur(vector<int>& nums,int left,int right)
    {
        if (left>=right) return nullptr;
        auto m = max_element(nums.begin()+left,nums.begin()+right);
        int x = distance(nums.begin(),m);

        TreeNode* root = new TreeNode(*m);

        root->left = recur(nums,left,x);
        root->right = recur(nums,x+1,right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        return recur(nums,0,nums.size());

    }
};
