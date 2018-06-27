/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Example :

Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

Rain water trapped: Example 1

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water (blue section) are being trapped.


*/

int Solution::trap(const vector<int> &A) {
    int n = A.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    int lmax = 0;
    int rmax = 0;
    for(int i=0; i<n; i++){
        left[i] = lmax;
        right[n-1-i] = rmax;
        if(A[i]>lmax){
            lmax = A[i];
        }
        if(A[n-1-i]>rmax){
            rmax = A[n-1-i];
        }
    }
    int area = 0;
    int min;
    for(int i=0; i<n; i++){
        min = left[i];
        if(right[i]<min){
            min = right[i];
        }
        if(min>A[i]){
            area += min - A[i];
        }
    }
    return area;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
