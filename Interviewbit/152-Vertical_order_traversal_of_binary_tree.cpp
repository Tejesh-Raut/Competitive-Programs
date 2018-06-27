/*
Given a binary tree, print a vertical order traversal of it.

Example :
Given binary tree:

      6
    /   \
   3     7
  / \     \
 2   5     9
returns

[
    [2],
    [3],
    [6 5],
    [7],
    [9]
]


Note : If 2 Tree Nodes shares the same vertical level then the one with lesser depth will come first.


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
void myFunction(TreeNode* A, map<int, vector<pair<int, int> > > &M, int &minl, int currl, int &maxl, int level){
    if(A==NULL){
        return;
    }
    if(minl>currl){
        minl = currl;
    }
    if(maxl<currl){
        maxl = currl;
    }
    if(M.find(currl)!=M.end()){
        M[currl].push_back(make_pair(level, A->val));
        // cout<<"*"<<level<<" "<<A->val<<endl;
    }
    else{
        vector<pair<int, int> > temp;
        temp.push_back(make_pair(level, A->val));
        // cout<<"*"<<level<<" "<<A->val<<endl;
        M[currl] = temp;
    }
    myFunction(A->left, M, minl, (currl-1), maxl, (level+1));
    myFunction(A->right, M, minl, (currl+1), maxl, (level+1));
    return;
}
struct compare_first_only {
    template<typename T1, typename T2>
    bool operator()(const std::pair<T1, T2>& p1, const std::pair<T1, T2>& p2) {
        return p1.first < p2.first;
    }
};
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    int minl=0;
    int currl=0;
    int maxl=0;
    map<int, vector<pair<int, int> > > M;
    myFunction(A, M, minl, currl, maxl, 0);
    vector<vector<int> > ans;
    for(int i=minl; i<=maxl; i++){
        vector<pair<int ,int > > temp1 = M[i];
        stable_sort(temp1.begin(), temp1.end(), compare_first_only());
        int n = temp1.size();
        vector<int> temp2;
        for(int i=0; i<n; i++){
            temp2.push_back(temp1[i].second);
        }
        ans.push_back(temp2);
    }
    return ans;
}
