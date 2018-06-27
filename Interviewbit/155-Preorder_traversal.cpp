/*
Given a binary tree, return the preorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,2,3].

Using recursion is not allowed.


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
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ans;
    if(A==NULL){
        return ans;
    }
    ans.push_back(A->val);
    vector<int> leftans = preorderTraversal(A->left);
    ans.insert(ans.end(), leftans.begin(), leftans.end());
    vector<int> rightans = preorderTraversal(A->right);
    ans.insert(ans.end(), rightans.begin(), rightans.end());
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
