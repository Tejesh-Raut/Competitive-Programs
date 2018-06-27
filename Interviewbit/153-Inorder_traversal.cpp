/*
Given a binary tree, return the inorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,3,2].

Using recursion is not allowed.


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
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
    if(A==NULL){
        return ans;
    }
    stack<TreeNode*> S;
    S.push(A);
    TreeNode* curr;
    curr = A;
    // cout<<endl;
    while(!S.empty()){
        int ans_size = ans.size();
        // cout<<"*"<<endl;
        // for(int i=0; i<ans_size; i++){
        //     cout<<ans[i]<<" ";
        // }
        // cout<<"*"<<endl;
        curr = curr->left;
        if(curr==NULL){
            TreeNode* temp;
            temp = S.top();
            S.pop();
            while(temp->right == NULL){
                if(S.empty()){
                    break;
                }
                ans.push_back(temp->val);
                temp = S.top();
                S.pop();
            }
            ans.push_back(temp->val);
            curr = temp->right;
            if(curr!=NULL){
                S.push(curr);
                // cout<<"pushed "<<curr->val<<endl;
            }
            else{
                
            }
        }
        else{
            S.push(curr);
            // cout<<"pushed- "<<curr->val<<endl;
        }
    }
    /*
    S.push(A);
    TreeNode* curr;
    stack<bool> Slc;
    Slc.push(true);
    while(!S.empty()){
        int ans_size = ans.size();
        cout<<"*"<<endl;
        for(int i=0; i<ans_size; i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        curr = S.top();
        if(curr->left!=NULL){
            S.push(curr->left);
            // cout<<"*push"<<curr->left->val<<endl;
            Slc.push(true);
        }
        else{
            bool tempbool = false;
            bool poped = false;
            if(!S.empty()){
                TreeNode* temp1 = S.top();
                S.pop();
                TreeNode* temp =NULL;
                if(!S.empty()){
                    temp = S.top();
                }
                S.push(temp1);
                if(Slc.top()){
                    ans.push_back(curr->val);
                    if(temp!=NULL){
                        temp->left = NULL;
                    }
                    S.pop();
                    poped = true;
                    tempbool = Slc.top();
                    Slc.pop();
                }
                else{
                    if(temp!=NULL){
                        temp->right = NULL;
                    }
                }
                Slc.pop();
            }
            if(curr->right!=NULL){
                if(poped){
                    Slc.pop();
                    Slc.push(tempbool);
                }
                S.push(curr->right);
                Slc.push(false);
            }
        }
    }
    */
    // ans = inorderTraversal(A->left);
    // ans.push_back(A->val);
    // vector<int> rightans = inorderTraversal(A->right);
    // ans.insert(ans.end(), rightans.begin(), rightans.end());
    // cout<<ans.size()<<endl;
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
