/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Example :

    1
   / \
  2   2
 / \ / \
3  4 4  3
The above binary tree is symmetric. 
But the following is not:

    1
   / \
  2   2
   \   \
   3    3
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
bool checkSymmetric(TreeNode* A1, TreeNode* A2){
    if(A1==NULL){
        if(A2 == NULL){
            return true;
        }
        else{
            return false;
        }
    }
    if(A2==NULL){
        return false;
    }
    if(A1->val!=A2->val){
        return false;
    }
    if(checkSymmetric(A1->left, A2->right)){
        if(checkSymmetric(A1->right, A2->left)){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
int Solution::isSymmetric(TreeNode* A) {
    if(A==NULL){
        return 1;
    }
    if(checkSymmetric(A->left, A->right)){
        return 1;
    }
    else{
        return 0;
    }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
