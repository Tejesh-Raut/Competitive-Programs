/*
Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example : 
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return

[
         [3],
         [20, 9],
         [15, 7]
]

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
void myFunction(vector<vector<int> > &ans, TreeNode* A, int level){
    int n= ans.size();
    if(A==NULL){
        return;
    }
    if(level>=ans.size()){
        vector<int> temp;
        temp.push_back(A->val);
        ans.push_back(temp);
    }
    else{
        ans[level].push_back(A->val);
    }
    myFunction(ans, A->left, (level+1));
    myFunction(ans, A->right, (level+1));
    return;
}
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int> > ans;
    myFunction(ans, A, 0);
    int n = ans.size();
    int temp;
    for(int i=1; i<n; i=i+2){
        int n1 = ans[i].size();
        for(int j=0; j<(n1/2); j++){
            temp = ans[i][j];
            ans[i][j] = ans[i][n1-j-1];
            ans[i][n1-j-1] = temp;
        }
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
