/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.
CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
The solution set must not contain duplicate combinations.
Example, 
Given candidate set 2,3,6,7 and target 7,
A solution set is:

[2, 2, 3]
[7]
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
Example : itertools.combinations in python.
If you do, we will disqualify your submission retroactively and give you penalty points. 

*/
void findSubsets(vector<vector<int> > &ans, vector<int> so_far, vector<int> &A, int start, int n, int target, int sum_so_far){
    if(sum_so_far > target){
        return;
    }
    if(n==0){
        if(sum_so_far == target){
            if(find(ans.begin(), ans.end(), so_far) == ans.end()){
                ans.push_back(so_far);
            }
        }
        return;
    }
    if(start==(n-1)){
        // cout<<"*"<<endl;
        if(sum_so_far == target){
            if(find(ans.begin(), ans.end(), so_far) == ans.end()){
                ans.push_back(so_far);
            }
        }
        // cout<<"*";
        // for(int i=0; i<so_far.size(); i++){
        //     cout<<so_far[i]<<" ";
        // }
        // cout<<endl;
        so_far.push_back(A[start]);
        if((sum_so_far+A[start])==target){
            if(find(ans.begin(), ans.end(), so_far) == ans.end()){
                ans.push_back(so_far);
            }
        }
        if((sum_so_far+A[start])<target){
            findSubsets(ans, so_far, A, (start), n, target, (sum_so_far+ A[start]));
        }
        // cout<<"*";
        // for(int i=0; i<so_far.size(); i++){
        //     cout<<so_far[i]<<" ";
        // }
        // cout<<endl;
    }
    else{
        findSubsets(ans, so_far, A, (start+1), n, target, sum_so_far);
        so_far.push_back(A[start]);
        if((sum_so_far+A[start])<=target){
            findSubsets(ans, so_far, A, (start), n, target, (sum_so_far+ A[start]));
            findSubsets(ans, so_far, A, (start+1), n, target, (sum_so_far+ A[start]));
        }
    }
    return;
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    vector<vector<int> > ans;
    int n = A.size();
    vector<int> so_far;
    findSubsets(ans, so_far, A, 0, n, B, 0);
    sort(ans.begin(), ans.end());
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
