/*
Given a binary tree, return the level order traversal of its nodes’ values. (ie, from left to right, level by level).

Example :
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]
Also think about a version of the question where you are asked to do a level order traversal of the tree when depth of the tree is much greater than number of nodes on a level.


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
void myFunc(TreeNode* A, int level, vector<vector<int> > &ans){
    if(A==NULL){
        return;
    }
    if(ans.size()<(level+1)){
        vector<int> temp;
        temp.push_back(A->val);
        ans.push_back(temp);
    }
    else{
        ans[level].push_back(A->val);
    }
    myFunc(A->left, (level+1), ans);
    myFunc(A->right, (level+1), ans);
    return;
}
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int> > ans;
    if(A==NULL){
        return ans;
    }
    vector<int> temp;
    temp.push_back(A->val);
    ans.push_back(temp);
    myFunc(A->left, 1, ans);
    myFunc(A->right, 1, ans);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
