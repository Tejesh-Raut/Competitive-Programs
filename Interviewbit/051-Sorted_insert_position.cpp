/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.

[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

*/

int Solution::searchInsert(vector<int> &A, int B) {
    int n=A.size();
    int l=0;
    int r=n-1;
    while(l<=r){
        int m= l+(r-l)/2 ;
        if(A[m]==B){
            return m;
        }
        if(A[m]<B){
            l = m+1;
        }
        else{
            r = m-1;
        }
    }
    return (l);
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
