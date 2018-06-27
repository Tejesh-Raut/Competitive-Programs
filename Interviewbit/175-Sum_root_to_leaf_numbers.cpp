/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers % 1003.

Example :

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.


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
void myFunction(TreeNode* A, int curr, int &allsum){
    if((A->left==NULL)&&(A->right==NULL)){
        allsum += ((curr*10+A->val)+1003)%1003;
        allsum += 1003;
        allsum %= 1003;
        return;
    }
    curr = curr*10 + A->val;
    curr += 1003;
    curr %= 1003;
    if(A->left==NULL){
        myFunction(A->right, curr, allsum);
        return;
    }
    if(A->right==NULL){
        myFunction(A->left, curr, allsum);
        return;
    }
    myFunction(A->left, curr, allsum);
    myFunction(A->right, curr, allsum);
    return;
}
int Solution::sumNumbers(TreeNode* A) {
    int curr = 0;
    int allsum=0;
    if(A==NULL){
        return 0;
    }
    myFunction(A, curr, allsum);
    return allsum;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
