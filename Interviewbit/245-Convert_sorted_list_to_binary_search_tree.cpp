/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

 A height balanced BST : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Example :


Given A : 1 -> 2 -> 3
A height balanced BST  :

      2
    /   \
   1     3

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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* Solution::sortedListToBST(ListNode* A) {
    if(A==NULL){
        return NULL;
    }
    ListNode* p;
    p = A;
    int len = 0;
    while(p!=NULL){
        p = p->next;
        len++;
    }
    if(len==1){
        TreeNode* final = new TreeNode(A->val);
        return final;
    }
    ListNode* left = A;
    ListNode* i=A;
    int mid = len/2;
    int j=1;
    while(j<mid){
        i = i->next;
        j++;
    }
    ListNode* root = i->next;
    i->next = NULL;
    if(root==NULL){
        TreeNode* final = sortedListToBST(left);
        return final;
    }
    ListNode* right = root->next;
    TreeNode* ans = new TreeNode(root->val);
    TreeNode* ans_left = sortedListToBST(left);
    TreeNode* ans_right = sortedListToBST(right);
    ans->left = ans_left;
    ans->right = ans_right;
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
