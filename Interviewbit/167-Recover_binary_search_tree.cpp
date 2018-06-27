/*
Two elements of a binary search tree (BST) are swapped by mistake.
Tell us the 2 values swapping which the tree will be restored.

 Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
Example :


Input : 
         1
        / \
       2   3

Output : 
       [1, 2]

Explanation : Swapping 1 and 2 will change the BST to be 
         2
        / \
       1   3
which is a valid BST          

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
vector<int> inorderTraversal(TreeNode* A) {
    vector<int> ans;
    if(A==NULL){
        return ans;
    }
    ans = inorderTraversal(A->left);
    ans.push_back(A->val);
    vector<int> temp2 = inorderTraversal(A->right);
    ans.insert(ans.end(), temp2.begin(), temp2.end());
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> ans;
    vector<int> temp = inorderTraversal(A);
    int n = temp.size();
    vector<int> temp2(n, 0);
    for(int i=0; i<n; i++){
        temp2[i] = temp[i];
    }
    sort(temp2.begin(), temp2.end());
    for(int i=0; i<n; i++){
        if(temp2[i] != temp[i]){
            ans.push_back(temp2[i]);
        }
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
