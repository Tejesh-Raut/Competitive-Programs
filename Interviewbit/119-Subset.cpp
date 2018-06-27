/*
Given a set of distinct integers, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]

*/

void findSubsets(vector<vector<int> > &ans, vector<int> so_far, vector<int> &A, int start, int n){
    if(n==0){
        ans.push_back(so_far);
        return;
    }
    if(start==(n-1)){
        // cout<<"*"<<endl;
        ans.push_back(so_far);
        // cout<<"*";
        // for(int i=0; i<so_far.size(); i++){
        //     cout<<so_far[i]<<" ";
        // }
        // cout<<endl;
        so_far.push_back(A[start]);
        
        ans.push_back(so_far);
        // cout<<"*";
        // for(int i=0; i<so_far.size(); i++){
        //     cout<<so_far[i]<<" ";
        // }
        // cout<<endl;
    }
    else{
        findSubsets(ans, so_far, A, (start+1), n);
        so_far.push_back(A[start]);
        findSubsets(ans, so_far, A, (start+1), n);
    }
    return;
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int> > ans;
    int n = A.size();
    vector<int> so_far;
    findSubsets(ans, so_far, A, 0, n);
    sort(ans.begin(), ans.end());
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
