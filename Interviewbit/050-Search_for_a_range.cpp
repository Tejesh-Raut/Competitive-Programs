/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm’s runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example:

Given [5, 7, 7, 8, 8, 10]

and target value 8,

return [3, 4].


*/

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int n = A.size();
    int l= 0;
    int r = n-1;
    int start =-1;
    int endpos = -1;
    vector<int> ans(2,-1);
    while(l<r){
        int m = l +(r-l)/2+1;
        // cout<<"l "<<l<<" r "<<r<<" m "<<m<<endl;
        if(A[m] <= B){
            l = m;
        }
        else{
            r = m-1;
        }
    }
    if(A[r]==B){
        endpos = r;
        // cout<<"end "<<endpos<<endl;
    }
    else{
        return ans;
    }
    l=0;
    r=n-1;
    while(l<r){
        int m = l+(r-l)/2;
        if(A[m]>=B){
            r = m;
        }
        else{
            l = m+1;
        }
    }
    start = l;
    // cout<<"start "<<start<<endl;
    ans[0] = start;
    ans[1] = endpos;
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
