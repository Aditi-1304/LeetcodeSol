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
    int s=0;
    int m=0;
    void heightTree(TreeNode* root,int h)
    {
        if(root == nullptr)return;
        if(root->left == nullptr && root->right == nullptr)
        {
            h++;
            if(h > m)
            {
                m = h;
            }
            return;
        }
        heightTree(root->left,h+1);
        heightTree(root->right,h+1);
    }

    void SumTree(TreeNode* root,int k)
    {
        if(root == nullptr)return;
        // if(root->left == nullptr && root->right == nullptr)
        // {
        //     k--;
        //     if(k==0)
        //     {
        //         s+=root->val;
        //     }
        //     return;
        // }
        if(k==1)
        {
            s+=root->val;
            return;
        }
        int x = k-1;
        // cout<<x<<" ";
        SumTree(root->left,x);
        SumTree(root->right,x);
    }

    int deepestLeavesSum(TreeNode* root) {
        heightTree(root,0);
        SumTree(root,m);
        cout<<m;
        return s;
    }
};
