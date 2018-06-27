/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).

You are given a target value to search. If found in the array, return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Input : [4 5 6 7 0 1 2] and target = 4
Output : 0

NOTE : Think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*

*/

int Solution::search(const vector<int> &A, int B) {
    int n = A.size();
    int ans = -1;
    int pivot = n-1;
    int l=0;
    int r=n-1;
    while(A[l]>A[r]){
        int m = l +(r-l)/2+1;
        if(A[m]>A[l]){
            l = m;
        }
        else{
            r = m-1;
        }
    }
    pivot = r;
    if(A[0]<=B){
        l=0;
        r = pivot;
    }
    else{
        l = pivot+1;
        if((pivot+1)>=n){
            return -1;
        }
        r = n-1;
    }
    while(l<r){
        int m = l+(r-l)/2;
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
    if(A[l]==B){
        return l;
    }
    else{
        if(A[r]==B){
            return r;
        }
        else{
            return -1;
        }
    }
    // while(true){
    //     int m;
    //     if(r<l){
    //         m = l + (n-l+r)/2;
    //         if(m>(n-1)){
    //             m = m-n;
    //         }
    //     }
    //     else{
    //         m = l+(r-l)/2;
    //     }
    //     if(A[m]==B){
    //         return m;
    //     }
    //     if(A[m])
    // }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
