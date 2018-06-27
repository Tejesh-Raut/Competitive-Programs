/*
Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,

Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
Entries should be sorted within themselves.
Example :
If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points. 

*/

void findSubsets(vector<vector<int> > &ans, vector<int> so_far, vector<int> &A, int start, int n, int remain){
    if(n==0){
        ans.push_back(so_far);
        return;
    }
    if(start==(n-1)){
        // cout<<"*"<<endl;
        if(remain==0){
            ans.push_back(so_far);
        }
        // cout<<"*";
        // for(int i=0; i<so_far.size(); i++){
        //     cout<<so_far[i]<<" ";
        // }
        // cout<<endl;
        so_far.push_back(A[start]);
        if(remain==1){
            ans.push_back(so_far);
        }
        // cout<<"*";
        // for(int i=0; i<so_far.size(); i++){
        //     cout<<so_far[i]<<" ";
        // }
        // cout<<endl;
    }
    else{
        findSubsets(ans, so_far, A, (start+1), n, remain);
        so_far.push_back(A[start]);
        findSubsets(ans, so_far, A, (start+1), n, (remain-1));
    }
    return;
}
vector<vector<int> > Solution::combine(int n, int k) {
    vector<int> A(n,0);
    for(int i=0; i<n; i++){
        A[i] = i+1;
    }
    // sort(A.begin(), A.end());
    vector<vector<int> > ans;
    // int n = A.size();
    vector<int> so_far;
    findSubsets(ans, so_far, A, 0, n, k);
    sort(ans.begin(), ans.end());
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
