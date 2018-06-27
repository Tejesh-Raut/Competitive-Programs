/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

 Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle. 

*/

int Solution::minimumTotal(vector<vector<int> > &A) {
    int n = A.size();
    if(n==0){
        return 0;
    }
    int m=0;
    int p1=0, p2=0;
    for(int i=(n-2); i>=0; i--){
        m = A[i].size();
        for(int j=0; j<m; j++){
            if(A[i+1][j]>A[i+1][j+1]){
                A[i][j] += A[i+1][j+1];
            }
            else{
                A[i][j] += A[i+1][j];
            }
        }
    }
    return A[0][0];
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
