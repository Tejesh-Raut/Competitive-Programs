/*
Given a binary tree, flatten it to a linked list in-place.

Example :
Given


         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Note that the left child of all nodes should be NULL.


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
/*
TreeNode* myFunction(TreeNode* A, TreeNode* ans){
    if(A==NULL){
        return ans;
    }
    ans->right = new TreeNode(A->val);
    // cout<<A->val<<endl;
    ans = myFunction(A->left, ans->right);
    ans = myFunction(A->right, ans);
    return ans;
}
TreeNode* Solution::flatten(TreeNode* A) {
    if(A==NULL){
        return NULL;
    }
    TreeNode* ans = new TreeNode(A->val);
    TreeNode* ans1 = myFunction(A->left, ans);
    TreeNode* ans2 = myFunction(A->right, ans1);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
*/
void myFlatten(TreeNode* root){
    if(root==NULL){
        return;
    }
    TreeNode* left_child = root->left;
    TreeNode* right_child = root->right;
    root->left = NULL;
    myFlatten(left_child);
    myFlatten(right_child);
    root->right = left_child;
    TreeNode* curr = root;
    while(curr->right!=NULL){
        curr = curr->right;
    }
    curr->right = right_child;
    return;
}
TreeNode* Solution::flatten(TreeNode* A) {
    myFlatten(A);
    return A;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
