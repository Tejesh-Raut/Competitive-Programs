/*
Write an efficient algorithm that searches for a value in an m x n matrix.

This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than or equal to the last integer of the previous row.
Example:

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return 1 ( 1 corresponds to true )

Return 0 / 1 ( 0 if the element is not present, 1 if the element is present ) for this problem


*/

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    long long m = A.size();
    if(m==0){
        return 0;
    }
    long long n = A[0].size();
    long long l, r;
    l = 0;
    r = (m*n)-1;
    while(l<=r){
        long long mid = l +(r-l)/2;
        long long row = mid/n;
        long long col = mid%n;
        // cout<<"l "<<l<<" r "<<r<<" mid "<<mid<<endl;
        // cout<<"mid row "<<row<<" col "<<col<<endl;
        // cout<<"mid value "<<A[row][col]<<endl;
        if(A[row][col] == B){
            return 1;
        }
        if(A[row][col]<B){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return 0;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
