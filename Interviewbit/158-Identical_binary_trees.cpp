/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input : 

   1       1
  / \     / \
 2   3   2   3

Output : 
  1 or True

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
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(A==NULL){
        if(B==NULL){
            return 1;
        }
        return 0;
    }
    if(B==NULL){
        return 0;
    }
    if(A->val!=B->val){
        return 0;
    }
    if(isSameTree(A->left, B->left)==1){
        if(isSameTree(A->right, B->right)==1){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
