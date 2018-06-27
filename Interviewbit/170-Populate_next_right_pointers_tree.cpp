/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 Note:
You may only use constant extra space.
Example :

Given the following binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
 Note 1: that using recursion has memory overhead and does not qualify for constant space.
Note 2: The tree need not be a perfect binary tree. 

*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void myFunction(vector<TreeLinkNode* > &ans, TreeLinkNode* A, int level){
    int n = ans.size();
    if(A==NULL){
        return;
    }
    if(level>=n){
        ans.push_back(A);
    }
    else{
        ans[level]->next = A;
        ans[level] = A;
    }
    myFunction(ans, A->left, (level+1));
    myFunction(ans, A->right, (level+1));
}
void Solution::connect(TreeLinkNode* A) {
    vector<TreeLinkNode* > ans;
    myFunction(ans, A, 0);
    return;
}
