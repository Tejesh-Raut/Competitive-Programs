/*
Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.

Do it in place.

Example

Given array A as

1 0 1
1 1 1 
1 1 1
On returning, the array A should be :

0 0 0
1 0 1
1 0 1
Note that this will be evaluated on the extra memory used. Try to minimize the space and time complexity.


*/

/*
void mySetZeroes(vector<vector<int> > &A, vector<int> &X, vector<int> &Y){
    int m = A.size();
    int n = A[0].size();
    int nz = X.size();
    for(int i=0; i<nz; i++){
        for(int j=0; j<n;j++){
            A[X[i]][j] = 0;
        }
        for(int j=0; j<m; j++){
            A[j][Y[i]] = 0;
        }
    }
}
*/
void Solution::setZeroes(vector<vector<int> > &A) {
    int m = A.size();
    if(m==0){
        return;
    }
    int n = A[0].size();
    int col0 = 1;
    for(int i=0; i<m; i++){
        if(A[i][0]==0){
            col0=0;
        }
        for(int j=1; j<n; j++){
            if(A[i][j]==0){
                A[i][0] = 0; // denotes ith row should be zeroed
                A[0][j] = 0; // denotes jth col should be zeroed
            }
        }
    }
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 1; j--){
            if (A[i][0] == 0 || A[0][j] == 0){
                A[i][j] = 0;
            }
        }
        if (col0 == 0){
            A[i][0] = 0;
        }
    }
    /*
    vector<int> xcord;
    vector<int> ycord;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(A[i][j]==0){
                xcord.push_back(i);
                ycord.push_back(j);
            }
        }
    }
    mySetZeroes(A, xcord, ycord);
    */
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
