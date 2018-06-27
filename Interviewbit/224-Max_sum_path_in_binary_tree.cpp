/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

Example :

Given the below binary tree,

       1
      / \
     2   3
Return 6.


*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int maxPath(TreeNode* A, int &ans){
    if(A==NULL){
        return 0;
    }
    int l = maxPath(A->left, ans);
    int r = maxPath(A->right, ans);
    int ans_single = max(A->val, (A->val + max(l,r)));
    ans = max(ans, max(ans_single, (A->val + l + r)));
    return ans_single;
}
int Solution::maxPathSum(TreeNode* A) {
    int ans = INT_MIN;
    maxPath(A, ans);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
