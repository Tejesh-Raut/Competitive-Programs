/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.
Example :
If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
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
        // if(find(ans.begin(), ans.end(), so_far) == ans.end()){
        //     ans.push_back(so_far);
        // }
        // cout<<"*";
        // for(int i=0; i<so_far.size(); i++){
        //     cout<<so_far[i]<<" ";
        // }
        // cout<<endl;
        so_far.push_back(A[start]);
        
        ans.push_back(so_far);
        // if(find(ans.begin(), ans.end(), so_far) == ans.end()){
        //     ans.push_back(so_far);
        // }
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
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int> > ans;
    int n = A.size();
    vector<int> so_far;
    findSubsets(ans, so_far, A, 0, n);
    sort(ans.begin(), ans.end());
    int m = ans.size();
    vector<vector<int> > final_ans;
    final_ans.push_back(ans[0]);
    for(int i=1; i<m; i++){
        if(ans[i]!=ans[i-1]){
            final_ans.push_back(ans[i]);
        }
    }
    return final_ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
