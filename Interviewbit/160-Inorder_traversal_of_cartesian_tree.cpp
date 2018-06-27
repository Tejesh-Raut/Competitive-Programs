/*
Given an inorder traversal of a cartesian tree, construct the tree.

 Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree. 
 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input : [1 2 3]

Return :   
          3
         /
        2
       /
      1

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
TreeNode* myBuildTree(vector<int> &A, int start, int end){
    if(start>end){
        return NULL;
    }
    int max = A[start];
    int maxi = start;
    for(int i=start; i<=end; i++){
        if(A[i]>max){
            max = A[i];
            maxi = i;
        }
    }
    TreeNode* ans = new TreeNode(max);
    ans->left = myBuildTree(A, start, (maxi-1));
    ans->right = myBuildTree(A, (maxi+1), end);
    return ans;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    int n = A.size();
    if(n==0){
        return NULL;
    }
    TreeNode* ans = myBuildTree(A, 0, (n-1));
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
