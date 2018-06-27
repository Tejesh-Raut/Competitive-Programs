/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return 1 ( true ).

A = [3,2,1,0,4], return 0 ( false ).

Return 0/1 for this problem


*/

bool myFunction(vector<int> &A, long long a){
    long long n = A.size();
    if(a>=n){
        return true;
    }
    if(a==(n-1)){
        A[a] = -1;
        return true;
    }
    if(A[a]==-1){
        return true;
    }
    else{
        if(A[a]== 0){
            return false;
        }
    }
    
    for(int i=A[a]; i>=1; i--){
        if(myFunction(A, (a+(long long)i))){
            A[a] = -1;
            return true;
        }
    }
    A[a] = 0;
    return false;
}
int Solution::canJump(vector<int> &A) {
    if(myFunction(A,0)){
        return 1;
    }
    else{
        return 0;
    }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
