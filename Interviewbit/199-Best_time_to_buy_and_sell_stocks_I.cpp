/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example :

Input : [1 2]
Return :  1

*/
int Solution::maxProfit(const vector<int> &A) {
    int n =A.size();
    if(n<=1){
        return 0;
    }
    vector<int> L(n,0);
    vector<int> R(n,0);
    L[0]= A[0];
    R[n-1] = A[n-1];
    for(int i=1; i<n; i++){
        if(A[i]<L[i-1]){
            L[i] = A[i];
        }
        else{
            L[i] = L[i-1];
        }
        if(A[n-1-i]>R[n-i]){
            R[n-1-i] = A[n-1-i];
        }
        else{
            R[n-1-i] = R[n-i];
        }
    }
    int ans=0;
    for(int i=0; i<n; i++){
        if((R[i]-L[i])>ans){
            ans = R[i]-L[i];
        }
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
     
}
