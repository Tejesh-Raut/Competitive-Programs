/*
Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.
 NOTE : You may assume 1 <= k <= Total number of nodes in BST 

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
int Solution::kthsmallest(TreeNode* root, int k) {
    TreeNode* curr = root;
    if(k==1){
        if(root==NULL){
            return -1;
        }
        else{
            while(curr->left!=NULL){
                curr = curr->left;
            }
            return curr->val;
        }
    }
    if(root==NULL){
        return -1;
    }
    TreeNode* prev = root;
    if(prev->left == NULL){
        return kthsmallest(prev->right, (k-1));
    }
    curr = prev->left;
    while(curr->left!=NULL){
        prev = curr;
        curr = curr->left;
    }
    prev->left = curr->right;
    return kthsmallest(root, (k-1));
}
