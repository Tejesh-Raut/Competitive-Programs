/*
You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

For example,

A=[1, 3, -1]

f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5.

*/
int Solution::maxArr(vector<int> &A) {
    int max1=INT_MIN;
    int max2=INT_MIN;
    int max3=INT_MIN;
    int max4=INT_MIN;
    int f=0;
    int n = A.size();
    for(int i=0; i<n; i++){
            if((A[i]+i)>max1){
                max1 = A[i] + i;
            }
            if((A[i]-i)>max2){
                max2 = A[i]-i;
            }
            if((i-A[i])>max3){
                max3 = i - A[i];
            }
            if((-i-A[i])>max4){
                max4 = -i - A[i];
            }
    }
    int ans=0;
    for(int i=0; i<n; i++){
        if(ans< (max1 - (A[i]+i))){
            ans = max1 - (A[i]+i);
        }
        if(ans< (max2 - (A[i]-i))){
            ans = max2 - (A[i]-i);
        }
        if(ans< (max3 - (i - A[i]))){
            ans = max3 - (i-A[i]);
        }
        if(ans< (max4 - (-i-A[i]))){
            ans = max4 - (-i-A[i]);
        }
    }
    return ans;
}

