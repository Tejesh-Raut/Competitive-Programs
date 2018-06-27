/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

 Note: You can only move either down or right at any point in time. 
Example :

Input : 

    [  1 3 2
       4 3 1
       5 6 1
    ]

Output : 8
     1 -> 3 -> 2 -> 1 -> 1

*/

int Solution::minPathSum(vector<vector<int> > &A) {
    int n = A.size();
    if(n==0){
        return 0;
    }
    int m = A[0].size();
    vector<int> temp(m, -1);
    vector<vector<int> > p(n, temp);
    p[n-1][m-1] = A[n-1][m-1];
    int p1, p2;
    for(int i=(n-1); i>=0; i--){
        for(int j=(m-1); j>=0; j--){
            if((i==(n-1))&&(j==(m-1))){
                continue;
            }
            if(j<(m-1)){
                p1 = A[i][j] + p[i][j+1];
            }
            else{
                p1 = INT_MAX;
            }
            if(i<(n-1)){
                p2 = A[i][j] + p[i+1][j];
            }
            else{
                p2 = INT_MAX;
            }
            if(p1<p2){
                p[i][j]=p1;
            }
            else{
                p[i][j] = p2;
            }
        }
    }
    return p[0][0];
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
