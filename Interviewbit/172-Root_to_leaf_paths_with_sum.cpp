/*
Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
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
vector<vector<int> > myFunction(TreeNode* root, int sum){
    if((root->left==NULL)&&(root->right==NULL)){
        vector<vector<int> > ans;
        if(root->val==sum){
            vector<int> temp;
            temp.push_back(root->val);
            ans.push_back(temp);
            return ans;
        }
        else{
            return ans;
        }
    }
    if(root->right==NULL){
        vector<vector<int> > ans;
        vector<vector<int> > temp = myFunction(root->left, (sum-root->val));
        int n1 = temp.size();
        for(int i=0; i<n1; i++){
            int n2 = temp[i].size();
            int sumi=root->val;
            vector<int> temp2;
            temp2.push_back(root->val);
            for(int j=0; j<n2; j++){
                sumi += temp[i][j];
                temp2.push_back(temp[i][j]);
            }
            if(sumi == sum){
                ans.push_back(temp2);
            }
        }
        return ans;
    }
    if(root->left==NULL){
        vector<vector<int> > ans;
        vector<vector<int> > temp = myFunction(root->right, (sum-root->val));
        int n1 = temp.size();
        for(int i=0; i<n1; i++){
            int n2 = temp[i].size();
            int sumi=root->val;
            vector<int> temp2;
            temp2.push_back(root->val);
            for(int j=0; j<n2; j++){
                sumi += temp[i][j];
                temp2.push_back(temp[i][j]);
            }
            if(sumi == sum){
                ans.push_back(temp2);
            }
        }
        return ans;
    }
    vector<vector<int> > ans;
    vector<vector<int> > temp = myFunction(root->left, (sum-root->val));
    int n1 = temp.size();
    for(int i=0; i<n1; i++){
        int n2 = temp[i].size();
        int sumi=root->val;
        vector<int> temp2;
        temp2.push_back(root->val);
        for(int j=0; j<n2; j++){
            sumi += temp[i][j];
            temp2.push_back(temp[i][j]);
        }
        if(sumi == sum){
            ans.push_back(temp2);
        }
    }
    temp = myFunction(root->right, (sum-root->val));
    n1 = temp.size();
    for(int i=0; i<n1; i++){
        int n2 = temp[i].size();
        int sumi=root->val;
        vector<int> temp2;
        temp2.push_back(root->val);
        for(int j=0; j<n2; j++){
            sumi += temp[i][j];
            temp2.push_back(temp[i][j]);
        }
        if(sumi == sum){
            ans.push_back(temp2);
        }
    }
    return ans;
}
vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
    if(root == NULL){
        vector<vector<int> > ans;
        return ans;
    }
    vector<vector<int> > ans = myFunction(root, sum);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
