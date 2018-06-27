/*
Given an array of integers, return the highest product possible by multiplying 3 numbers from the array

Input:

array of integers e.g {1, 2, 3}
 NOTE: Solution will fit in a 32-bit signed integer 
Example:

[0, -1, 3, 100, 70, 50]

=> 70*50*100 = 350000


*/

int Solution::maxp3(vector<int> &A) {
    int n = A.size();
    int ans1 = 1;
    int ans2 = 1;
    sort(A.begin(), A.end());
    ans1 = A[n-1]*A[n-2]*A[n-3];
    ans2 = A[0]*A[1]*A[n-1];
    if(ans1>ans2){
        return ans1;
    }
    else{
        return ans2;
    }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
