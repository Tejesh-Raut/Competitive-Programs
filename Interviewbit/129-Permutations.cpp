/*
Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]
 NOTE
No two entries in the permutation sequence should be the same.
For the purpose of this problem, assume that all the numbers in the collection are unique.
 Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS.
Example : next_permutations in C++ / itertools.permutations in python.
If you do, we will disqualify your submission retroactively and give you penalty points. 

*/

vector<vector<int> > permutations(vector<int> &A, int x){
    vector<vector<int> > ans;
    int n = A.size();
    if(x==(n-1)){
        vector<int> temp2;
        temp2.push_back(A[x]);
        ans.push_back(temp2);
        return ans;
    }
    vector<vector<int> > temp = permutations(A, (x+1));
    int nt = temp.size();
    int ntin = temp[0].size();
    for(int i=0; i<nt; i++){
        for(int j=0; j<(ntin+1); j++){
            vector<int> ansin((ntin+1), 0);
            for(int k=0; k<j; k++){
                ansin[k] = temp[i][k];
            }
            ansin[j] = A[x];
            for(int k=(j+1); k<(ntin+1); k++){
                ansin[k] = temp[i][k-1];
            }
            ans.push_back(ansin);
        }
    }
    return ans;
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int> > ans;
    ans = permutations(A, 0);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
