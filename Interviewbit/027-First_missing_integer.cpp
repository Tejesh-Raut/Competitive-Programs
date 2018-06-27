/*
Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.


*/

void swap(vector<int> &A, int i, int j){
    int k = A[i];
    A[i] = A[j];
    A[j] = k;
    return;
}
int segregate(vector<int> &A){
    int n = A.size();
    int j=0;
    for(int i=0; i<n; i++){
        if(A[i]<=0){
            swap(A, i, j);
            j++;
        }
    }
    return j;
}
int Solution::firstMissingPositive(vector<int> &A){
    int n = A.size();
    int shift = segregate(A);
    // cout<<shift<<endl;
    for(int i=shift; i<n; i++){
        if((abs(A[i])+shift-1<n)&&(A[abs(A[i])+shift-1]>0)){
            A[abs(A[i])+shift-1]= - A[abs(A[i])+shift-1];
        }
    }
    for(int i=shift; i<n; i++){
        if(A[i]>0){
            return (i-shift+1);
        }
    }
    return (n-shift+1);
}