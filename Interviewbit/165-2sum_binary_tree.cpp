/*
Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.

Return 1 to denote that two such nodes exist. Return 0, otherwise.

Notes

Your solution should run in linear time and not take memory more than O(height of T).
Assume all values in BST are distinct.
Example :

Input 1: 

T :       10
         / \
        9   20

K = 19

Return: 1

Input 2: 

T:        10
         / \
        9   20

K = 40

Return: 0

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
bool search(TreeNode* root, int x){
    TreeNode* curr = root;
    while(curr!=NULL){
        if(curr->val == x){
            return true;
        }
        if(curr->val < x){
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    return false;
}
bool myt2Sum(TreeNode* A, int B, TreeNode* root){
    if(A==NULL){
        return false;
    }
    if(A->val == (B-(A->val))){
        return false;
    }
    if(search(root, (B-(A->val)))){
        return true;
    }
    if(myt2Sum(A->left, B, root)){
        return true;
    }
    if(myt2Sum(A->right, B, root)){
        return true;
    }
    return false;
}
int Solution::t2Sum(TreeNode* A, int B) {
    if(myt2Sum(A, B, A)){
        return 1;
    }
    else{
        return 0;
    }
}
