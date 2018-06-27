/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Example :

Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem


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
int Solution::hasPathSum(TreeNode* A, int B) {
    if(A==NULL){
        return 0;
    }
    if((A->left==NULL)&&(A->right==NULL)){
        if(B==A->val){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(A->right==NULL){
        if(hasPathSum(A->left, (B-(A->val)))==1){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(A->left==NULL){
        if(hasPathSum(A->right, (B-(A->val)))==1){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(hasPathSum(A->left, (B-(A->val)))==1){
        return 1;
    }
    if(hasPathSum(A->right, (B-(A->val)))==1){
        return 1;
    }
    return 0;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
