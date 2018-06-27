/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

 Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Example :


Given A : [1, 2, 3]
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
TreeNode* myFunction(const vector<int> &A, int start, int end){
    int n = end-start+1;
    if(n<1){
        return NULL;
    }
    if(n==1){
        TreeNode* ans = new TreeNode(A[start]);
        return ans;
    }
    // int i=1;
    // int j=0;
    // while((i -1)<(n/2)){
    //     i = i*2;
    //     j++;
    // }
    int i = (n/2);
    int mid = start+i;
    // cout<<"* "<<start<<" "<<mid<<" "<<end<<endl;
    TreeNode* ans = new TreeNode(A[mid]);
    ans->left = myFunction(A, start, (mid-1));
    ans->right = myFunction(A, (mid+1), end);
    return ans;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    int n = A.size();
    if(n==0){
        return NULL;
    }
    TreeNode* ans = myFunction(A, 0, (n-1));
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
