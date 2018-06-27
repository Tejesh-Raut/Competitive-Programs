/*
Given inorder and postorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input : 
        Inorder : [2, 1, 3]
        Postorder : [2, 3, 1]

Return : 
            1
           / \
          2   3

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
TreeNode* myFunction(vector<int> &inorder, int si, int ei, vector<int> &postorder, int sp, int ep){    
    if(si>ei){
        return NULL;
    }
    TreeNode* ans = new TreeNode(postorder[ep]);
    int mid = find(inorder.begin(), inorder.end(), postorder[ep])- inorder.begin();
    ans->left = myFunction(inorder, si, (mid-1), postorder, sp, (ep-(ei-mid)-1));
    ans->right = myFunction(inorder, (mid+1), ei, postorder, (ep-(ei-mid)), (ep-1));
    return ans;
}
TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
    int n = inorder.size();
    if(n==0){
        return NULL;
    }
    int si, ei, sp, ep;
    si=0;
    ei=n-1;
    sp=0;
    ep=n-1;
    TreeNode* ans = myFunction(inorder, si, ei, postorder, sp, ep);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
