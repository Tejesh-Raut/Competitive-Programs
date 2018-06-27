/*
Find the lowest common ancestor in an unordered binary tree given two values in the tree.

 Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants. 
Example :


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4
For the above tree, the LCA of nodes 5 and 1 is 3.

 LCA = Lowest common ancestor 
Please note that LCA for nodes 5 and 4 is 5.

You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
There are no duplicate values.
You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.

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
vector<int> myFunction(vector<int> v, TreeNode* A, int x){
    if(A==NULL){
        return v;
    }
    if(A->val == x){
        v.push_back(A->val);
        return v;
    }
    v.push_back(A->val);
    vector<int> v1 = myFunction(v, A->left, x);
    if(v1[v1.size()-1] == x){
        return v1;
    }
    vector<int> v2 = myFunction(v, A->right, x);
    if(v2[v2.size()-1] == x){
        return v2;
    }
    return v;
}
int Solution::lca(TreeNode* A, int val1, int val2) {
    vector<int> v1;
    vector<int> v2;
    int n1, n2, n;
    int i=0;
    v1 = myFunction(v1, A, val1);
    n1 = v1.size();
    // cout<<"* "<<endl;
    // for(i=0; i<n1; i++){
    //     cout<<v1[i]<<" ";
    // }
    // cout<<endl;
    if(n1==0){
        return -1;
    }
    if(v1[n1-1]!=val1){
        return -1;
    }
    v2 = myFunction(v2, A, val2);
    n2 = v2.size();
    // cout<<"* "<<endl;
    // for(i=0; i<n2; i++){
    //     cout<<v2[i]<<" ";
    // }
    // cout<<endl;
    if(n2==0){
        return -1;
    }
    if(v2[n2-1]!=val2){
        return -1;
    }
    if(n1<n2){
        n= n1;
    }
    else{
        n= n2;
    }
    for(i=0; i<n; i++){
        if(v1[i]!=v2[i]){
            break;
        }
    }
    i--;
    return v1[i];
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
