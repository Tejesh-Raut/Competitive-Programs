/*
Given a binary tree, determine if it is height-balanced.

 Height-balanced binary tree : is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input : 
          1
         / \
        2   3

Return : True or 1 

Input 2 : 
         3
        /
       2
      /
     1

Return : False or 0 
         Because for the root node, left subtree has depth 2 and right subtree has depth 0. 
         Difference = 2 > 1. 

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
int depth(TreeNode* A){
    if(A==NULL){
        return 0;
    }
    else{
        int dl, dr;
        dl = depth(A->left);
        dr = depth(A->right);
        if(dl>dr){
            return (1+dl);
        }
        else{
            return (1+dr);
        }
    }
}
int Solution::isBalanced(TreeNode* A) {
    if(A==NULL){
        return 1;
    }
    int dl, dr;
    dl = depth(A->left);
    dr = depth(A->right);
    if(abs(dl-dr)>1){
        return 0;
    }
    if(isBalanced(A->left)==1){
        if(isBalanced(A->right)==1){
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
