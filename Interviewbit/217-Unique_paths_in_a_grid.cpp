/*
Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n). At any instance, if you are on (x,y), you can either go to (x, y + 1) or (x + 1, y).

Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Example :
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

 Note: m and n will be at most 100. 

*/

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int n = A.size();
    if(n==0){
        return 0;
    }
    int m = A[0].size();
    vector<int> temp(m, -1);
    vector<vector<int> > p(n, temp);
    if(A[n-1][m-1]==0){
        p[n-1][m-1] = 1;
    }
    else{
        p[n-1][m-1] = 0;
    }
    int p1, p2;
    for(int i=(n-1); i>=0; i--){
        for(int j=(m-1); j>=0; j--){
            if((i==(n-1))&&(j==(m-1))){
                continue;
            }
            if(j<(m-1)){
                p1 = p[i][j+1];
            }
            else{
                p1 = 0;
            }
            if(i<(n-1)){
                p2 = p[i+1][j];
            }
            else{
                p2 = 0;
            }
            if(A[i][j]==1){
                p[i][j]=0;
            }
            else{
                p[i][j] = p1+p2;
            }
        }
    }
    return p[0][0];
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
