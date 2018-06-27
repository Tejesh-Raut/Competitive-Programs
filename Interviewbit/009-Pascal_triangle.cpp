/*
Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]

*/

vector<vector<int> > Solution::generate(int A) {
    vector<int> prev(1,1);
    vector<vector<int> > ans;
    if(A==0){
        return ans;
    }
    ans.push_back(prev);
    for(int i=1; i<A; i++){
        vector<int> curr(i+1, 1);
        for(int j=1; j<i; j++){
            curr[j] = prev[j]+prev[j-1];
        }
        ans.push_back(curr);
        prev = curr;
    }
    return ans;
}
